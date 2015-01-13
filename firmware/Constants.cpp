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

const int pwm_pins = {7,8};
const int analog_in_pins = {0,1};
const int purge_pins = {22,24};
const int valve_off_pins = {23,25};

const int pwm_min = 0;
const int pwm_max = 255;
const int analog_in_min = 0;
const int analog_in_max = 1023;

const int percent_min = 0;
const int percent_max = 100;

extern const uint8 flow_setting_default = 0;

FLASH_STRING(device_name,"aalborg_mfc_interface");
FLASH_STRING(set_mfc_flow_method_name,"setMfcFlow");
FLASH_STRING(get_mfc_flow_setting_method_name,"getMfcFlowSetting");
FLASH_STRING(get_mfc_flow_measure_method_name,"getMfcFlowMeasure");
FLASH_STRING(mfc_parameter_name,"mfc");
FLASH_STRING(percent_parameter_name,"percent");
FLASH_STRING(flow_setting_0_name,"flow_setting_0");
FLASH_STRING(flow_setting_1_name,"flow_setting_1");
FLASH_STRING(flow_setting_2_name,"flow_setting_2");
}
