<?php
/**
 * @file
 * journalstream_web_resource.strongarm.inc
 */

/**
 * Implementation of hook_strongarm().
 */
function journalstream_web_resource_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_web_resource';
  $strongarm->value = 0;
  $export['comment_anonymous_web_resource'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_web_resource';
  $strongarm->value = 0;
  $export['comment_default_mode_web_resource'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_web_resource';
  $strongarm->value = '50';
  $export['comment_default_per_page_web_resource'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_web_resource';
  $strongarm->value = 0;
  $export['comment_form_location_web_resource'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_web_resource';
  $strongarm->value = '0';
  $export['comment_preview_web_resource'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_web_resource';
  $strongarm->value = 0;
  $export['comment_subject_field_web_resource'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_web_resource';
  $strongarm->value = '1';
  $export['comment_web_resource'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_web_resource';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_web_resource'] = $strongarm;

  return $export;
}