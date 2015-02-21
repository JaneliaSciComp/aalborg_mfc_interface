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

void setMfcFlowsCallback()
{
  JsonArray percents_array = modular_device.getParameterValue(constants::percents_parameter_name);
  int mfc = 0;
  for (JsonArrayIterator percents_it=percents_array.begin();
       percents_it != percents_array.end();
       ++percents_it)
  {
    long percent = *percents_it;
    controller.setMfcFlow(mfc,percent);
    mfc++;
  }
}

void getMfcFlowSettingCallback()
{
  long mfc = modular_device.getParameterValue(constants::mfc_parameter_name);
  uint8_t percent = controller.getMfcFlowSetting(mfc);
  modular_device.addToResponse("percent",percent);
}

void getMfcFlowSettingsCallback()
{
  modular_device.addKeyToResponse("percents");
  modular_device.startResponseArray();
  for (int mfc=0; mfc<constants::MFC_COUNT; mfc++)
  {
    uint8_t percent = controller.getMfcFlowSetting(mfc);
    modular_device.addToResponse(percent);
  }
  modular_device.stopResponseArray();
}

void getMfcFlowMeasureCallback()
{
  long mfc = modular_device.getParameterValue(constants::mfc_parameter_name);
  uint8_t percent = controller.getMfcFlowMeasure(mfc);
  modular_device.addToResponse("percent",percent);
}

void getMfcFlowMeasuresCallback()
{
  modular_device.addKeyToResponse("percents");
  modular_device.startResponseArray();
  for (int mfc=0; mfc<constants::MFC_COUNT; mfc++)
  {
    uint8_t percent = controller.getMfcFlowMeasure(mfc);
    modular_device.addToResponse(percent);
  }
  modular_device.stopResponseArray();
}

void getAnalogInputCallback()
{
  long channel = modular_device.getParameterValue(constants::channel_parameter_name);
  uint8_t percent = controller.getAnalogInput(channel);
  modular_device.addToResponse("percent",percent);
}

void getAnalogInputsCallback()
{
  modular_device.addKeyToResponse("percents");
  modular_device.startResponseArray();
  for (int channel=0; channel<constants::ANALOG_INPUT_COUNT; channel++)
  {
    uint8_t percent = controller.getAnalogInput(channel);
    modular_device.addToResponse(percent);
  }
  modular_device.stopResponseArray();
}

void saveStateCallback()
{
  long state = modular_device.getParameterValue(constants::state_parameter_name);
  controller.saveState(state);
}

void recallStateCallback()
{
  long state = modular_device.getParameterValue(constants::state_parameter_name);
  controller.recallState(state);
}

void getSavedStatesCallback()
{
  uint8_t** states_array = controller.getStatesArray();
  modular_device.addKeyToResponse("saved_states");
  modular_device.startResponseArray();
  for (int state=0; state<constants::STATE_COUNT; state++)
  {
    modular_device.startResponseArray();
    for (int mfc=0; mfc<=constants::MFC_COUNT; mfc++)
    {
      modular_device.addToResponse(states_array[state][mfc]);
    }
    modular_device.stopResponseArray();
  }
  modular_device.stopResponseArray();
}

// Standalone Callbacks
void executeStandaloneCallbackCallback()
{
  controller.executeStandaloneCallback();
}
}
