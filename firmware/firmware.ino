#include <EEPROM.h>
#include "Streaming.h"
#include "JsonParser.h"
#include "StandardCplusplus.h"
#include "MemoryFree.h"
#include "Flash.h"
#include "RemoteDevice.h"
#include "Constants.h"
#include "Callbacks.h"

// See README.md for more information

using namespace RemoteDevice;

void setup()
{
  for (int mfc = 0; mfc < constants::MFC_COUNT; mfc++)
  {
    pinMode(constants::purge_pins[mfc],INPUT);
    pinMode(constants::valve_off_pins[mfc],INPUT);
  }

  remote_device.setName(constants::device_name);
  remote_device.setModelNumber(constants::model_number);
  remote_device.setFirmwareNumber(constants::firmware_number);

  remote_device.createSavedVariable(constants::flow_setting_0_name,constants::flow_setting_default);
  remote_device.createSavedVariable(constants::flow_setting_1_name,constants::flow_setting_default);
  remote_device.createSavedVariable(constants::flow_setting_2_name,constants::flow_setting_default);

  for (int mfc = 0; mfc < constants::MFC_COUNT; mfc++)
  {
    uint8 pwm_value;
    remote_device.getSavedVariableValue(constants::starting_chars_name,starting_chars_count);
    analogWrite(constants::pwm_pins[mfc],0);
  }

  Parameter& mfc_parameter = remote_device.createParameter(constants::mfc_parameter_name);
  percent_parameter.setRange(0,constants::MFC_COUNT-1);
  Parameter& percent_parameter = remote_device.createParameter(constants::percent_parameter_name);
  percent_parameter.setRange(constants::percent_min,constants::percent_max);

  Method& set_mfc_flow_method = remote_device.createMethod(constants::set_mfc_flow_method_name);
  set_mfc_flow_method.attachCallback(callbacks::setMfcFlowCallback);
  set_mfc_flow_method.addParameter(mfc_parameter);
  set_mfc_flow_method.addParameter(percent_parameter);

  Method& get_mfc_flow_setting_method = remote_device.createMethod(constants::get_mfc_flow_setting_method_name);
  get_mfc_flow_setting_method.attachCallback(callbacks::getMfcValueACallback);
  get_mfc_flow_setting_method.addParameter(mfc_parameter);

  Method& get_mfc_flow_measure_method = remote_device.createMethod(constants::get_mfc_flow_measure_method_name);
  get_mfc_flow_measure_method.attachCallback(callbacks::getMfcValueACallback);
  get_mfc_flow_measure_method.addParameter(mfc_parameter);

  remote_device.startServer(constants::baudrate);
}

void loop()
{
  remote_device.handleServerRequests();
}
