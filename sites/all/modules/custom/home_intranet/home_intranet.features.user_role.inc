<?php
/**
 * @file
 * home_intranet.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function home_intranet_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 7,
  );

  // Exported role: expense manager.
  $roles['expense manager'] = array(
    'name' => 'expense manager',
    'weight' => 5,
  );

  // Exported role: importer.
  $roles['importer'] = array(
    'name' => 'importer',
    'weight' => 2,
  );

  // Exported role: issue manager.
  $roles['issue manager'] = array(
    'name' => 'issue manager',
    'weight' => 4,
  );

  // Exported role: project manager.
  $roles['project manager'] = array(
    'name' => 'project manager',
    'weight' => 6,
  );

  // Exported role: web services.
  $roles['web services'] = array(
    'name' => 'web services',
    'weight' => 3,
  );

  return $roles;
}
