<?php
/**
 * @file
 * journalstream_biblio_query.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function journalstream_biblio_query_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function journalstream_biblio_query_node_info() {
  $items = array(
    'biblio_topic_query' => array(
      'name' => t('JournalStream Topic Query'),
      'base' => 'node_content',
      'description' => t('A biblio query used to populate the topic queue.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
