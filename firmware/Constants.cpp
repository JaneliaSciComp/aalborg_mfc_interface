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

HardwareSerial& display_serial = Serial3;

const int enc_a_pin = 18;
const int enc_b_pin = 2;
const int enc_btn_pin = 19;
const int enc_btn_int = 4;
const int btn_pin = 21;
const int btn_int = 2;
const int led_pwr_pin = 17;
const int bnc_b_pin = 3;
const int standalone_update_period = 300;

const int mfc_pwm_pins[] = {7,8,9};
const int mfc_ain_pins[] = {4,5,6};
const int mfc_purge_pins[] = {22,24,26};
const int mfc_valve_off_pins[] = {23,25,27};

const int ain_pins[] = {1,2,3};

const int pwm_min = 0;
const int pwm_max = 255;
const int ain_min = 0;
const int ain_max = 1023;

const int percent_min = 0;
const int percent_max = 100;

const uint8_t states_array_default[STATE_COUNT][MFC_COUNT] = {0};

const uint8_t mfc_dsp_lbl_display_positions[] = {24,44,64};
const uint8_t ain_dsp_lbl_display_positions[] = {24,44,64};
const uint8_t state_dsp_lbl_display_position = 51;
const uint8_t duration_dsp_lbl_display_position = 49;

const uint8_t percent_display_width = 3;

const uint8_t flow_var_display_positions[] = {26,46,66};
const uint8_t ain_dsp_var_display_positions[] = {26,46,66};
const uint8_t state_int_var_display_position = 57;
const uint8_t duration_int_var_display_position = 51;
const uint16_t duration_int_var_default = 10;

const uint16_t duration_min = 1;
const uint16_t duration_max = 10000;

CONSTANT_STRING(device_name,"aalborg_mfc_interface");

CONSTANT_STRING(mfc_parameter_name,"mfc");
CONSTANT_STRING(ain_parameter_name,"ain");
CONSTANT_STRING(percent_parameter_name,"percent");
CONSTANT_STRING(percents_parameter_name,"percents");
CONSTANT_STRING(state_parameter_name,"state");
CONSTANT_STRING(duration_parameter_name,"duration");
CONSTANT_STRING(duration_parameter_units,"ms");

CONSTANT_STRING(execute_standalone_callback_method_name,"executeStandaloneCallback");
CONSTANT_STRING(get_leds_powered_method_name,"getLedsPowered");
CONSTANT_STRING(set_mfc_flow_method_name,"setMfcFlow");
CONSTANT_STRING(set_mfc_flows_method_name,"setMfcFlows");
CONSTANT_STRING(get_mfc_flow_setting_method_name,"getMfcFlowSetting");
CONSTANT_STRING(get_mfc_flow_settings_method_name,"getMfcFlowSettings");
CONSTANT_STRING(get_mfc_flow_measure_method_name,"getMfcFlowMeasure");
CONSTANT_STRING(get_mfc_flow_measures_method_name,"getMfcFlowMeasures");
CONSTANT_STRING(get_analog_input_method_name,"getAnalogInput");
CONSTANT_STRING(get_analog_inputs_method_name,"getAnalogInputs");
CONSTANT_STRING(save_state_method_name,"saveState");
CONSTANT_STRING(recall_state_method_name,"recallState");
CONSTANT_STRING(get_saved_states_method_name,"getSavedStates");
CONSTANT_STRING(pulse_bnc_b_method_name,"pulseBncB");

CONSTANT_STRING(states_name,"states");
CONSTANT_STRING(frame0_name,"setMfcFlows %");
CONSTANT_STRING(frame1_name,"getMfcFlowMeasures %");
CONSTANT_STRING(frame2_name,"getAnalogInputs %");
const ConstantString frame_name_array[] =
  {
    frame0_name,
    frame1_name,
    frame2_name,
    save_state_method_name,
    recall_state_method_name,
    pulse_bnc_b_method_name,
  };
CONSTANT_STRING(mfc0_dsp_lbl_string,"mfc0");
CONSTANT_STRING(mfc1_dsp_lbl_string,"mfc1");
CONSTANT_STRING(mfc2_dsp_lbl_string,"mfc2");
const ConstantString mfc_dsp_lbl_strings[] =
  {
    mfc0_dsp_lbl_string,
    mfc1_dsp_lbl_string,
    mfc2_dsp_lbl_string,
  };
CONSTANT_STRING(ain0_dsp_lbl_string,"ain0");
CONSTANT_STRING(ain1_dsp_lbl_string,"ain1");
CONSTANT_STRING(ain2_dsp_lbl_string,"ain2");
const ConstantString ain_dsp_lbl_strings[] =
  {
    ain0_dsp_lbl_string,
    ain1_dsp_lbl_string,
    ain2_dsp_lbl_string,
  };
}
