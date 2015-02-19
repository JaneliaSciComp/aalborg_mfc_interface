// ----------------------------------------------------------------------------
// Controller.cpp
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "Controller.h"

Controller::Controller() :
  standalone_interface_(Standalone::StandaloneInterface(constants::display_serial,
                                                        constants::enc_a_pin,
                                                        constants::enc_b_pin,
                                                        constants::enc_btn_pin,
                                                        constants::enc_btn_int,
                                                        constants::btn_pin,
                                                        constants::btn_int,
                                                        constants::led_pwr_pin,
                                                        constants::standalone_update_period))
{
}

void Controller::setup()
{
  // Pin Setup
  for (int mfc = 0; mfc < constants::MFC_COUNT; mfc++)
  {
    pinMode(constants::mfc_purge_pins[mfc],INPUT);
    pinMode(constants::mfc_valve_off_pins[mfc],INPUT);
  }

  // Device Info
  modular_device.setName(constants::device_name);
  modular_device.setModelNumber(constants::model_number);
  modular_device.setFirmwareNumber(constants::firmware_number);

  // Saved Variables
  modular_device.createSavedVariable(constants::flow_settings_name,
                                     constants::flow_settings_default,
                                     constants::MFC_COUNT);

  for (int mfc=0; mfc<constants::MFC_COUNT; mfc++)
  {
    modular_device.getSavedVariableValue(constants::flow_settings_name,flow_settings_array_,mfc);
    setMfcFlow(mfc,flow_settings_array_[mfc]);
  }

  // Parameters
  ModularDevice::Parameter& mfc_parameter = modular_device.createParameter(constants::mfc_parameter_name);
  mfc_parameter.setRange(0,constants::MFC_COUNT-1);

  ModularDevice::Parameter& channel_parameter = modular_device.createParameter(constants::channel_parameter_name);
  channel_parameter.setRange(0,constants::ANALOG_INPUT_COUNT-1);

  ModularDevice::Parameter& percent_parameter = modular_device.createParameter(constants::percent_parameter_name);
  percent_parameter.setRange(constants::percent_min,constants::percent_max);

  // Methods
  ModularDevice::Method& execute_standalone_callback_method = modular_device.createMethod(constants::execute_standalone_callback_method_name);
  execute_standalone_callback_method.attachCallback(callbacks::executeStandaloneCallbackCallback);

  ModularDevice::Method& get_leds_powered_method = modular_device.createMethod(constants::get_leds_powered_method_name);
  get_leds_powered_method.attachCallback(callbacks::getLedsPoweredCallback);

  ModularDevice::Method& set_mfc_flow_method = modular_device.createMethod(constants::set_mfc_flow_method_name);
  set_mfc_flow_method.attachCallback(callbacks::setMfcFlowCallback);
  set_mfc_flow_method.addParameter(mfc_parameter);
  set_mfc_flow_method.addParameter(percent_parameter);

  ModularDevice::Method& get_mfc_flow_setting_method = modular_device.createMethod(constants::get_mfc_flow_setting_method_name);
  get_mfc_flow_setting_method.attachCallback(callbacks::getMfcFlowSettingCallback);
  get_mfc_flow_setting_method.addParameter(mfc_parameter);

  ModularDevice::Method& get_mfc_flow_measure_method = modular_device.createMethod(constants::get_mfc_flow_measure_method_name);
  get_mfc_flow_measure_method.attachCallback(callbacks::getMfcFlowMeasureCallback);
  get_mfc_flow_measure_method.addParameter(mfc_parameter);

  ModularDevice::Method& get_analog_input_method = modular_device.createMethod(constants::get_analog_input_method_name);
  get_analog_input_method.attachCallback(callbacks::getAnalogInputCallback);
  get_analog_input_method.addParameter(channel_parameter);

  // Start Server
  modular_device.startServer(constants::baudrate);

  // Standalone Interface
  standalone_interface_.setup(constants::frame_name_array,constants::FRAME_COUNT);

  // Display Labels
  Standalone::DisplayLabel* mfc_dsp_lbl_ptr_array[constants::MFC_COUNT];
  for (int mfc=0; mfc<constants::MFC_COUNT; mfc++)
  {
    mfc_dsp_lbl_ptr_array[mfc] = &(standalone_interface_.createDisplayLabel());
    mfc_dsp_lbl_ptr_array[mfc]->setDisplayPosition(constants::mfc_dsp_lbl_display_positions[mfc]);
    mfc_dsp_lbl_ptr_array[mfc]->setFlashString(constants::mfc_dsp_lbl_strings[mfc]);
    mfc_dsp_lbl_ptr_array[mfc]->setRightJustify();
  }

  Standalone::DisplayLabel* ain_dsp_lbl_ptr_array[constants::ANALOG_INPUT_COUNT];
  for (int channel=0; channel<constants::ANALOG_INPUT_COUNT; channel++)
  {
    ain_dsp_lbl_ptr_array[channel] = &(standalone_interface_.createDisplayLabel());
    ain_dsp_lbl_ptr_array[channel]->setDisplayPosition(constants::ain_dsp_lbl_display_positions[channel]);
    ain_dsp_lbl_ptr_array[channel]->setFlashString(constants::ain_dsp_lbl_strings[channel]);
    ain_dsp_lbl_ptr_array[channel]->setRightJustify();
  }

  // Display Variables
  for (int mfc=0; mfc<constants::MFC_COUNT; mfc++)
  {
    flow_dsp_var_ptr_array_[mfc] = &(standalone_interface_.createDisplayVariable());
    flow_dsp_var_ptr_array_[mfc]->setDisplayPosition(constants::flow_var_display_positions[mfc]);
    flow_dsp_var_ptr_array_[mfc]->setDisplayWidth(constants::percent_display_width);
  }
  for (int channel=0; channel<constants::ANALOG_INPUT_COUNT; channel++)
  {
    ain_dsp_var_ptr_array_[channel] = &(standalone_interface_.createDisplayVariable());
    ain_dsp_var_ptr_array_[channel]->setDisplayPosition(constants::ain_dsp_var_display_positions[channel]);
    ain_dsp_var_ptr_array_[channel]->setDisplayWidth(constants::percent_display_width);
  }

  // Interactive Variables
  for (int mfc=0; mfc<constants::MFC_COUNT; mfc++)
  {
    flow_int_var_ptr_array_[mfc] = &(standalone_interface_.createInteractiveVariable());
    flow_int_var_ptr_array_[mfc]->setDisplayPosition(constants::flow_var_display_positions[mfc]);
    flow_int_var_ptr_array_[mfc]->setDisplayWidth(constants::percent_display_width);
    flow_int_var_ptr_array_[mfc]->setRange(constants::percent_min,constants::percent_max);
    flow_int_var_ptr_array_[mfc]->setValue(flow_settings_array_[mfc]);
  }

  // All Frames

  // Frame 0
  for (int mfc=0; mfc<constants::MFC_COUNT; mfc++)
  {
    mfc_dsp_lbl_ptr_array[mfc]->addToFrame(0);
    flow_int_var_ptr_array_[mfc]->addToFrame(0);
  }

  // Frame 1
  for (int mfc=0; mfc<constants::MFC_COUNT; mfc++)
  {
    mfc_dsp_lbl_ptr_array[mfc]->addToFrame(1);
    flow_dsp_var_ptr_array_[mfc]->addToFrame(1);
  }
  // standalone_interface_.attachCallbackToFrame(callbacks::setAllChannelsOffCallback,1);

  // Frame 2
  for (int channel=0; channel<constants::ANALOG_INPUT_COUNT; channel++)
  {
    ain_dsp_lbl_ptr_array[channel]->addToFrame(2);
    ain_dsp_var_ptr_array_[channel]->addToFrame(2);
  }
  // standalone_interface_.attachCallbackToFrame(callbacks::setAllChannelsOnCallback,2);

  // Frame 3
  // state_dsp_lbl_ptr_->addToFrame(3);
  // state_int_var_ptr_->addToFrame(3);
  // standalone_interface_.attachCallbackToFrame(callbacks::saveStateStandaloneCallback,3);

  // Frame 4
  // state_dsp_lbl_ptr_->addToFrame(4);
  // state_int_var_ptr_->addToFrame(4);
  // standalone_interface_.attachCallbackToFrame(callbacks::recallStateStandaloneCallback,4);

  // Enable Standalone Interface
  standalone_interface_.enable();
}

