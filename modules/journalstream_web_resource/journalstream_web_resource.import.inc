<?php

function journalstream_web_resource_import_form($form_state) {
  global $user;
  $node = menu_get_object();
  $queue_options = array( 
    'not_reviewed' => 'Not Reviewed',
    'accepted' => 'Accepted',
    'rejected' => 'Rejected',
  );

  $form['import_file'] = array (
    '#type' => 'file',
    '#title' => t('Import file'),
    '#size' => 60,
    '#description' => t('A CSV file containing list of URL\'s to import.'),
  );
  $form['import_raw'] = array (
    '#type' => 'textarea',
    '#title' => t('Import data'),
    '#default_value' => '',
    '#description' => t('Paste a comma seperated list of URL\'s'),
    '#size' => 60
  );
  $form['queue'] = array( 
    '#type' => 'select',
    '#title' => t('Moderation Queue'),
    '#options' => $queue_options,
    '#default_value' => 'not_reviewed', 
    '#description' => t('Moderation queue to append papers to.')
  );
  /** Temporarily Disabled
  $form['batch_process'] = array (
    '#type' => 'checkbox',
    '#title' => t('Batch Process'),
    '#default_value' => 1,
    '#description' => t('You should use batch processing if your import file contains more than about 20 records, or if you are experiencing script timeouts during import'),
  );
  **/
  $form['batch_process'] = array(
    '#type' => 'value',
    '#value' => 0,
  );
  $form['nid'] = array( 
    '#type' => 'value',
    '#value' => $node->nid,
  );
  $form['#attributes'] = array('enctype' => 'multipart/form-data');
  $form['button'] = array ('#type' => 'submit', '#value' => t('Import'));
  return $form;
}

function journalstream_web_resource_import_form_validate($form, &$form_state) {
  $op = $form_state['values']['op'];
   // Test for either the raw input or the file.
  if (!$form_state['values']['import_raw'] && !$_FILES['files']['name']['import_file']) {
    form_set_error('journalstream_web_resource_import_form', t("You must either select a file or paste import data."));
  }

  if (!$form_state['values']['import_raw'] && $error = $_FILES['files']['error']['import_file']) {
    switch ($error){
      case 1: form_set_error('journalstream_web_resource_import_form', t("The uploaded file exceeds the upload_max_filesize directive in php.ini."));
      break;
      case 2: form_set_error('journalstream_web_resource_import_form', t("The uploaded file exceeds the MAX_FILE_SIZE directive that was specified in the HTML form."));
      break;
      case 3: form_set_error('journalstream_web_resource_import_form', t("The uploaded file was only partially uploaded."));
      break;
      case 4: form_set_error('journalstream_web_resource_import_form', t("No file was uploaded."));
      break;
      case 6: form_set_error('journalstream_web_resource_import_form', t("Missing a temporary folder."));
      break;
      case 7: form_set_error('journalstream_web_resource_import_form', t("Failed to write file to disk."));
      break;
      case 8: form_set_error('journalstream_web_resource_import_form', t("File upload stopped by extension."));
    }
  } 
}

/**
 * Implementation of hook_submit() for the journalstream_biblio_import_form.
 */
function journalstream_web_resource_import_form_submit($form, & $form_state) {
  global $batch_proc;
  global $session_id;
  global $user;
  $raw = '';
  $import_file = false;
  $queue = (isset ($form_state['values']['queue'])) ? $form_state['values']['queue'] : 'not_reviewed';
  $queue_nid = (isset ($form_state['values']['nid'])) ? $form_state['values']['nid'] : FALSE;

  if ($raw = $form_state['values']['import_raw']) {
    // In the case of a raw input containing no LF, we check if it contains
    // a comma separated list of IDs and format it as LF separated list.
    if (strpos($raw, "\n") === FALSE) {
      $raw = implode("\n", drupal_explode_tags($raw));
    }
    $import_file = file_save_data($raw, 'temporary://pow_raw_import' . mt_rand());
  }
  else {
    $import_file = file_save_upload('import_file');
  }

  if(!$import_file) {
    drupal_set_message(t("File was NOT successfully uploaded"), 'error');
    return;
  }
  //Read each URL and import
  $file_data = file_get_contents($import_file->uri);
  $url_list = explode(',',preg_replace('/\n|\t|\s/','',$file_data));
  $nids = array();
  foreach($url_list as $url) {
    if(!empty($url) && valid_url($url, TRUE)) {
      if($nid = journalstream_web_resource_import_by_url($url)) {
        $nids[] = $nid;
      }
    }
  }
  journalstream_add_to_queue($nids,$queue_nid,$queue);
  drupal_set_message(t("Successfully imported " . count($nids) . " " . SCF_WEB_RESOURCE_NODE_TYPE . "."));
  file_delete($import_file);
  //Go to assigned queue
  $path = 'node/' . $queue_nid . '/' . $queue;
  drupal_goto($path);
}
