<?php
/**
 * Handles running query via batch
*/
function journalstream_biblio_query_batch_execute($nid, &$context) {
  //TODO: Refactor so it uses a "real" batch hook and not journalstream_biblio_query_execute
  drupal_set_message(t('Executing biblio query import.'));
  $feed = node_load($nid);
  journalstream_biblio_query_execute($feed);
  $context['message'] = 'Importing biblio nodes.';
}

function journalstream_biblio_query_batch_finished($success, $results, $operations) {
  //require('./'. drupal_get_path('module', 'biblio') .'/includes/biblio.import.export.inc');
  //biblio_import_batch_finished($success, $results, $operations);
}
