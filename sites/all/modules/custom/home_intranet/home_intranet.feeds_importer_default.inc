<?php
/**
 * @file
 * home_intranet.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function home_intranet_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'email_import';
  $feeds_importer->config = array(
    'name' => 'Email import Gmail-MyHub',
    'description' => 'Import email from tharam04@gmail.com',
    'fetcher' => array(
      'plugin_key' => 'MailhandlerFetcher',
      'config' => array(
        'filter' => 'MailhandlerFiltersNodes',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'MailhandlerParser',
      'config' => array(
        'available_commands' => 'status',
        'authenticate_plugin' => 'MailhandlerAuthenticateDefault',
        'extended_headers' => NULL,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '259200',
        'author' => '41',
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'subject',
            'target' => 'title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'udate',
            'target' => 'created',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'message_id',
            'target' => 'guid',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'body_text',
            'target' => 'body',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'fromaddress',
            'target' => 'body:summary',
            'unique' => FALSE,
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '0',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'imported_email',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '0',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['email_import'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'internet_speed_test_2';
  $feeds_importer->config = array(
    'name' => 'Internet Speed Test 2',
    'description' => 'Internet speed test importer for new file format after 2016-11-23',
    'fetcher' => array(
      'plugin_key' => 'feeds_fetcher_directory_fetcher',
      'config' => array(
        'recursive' => 0,
        'directory' => 'private://feeds/inetspeed',
        'filemask' => '/\\.csv$/',
        'updated_files' => 1,
        'after_processed' => '1',
        'move_to_folder' => 'private://feeds/inetspeed/archive',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => '|',
        'encoding' => 'UTF-8',
        'no_headers' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '49',
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => '0',
            'target' => 'field_inet_server_id',
            'unique' => FALSE,
            'language' => 'und',
          ),
          1 => array(
            'source' => '1',
            'target' => 'field_inet_sponsor',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => '2',
            'target' => 'field_inet_server',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => '4',
            'target' => 'field_inet_server_distance',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => '5',
            'target' => 'field_inet_server_ping',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => '6',
            'target' => 'field_inet_download',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => '7',
            'target' => 'field_inet_upload',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => '3',
            'target' => 'title',
            'unique' => 0,
            'language' => 'und',
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '0',
        'update_non_existent' => 'unpublish',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'internet_speed_test',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '0',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['internet_speed_test_2'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'iot_variable';
  $feeds_importer->config = array(
    'name' => 'IOT Variable',
    'description' => 'Import an IOT variable from another system.',
    'fetcher' => array(
      'plugin_key' => 'feeds_fetcher_directory_fetcher',
      'config' => array(
        'recursive' => 0,
        'directory' => 'private://feeds/iotvariable',
        'filemask' => '/\\.csv$/',
        'updated_files' => 1,
        'after_processed' => '1',
        'move_to_folder' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'encoding' => 'UTF-8',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '47',
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => '0',
            'target' => 'nid',
            'unique' => 1,
          ),
          1 => array(
            'source' => '1',
            'target' => 'title',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'unpublish',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'iot_value',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '0',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['iot_variable'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'weather_from_nws';
  $feeds_importer->config = array(
    'name' => 'Weather from NWS',
    'description' => 'Import weather data from the National Weather Service feeds.',
    'fetcher' => array(
      'plugin_key' => 'feeds_fetcher_directory_fetcher',
      'config' => array(
        'recursive' => 0,
        'directory' => 'private://feeds/curweather',
        'filemask' => '/\\.xml$/',
        'updated_files' => 0,
        'after_processed' => '1',
        'move_to_folder' => 'private://feeds/curweather/archive',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'observation_time_rfc822',
          'xpathparser:2' => 'temp_f',
          'xpathparser:3' => 'relative_humidity',
          'xpathparser:4' => 'observation_time_rfc822',
          'xpathparser:5' => 'weather',
          'xpathparser:6' => 'visibility_mi',
          'xpathparser:7' => 'wind_dir',
          'xpathparser:8' => 'wind_gust_mph',
          'xpathparser:9' => 'wind_mph',
          'xpathparser:10' => 'location',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
          'xpathparser:6' => 0,
          'xpathparser:7' => 0,
          'xpathparser:8' => 0,
          'xpathparser:9' => 0,
          'xpathparser:10' => 0,
        ),
        'context' => '/current_observation',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
            'xpathparser:9' => 0,
            'xpathparser:10' => 0,
          ),
        ),
        'allow_override' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '604800',
        'author' => '28',
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'title',
            'unique' => 0,
          ),
          1 => array(
            'source' => 'xpathparser:2',
            'target' => 'field_temp_farenheit',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'xpathparser:3',
            'target' => 'field_temp_humidity',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_date_string',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'xpathparser:5',
            'target' => 'field_weather_string',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'xpathparser:6',
            'target' => 'field_temp_visibility',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_temp_wind_direction',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'xpathparser:8',
            'target' => 'field_temp_wind_gust_mph',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'xpathparser:9',
            'target' => 'field_temp_wind_mph',
            'unique' => FALSE,
            'language' => 'und',
          ),
          9 => array(
            'source' => 'xpathparser:10',
            'target' => 'field_location2',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '0',
        'update_non_existent' => 'unpublish',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'temperature_reading',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '1800',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['weather_from_nws'] = $feeds_importer;

  return $export;
}
