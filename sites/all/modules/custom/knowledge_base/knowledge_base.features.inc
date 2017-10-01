<?php
/**
 * @file
 * knowledge_base.features.inc
 */

/**
 * Implements hook_node_info().
 */
function knowledge_base_node_info() {
  $items = array(
    'knowledge_solution' => array(
      'name' => t('Knowledge Solution'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Summary'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
