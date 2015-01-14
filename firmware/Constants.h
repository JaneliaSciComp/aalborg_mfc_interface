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
enum {MFC_COUNT=2};

extern const int baudrate;

extern const int model_number;
extern const int firmware_number;

extern const int pwm_pins[MFC_COUNT];
extern const int analog_in_pins[MFC_COUNT];
extern const int purge_pins[MFC_COUNT];
extern const int valve_off_pins[MFC_COUNT];

extern const int pwm_min;
extern const int pwm_max;
extern const int analog_in_min;
extern const int analog_in_max;

extern const int percent_min;
extern const int percent_max;

extern const uint8 flow_settings_default[MFC_COUNT];

extern _FLASH_STRING device_name;
extern _FLASH_STRING set_mfc_flow_method_name;
extern _FLASH_STRING get_mfc_flow_setting_method_name;
extern _FLASH_STRING get_mfc_flow_measure_method_name;
extern _FLASH_STRING mfc_parameter_name;
extern _FLASH_STRING percent_parameter_name;
extern _FLASH_STRING flow_settings_name;
}
#endif
