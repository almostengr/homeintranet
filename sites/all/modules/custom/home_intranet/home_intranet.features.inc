<?php
/**
 * @file
 * home_intranet.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function home_intranet_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "mailhandler" && $api == "mailhandler_mailbox") {
    return array("version" => "2");
  }
}

/**
 * Implements hook_eck_bundle_info().
 */
function home_intranet_eck_bundle_info() {
  $items = array(
    'internet_connection_test_internet_connection_test' => array(
      'machine_name' => 'internet_connection_test_internet_connection_test',
      'entity_type' => 'internet_connection_test',
      'name' => 'internet_connection_test',
      'label' => 'Internet Connection Test',
      'config' => array(
        'managed_properties' => array(
          'location' => 'location',
          'ip_address' => 'ip_address',
          'tested_from_isp' => 'tested_from_isp',
          'tested_from_ip_addr' => 'tested_from_ip_addr',
          'server' => 'server',
          'distance' => 'distance',
          'server_ping' => 'server_ping',
          'download' => 'download',
          'upload' => 'upload',
          'share_url_img' => 'share_url_img',
          'time_start' => 'time_start',
          'time_end' => 'time_end',
          'uid' => 0,
          'created' => 0,
        ),
      ),
    ),
    'internet_of_things_value_internet_of_things_value' => array(
      'machine_name' => 'internet_of_things_value_internet_of_things_value',
      'entity_type' => 'internet_of_things_value',
      'name' => 'internet_of_things_value',
      'label' => 'Internet of Things Value',
      'config' => array(),
    ),
    'system_notification_system_notification' => array(
      'machine_name' => 'system_notification_system_notification',
      'entity_type' => 'system_notification',
      'name' => 'system_notification',
      'label' => 'System Notification',
      'config' => array(),
    ),
    'temperature_reading_temperature_reading' => array(
      'machine_name' => 'temperature_reading_temperature_reading',
      'entity_type' => 'temperature_reading',
      'name' => 'temperature_reading',
      'label' => 'Temperature Reading',
      'config' => array(),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function home_intranet_eck_entity_type_info() {
  $items = array(
    'internet_connection_test' => array(
      'name' => 'internet_connection_test',
      'label' => 'Internet Connection Test',
      'properties' => array(
        'uid' => array(
          'label' => 'Author',
          'type' => 'integer',
          'behavior' => 'author',
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
        'location' => array(
          'label' => 'Location',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'ip_address' => array(
          'label' => 'IP Address',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'tested_from_isp' => array(
          'label' => 'Tested From ISP',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'tested_from_ip_addr' => array(
          'label' => 'Tested From IP Address',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'server' => array(
          'label' => 'server',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'distance' => array(
          'label' => 'Distance',
          'type' => 'decimal',
          'behavior' => 'title',
        ),
        'server_ping' => array(
          'label' => 'Server Ping',
          'type' => 'decimal',
          'behavior' => 'title',
        ),
        'download' => array(
          'label' => 'download',
          'type' => 'decimal',
          'behavior' => 'title',
        ),
        'upload' => array(
          'label' => 'Upload',
          'type' => 'decimal',
          'behavior' => 'title',
        ),
        'share_url_img' => array(
          'label' => 'Share URL',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'time_start' => array(
          'label' => 'Start Time',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'time_end' => array(
          'label' => 'End Time',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'sponsor' => array(
          'label' => 'Sponsor',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'server_id' => array(
          'label' => 'Server ID',
          'type' => 'integer',
          'behavior' => 'title',
        ),
      ),
    ),
    'internet_of_things_value' => array(
      'name' => 'internet_of_things_value',
      'label' => 'Internet of Things Value',
      'properties' => array(
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
        'changed' => array(
          'label' => 'Changed',
          'type' => 'integer',
          'behavior' => 'changed',
        ),
        'uid' => array(
          'label' => 'Author',
          'type' => 'integer',
          'behavior' => 'author',
        ),
        'security' => array(
          'label' => 'Security',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'wemo_living_light' => array(
          'label' => 'Living Light',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'wemo_living_tv' => array(
          'label' => 'Living TV',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'season' => array(
          'label' => 'Season',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'weather_montgomery' => array(
          'label' => 'Montgomery Weather',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'ss_username' => array(
          'label' => 'SS Username',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'ss_pass' => array(
          'label' => 'SS Pass',
          'type' => 'text',
          'behavior' => 'title',
        ),
      ),
    ),
    'system_notification' => array(
      'name' => 'system_notification',
      'label' => 'System Notification',
      'properties' => array(
        'title' => array(
          'label' => 'Title',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'uid' => array(
          'label' => 'Author',
          'type' => 'integer',
          'behavior' => 'author',
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
        'changed' => array(
          'label' => 'Changed',
          'type' => 'integer',
          'behavior' => 'changed',
        ),
        'do_notify' => array(
          'label' => 'Do Notify',
          'type' => 'integer',
          'behavior' => 'title',
        ),
        'notify' => array(
          'label' => 'Notify',
          'type' => 'text',
          'behavior' => 'title',
        ),
      ),
    ),
    'temperature_reading' => array(
      'name' => 'temperature_reading',
      'label' => 'Temperature Reading',
      'properties' => array(
        'uid' => array(
          'label' => 'Author',
          'type' => 'integer',
          'behavior' => 'author',
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
        'read_time' => array(
          'label' => 'Read Time',
          'type' => 'positive_integer',
          'behavior' => 'created',
        ),
        'location' => array(
          'label' => 'Location',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'read_time_text' => array(
          'label' => 'Read Time Text',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'temp_f' => array(
          'label' => 'temp_f',
          'type' => 'decimal',
          'behavior' => 'title',
        ),
        'humidity' => array(
          'label' => 'Humidity',
          'type' => 'decimal',
          'behavior' => 'title',
        ),
        'wthr_strng' => array(
          'label' => 'Weather',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'visibility' => array(
          'label' => 'Visibility',
          'type' => 'decimal',
          'behavior' => 'title',
        ),
        'wind_mph' => array(
          'label' => 'Wind MPH',
          'type' => 'decimal',
          'behavior' => 'title',
        ),
        'wind_gust_mph' => array(
          'label' => 'Wind Gust MPH',
          'type' => 'decimal',
          'behavior' => 'title',
        ),
        'wind_direction' => array(
          'label' => 'Wind Direction',
          'type' => 'text',
          'behavior' => 'title',
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implements hook_node_info().
 */
function home_intranet_node_info() {
  $items = array(
    'eck_xml_weather_data' => array(
      'name' => t('ECK XML Weather Data'),
      'base' => 'node_content',
      'description' => t('Weather data form the National Water Service.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'import_utility_usage' => array(
      'name' => t('Import Utility Usage'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'imported_email' => array(
      'name' => t('Imported Email'),
      'base' => 'node_content',
      'description' => t('Emails that are imported via the Mailhandler module to be processed by Feeds. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'internet_speed_test' => array(
      'name' => t('Internet Speed Test'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'iot_value' => array(
      'name' => t('IOT Value'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Key'),
      'help' => '',
    ),
    'issue' => array(
      'name' => t('Issue'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Summary'),
      'help' => '',
    ),
    'knowledge_solution' => array(
      'name' => t('Knowledge Solution'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Summary'),
      'help' => '',
    ),
    'system_notification' => array(
      'name' => t('System Notification'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Message'),
      'help' => '',
    ),
    'temperature_reading' => array(
      'name' => t('Temperature Reading'),
      'base' => 'node_content',
      'description' => t('Record the temperature from various sources. Also includes weather readings. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
