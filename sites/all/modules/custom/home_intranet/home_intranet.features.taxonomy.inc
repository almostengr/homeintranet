<?php
/**
 * @file
 * home_intranet.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function home_intranet_taxonomy_default_vocabularies() {
  return array(
    'expense_payees' => array(
      'name' => 'Expense Payees',
      'machine_name' => 'expense_payees',
      'description' => 'People that could be listed as payee for an expense. ',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'projects' => array(
      'name' => 'Projects',
      'machine_name' => 'projects',
      'description' => 'Projects',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'tags' => array(
      'name' => 'Tags',
      'machine_name' => 'tags',
      'description' => 'Use tags to group articles on similar topics into categories.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'ticket_priority' => array(
      'name' => 'Priority',
      'machine_name' => 'ticket_priority',
      'description' => 'Priority of the item. Higher priority requires sooner and immediate attention.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'ticket_types' => array(
      'name' => 'Ticket Types',
      'machine_name' => 'ticket_types',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
