#include "pressureManager.h"

String mEmbeddedPressureStateMessage;
String mEmbeddedPressureStatevalue;

//Donne l'état de la lumière ambiante:
void handlePressureState() {
  if (server.method() == HTTP_GET) {
    String tAPiKey = server.arg(PRM_EMBEDDED_PRESSURE_API_KEY);
    String tState = server.arg(PRM_EMBEDDED_PRESSURE_STATE);

    if (PRM_EMBEDDED_PRESSURE_API_KEY_VALUE_EXPECTED == tAPiKey) {
      getPressureStatus();
      server.send(HTTP_SUCCESS, JSON, "{\"state_str\": \"" + mEmbeddedPressureStateMessage + "\", \"state\":\"" + mEmbeddedPressureStatevalue + "\"}");
    } else {
      server.send(HTTP_FORBIDDEN, JSON, "{\"error\":\"Api key non reconnue.\"}");
    }
  } else {
    String rMessageErreur = "{\"error\":\"Methode http demandée (";
    rMessageErreur += server.method();
    rMessageErreur += ") non disponible.\"}";
    server.send(HTTP_METHOD_NOT_ALLOW, JSON, rMessageErreur);
  }
}

void present() {
  mEmbeddedPressureStateMessage = "Présent";
  mEmbeddedPressureStatevalue = PRM_EMBEDDED_PRESSURE_STATE_PRESENT_VALUE_EXPECTED;
}

void missing() {
  mEmbeddedPressureStateMessage = "Absent";
  mEmbeddedPressureStatevalue = PRM_EMBEDDED_PRESSURE_STATE_MISSING_VALUE_EXPECTED;
}

void getPressureStatus() {
  analogRead(A0) > 512 ? present() : missing();
}
