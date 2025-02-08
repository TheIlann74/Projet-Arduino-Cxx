#include <WiFi.h>
#include <WiFiClient.h>
#include <HTTPClient.h>
#include "esp_wifi.h"
#include <ArduinoJson.h>

class JsonAPIManager {
public:
    void getJSON(String url);
    void postJSON(String& encodedJSON);
    void sendPM25ValueToAPI(uint16_t pm25Value);
    JsonAPIManager(String apiToken, String apiStationPostUrl, String apiGetStationUrl) 
        : apiToken(apiToken), apiStationPostUrl(apiStationPostUrl), apiGetStationUrl(apiGetStationUrl) {}
private:
    String apiToken;
    String apiStationPostUrl;
    String apiGetStationUrl;
};