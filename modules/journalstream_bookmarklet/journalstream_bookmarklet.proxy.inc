<?php

/**
 * Generates the porthole.js iframe proxy html
 */
function journalstream_bookmarklet_portal_proxy() {
  global $base_url;
  $module_path = drupal_get_path('module','journalstream_bookmarklet');
  $porthole_path = $base_url . '/' . $module_path . '/javascripts/porthole.js';
$html = <<< EOF
  <!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"> 
<html xmlns="http://www.w3.org/1999/xhtml"> 
	<head> 
		<script type="text/javascript" src="%s"></script> 
		<script type="text/javascript"> 
			window.onload=function(){ Porthole.WindowProxyDispatcher.start(); };
		</script> 
	</head> 
	<body> 
	</body> 
</html>
EOF;
header('Access-Control-Allow-Origin: *');
printf($html,$porthole_path);
}