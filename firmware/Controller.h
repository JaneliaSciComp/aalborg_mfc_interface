// ----------------------------------------------------------------------------
// Controller.h
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------

#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "ModularDevice.h"
#include "StandaloneInterface.h"
#include "Constants.h"
#include "Callbacks.h"

class Controller
{
public:
  Controller();
  void setup();
  void update();
  void executeStandaloneCallback();
  bool getLedsPowered();
  // void saveState(int state);
  // void recallState(int state);
  // uint32_t* getStatesArray();
private:
  // uint32_t states_array_[constants::STATE_COUNT];
  Standalone::StandaloneInterface standalone_interface_;
  // Standalone::DisplayLabel *channel_dsp_lbl_ptr_;
  // Standalone::DisplayLabel *state_dsp_lbl_ptr_;
  // Standalone::InteractiveVariable *channel_int_var_ptr_;
  // Standalone::InteractiveVariable *state_int_var_ptr_;
};

extern Controller controller;

#endif
