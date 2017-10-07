<?php
/**
 * @file
 * home_intranet.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function home_intranet_default_rules_configuration() {
  $items = array();
  $items['rules_data_internet_speed_test_2_validation'] = entity_import('rules_config', '{ "rules_data_internet_speed_test_2_validation" : {
      "LABEL" : "DATA: Internet Speed Test 2 validation",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_presave--internet_speed_test" : { "bundle" : "internet_speed_test" } },
      "IF" : [
        { "OR" : [
            { "data_is" : {
                "data" : [ "node:field-inet-download" ],
                "op" : "\\u003C",
                "value" : "50331648"
              }
            },
            { "data_is" : {
                "data" : [ "node:field-inet-server-ping" ],
                "op" : "\\u003E",
                "value" : "90.00"
              }
            },
            { "data_is" : {
                "data" : [ "node:field-inet-upload" ],
                "op" : "\\u003C",
                "value" : "3355443"
              }
            },
            { "data_is_empty" : { "data" : [ "node:field-inet-server-ping" ] } },
            { "data_is_empty" : { "data" : [ "node:field-inet-upload" ] } },
            { "data_is_empty" : { "data" : [ "node:field-inet-download" ] } }
          ]
        }
      ],
      "DO" : [
        { "component_rules_notification_create_system_notification" : {
            "msg" : "Internet connectivity or unavailability detected",
            "uid" : [ "site:current-user:uid" ],
            "notify" : "Y"
          }
        },
        { "entity_create" : {
            "USING" : {
              "type" : "node",
              "param_type" : "issue",
              "param_title" : "Internet Speed test is below threshold standards",
              "param_author" : [ "site:current-user" ]
            },
            "PROVIDE" : { "entity_created" : { "issue_node" : "issue node" } }
          }
        },
        { "data_set" : { "data" : [ "issue-node:field-priority" ], "value" : "133" } },
        { "entity_save" : { "data" : [ "issue-node" ] } }
      ]
    }
  }');
  $items['rules_download_nws_weather_data'] = entity_import('rules_config', '{ "rules_download_nws_weather_data" : {
      "LABEL" : "Download NWS Weather Data",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules_download", "rules" ],
      "ON" : { "cron" : [] },
      "DO" : [
        { "rules_download_action_generate_path" : {
            "USING" : {
              "path" : "http:\\/\\/w1.weather.gov\\/xml\\/current_obs\\/KMGM.xml",
              "cookie" : "0",
              "filename" : "KMGM.xml",
              "uri_scheme" : "private",
              "file_directory" : "feeds\\/curweather",
              "temporary" : "0",
              "replace" : "0"
            },
            "PROVIDE" : { "rules_download_file" : { "rules_download_file" : "Downloaded file" } }
          }
        },
        { "rules_download_action_generate_path" : {
            "USING" : {
              "path" : "http:\\/\\/w1.weather.gov\\/xml\\/current_obs\\/KTOI.xml",
              "cookie" : "0",
              "uri_scheme" : "private",
              "file_directory" : "feeds\\/curweather",
              "temporary" : "0",
              "replace" : "0"
            },
            "PROVIDE" : { "rules_download_file" : { "rules_download_file1" : "Downloaded file1" } }
          }
        }
      ]
    }
  }');
  $items['rules_notification_create_system_notification'] = entity_import('rules_config', '{ "rules_notification_create_system_notification" : {
      "LABEL" : "Notification: Create System Notification",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "msg" : { "label" : "Message", "type" : "text" },
        "uid" : { "label" : "User ID", "type" : "integer" },
        "notify" : { "label" : "Notify", "type" : "text" }
      },
      "ACTION SET" : [
        { "entity_create" : {
            "USING" : { "type" : "system_notification", "param_type" : "system_notification" },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
          }
        },
        { "data_set" : { "data" : [ "entity-created:title" ], "value" : "[msg:value]" } },
        { "data_set" : { "data" : [ "entity-created:uid" ], "value" : [ "site:current-user" ] } },
        { "data_set" : { "data" : [ "entity-created:created" ], "value" : "now" } },
        { "data_set" : { "data" : [ "entity-created:changed" ], "value" : "now" } },
        { "data_set" : { "data" : [ "entity-created:notify" ], "value" : "[notify:value]" } },
        { "entity_save" : { "data" : [ "entity-created" ] } },
        { "entity_create" : {
            "USING" : {
              "type" : "node",
              "param_type" : "system_notification",
              "param_title" : [ "msg" ],
              "param_author" : [ "site:current-user" ]
            },
            "PROVIDE" : { "entity_created" : { "notification_message" : "Notification" } }
          }
        },
        { "entity_save" : { "data" : [ "notification-message" ] } }
      ]
    }
  }');
  return $items;
}
