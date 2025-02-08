#include <JsonAPIManager.h>

void JsonAPIManager::getJSON(String url) {
  HTTPClient http;

  http.begin(apiGetStationUrl);
  http.addHeader("Accept", "application/json");
  http.addHeader("Content-Type", "application/json");

  int httpCode = http.GET();
  String payload = http.getString();
  Serial.println(httpCode);
  Serial.println(payload);
  http.end();
}

void JsonAPIManager::postJSON(String& encodedJSON) {
  HTTPClient http;
  http.begin(apiStationPostUrl);

  http.addHeader("Accept", "application/json");
  http.addHeader("Content-Type", "application/json");
  http.addHeader("Authorization", "Bearer " + String(apiToken));

  int httpCode = http.POST(encodedJSON);
  String payload = http.getString();
  Serial.println("URL: 🖇️ " + apiStationPostUrl);
  Serial.println(httpCode);
  Serial.println(payload);
  http.end();
}

void JsonAPIManager::sendPM25ValueToAPI(uint16_t pm25Value) {
  DynamicJsonDocument doc(1024);

  doc["value"] = pm25Value;
  doc["unit"] = "pm25_raw";

  String jsonPm25Package = "";
  serializeJson(doc, jsonPm25Package);
  postJSON(jsonPm25Package);
}