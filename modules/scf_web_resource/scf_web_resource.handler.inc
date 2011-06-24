<?php
/**
 * Handles bookmarklet submissions
*/
function scf_web_resource_bookmarklet_handler() {
  global $base_url;
  $js = '';

  //Parse POST Vars
  $title = (!empty($_POST['title'])) ? filter_xss($_POST['title'], array()) : '';
  $description = (!empty($_POST['description'])) ? filter_xss($_POST['description'], array()) : '';
  $url = (!empty($_POST['url'])) ? filter_xss($_POST['url'], array()) : '';
  $queue = (!empty($_POST['queue'])) ? filter_xss($_POST['queue'], array()) : '';
  watchdog('info','web resource response: ' . $url);

  //Setup Source and Path vars
  $module_path = drupal_get_path('module','scf_web_resource');
  $porthole_path = $base_url . '/' . $module_path . '/javascripts/porthole.js';
  $proxy_path = $base_url . '/scf_web_resource/bookmarklet/proxy';
//if(!empty($url)) {
$js = <<< EOF
windowProxy.postMessage('url=%s');
EOF;

$js = sprintf($js,$url);

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

  //Validate API
  //Flood Control flood_register_event
  //Save Data
  //Record Throttle
  //Watchdog Info
}
