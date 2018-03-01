<?php
/**
 * @file
 * home_intranet.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function home_intranet_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'internet_speed_test_results';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Internet Speed Test Results';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Internet Speed Test Results';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    2 => '2',
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['empty'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Date/Time';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Server Ping */
  $handler->display->display_options['fields']['field_inet_server_ping']['id'] = 'field_inet_server_ping';
  $handler->display->display_options['fields']['field_inet_server_ping']['table'] = 'field_data_field_inet_server_ping';
  $handler->display->display_options['fields']['field_inet_server_ping']['field'] = 'field_inet_server_ping';
  $handler->display->display_options['fields']['field_inet_server_ping']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Download */
  $handler->display->display_options['fields']['field_inet_download']['id'] = 'field_inet_download';
  $handler->display->display_options['fields']['field_inet_download']['table'] = 'field_data_field_inet_download';
  $handler->display->display_options['fields']['field_inet_download']['field'] = 'field_inet_download';
  $handler->display->display_options['fields']['field_inet_download']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Upload */
  $handler->display->display_options['fields']['field_inet_upload']['id'] = 'field_inet_upload';
  $handler->display->display_options['fields']['field_inet_upload']['table'] = 'field_data_field_inet_upload';
  $handler->display->display_options['fields']['field_inet_upload']['field'] = 'field_inet_upload';
  $handler->display->display_options['fields']['field_inet_upload']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Content: Dates -  start date (field_dates) */
  $handler->display->display_options['sorts']['field_dates_value']['id'] = 'field_dates_value';
  $handler->display->display_options['sorts']['field_dates_value']['table'] = 'field_data_field_dates';
  $handler->display->display_options['sorts']['field_dates_value']['field'] = 'field_dates_value';
  $handler->display->display_options['sorts']['field_dates_value']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'internet_speed_test' => 'internet_speed_test',
  );
  /* Filter criterion: Content: Dates -  start date (field_dates) */
  $handler->display->display_options['filters']['field_dates_value']['id'] = 'field_dates_value';
  $handler->display->display_options['filters']['field_dates_value']['table'] = 'field_data_field_dates';
  $handler->display->display_options['filters']['field_dates_value']['field'] = 'field_dates_value';
  $handler->display->display_options['filters']['field_dates_value']['operator'] = '>=';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'internet_speed_test' => 'internet_speed_test',
  );
  $handler->display->display_options['path'] = 'internet-speed-test-results';
  $handler->display->display_options['menu']['title'] = 'Internet Speed Test';
  $handler->display->display_options['menu']['description'] = 'Internet Speed Results';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['internet_speed_test_results'] = $view;

  $view = new view();
  $view->name = 'internet_test_results';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_internet_connection_test';
  $view->human_name = 'Internet Test Results';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Internet Test Results, Last 7 Days';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'time_start' => 'time_start',
    'server_ping' => 'server_ping',
    'download' => 'download',
    'upload' => 'upload',
    'view_link' => 'view_link',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'time_start' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'server_ping' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'download' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'upload' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Internet Connection Test: Start Time */
  $handler->display->display_options['fields']['time_start']['id'] = 'time_start';
  $handler->display->display_options['fields']['time_start']['table'] = 'eck_internet_connection_test';
  $handler->display->display_options['fields']['time_start']['field'] = 'time_start';
  /* Field: Internet Connection Test: Server Ping */
  $handler->display->display_options['fields']['server_ping']['id'] = 'server_ping';
  $handler->display->display_options['fields']['server_ping']['table'] = 'eck_internet_connection_test';
  $handler->display->display_options['fields']['server_ping']['field'] = 'server_ping';
  $handler->display->display_options['fields']['server_ping']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['server_ping']['precision'] = '3';
  $handler->display->display_options['fields']['server_ping']['separator'] = '';
  $handler->display->display_options['fields']['server_ping']['suffix'] = ' ms';
  /* Field: Internet Connection Test: download */
  $handler->display->display_options['fields']['download']['id'] = 'download';
  $handler->display->display_options['fields']['download']['table'] = 'eck_internet_connection_test';
  $handler->display->display_options['fields']['download']['field'] = 'download';
  $handler->display->display_options['fields']['download']['label'] = 'Download';
  $handler->display->display_options['fields']['download']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['download']['precision'] = '3';
  $handler->display->display_options['fields']['download']['separator'] = '';
  $handler->display->display_options['fields']['download']['suffix'] = ' Mbps';
  /* Field: Internet Connection Test: Upload */
  $handler->display->display_options['fields']['upload']['id'] = 'upload';
  $handler->display->display_options['fields']['upload']['table'] = 'eck_internet_connection_test';
  $handler->display->display_options['fields']['upload']['field'] = 'upload';
  $handler->display->display_options['fields']['upload']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['upload']['precision'] = '3';
  $handler->display->display_options['fields']['upload']['separator'] = '';
  $handler->display->display_options['fields']['upload']['suffix'] = ' Mbps';
  /* Field: Internet Connection Test: Link */
  $handler->display->display_options['fields']['view_link']['id'] = 'view_link';
  $handler->display->display_options['fields']['view_link']['table'] = 'eck_internet_connection_test';
  $handler->display->display_options['fields']['view_link']['field'] = 'view_link';
  $handler->display->display_options['fields']['view_link']['label'] = 'Actions';
  $handler->display->display_options['fields']['view_link']['text'] = 'View';
  /* Sort criterion: Internet Connection Test: Start Time */
  $handler->display->display_options['sorts']['time_start']['id'] = 'time_start';
  $handler->display->display_options['sorts']['time_start']['table'] = 'eck_internet_connection_test';
  $handler->display->display_options['sorts']['time_start']['field'] = 'time_start';
  $handler->display->display_options['sorts']['time_start']['order'] = 'DESC';

  /* Display: Graph */
  $handler = $view->new_display('page', 'Graph', 'page_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'google_chart_tools_views';
  $handler->display->display_options['style_options']['width'] = '600';
  $handler->display->display_options['style_options']['height'] = '400';
  $handler->display->display_options['style_options']['isstacked'] = 0;
  $handler->display->display_options['style_options']['pointsize'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Internet Connection Test: Start Time */
  $handler->display->display_options['fields']['time_start']['id'] = 'time_start';
  $handler->display->display_options['fields']['time_start']['table'] = 'eck_internet_connection_test';
  $handler->display->display_options['fields']['time_start']['field'] = 'time_start';
  /* Field: Internet Connection Test: Server Ping */
  $handler->display->display_options['fields']['server_ping']['id'] = 'server_ping';
  $handler->display->display_options['fields']['server_ping']['table'] = 'eck_internet_connection_test';
  $handler->display->display_options['fields']['server_ping']['field'] = 'server_ping';
  $handler->display->display_options['fields']['server_ping']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['server_ping']['precision'] = '3';
  $handler->display->display_options['fields']['server_ping']['separator'] = '';
  $handler->display->display_options['fields']['server_ping']['suffix'] = ' ms';
  /* Field: Internet Connection Test: download */
  $handler->display->display_options['fields']['download']['id'] = 'download';
  $handler->display->display_options['fields']['download']['table'] = 'eck_internet_connection_test';
  $handler->display->display_options['fields']['download']['field'] = 'download';
  $handler->display->display_options['fields']['download']['label'] = 'Download';
  $handler->display->display_options['fields']['download']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['download']['precision'] = '3';
  $handler->display->display_options['fields']['download']['separator'] = '';
  $handler->display->display_options['fields']['download']['suffix'] = ' Mbps';
  /* Field: Internet Connection Test: Upload */
  $handler->display->display_options['fields']['upload']['id'] = 'upload';
  $handler->display->display_options['fields']['upload']['table'] = 'eck_internet_connection_test';
  $handler->display->display_options['fields']['upload']['field'] = 'upload';
  $handler->display->display_options['fields']['upload']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['upload']['precision'] = '3';
  $handler->display->display_options['fields']['upload']['separator'] = '';
  $handler->display->display_options['fields']['upload']['suffix'] = ' Mbps';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Internet Connection Test: Created */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'eck_internet_connection_test';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = '>=';
  $handler->display->display_options['filters']['created']['value']['value'] = '-7 days';
  $handler->display->display_options['filters']['created']['value']['type'] = 'offset';
  $handler->display->display_options['path'] = 'inettestspeed';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Internet Test Results';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $export['internet_test_results'] = $view;

  $view = new view();
  $view->name = 'logged_in_as';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Logged In As';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = ' ';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = 'Hello [name]';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: User: Link */
  $handler->display->display_options['fields']['view_user']['id'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['table'] = 'users';
  $handler->display->display_options['fields']['view_user']['field'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['label'] = '';
  $handler->display->display_options['fields']['view_user']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_user']['text'] = 'My account';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Log out';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'user/logout';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['uid']['title'] = '%1';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['logged_in_as'] = $view;

  $view = new view();
  $view->name = 'temperature_history';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_temperature_reading';
  $view->human_name = 'Temperature History';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Temperature History';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'google_chart_tools_views';
  $handler->display->display_options['style_options']['haxis_title'] = 'Time ago';
  $handler->display->display_options['style_options']['vaxis_title'] = 'Temperature';
  $handler->display->display_options['style_options']['width'] = '600';
  $handler->display->display_options['style_options']['height'] = '400';
  $handler->display->display_options['style_options']['isstacked'] = 1;
  $handler->display->display_options['style_options']['pointsize'] = '0';
  /* Field: Temperature Reading: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_temperature_reading';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'raw time ago';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Temperature Reading: temp_f */
  $handler->display->display_options['fields']['temp_f']['id'] = 'temp_f';
  $handler->display->display_options['fields']['temp_f']['table'] = 'eck_temperature_reading';
  $handler->display->display_options['fields']['temp_f']['field'] = 'temp_f';
  $handler->display->display_options['fields']['temp_f']['label'] = '';
  $handler->display->display_options['fields']['temp_f']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['temp_f']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['temp_f']['precision'] = '0';
  $handler->display->display_options['fields']['temp_f']['separator'] = '';
  /* Sort criterion: Temperature Reading: Read Time */
  $handler->display->display_options['sorts']['read_time']['id'] = 'read_time';
  $handler->display->display_options['sorts']['read_time']['table'] = 'eck_temperature_reading';
  $handler->display->display_options['sorts']['read_time']['field'] = 'read_time';
  $handler->display->display_options['sorts']['read_time']['order'] = 'DESC';
  $handler->display->display_options['sorts']['read_time']['granularity'] = 'minute';
  /* Filter criterion: Temperature Reading: Created */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'eck_temperature_reading';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = '>=';
  $handler->display->display_options['filters']['created']['value']['value'] = '-30 days';
  $handler->display->display_options['filters']['created']['value']['type'] = 'offset';
  /* Filter criterion: Temperature Reading: Location */
  $handler->display->display_options['filters']['location']['id'] = 'location';
  $handler->display->display_options['filters']['location']['table'] = 'eck_temperature_reading';
  $handler->display->display_options['filters']['location']['field'] = 'location';
  $handler->display->display_options['filters']['location']['operator'] = 'contains';
  $handler->display->display_options['filters']['location']['value'] = 'Montgomery';
  $handler->display->display_options['filters']['location']['exposed'] = TRUE;
  $handler->display->display_options['filters']['location']['expose']['operator_id'] = 'location_op';
  $handler->display->display_options['filters']['location']['expose']['label'] = 'Location';
  $handler->display->display_options['filters']['location']['expose']['operator'] = 'location_op';
  $handler->display->display_options['filters']['location']['expose']['identifier'] = 'location';
  $handler->display->display_options['filters']['location']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    14 => 0,
    11 => 0,
    5 => 0,
    9 => 0,
    15 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'temp-history';
  $export['temperature_history'] = $view;

  $view = new view();
  $view->name = 'weather';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Weather';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Current Weather';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_location2']['id'] = 'field_location2';
  $handler->display->display_options['fields']['field_location2']['table'] = 'field_data_field_location2';
  $handler->display->display_options['fields']['field_location2']['field'] = 'field_location2';
  /* Field: Content: Temp Farenheit */
  $handler->display->display_options['fields']['field_temp_farenheit']['id'] = 'field_temp_farenheit';
  $handler->display->display_options['fields']['field_temp_farenheit']['table'] = 'field_data_field_temp_farenheit';
  $handler->display->display_options['fields']['field_temp_farenheit']['field'] = 'field_temp_farenheit';
  $handler->display->display_options['fields']['field_temp_farenheit']['label'] = 'Temperature';
  $handler->display->display_options['fields']['field_temp_farenheit']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Humidity */
  $handler->display->display_options['fields']['field_temp_humidity']['id'] = 'field_temp_humidity';
  $handler->display->display_options['fields']['field_temp_humidity']['table'] = 'field_data_field_temp_humidity';
  $handler->display->display_options['fields']['field_temp_humidity']['field'] = 'field_temp_humidity';
  $handler->display->display_options['fields']['field_temp_humidity']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Wind Direction */
  $handler->display->display_options['fields']['field_temp_wind_direction']['id'] = 'field_temp_wind_direction';
  $handler->display->display_options['fields']['field_temp_wind_direction']['table'] = 'field_data_field_temp_wind_direction';
  $handler->display->display_options['fields']['field_temp_wind_direction']['field'] = 'field_temp_wind_direction';
  /* Field: Content: Wind MPH */
  $handler->display->display_options['fields']['field_temp_wind_mph']['id'] = 'field_temp_wind_mph';
  $handler->display->display_options['fields']['field_temp_wind_mph']['table'] = 'field_data_field_temp_wind_mph';
  $handler->display->display_options['fields']['field_temp_wind_mph']['field'] = 'field_temp_wind_mph';
  $handler->display->display_options['fields']['field_temp_wind_mph']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Updated';
  $handler->display->display_options['fields']['created']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'temperature_reading' => 'temperature_reading',
  );
  /* Filter criterion: Content: Location (field_location2) */
  $handler->display->display_options['filters']['field_location2_value']['id'] = 'field_location2_value';
  $handler->display->display_options['filters']['field_location2_value']['table'] = 'field_data_field_location2';
  $handler->display->display_options['filters']['field_location2_value']['field'] = 'field_location2_value';
  $handler->display->display_options['filters']['field_location2_value']['operator'] = 'word';
  $handler->display->display_options['filters']['field_location2_value']['value'] = 'AL';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['weather'] = $view;

  return $export;
}
