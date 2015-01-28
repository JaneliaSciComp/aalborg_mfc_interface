// ----------------------------------------------------------------------------
// Callbacks.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "Callbacks.h"

using namespace ArduinoJson::Parser;

namespace callbacks
{
// Callbacks must be non-blocking (avoid 'delay')
//
// modular_device.getParameterValue must be cast to either:
// char*
// long
// double
// JsonArray
// JsonObject
//
// For more info read about ArduinoJson v3 JsonParser JsonValues
//
// modular_device.getSavedVariableValue type must match the saved variable default type
// modular_device.setSavedVariableValue type must match the saved variable default type

void setMfcValue(int pwm_pin)
{
  long percent = modular_device.getParameterValue(constants::percent_parameter_name);
  int pwm_value = map(percent,
                      constants::percent_min,
                      constants::percent_max,
                      constants::pwm_min,
                      constants::pwm_max);
  analogWrite(pwm_pin,pwm_value);
}

void getMfcValue(int analog_in_pin)
{
  int analog_in_value = analogRead(analog_in_pin);
  int percent_value = map(analog_in_value,
                          constants::analog_in_min,
                          constants::analog_in_max,
                          constants::percent_min,
                          constants::percent_max);
  modular_device.addToResponse("percent",percent_value);
}

void setMfcValueACallback()
{
  setMfcValue(constants::pwm_a_pin);
}

void getMfcValueACallback()
{
  getMfcValue(constants::analog_in_a_pin);
}
}
