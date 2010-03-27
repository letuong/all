$Id: README.txt,v 1.2.4.7 2009/05/30 02:58:08 weitzman Exp $

Introduction
=============
Block Page Visibility enables site developers to centralize the display of blocks to a single Drupal hook. It is an alternative to controlling display via each block's configure form. The more "sometimes on, sometimes off blocks" that a site uses, the more useful this module becomes.

Install
=============
Activate as usual, and then submit the admin/settings/bpv page. That changes all block visibility to run through this module.

Usage
=============
Before activating the module, you'll want to create one instance of hook_bpv_config() in a custom module. It accepts no arguments, and returns an multi-dimensional array that looks like below. Usually, you only one of the last three arguments.

Each block entry contains:
//
// - positive: BPV_INCLUSIVE or BPV_EXCLUSIVE  
// - pages: array of Drupal paths
// - types: array of content types
// - bool: general-purpose boolean
//
// A block matches if pages or types matches or the boolean is
// true.  A block is shown if (exclude XOR match).
// function HOOK_bpv_config($name) {
//   $blocks = array(
//     'user-0' => array(BPV_EXCLUSIVE, array('user*',  'node*'), array(), NULL),
//     'comment-0' => array(BPV_INCLUSIVE, array('<front>'), array('story', 'page'), NULL),
//   );
//   return $blocks[$name];
// }

The key is the name of the block. The first argument to its array must either be BPV_INCLUSIVE or BPV_EXCLUSIVE; BPV_INCLUSIVE only displays the block whenever it matches the second or third argument, BPV_EXCLUSIVE always displays the block unless it matches the second or third argument. The second argument is an array of paths like in block control, and the third argument is an array of content types to match. The fourth is a general purpose boolean. Put whatever php here you want, that returns a boolean.

Credits
===========
Barry Jaspan (http://jaspan.com)
Moshe Weitzman (http://drupal.org/moshe)
Austin Smith (http://www.netaustin.net) - Port to Drupal 6.

Initial sponsorship by New York Observer (see http://drupal.org/nyobserver)
Further sponsorship from Flisolo