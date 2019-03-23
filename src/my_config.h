/*
 * my_config.h
 *
 * All configurations and customization's go here
 *
 * Paul Derbyshire - https://github.com/proddy/EMS-ESP
 */

#pragma once

#include "ems.h"

// MQTT base name
#define MQTT_BASE "home" // all MQTT topics are prefix with this string, in the format <MQTT_BASE>/<app name>/<topic>

// MQTT general settings
#define MQTT_TOPIC_START "start"
#define MQTT_TOPIC_START_PAYLOAD "start"
#define MQTT_WILL_TOPIC "status"            // for last will & testament topic name
#define MQTT_WILL_ONLINE_PAYLOAD "online"   // for last will & testament payload
#define MQTT_WILL_OFFLINE_PAYLOAD "offline" // for last will & testament payload
#define MQTT_RETAIN false
#define MQTT_KEEPALIVE 120 // 2 minutes
#define MQTT_QOS 1

// MQTT for thermostat
#define TOPIC_THERMOSTAT_DATA "thermostat_data"         // for sending thermostat values to MQTT
#define TOPIC_THERMOSTAT_CMD_TEMP "thermostat_cmd_temp" // for received thermostat temp changes via MQTT
#define TOPIC_THERMOSTAT_CMD_MODE "thermostat_cmd_mode" // for received thermostat mode changes via MQTT
// lobocobra start
#define TOPIC_THERMOSTAT_CMD_RC35HC "thermostat_cmd_rc35hc" // for received thermostat mode changes via MQTT
#define TOPIC_MQTT_CMD_RAW "mqtt_cmd_raw" // receive mqtt cmd
// lobocobra end
#define THERMOSTAT_CURRTEMP "thermostat_currtemp"       // current temperature
#define THERMOSTAT_SELTEMP "thermostat_seltemp"         // selected temperature
#define THERMOSTAT_MODE "thermostat_mode"               // mode
// lobocobra start
#define THERMOSTAT_RC35HC "thermostat_rc35hc"           // RC35, which heating circuit is active
#define MQTT_RAW "mqtt_raw" // send mqtt answer
// lobocobra end

// MQTT for boiler
#define TOPIC_BOILER_DATA "boiler_data"                // for sending boiler values to MQTT
#define TOPIC_BOILER_TAPWATER_ACTIVE "tapwater_active" // if hot tap water is running
#define TOPIC_BOILER_HEATING_ACTIVE "heating_active"   // if heating is on
#define TOPIC_BOILER_WWACTIVATED "wwactivated"         // for receiving MQTT message to change water on/off
#define TOPIC_BOILER_CMD_WWTEMP "boiler_cmd_wwtemp"    // for received boiler wwtemp changes via MQTT
#define TOPIC_BOILER_CMD_COMFORT "boiler_cmd_comfort"  // for received boiler ww comfort setting via MQTT

// shower time
#define TOPIC_SHOWERTIME "showertime"           // for sending shower time results
#define TOPIC_SHOWER_TIMER "shower_timer"       // toggle switch for enabling the shower logic
#define TOPIC_SHOWER_ALERT "shower_alert"       // toggle switch for enabling the shower alarm logic
#define TOPIC_SHOWER_COLDSHOT "shower_coldshot" // used to trigger a coldshot from an MQTT command

// MQTT for EXTERNAL SENSORS
#define TOPIC_EXTERNAL_SENSORS "sensors"   // for sending sensor values to MQTT
#define PAYLOAD_EXTERNAL_SENSORS "temp_%d" // for formatting the payload for each external dallas sensor

////////////////////////////////////////////////////////////////////////////////////////////////////
// THESE DEFAULT VALUES CAN ALSO BE SET AND STORED WITHTIN THE APPLICATION (see 'set' command)    //
////////////////////////////////////////////////////////////////////////////////////////////////////

// Set LED pin used for showing the EMS bus connection status. Solid means EMS bus working, flashing is an error
// can be either the onboard LED on the ESP8266 (LED_BULLETIN) or external via an external pull-up LED (e.g. D1 on a bbqkees' board)
// can be enabled and disabled via the 'set led' command and pin set by 'set led_gpio'
#define EMSESP_LED_GPIO LED_BUILTIN

// set this if using an external temperature sensor like a DS18B20
// D5 is the default on a bbqkees board
#define EMSESP_DALLAS_GPIO D5
// lobocobra start
// RC35 uses heating circuit 2 if you have a floor heating
// change the heating circuit to Nr. 2
#define EMSESP_HEATINGCIRCUIT 1
// lobocobra end
#define EMSESP_DALLAS_PARASITE false

// By default the EMS bus will be scanned for known devices based on the product ids in ems_devices.h
// You can override the Thermostat and Boiler types here
#define EMSESP_BOILER_TYPE EMS_ID_NONE
#define EMSESP_THERMOSTAT_TYPE EMS_ID_NONE