void Controller::update()
{
  modular_device.handleServerRequests();
  boolean updated = standalone_interface_.update();
  if (updated)
  {
    updateDisplayVariables();
    updateMfcFlow();
  }
}

void Controller::executeStandaloneCallback()
{
  standalone_interface_.executeCurrentFrameCallback();
}

bool Controller::getLedsPowered()
{
  return digitalRead(constants::led_pwr_pin) == HIGH;
}

void Controller::setMfcFlow(const uint8_t mfc, const uint8_t percent)
{
  if (percent != flow_settings_array_[mfc])
  {
    flow_settings_array_[mfc] = percent;
    flow_int_var_ptr_array_[mfc]->setValue(percent);
    int pwm_value = betterMap(percent,
                              constants::percent_min,
                              constants::percent_max,
                              constants::pwm_min,
                              constants::pwm_max);
    analogWrite(constants::mfc_pwm_pins[mfc],pwm_value);
  }
}

uint8_t Controller::getMfcFlowSetting(const uint8_t mfc)
{
  return flow_settings_array_[mfc];
}

uint8_t Controller::getMfcFlowMeasure(const uint8_t mfc)
{
  int analog_in_value = analogRead(constants::mfc_analog_in_pins[mfc]);
  int percent = betterMap(analog_in_value,
                          constants::analog_in_min,
                          constants::analog_in_max,
                          constants::percent_min,
                          constants::percent_max);
  return percent;
}

