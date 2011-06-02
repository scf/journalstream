<?php
/**
 * @file
 * scf_biblio_query.features.inc
 */

/**
 * Implementation of hook_node_info().
 */
function scf_biblio_query_node_info() {
  $items = array(
    'biblio_topic_query' => array(
      'name' => t('Biblio Topic Query'),
      'base' => 'node_content',
      'description' => t('A biblio query used to populate the topic queue.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
