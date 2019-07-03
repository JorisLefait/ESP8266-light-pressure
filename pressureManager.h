#ifndef PRESSURE_MANAGER_H_
#define PRESSURE_MANAGER_H_
#include "webServerManager.h"

const String PRM_EMBEDDED_PRESSURE_API_KEY = "embedded_pressure_api_key";
const String PRM_EMBEDDED_PRESSURE_API_KEY_VALUE_EXPECTED =
  "ppDk0rATHKv8vyqlzjvVnLpBj";
const String PRM_EMBEDDED_PRESSURE_STATE = "state";
const String PRM_EMBEDDED_PRESSURE_STATE_PRESENT_VALUE_EXPECTED =
  "STATE_PRESENT";
const String PRM_EMBEDDED_PRESSURE_STATE_MISSING_VALUE_EXPECTED =
  "STATE_MISSING";
const String URL_POST_PRESSURE_STATE = "/api/embedded_pressure/state";

void handlePressureState();
void present();
void missing();
void getPressureStatus();

#endif