uint8_t Controller::getAnalogInput(const uint8_t channel)
{
  int analog_in_value = analogRead(constants::analog_in_pins[channel]);
  int percent = betterMap(analog_in_value,
                          constants::analog_in_min,
                          constants::analog_in_max,
                          constants::percent_min,
                          constants::percent_max);
  return percent;
}

void Controller::updateDisplayVariables()
{
  int percent;
  for (int mfc=0; mfc<constants::MFC_COUNT; mfc++)
  {
    percent = getMfcFlowMeasure(mfc);
    flow_dsp_var_ptr_array_[mfc]->setValue(percent);
  }
  for (int channel=0; channel<constants::ANALOG_INPUT_COUNT; channel++)
  {
    percent = getAnalogInput(channel);
    ain_dsp_var_ptr_array_[channel]->setValue(percent);
  }
}

void Controller::updateMfcFlow()
{
  int percent;
  for (int mfc=0; mfc<constants::MFC_COUNT; mfc++)
  {
    percent = flow_int_var_ptr_array_[mfc]->getValue();
    setMfcFlow(mfc,percent);
  }
}

// void Controller::saveState(int state)
// {
//   uint32_t channels = getChannelsOn();
//   states_array_[state] = channels;
//   modular_device.setSavedVariableValue(constants::states_name,states_array_,state);
// }

// void Controller::recallState(int state)
// {
//   modular_device.getSavedVariableValue(constants::states_name,states_array_,state);
//   uint32_t channels = states_array_[state];
//   setChannels(channels);
// }

// uint32_t* Controller::getStatesArray()
// {
//   for (int state=0; state<constants::STATE_COUNT; state++)
//   {
//     modular_device.getSavedVariableValue(constants::states_name,states_array_,state);
//   }
//   return states_array_;
// }

Controller controller;
