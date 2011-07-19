<?php

/**
 * Implements of drush_hook_command().
 */
function journalstream_drush_command() {
  $items = array();
  $items['journalstream-cleanup'] = array( 
    'description' => 'Cleans up orphaned nodes from journalstream topic queues'    
  );
  return $items;
}

/**
 * Implements of drush_hook_COMMAND().
 * Drush interface for running journalstream_cleanup()
 */
function drush_journalstream_cleanup() {
  $count = journalstream_cleanup();
  drush_print("Cleaned up $count orphaned nodes.");
}
