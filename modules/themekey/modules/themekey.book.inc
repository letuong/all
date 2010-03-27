<?php
// $Id: themekey.book.inc,v 1.5.2.4 2010/01/04 15:00:42 mkalkbrenner Exp $

/**
 * @file
 * Provides some comment attributes as ThemeKey properties.
 */


/**
 * Implements hook_themekey_properties().
 *
 * Provides additional properties for module ThemeKey:
 * - book:bid
 * - book:has_children
 *
 * @return
 *   array of themekey properties and mapping functions
 */
function themekey_book_themekey_properties() {
  // Attributes for properties
  $attributes = array();
  $attributes['book:bid'] = array(
    'description' => t('Book: ID - The id of the book (bid). This is the node id (nid) of the top book page. See !link for your books', array('!link' => l('admin/content/book', 'admin/content/book'))),
    'validator' => 'themekey_validator_ctype_digit',
  );
  $attributes['book:has_children'] = array(
    'description' => t('Book: Has Children - Wheter the book has child pages or not. Possible values are "0" for false and "1" for true.'),
    'validator' => 'themekey_validator_nummeric_boolean',
  );

  $maps = array();
  $maps[] = array('src'       => 'node:nid',
                  'dst'       => 'book:bid',
                  'callback'  => 'themekey_book_nid2bid');
  $maps[] = array('src'       => 'node:nid',
                  'dst'       => 'book:has_children',
                  'callback'  => 'themekey_book_nid2has_children');

  return array('attributes' => $attributes, 'maps' => $maps);
}


/**
 * ThemeKey mapping function to set a
 * ThemeKey property's value (destination)
 * with the aid of another ThemeKey property (source).
 *
 * src: node_nid
 * dst: book:bid
 *
 * @param $nid
 *   a node id
 *
 * @return
 *   a book id
 *   or NULL if no value could be mapped
 */
function themekey_book_nid2bid($nid, $object = NULL) {
  if ($node = node_load($nid)) {
    if (!empty($node->book['bid'])) {
      return $node->book['bid'];
    }
  }

  return NULL;
}


/**
 * ThemeKey mapping function to set a
 * ThemeKey property's value (destination)
 * with the aid of another ThemeKey property (source).
 *
 * src: node_nid
 * dst: book:has_children
 *
 * @param $nid
 *   a node id
 *
 * @return
 *   boolean
 *   or NULL if no value could be mapped
 */
function themekey_book_nid2has_children($nid, $object = NULL) {
  if ($node = node_load($nid)) {
    if (!empty($node->book['has_children'])) {
      return $node->book['has_children'];
    }
  }

  return NULL;
}
