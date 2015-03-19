// ----------------------------------------------------------------------------
// Constants.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef CONSTANTS_H
#define CONSTANTS_H
#include "Flash.h"

namespace constants
{
enum {FRAME_COUNT=5};
enum {STATE_COUNT=10};
enum {MFC_COUNT=3};
enum {AIN_COUNT=3};

extern const int baudrate;

extern const int model_number;
extern const int firmware_number;

extern HardwareSerial& display_serial;

extern const int enc_a_pin;
extern const int enc_b_pin;
extern const int enc_btn_pin;
extern const int enc_btn_int;
extern const int btn_pin;
extern const int btn_int;
extern const int led_pwr_pin;
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

extern const uint8_t percent_display_width;

extern const uint8_t flow_var_display_positions[MFC_COUNT];
extern const uint8_t ain_dsp_var_display_positions[AIN_COUNT];
extern const uint8_t state_int_var_display_position;

extern _FLASH_STRING device_name;
extern _FLASH_STRING execute_standalone_callback_method_name;
extern _FLASH_STRING get_leds_powered_method_name;
extern _FLASH_STRING set_mfc_flow_method_name;
extern _FLASH_STRING set_mfc_flows_method_name;
extern _FLASH_STRING get_mfc_flow_setting_method_name;
extern _FLASH_STRING get_mfc_flow_settings_method_name;
extern _FLASH_STRING get_mfc_flow_measure_method_name;
extern _FLASH_STRING get_mfc_flow_measures_method_name;
extern _FLASH_STRING get_analog_input_method_name;
extern _FLASH_STRING get_analog_inputs_method_name;
extern _FLASH_STRING save_state_method_name;
extern _FLASH_STRING recall_state_method_name;
extern _FLASH_STRING get_saved_states_method_name;
extern _FLASH_STRING mfc_parameter_name;
extern _FLASH_STRING ain_parameter_name;
extern _FLASH_STRING percent_parameter_name;
extern _FLASH_STRING percents_parameter_name;
extern _FLASH_STRING state_parameter_name;
extern _FLASH_STRING states_name;
extern _FLASH_STRING frame0_name;
extern _FLASH_STRING frame1_name;
extern _FLASH_STRING frame2_name;
extern const _FLASH_STRING frame_name_array[FRAME_COUNT];
extern _FLASH_STRING mfc0_dsp_lbl_string;
extern _FLASH_STRING mfc1_dsp_lbl_string;
extern _FLASH_STRING mfc2_dsp_lbl_string;
extern const _FLASH_STRING mfc_dsp_lbl_strings[MFC_COUNT];
extern _FLASH_STRING ain0_dsp_lbl_string;
extern _FLASH_STRING ain1_dsp_lbl_string;
extern _FLASH_STRING ain2_dsp_lbl_string;
extern const _FLASH_STRING ain_dsp_lbl_strings[AIN_COUNT];
}
#endif
