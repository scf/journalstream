<?php
/**
 * @file
 * journalstream.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function journalstream_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function journalstream_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function journalstream_node_info() {
  $items = array(
    'collection' => array(
      'name' => t('JournalStream Collection'),
      'base' => 'node_content',
      'description' => t('A curated collection of Articles. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'topic_queue' => array(
      'name' => t('JournalStream Topic Queue'),
      'base' => 'node_content',
      'description' => t('A moderation queue containing articles originating from various source queries. A moderation queue published a collection.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
