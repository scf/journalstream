<?php
/**
 * @file
 * scf_collections.features.inc
 */

/**
 * Implementation of hook_node_info().
 */
function scf_collections_node_info() {
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
