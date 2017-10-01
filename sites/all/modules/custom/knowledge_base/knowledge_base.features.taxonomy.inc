<?php
/**
 * @file
 * knowledge_base.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function knowledge_base_taxonomy_default_vocabularies() {
  return array(
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
  );
}
