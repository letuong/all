<?php
// $Id: views_slideshow_singleframe.theme.inc,v 1.1.2.1.2.9 2009/09/28 21:32:22 redndahead Exp $

/**
 *  @file
 *  Theme & preprocess functions for the Views Slideshow: SingleFrame module.
 */

/**
 *  Implement template_preprocess_hook_THEMENAME().
 */
function template_preprocess_views_slideshow_singleframe(&$vars) {
  $options = $vars['options'];
  $base = drupal_get_path('module', 'views_slideshow_singleframe');
  drupal_add_js($base . '/views_slideshow.js', 'module');
  drupal_add_css($base . '/views_slideshow.css', 'module');

  $num_divs = sizeof($vars['rows']);

  $settings = array_merge(
    array(
      'num_divs' => $num_divs,
      'hoverFunction' => $hover,
      'id_prefix' => '#views_slideshow_singleframe_main_',
      'div_prefix' => '#views_slideshow_singleframe_div_',
      'id' => $vars['id'],
    ),
    $options['singleframe']
  );

  drupal_add_js(array('viewsSlideshowSingleFrame' => array('#views_slideshow_singleframe_main_'. $vars['id'] => $settings)), 'setting');

}


/**
 *  These are the slideshow elements themselves; not actually displayed, but used to give the html to the main element.
 */
function theme_views_slideshow_singleframe_no_display_section($view, $rows, $id, $mode, $teaser = TRUE) {
  // Add support for the jQuery Cycle plugin.
  // If we have the jQ module installed, use that to add the Cycle plugin if possible.
  // That allows for version control.
  if (module_exists('jq')) {
    if (in_array('cycle', jq_plugins())) {
      $js = jq_add('cycle');
    }
  }

  // Otherwise, we'll add the version included with this module.
  if (!$js) {
    drupal_add_js(drupal_get_path('module', 'views_slideshow') .'/js/jquery.cycle.all.min.js', 'module');
  }
  
  $output = '<div id="views_slideshow_singleframe_teaser_section_' . $id . '" class="views_slideshow_singleframe_teaser_section">' . "\n";

  foreach ($rows as $count => $item) {
    $output .= theme('views_slideshow_singleframe_no_display_teaser', $item, $id, $count);
  }
  $output .= "</div><!--close views_slideshow_singleframe_no_display-->\n\n";
  return $output;
}

/**
 *  The html that will be placed into the element in its turn during its frame.
 */
function theme_views_slideshow_singleframe_no_display_teaser($item, $id, $count) {
  $class = 'views_slideshow_singleframe_slide';
  if ($count) {
    $class .= ' views_slideshow_singleframe_hidden';
  }

  if ($count % 2) {
    $class .= ' views-row-even';
  }
  else {
    $class .= ' views-row-odd';
  }
  $output = '  <div id="views_slideshow_singleframe_div_' . $id . '_' . $count . '" class="' . $class .'">' . "\n  ";
  $output .= $item . "\n";
  $output .= '  </div><!--close views_slideshow_singleframe_div_' . $id . '_' . $count . '-->' . "\n\n";
  return $output;
}

/**
 * Themed slideshow controls.
 */
function theme_views_slideshow_singleframe_controls($id, $view, $options) {
  $output = '<div class="views_slideshow_singleframe_controls" id="views_slideshow_singleframe_controls_' . $id . '">' . "\n";
  $output .= theme('views_slideshow_singleframe_control_previous', $id, $view, $options);
  $output .= theme('views_slideshow_singleframe_control_pause', $id, $view, $options);
  $output .= theme('views_slideshow_singleframe_control_next', $id, $view, $options);
  $output .= "</div>\n";
  return $output;
}

/**
 * Themed Previous Control
 */
function theme_views_slideshow_singleframe_control_previous($id, $view, $options) {
  return '<a href="#" id="views_slideshow_singleframe_prev_' . $id . '" class="views_slideshow_singleframe_previous">' . t('Previous') . "</a>\n";
}

/**
 * Themed Pause Control
 */
function theme_views_slideshow_singleframe_control_pause($id, $view, $options) {
  return '<a href="#" id="views_slideshow_singleframe_playpause_' . $id . '" class="views_slideshow_singleframe_pause">' . t('Pause') . "</a>\n";
}

/**
 * Themed Next Control
 */
function theme_views_slideshow_singleframe_control_next($id, $view, $options) {
  return '<a href="#" id="views_slideshow_singleframe_next_' . $id . '" class="views_slideshow_singleframe_next">' . t('Next') . "</a>\n";
}

function theme_views_slideshow_singleframe_pager($id, $view, $options) {
  
  $classes = "views_slideshow_singleframe_pager";
  if ($options['singleframe']['pager_type'] == 1) {
    $classes .= ' thumbnails';
  }
  else {
    $classes .= ' numbered';
  }
  
  $output = '<div class="' . $classes . '" id="views_slideshow_singleframe_pager_' . $id . '"></div>';
  return $output;

}

function theme_views_slideshow_singleframe_image_count($id, $view, $options) {
  $output = '<div class="views_slideshow_singleframe_image_count" id="views_slideshow_singleframe_image_count_' . $id . '"><span class="num"></span> ' . t('of') .' <span class="total"></span></div>';
  return $output;
}
