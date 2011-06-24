<?php
/**
 * @file
 * scf_web_resource.features.inc
 */

/**
 * Implementation of hook_node_info().
 */
function scf_web_resource_node_info() {
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
