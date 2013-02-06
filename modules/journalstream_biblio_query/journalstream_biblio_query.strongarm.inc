<?php
/**
 * @file
 * journalstream_biblio_query.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function journalstream_biblio_query_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_biblio_topic_query';
  $strongarm->value = 0;
  $export['comment_anonymous_biblio_topic_query'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_biblio_topic_query';
  $strongarm->value = '1';
  $export['comment_biblio_topic_query'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_biblio_topic_query';
  $strongarm->value = 1;
  $export['comment_default_mode_biblio_topic_query'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_biblio_topic_query';
  $strongarm->value = '50';
  $export['comment_default_per_page_biblio_topic_query'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_biblio_topic_query';
  $strongarm->value = 1;
  $export['comment_form_location_biblio_topic_query'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_biblio_topic_query';
  $strongarm->value = '1';
  $export['comment_preview_biblio_topic_query'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_biblio_topic_query';
  $strongarm->value = 1;
  $export['comment_subject_field_biblio_topic_query'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_biblio_topic_query';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_biblio_topic_query'] = $strongarm;

  return $export;
}
