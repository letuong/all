<?php
function leenews_newsview_views_plugins() {
  return array(	
	'module' => 'leenews_newsview',
    'style' => array(
      'leenews_newsview' => array(
        'title' => t('News View'),
        'theme' => 'leenews_newsview',
        'help'  => t('Display the results as a news style.'),
        'handler' => 'leenews_newsview_plugin_style_newsview',
        'uses options' => FALSE,
        'uses row plugin' => FALSE,
		'uses fields' => TRUE,
        'type' => 'normal',
      ),
    ),
  );
}

