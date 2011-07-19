<?php
/**
 * Handles bookmarklet submissions
*/
function journalstream_bookmarklet_handler() {
  global $base_url;
  global $user;
  $js = '';
  $status = 0;
  $queue_node = menu_get_object();
  //Parse POST Vars
  $url = (!empty($_POST['url'])) ? filter_xss($_POST['url'], array()) : '';

  //Setup Source and Path vars
  $module_path = drupal_get_path('module','journalstream_bookmarklet');
  $porthole_path = $base_url . '/' . $module_path . '/javascripts/porthole.js';
  $proxy_path = $base_url . '/journalstream/bookmarklet/proxy';
  if($queue_node->type == JS_TOPIC_QUEUE_TYPE && !empty($url) && user_is_logged_in($user)) {
    $decoded_url = urldecode($url);
    $nid = journalstream_web_resource_import_by_url($decoded_url);
    //Add to queue
    $nids = array();
    $nids[] = $nid;
    journalstream_add_to_queue($nids,$queue_node->nid);
    $status = (!empty($nid)) ? 1 : 0; 
    watchdog('info','Journalstream Web Resources saved url: ' . $decoded_url);
  }
  $js = <<< EOF
windowProxy.postMessage('url=%s&status=%s');
EOF;

  $js = sprintf($js,$url,$status);

$html = <<< EOF
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"> 
<html xmlns="http://www.w3.org/1999/xhtml"> 
	<head> 
		<script type="text/javascript" src="%s"></script> 
		<script type="text/javascript"> 
      var windowProxy;
      window.onload = function() { 
        windowProxy = new Porthole.WindowProxy('%s');
        %s
      }
		</script> 
	</head> 
	<body> 
	</body> 
</html>
EOF;
  header('Access-Control-Allow-Origin: *');
  printf($html,$porthole_path, $proxy_path, $js);
}

/**
 * Handles redirected bookmarklet requests
*/
function journalstream_bookmarklet_redirect_handler() {
  $queue_node = menu_get_object();
  $hash = arg(3); 
  $url = urldecode(base64_decode($hash));
  if(empty($hash) || !valid_url($url,TRUE)) {
    drupal_set_message('Invalid URL sent to bookmarklet');
    drupal_goto('node/' . $queue_node->nid);
  }
  $nid = journalstream_resource_import_by_url($url);
  //Add to queue
  $nids = array();
  $nids[] = $nid;
  journalstream_add_to_queue($nids,$queue_node->nid);
  $status = (!empty($nid)) ? 1 : 0; 
  watchdog('info','Journalstream Web Resources saved url: ' . $url);
  drupal_goto($url);
}
