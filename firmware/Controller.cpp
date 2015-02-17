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
    pinMode(constants::purge_pins[mfc],INPUT);
    pinMode(constants::valve_off_pins[mfc],INPUT);
  }

  // Device Info
  modular_device.setName(constants::device_name);
  modular_device.setModelNumber(constants::model_number);
  modular_device.setFirmwareNumber(constants::firmware_number);

  // Saved Variables
  modular_device.createSavedVariable(constants::flow_settings_name,constants::flow_settings_default);

  uint8 flow_settings[constants::MFC_COUNT];
  modular_device.getSavedVariableValue(constants::flow_settings_name,flow_settings);

  for (int mfc = 0; mfc < constants::MFC_COUNT; mfc++)
  {
    analogWrite(constants::pwm_pins[mfc],flow_settings[mfc]);
  }

  // Parameters
  Parameter& mfc_parameter = modular_device.createParameter(constants::mfc_parameter_name);
  percent_parameter.setRange(0,constants::MFC_COUNT-1);
  Parameter& percent_parameter = modular_device.createParameter(constants::percent_parameter_name);
  percent_parameter.setRange(constants::percent_min,constants::percent_max);

  // Methods
  Method& set_mfc_flow_method = modular_device.createMethod(constants::set_mfc_flow_method_name);
  set_mfc_flow_method.attachCallback(callbacks::setMfcFlowCallback);
  set_mfc_flow_method.addParameter(mfc_parameter);
  set_mfc_flow_method.addParameter(percent_parameter);

  Method& get_mfc_flow_setting_method = modular_device.createMethod(constants::get_mfc_flow_setting_method_name);
  get_mfc_flow_setting_method.attachCallback(callbacks::getMfcValueACallback);
  get_mfc_flow_setting_method.addParameter(mfc_parameter);

  Method& get_mfc_flow_measure_method = modular_device.createMethod(constants::get_mfc_flow_measure_method_name);
  get_mfc_flow_measure_method.attachCallback(callbacks::getMfcValueACallback);
  get_mfc_flow_measure_method.addParameter(mfc_parameter);

  // Start Server
  modular_device.startServer(constants::baudrate);

  // Standalone Interface
  standalone_interface_.setup(constants::frame_name_array,constants::FRAME_COUNT);

  // Display Labels
  // channel_dsp_lbl_ptr_ = &(standalone_interface_.createDisplayLabel());
  // channel_dsp_lbl_ptr_->setDisplayPosition(constants::dsp_lbl_display_position);
  // channel_dsp_lbl_ptr_->setFlashString(constants::channel_parameter_name);
  // channel_dsp_lbl_ptr_->setRightJustify();

  // state_dsp_lbl_ptr_ = &(standalone_interface_.createDisplayLabel());
  // state_dsp_lbl_ptr_->setDisplayPosition(constants::dsp_lbl_display_position);
  // state_dsp_lbl_ptr_->setFlashString(constants::state_parameter_name);
  // state_dsp_lbl_ptr_->setRightJustify();

  // Display Variables

  // Interactive Variables
  // channel_int_var_ptr_ = &(standalone_interface_.createInteractiveVariable());
  // channel_int_var_ptr_->setDisplayPosition(constants::int_var_display_position);
  // channel_int_var_ptr_->setRange(constants::channel_min,constants::channel_max);

  // state_int_var_ptr_ = &(standalone_interface_.createInteractiveVariable());
  // state_int_var_ptr_->setDisplayPosition(constants::int_var_display_position);
  // state_int_var_ptr_->setRange(0,constants::STATE_COUNT-1);

  // All Frames

  // Frame 0
  // channel_dsp_lbl_ptr_->addToFrame(0);
  // channel_int_var_ptr_->addToFrame(0);
  // standalone_interface_.attachCallbackToFrame(callbacks::toggleChannelStandaloneCallback,0);

  // Frame 1
  // standalone_interface_.attachCallbackToFrame(callbacks::setAllChannelsOffCallback,1);

  // Frame 2
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
  standalone_interface_.update();
}

void Controller::executeStandaloneCallback()
{
  standalone_interface_.executeCurrentFrameCallback();
}

bool Controller::getLedsPowered()
{
  return digitalRead(constants::led_pwr_pin) == HIGH;
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
