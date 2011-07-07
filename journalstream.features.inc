<?php
/**
 * @file
 * journalstream.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function journalstream_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_views_api().
 */
function journalstream_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => 3.0);
  }
}

/**
 * Implementation of hook_node_info().
 */
function journalstream_node_info() {
  $items = array(
    'collection' => array(
      'name' => t('Collection'),
      'base' => 'node_content',
      'description' => t('A curated collection of Articles. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'topic_queue' => array(
      'name' => t('Topic Queue'),
      'base' => 'node_content',
      'description' => t('A moderation queue containing articles originating from various source queries. A moderation queue published a collection.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
