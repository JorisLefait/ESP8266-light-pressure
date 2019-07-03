#ifndef LIGHT_MANAGER_H_
#define LIGHT_MANAGER_H_
#include "webServerManager.h"

const String PRM_EMBEDDED_LIGHT_API_KEY = "embedded_light_api_key";
const String PRM_EMBEDDED_LIGHT_API_KEY_VALUE_EXPECTED =
  "ppDk0rATHKv8vyqlzjvVnNIYc";
const String PRM_EMBEDDED_LIGHT_STATE = "state";
const String PRM_EMBEDDED_LIGHT_STATE_DAY_VALUE_EXPECTED =
  "STATE_DAY";
const String PRM_EMBEDDED_LIGHT_STATE_NIGHT_VALUE_EXPECTED =
  "STATE_NIGHT";
const String URL_POST_LIGHT_STATE = "/api/embedded_light/state";

void handleLightState();
void day();
void night();
void getLightStatus();

#endif
