<?php
/**
 * @file
 * journalstream_web_resource.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function journalstream_web_resource_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function journalstream_web_resource_node_info() {
  $items = array(
    'web_resource' => array(
      'name' => t('Web Resource'),
      'base' => 'node_content',
      'description' => t('A website resource.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
