<?php

/**
 * Implements hook_form()
 * Journalstream admin form
*/
function journalstream_admin_form() {
  $form = array();
  $content_types = variable_get('journalstream_content_types', _journalstream_get_default_types());
  $form['journalstream_content_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Node Types:'),
    '#description' => t('Select which node types will be used in a Journalstream feed.'),
    '#options' => _journalstream_get_node_types(),
    '#default_value' => $content_types,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#name' => 'Submit',
    '#value' => 'Submit'
  );
  return $form;
}

/**
 * Implements hook_submit()
 * Submit handler for admin form
*/
function journalstream_admin_form_submit($form, & $form_state) {
  $vals = array_values($form_state['values']['journalstream_content_types']);
  $content_types = array();
  foreach($vals as $key => $val) {
    if(!empty($val)) {
      $content_types[] = $val;
    }
  }
  variable_set('journalstream_content_types', $content_types);
  drupal_set_message('Journalstream content types successfully saved.');
}



/**
 * Helper hook to retrieve a list of node types
*/
function _journalstream_get_node_types() {
  $types = array();
  $node_types = node_type_get_types();
  foreach($node_types as $type) {
    $types[$type->type] = $type->type;
  }
  return $types;

  dd(node_type_get_types());

  return array(
    'biblio' => 'Biblio',
  );
}
