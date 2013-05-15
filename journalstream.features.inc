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
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function journalstream_flag_default_flags() {
  $flags = array();
  // Exported flag: "Classic Paper".
  $flags['js_classic_paper'] = array(
    'content_type' => 'node',
    'title' => 'Classic Paper',
    'global' => 1,
    'types' => array(
      0 => 'biblio',
    ),
    'flag_short' => 'Mark as Classic Paper',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Remove Classic Paper',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => 2,
      ),
      'unflag' => array(
        0 => 2,
      ),
    ),
    'weight' => 1,
    'show_on_form' => 1,
    'access_author' => '',
    'show_on_page' => 0,
    'show_on_teaser' => 0,
    'show_contextual_link' => 0,
    'i18n' => 0,
    'api_version' => 2,
    'module' => 'journalstream',
    'locked' => array(
      0 => 'name',
    ),
  );
  // Exported flag: "Editors&#039; Pick".
  $flags['js_editors_pick'] = array(
    'content_type' => 'node',
    'title' => 'Editors\' Pick',
    'global' => 1,
    'types' => array(
      0 => 'biblio',
    ),
    'flag_short' => 'Mark as Editors\' Pick',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Remove Editors\' Pick',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => 2,
      ),
      'unflag' => array(
        0 => 2,
      ),
    ),
    'weight' => 0,
    'show_on_form' => 1,
    'access_author' => '',
    'show_on_page' => 0,
    'show_on_teaser' => 0,
    'show_contextual_link' => 0,
    'i18n' => 0,
    'api_version' => 2,
    'module' => 'journalstream',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;

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
