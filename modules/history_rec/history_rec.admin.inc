<?php

// $Id: history_rec.admin.inc,v 1.1 2009/07/04 03:12:09 danithaca Exp $

/**
 * @see http://drupal.org/project/history_rec
 */

function history_rec_settings_form() {
  $form = array();
  
  $form['enabled_types'] = array(
    '#title' => t("Enabled content types"),
    '#type' => 'checkboxes',
    '#default_value' => variable_get('history_rec_enabled_types', array()),
    '#options' => node_get_types('names'),
    '#description' => t('Please select which content types you want to enable for node browsing history recommendation.')
  );
  
  $form['display_num'] = array(
    '#title' => t('Number of items to display in the block.'),
    '#type' => 'select',
    '#default_value' => variable_get('history_rec_display_num', 5),
    '#options' => array(
      3 => '3',
      5 => '5',
      8 => '8',
      10 => '10',
      15 => '15',
    ),
    '#description' => t('Please specify how many items to show in the recommendation block list.') 
  );
  
  $form['boost_comments'] = array(
    '#title' => t('Boost comments'),
    '#type' => 'checkbox',
    '#description' => t('Check the box to consider commenting as browse history too.'),
    '#default_value' => variable_get('history_rec_boost_comments', 1),
  );
  
  $form['boost_recency'] = array(
    '#title' => t('Boost recent items'),
    '#type' => 'checkbox',
    '#description' => t('Check the box to boost recent node browsing history and recent comment history (if enabled).'),
    '#default_value' => variable_get('history_rec_boost_recency', 1),
  );
  
  /*$form['algorithm'] = array(
    '#title' => t('Choose recommender algorithm'),
    '#type' => 'radios',
    '#default_value' => variable_get('history_rec_algorithm', 'classical'),
    '#options' => array(
      'cooccurrence' => t("Cooccurrence (less accurate; better performance)"),
      'classical' => t("Classical (more accurate; slower performance)"),
    ),
    '#description' => t('Different algorithms are useful in different situations. Please leave it as the default classical algorithm unless you have large number of nodes/users.')
  );*/
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );
  
  return $form;
}

function history_rec_settings_form_submit($form, &$form_state) {
  $display_num = $form_state['values']['display_num'];
  $boost_comments = $form_state['values']['boost_comments'];
  $boost_recency = $form_state['values']['boost_recency'];
  $enabled_types = array_diff($form_state['values']['enabled_types'], array('0'));
  //$algorithm = $form_state['values']['algorithm']; // default is the classical algorithm
  
  variable_set('history_rec_display_num', $display_num);
  variable_set('history_rec_boost_comments', $boost_comments);
  variable_set('history_rec_boost_recency', $boost_recency);
  variable_set('history_rec_enabled_types', $enabled_types);
  //variable_set('history_rec_algorithm', $algorithm);
  
  drupal_set_message(t("The configuration options have been saved."));
}