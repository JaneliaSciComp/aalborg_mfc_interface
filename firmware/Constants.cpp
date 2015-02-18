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

const int mfc_pwm_pins[] = {7,8,9};
const int mfc_analog_in_pins[] = {3,4,5};
const int mfc_purge_pins[] = {22,24,26};
const int mfc_valve_off_pins[] = {23,25,27};

const int pwm_min = 0;
const int pwm_max = 255;
const int analog_in_min = 0;
const int analog_in_max = 1023;

const int percent_min = 0;
const int percent_max = 100;

const uint8_t flow_settings_default[] = {0};

const uint8_t setting_dsp_lbl_display_position = 21;
const uint8_t measure_dsp_lbl_display_position = 31;

const uint8_t mfc0_s_dsp_lbl_display_position = 40;
const uint8_t mfc1_s_dsp_lbl_display_position = 45;
const uint8_t mfc2_s_dsp_lbl_display_position = 60;

const uint8_t mfc0_m_dsp_lbl_display_position = 50;
const uint8_t mfc1_m_dsp_lbl_display_position = 55;
const uint8_t mfc2_m_dsp_lbl_display_position = 70;

const uint8_t mfc_dsp_var_display_width = 3;

const uint8_t mfc0_dsp_var_display_position = 52;
const uint8_t mfc1_dsp_var_display_position = 57;
const uint8_t mfc2_dsp_var_display_position = 72;

FLASH_STRING(device_name,"aalborg_mfc_interface");
FLASH_STRING(execute_standalone_callback_method_name,"executeStandaloneCallback");
FLASH_STRING(get_leds_powered_method_name,"getLedsPowered");
FLASH_STRING(set_mfc_flow_method_name,"setMfcFlow");
FLASH_STRING(get_mfc_flow_setting_method_name,"getMfcFlowSetting");
FLASH_STRING(get_mfc_flow_measure_method_name,"getMfcFlowMeasure");
FLASH_STRING(mfc_parameter_name,"mfc");
FLASH_STRING(percent_parameter_name,"percent");
FLASH_STRING(flow_settings_name,"flow_settings");
FLASH_STRING(setting_dsp_lbl_string,"setting%");
FLASH_STRING(measure_dsp_lbl_string,"measure%");
FLASH_STRING(mfc0_dsp_lbl_string,"0");
FLASH_STRING(mfc1_dsp_lbl_string,"1");
FLASH_STRING(mfc2_dsp_lbl_string,"2");
const _FLASH_STRING frame_name_array[] =
  {
    set_mfc_flow_method_name,
  };
}
