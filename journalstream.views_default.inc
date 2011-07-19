<?php
/**
 * @file
 * journalstream.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function journalstream_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'journalstream_queue';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'SCF Collections Queue';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Accepted Papers';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Not Reviewed Nodes */
  $handler->display->display_options['fields']['field_not_reviewed_nodes']['id'] = 'field_not_reviewed_nodes';
  $handler->display->display_options['fields']['field_not_reviewed_nodes']['table'] = 'field_data_field_not_reviewed_nodes';
  $handler->display->display_options['fields']['field_not_reviewed_nodes']['field'] = 'field_not_reviewed_nodes';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'topic_queue' => 'topic_queue',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['access'] = '1';
  $handler->display->display_options['arguments']['nid']['validate_options']['access_op'] = 'update';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'topic_queue' => 'topic_queue',
  );

  /* Display: Not Reviewed */
  $handler = $view->new_display('block', 'Not Reviewed', 'not_reviewed');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Not Reviewed Papers';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Not Reviewed Nodes */
  $handler->display->display_options['fields']['field_not_reviewed_nodes']['id'] = 'field_not_reviewed_nodes';
  $handler->display->display_options['fields']['field_not_reviewed_nodes']['table'] = 'field_data_field_not_reviewed_nodes';
  $handler->display->display_options['fields']['field_not_reviewed_nodes']['field'] = 'field_not_reviewed_nodes';
  $handler->display->display_options['fields']['field_not_reviewed_nodes']['label'] = '';
  $handler->display->display_options['fields']['field_not_reviewed_nodes']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_not_reviewed_nodes']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_not_reviewed_nodes']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_not_reviewed_nodes']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_not_reviewed_nodes']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_not_reviewed_nodes']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_not_reviewed_nodes']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_not_reviewed_nodes']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_not_reviewed_nodes']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_not_reviewed_nodes']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_not_reviewed_nodes']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_not_reviewed_nodes']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_not_reviewed_nodes']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_not_reviewed_nodes']['element_wrapper_class'] = 'niddeous-[field_not_reviewed_nodes-nid]';
  $handler->display->display_options['fields']['field_not_reviewed_nodes']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_not_reviewed_nodes']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_not_reviewed_nodes']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_not_reviewed_nodes']['click_sort_column'] = 'nid';
  $handler->display->display_options['fields']['field_not_reviewed_nodes']['type'] = 'node_reference_node';
  $handler->display->display_options['fields']['field_not_reviewed_nodes']['settings'] = array(
    'node_reference_view_mode' => 'teaser_moderation',
  );
  $handler->display->display_options['fields']['field_not_reviewed_nodes']['group_rows'] = 0;
  $handler->display->display_options['fields']['field_not_reviewed_nodes']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_not_reviewed_nodes']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_not_reviewed_nodes']['multi_type'] = 'ul';
  $handler->display->display_options['fields']['field_not_reviewed_nodes']['field_api_classes'] = 0;

  /* Display: Accepted */
  $handler = $view->new_display('block', 'Accepted', 'accepted');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Accepted Papers';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Accepted Nodes */
  $handler->display->display_options['fields']['field_accepted_nodes']['id'] = 'field_accepted_nodes';
  $handler->display->display_options['fields']['field_accepted_nodes']['table'] = 'field_data_field_accepted_nodes';
  $handler->display->display_options['fields']['field_accepted_nodes']['field'] = 'field_accepted_nodes';
  $handler->display->display_options['fields']['field_accepted_nodes']['label'] = '';
  $handler->display->display_options['fields']['field_accepted_nodes']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_accepted_nodes']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_accepted_nodes']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_accepted_nodes']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_accepted_nodes']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_accepted_nodes']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_accepted_nodes']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_accepted_nodes']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_accepted_nodes']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_accepted_nodes']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_accepted_nodes']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_accepted_nodes']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_accepted_nodes']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_accepted_nodes']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_accepted_nodes']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_accepted_nodes']['click_sort_column'] = 'nid';
  $handler->display->display_options['fields']['field_accepted_nodes']['type'] = 'node_reference_node';
  $handler->display->display_options['fields']['field_accepted_nodes']['settings'] = array(
    'node_reference_view_mode' => 'teaser_moderation',
  );
  $handler->display->display_options['fields']['field_accepted_nodes']['group_rows'] = 0;
  $handler->display->display_options['fields']['field_accepted_nodes']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_accepted_nodes']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_accepted_nodes']['field_api_classes'] = 0;

  /* Display: Rejected */
  $handler = $view->new_display('block', 'Rejected', 'rejected');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Rejected Papers';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Rejected Nodes */
  $handler->display->display_options['fields']['field_rejected_nodes']['id'] = 'field_rejected_nodes';
  $handler->display->display_options['fields']['field_rejected_nodes']['table'] = 'field_data_field_rejected_nodes';
  $handler->display->display_options['fields']['field_rejected_nodes']['field'] = 'field_rejected_nodes';
  $handler->display->display_options['fields']['field_rejected_nodes']['label'] = '';
  $handler->display->display_options['fields']['field_rejected_nodes']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_rejected_nodes']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_rejected_nodes']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_rejected_nodes']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_rejected_nodes']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_rejected_nodes']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_rejected_nodes']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_rejected_nodes']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_rejected_nodes']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_rejected_nodes']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_rejected_nodes']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_rejected_nodes']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_rejected_nodes']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_rejected_nodes']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_rejected_nodes']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_rejected_nodes']['click_sort_column'] = 'nid';
  $handler->display->display_options['fields']['field_rejected_nodes']['type'] = 'node_reference_node';
  $handler->display->display_options['fields']['field_rejected_nodes']['settings'] = array(
    'node_reference_view_mode' => 'teaser_moderation',
  );
  $handler->display->display_options['fields']['field_rejected_nodes']['group_rows'] = 0;
  $handler->display->display_options['fields']['field_rejected_nodes']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_rejected_nodes']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_rejected_nodes']['field_api_classes'] = 0;

  /* Display: Preview */
  $handler = $view->new_display('block', 'Preview', 'preview');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Preview';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Accepted Nodes */
  $handler->display->display_options['fields']['field_accepted_nodes']['id'] = 'field_accepted_nodes';
  $handler->display->display_options['fields']['field_accepted_nodes']['table'] = 'field_data_field_accepted_nodes';
  $handler->display->display_options['fields']['field_accepted_nodes']['field'] = 'field_accepted_nodes';
  $handler->display->display_options['fields']['field_accepted_nodes']['label'] = '';
  $handler->display->display_options['fields']['field_accepted_nodes']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_accepted_nodes']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_accepted_nodes']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_accepted_nodes']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_accepted_nodes']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_accepted_nodes']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_accepted_nodes']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_accepted_nodes']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_accepted_nodes']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_accepted_nodes']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_accepted_nodes']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_accepted_nodes']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_accepted_nodes']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_accepted_nodes']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_accepted_nodes']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_accepted_nodes']['click_sort_column'] = 'nid';
  $handler->display->display_options['fields']['field_accepted_nodes']['type'] = 'node_reference_node';
  $handler->display->display_options['fields']['field_accepted_nodes']['settings'] = array(
    'node_reference_view_mode' => 'teaser',
  );
  $handler->display->display_options['fields']['field_accepted_nodes']['group_rows'] = 0;
  $handler->display->display_options['fields']['field_accepted_nodes']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_accepted_nodes']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_accepted_nodes']['field_api_classes'] = 0;
  $translatables['journalstream_queue'] = array(
    t('Master'),
    t('Accepted Papers'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Not Reviewed Nodes'),
    t('All'),
    t('Not Reviewed'),
    t('Not Reviewed Papers'),
    t('Accepted'),
    t('Rejected'),
    t('Rejected Papers'),
    t('Preview'),
  );
  $export['journalstream_queue'] = $view;

  return $export;
}
