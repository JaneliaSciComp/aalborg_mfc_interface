// ----------------------------------------------------------------------------
// Callbacks.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef CALLBACKS_H
#define CALLBACKS_H
#include "JsonParser.h"
#include "BetterMap.h"
#include "ModularDevice.h"
#include "Constants.h"


namespace callbacks
{
void getLedsPoweredCallback();

void setMfcFlowCallback();

void getMfcFlowSettingCallback();

void getMfcFlowMeasureCallback();

// Standalone Callbacks
void executeStandaloneCallbackCallback();
}
#endif
