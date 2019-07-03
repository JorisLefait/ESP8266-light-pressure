#include "lightManager.h"

String mEmbeddedLightStateMessage;
String mEmbeddedLightStatevalue;

//Donne l'état de la lumière ambiante:
void handleLightState() {
  if (server.method() == HTTP_GET) {
    String tAPiKey = server.arg(PRM_EMBEDDED_LIGHT_API_KEY);
    String tState = server.arg(PRM_EMBEDDED_LIGHT_STATE);

    if (PRM_EMBEDDED_LIGHT_API_KEY_VALUE_EXPECTED == tAPiKey) {
      getLightStatus();
      server.send(HTTP_SUCCESS, JSON, "{\"state_str\": \"" + mEmbeddedLightStateMessage + "\", \"state\":\"" + mEmbeddedLightStatevalue + "\"}");
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

void day() {
  mEmbeddedLightStateMessage = "Jour";
  mEmbeddedLightStatevalue = PRM_EMBEDDED_LIGHT_STATE_DAY_VALUE_EXPECTED;
}

void night() {
  mEmbeddedLightStateMessage = "Nuit";
  mEmbeddedLightStatevalue = PRM_EMBEDDED_LIGHT_STATE_NIGHT_VALUE_EXPECTED;
}

void getLightStatus() {
  analogRead(A0) > 512 ? day() : night();
}
