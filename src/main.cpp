#include <Arduino.h>
#include <PmsManager.h>
#include <JsonAPIManager.h>
#include <RGBLedManager.h>
#include "config.h"
#include <WiFi.h>
#include <WifiConnection.h>
#include <RevolvairWebServer.h>

#if defined(USE_BLUETOOTH)
  #include <BluetoothConnection.h>
  BluetoothConnection bluetoothConnection;
#endif

const int delayBeforeSendToAPI = 120000; // 2 minutes
const int delayBeforeSendByBlutooth = 5000; // 5 secondes
int millisSinceLastSend = 0;
int bluetoothDelay = 0;

//Managers
PmsManager pmsManager(Serial2);
JsonAPIManager jsonAPIManager(API_TOKEN, API_STATION_POST_URL, API_GET_STATION_URL);
WifiConnection wifiConnection(ssid, password, autoConnectAPPassword);
RGBLedManager rgbLedManager;

PmsManager::DATA data;

WebServer server(80);
RevolvairWebServer revolvairWebServer(server, data);

const char* htmlfile = "/index.html";

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600);

  #if defined(USE_BLUETOOTH)
    bluetoothConnection.bluetoothSetup();
  #endif

  wifiConnection.wifiConnect();

  // Set WiFi TX power level to minimum (values range from -12 to 20.5 dBm)
  esp_wifi_set_max_tx_power(8); // 8 to 88
  
  revolvairWebServer.begin();

  ledcAttachPin(rgbLedManager.ledR, 1); // assign RGB led pins to channels
  ledcAttachPin(rgbLedManager.ledG, 2);
  ledcAttachPin(rgbLedManager.ledB, 3);

  ledcSetup(1, 12000, 8);
  ledcSetup(2, 12000, 8);
  ledcSetup(3, 12000, 8);

  if (!SPIFFS.begin(true)) {
    Serial.println("Error: ��� Warning");
    return;
  }
  
  Serial.println("Success: ✔ executed with success");
  Serial.println("Mac address: " + WiFi.macAddress());
  Serial.println("Chip id: " + String(ESP.getEfuseMac()));
  Serial.println("SSID: " + WiFi.SSID());
  Serial.println("RSSI: " + String(WiFi.RSSI()));
}

void loop() {
  wifiConnection.verifyWifi();

  #if defined(USE_BLUETOOTH)
    bluetoothConnection.bluetoothGetCommand();
  #endif
  uint16_t PM25value = data.PM_SP_UG_2_5;

  if (pmsManager.read(data)) {
    Serial.print("PM 2.5 (ug/m3): ");
    Serial.println(data.PM_SP_UG_2_5);
    Serial.println();
    Serial.print("1.0 um in 0.1 L air: ");
    Serial.println(data.PM_TOTALPARTICLES_1_0);
    Serial.print("2.5 um in 0.1 L air: ");
    Serial.println(data.PM_TOTALPARTICLES_2_5);
    Serial.print("");
    pmsManager.sendDisplay(data.PM_SP_UG_2_5);
    delay(1000);

    #if defined(USE_BLUETOOTH)
      if (millis() - bluetoothDelay > delayBeforeSendByBlutooth) {
      bluetoothConnection.bluetoothReceiveInformation(data.PM_SP_UG_2_5, data.PM_SP_UG_1_0, data.PM_TOTALPARTICLES_2_5);
      bluetoothDelay = millis();
      }
    #else
      if (millis() - millisSinceLastSend > delayBeforeSendToAPI) {
      jsonAPIManager.sendPM25ValueToAPI(data.PM_SP_UG_2_5);
      millisSinceLastSend = millis();
      }
    #endif
  }

  rgbLedManager.setColorWithParticles(data.PM_SP_UG_2_5);

  ledcWrite(1, rgbLedManager.R);
  ledcWrite(2, rgbLedManager.G);
  ledcWrite(3, rgbLedManager.B);

  revolvairWebServer.handleClient();
}

