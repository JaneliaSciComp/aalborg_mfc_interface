// ----------------------------------------------------------------------------
// Constants.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef CONSTANTS_H
#define CONSTANTS_H
#include "ConstantVariable.h"

namespace constants
{
enum {FRAME_COUNT=6};
enum {STATE_COUNT=10};
enum {MFC_COUNT=3};
enum {AIN_COUNT=3};

extern const unsigned int baudrate;

extern const unsigned int model_number;

extern const unsigned char firmware_major;
extern const unsigned char firmware_minor;
extern const unsigned char firmware_patch;

extern HardwareSerial & display_serial;

extern const int enc_a_pin;
extern const int enc_b_pin;
extern const int enc_btn_pin;
extern const int enc_btn_int;
extern const int btn_pin;
extern const int btn_int;
extern const int lights_pin;
extern const int bnc_b_pin;
extern const int standalone_update_period;

extern const int mfc_pwm_pins[MFC_COUNT];
extern const int mfc_ain_pins[MFC_COUNT];
extern const int mfc_purge_pins[MFC_COUNT];
extern const int mfc_valve_off_pins[MFC_COUNT];

extern const int ain_pins[AIN_COUNT];

extern const int pwm_min;
extern const int pwm_max;
extern const int ain_min;
extern const int ain_max;

extern const int percent_min;
extern const int percent_max;

extern const uint8_t states_array_default[STATE_COUNT][MFC_COUNT];

extern const uint8_t mfc_dsp_lbl_display_positions[MFC_COUNT];
extern const uint8_t ain_dsp_lbl_display_positions[AIN_COUNT];
extern const uint8_t state_dsp_lbl_display_position;
extern const uint8_t duration_dsp_lbl_display_position;

extern const uint8_t percent_display_width;

extern const uint8_t flow_var_display_positions[MFC_COUNT];
extern const uint8_t ain_dsp_var_display_positions[AIN_COUNT];
extern const uint8_t state_int_var_display_position;
extern const uint8_t duration_int_var_display_position;
extern const uint16_t duration_int_var_default;

extern const uint16_t duration_min;
extern const uint16_t duration_max;

extern ConstantString device_name;

extern ConstantString mfc_parameter_name;
extern ConstantString ain_parameter_name;
extern ConstantString percent_parameter_name;
extern ConstantString percents_parameter_name;
extern ConstantString state_parameter_name;
extern ConstantString duration_parameter_name;
extern ConstantString duration_parameter_units;

extern ConstantString execute_standalone_callback_method_name;
extern ConstantString get_leds_powered_method_name;
extern ConstantString set_mfc_flow_method_name;
extern ConstantString set_mfc_flows_method_name;
extern ConstantString get_mfc_flow_setting_method_name;
extern ConstantString get_mfc_flow_settings_method_name;
extern ConstantString get_mfc_flow_measure_method_name;
extern ConstantString get_mfc_flow_measures_method_name;
extern ConstantString get_analog_input_method_name;
extern ConstantString get_analog_inputs_method_name;
extern ConstantString save_state_method_name;
extern ConstantString recall_state_method_name;
extern ConstantString get_saved_states_method_name;
extern ConstantString pulse_bnc_b_method_name;

extern ConstantString states_name;
extern ConstantString frame0_name;
extern ConstantString frame1_name;
extern ConstantString frame2_name;
extern const ConstantString frame_name_array[FRAME_COUNT];
extern ConstantString mfc0_dsp_lbl_string;
extern ConstantString mfc1_dsp_lbl_string;
extern ConstantString mfc2_dsp_lbl_string;
extern const ConstantString mfc_dsp_lbl_strings[MFC_COUNT];
extern ConstantString ain0_dsp_lbl_string;
extern ConstantString ain1_dsp_lbl_string;
extern ConstantString ain2_dsp_lbl_string;
extern const ConstantString ain_dsp_lbl_strings[AIN_COUNT];
}
#endif
