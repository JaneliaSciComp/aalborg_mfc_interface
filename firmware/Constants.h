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
enum {MFC_COUNT=3};
enum {FRAME_COUNT=1};

extern const int baudrate;

extern const int model_number;
extern const int firmware_number;

extern HardwareSerial display_serial;

extern const int enc_a_pin;
extern const int enc_b_pin;
extern const int enc_btn_pin;
extern const int enc_btn_int;
extern const int btn_pin;
extern const int btn_int;
extern const int led_pwr_pin;
extern const int standalone_update_period;

extern const int mfc_pwm_pins[MFC_COUNT];
extern const int mfc_analog_in_pins[MFC_COUNT];
extern const int mfc_purge_pins[MFC_COUNT];
extern const int mfc_valve_off_pins[MFC_COUNT];

extern const int pwm_min;
extern const int pwm_max;
extern const int analog_in_min;
extern const int analog_in_max;

extern const int percent_min;
extern const int percent_max;

extern const uint8_t flow_settings_default[MFC_COUNT];

extern const uint8_t setting_dsp_lbl_display_position;
extern const uint8_t measure_dsp_lbl_display_position;

extern const uint8_t mfc_s_dsp_lbl_display_positions[MFC_COUNT];
extern const uint8_t mfc_m_dsp_lbl_display_positions[MFC_COUNT];

extern const uint8_t percent_display_width;

extern const uint8_t flow_dsp_var_display_positions[MFC_COUNT];
extern const uint8_t flow_int_var_display_positions[MFC_COUNT];

extern _FLASH_STRING device_name;
extern _FLASH_STRING execute_standalone_callback_method_name;
extern _FLASH_STRING get_leds_powered_method_name;
extern _FLASH_STRING set_mfc_flow_method_name;
extern _FLASH_STRING get_mfc_flow_setting_method_name;
extern _FLASH_STRING get_mfc_flow_measure_method_name;
extern _FLASH_STRING mfc_parameter_name;
extern _FLASH_STRING percent_parameter_name;
extern _FLASH_STRING flow_settings_name;
extern _FLASH_STRING setting_dsp_lbl_string;
extern _FLASH_STRING measure_dsp_lbl_string;
extern const _FLASH_STRING frame_name_array[FRAME_COUNT];
extern _FLASH_STRING mfc0_dsp_lbl_string;
extern _FLASH_STRING mfc1_dsp_lbl_string;
extern _FLASH_STRING mfc2_dsp_lbl_string;
extern const _FLASH_STRING mfc_dsp_lbl_strings[MFC_COUNT];
}
#endif
