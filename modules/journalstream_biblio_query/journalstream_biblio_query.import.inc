<?php
/**
 * Handles running query via batch
*/

/**
 * Hook for processing biblio_queries in a queue, as a batch job. Code heisted from update.module
*/
function journalstream_biblio_query_batch(&$context) {
  $queue = DrupalQueue::get('journalstream_biblio_query_feeds');
  $queue_data = journalstream_biblio_query_cron_queue_info();
  $function = $queue_data['journalstream_biblio_query_feeds']['worker callback'];
  $end = time() + (isset($queue_data['journalstream_biblio_query_feeds']['time']) ? $queue_data['journalstream_biblio_query_feeds']['time'] : 15);

  if (empty($context['sandbox']['max'])) {
    $context['finished'] = 0;
    $context['sandbox']['max'] = $queue->numberOfItems();
    $context['sandbox']['progress'] = 0;
    $context['message'] = t('Checking available update data ...');
    $context['results']['updated'] = 0;
    $context['results']['failures'] = 0;
    $context['results']['processed'] = 0;
  }

  while (time() < $end && ($item = $queue->claimItem())) {
    $function($item->data);
    $context['results']['updated']++;
    $context['message'] = t('Importing content');
    $context['sandbox']['progress']++;
    $context['results']['processed']++;
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
    $queue->deleteItem($item);
   }

   $context['finished'] = 1;
   return;
}

/**
 * Batch API callback when all fetch tasks have been completed.
 *
 * @param $success
 *   Boolean indicating the success of the batch.
 * @param $results
 *   Associative array holding the results of the batch, including the key
 *   'updated' which holds the total number of projects we fetched available
 *   update data for.
 */
function journalstream_biblio_query_batch_finished($success, $results) {
  if ($success) {
    if (!empty($results)) {
      if (!empty($results['updated'])) {
        watchdog('journalstream_biblio_query', 'Batch import of papers completed.');
      }
    }
  }
  else {
    drupal_set_message(t('An error occurred trying to import papers.'), 'error');
  }
}