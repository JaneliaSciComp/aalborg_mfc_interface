// ----------------------------------------------------------------------------
// Constants.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "Constants.h"


namespace constants
{
const int baudrate = 9600;

const int model_number = 1100;
const int firmware_number = 1;

HardwareSerial display_serial = Serial3;

const int enc_a_pin = 2;
const int enc_b_pin = 3;
const int enc_btn_pin = 19;
const int enc_btn_int = 4;
const int btn_pin = 21;
const int btn_int = 2;
const int led_pwr_pin = 18;
const int standalone_update_period = 300;

const int mfc_pwm_pins = {7,8,9};
const int mfc_analog_in_pins = {3,4,5};
const int mfc_purge_pins = {22,24,26};
const int mfc_valve_off_pins = {23,25,27};

const int pwm_min = 0;
const int pwm_max = 255;
const int analog_in_min = 0;
const int analog_in_max = 1023;

const int percent_min = 0;
const int percent_max = 100;

extern const uint8 flow_settings_default = {0,0,0};

FLASH_STRING(device_name,"aalborg_mfc_interface");
FLASH_STRING(set_mfc_flow_method_name,"setMfcFlow");
FLASH_STRING(get_mfc_flow_setting_method_name,"getMfcFlowSetting");
FLASH_STRING(get_mfc_flow_measure_method_name,"getMfcFlowMeasure");
FLASH_STRING(mfc_parameter_name,"mfc");
FLASH_STRING(percent_parameter_name,"percent");
FLASH_STRING(flow_settings_name,"flow_settings");
}
