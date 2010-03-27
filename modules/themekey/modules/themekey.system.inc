<?php
// $Id: themekey.system.inc,v 1.3.2.12 2010/01/07 09:35:56 mkalkbrenner Exp $

/**
 * @file
 * Provides some ThemeKey properties.
 */


/**
 * Implements hook_themekey_properties().
 *
 * Provides additional properties for module ThemeKey:
 * - system:host
 * - drupal:path
 * - drupal:path:wildcard
 *
 * @return
 *   array of themekey properties and mapping functions
 */
function themekey_system_themekey_properties() {
  // Attributes for properties
  $attributes = array();
  $attributes['system:host'] = array(
    'description' => t('System: HTTP_HOST - The hostname/domain of the site without http:// or https://, like "www.drupal.org" or "drupal.cocomore.com"'),
    'validator' => 'themekey_validator_http_host',
  );
  $attributes['drupal:path'] = array(
    'description' => t('Drupal: Drupal path or path alias with support for wildcards<br />
Text copied from ThemeKey 6.x-1.2 paths description and needs to be reviewed:
<del>Here you can map themes to Drupal paths or path aliases. To add a new map entry to the table,
enter the path into the "Path" field and select a theme from the "Theme" dropdown. For example:
Path = "node/add" and Theme = "Bluemarine" switches the theme of the "Create content" page to
Bluemarine. You may also use wildcard characters in the path and/or specify "Conditions" to match.<br />
Wildcard characters are "#" for numeric parts and "%" for all characters. To match conditions
against a certain part, use an identifier with the wildcard. For example: Path =
"comment/reply/#xyz" matches all paths with "comment/reply" and a numeric third argument.
You can then specify conditions for every wildcard argument using the following syntax:
"id=value;id2=value2;...", e.g. "xyz=123". Supported operators are "=" (equal), "!" (not equal),
"<" (smaller), ">" (greater) and "~" (regex match).</del>'),
    'validator' => 'themekey_validator_drupal_path',
  );
  $attributes['drupal:path:wildcard'] = array(
    'description' => t('wildcard of drupal:path'), // TODO DESCRIPTION
    'validator' => 'themekey_validator_wildcard',
  );


  return array('attributes' => $attributes);
}


/**
 * Implements hook_themekey_global().
 */
function themekey_system_themekey_global() {
  global $user;

  $parameters = array();
  $parameters['system:host'] = $_SERVER['HTTP_HOST'];

  list($ancestors, $placeholders) = themekey_get_path_ancestors($_GET['q']);
  foreach ($ancestors as $ancestor) {
    $parameters['drupal:path'][] = $ancestor;
  }

  if (module_exists('path')) {
    // Derive path from request_uri
    $offset = (variable_get('clean_url', 0) ? 0 : 3) + strlen(base_path());
    $alias_uri = substr(request_uri(), $offset);
    if (strpos($alias_uri, '?') !== FALSE) {
      // Remove query string from request uri
      $alias_uri_parts = explode('?', $alias_uri);
      $alias_uri = $alias_uri_parts[0];
    }
    // For $alias_uri != $_GET['q'] the page was requested using an
    // aliased path, otherwise get the path alias internally
    if ($alias_uri == $_GET['q']) {
      $alias_uri = drupal_get_path_alias($_GET['q']);
    }

    if ($alias_uri != $_GET['q']) {
      $parameters['internal:alias_uri'] = $alias_uri;

      list($ancestors, $placeholders) = themekey_get_path_ancestors($alias_uri);
      foreach ($ancestors as $ancestor) {
        $parameters['drupal:path'][] = $parameters['internal:path_alias'][] = $ancestor;
      }

      if (!empty($parameters['internal:path_alias'])) {
        $parameters['drupal:path'] = array_unique($parameters['drupal:path']);
        $parameters['internal:path_alias'] = array_unique($parameters['internal:path_alias']);
      }
    }
  }

  rsort($parameters['drupal:path']);

  return $parameters;
}
