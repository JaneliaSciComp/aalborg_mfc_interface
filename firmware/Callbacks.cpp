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
// bool
// JsonArray
// JsonObject
//
// For more info read about ArduinoJson v3 JsonParser JsonValues
//
// modular_device.getSavedVariableValue type must match the saved variable default type
// modular_device.setSavedVariableValue type must match the saved variable default type


void getLedsPoweredCallback()
{
  boolean leds_powered = controller.getLedsPowered();
  modular_device.addBooleanToResponse("leds_powered",leds_powered);
}

void setMfcFlowCallback()
{
  long mfc = modular_device.getParameterValue(constants::mfc_parameter_name);
  long percent = modular_device.getParameterValue(constants::percent_parameter_name);
  controller.setMfcFlow(mfc,percent);
}

void getMfcFlowSettingCallback()
{
  long mfc = modular_device.getParameterValue(constants::mfc_parameter_name);
  uint8_t percent = controller.getMfcFlowSetting(mfc);
  modular_device.addToResponse("percent",percent);
}

void getMfcFlowMeasureCallback()
{
  long mfc = modular_device.getParameterValue(constants::mfc_parameter_name);
  uint8_t percent = controller.getMfcFlowMeasure(mfc);
  modular_device.addToResponse("percent",percent);
}

// Standalone Callbacks
void executeStandaloneCallbackCallback()
{
  controller.executeStandaloneCallback();
}
}
