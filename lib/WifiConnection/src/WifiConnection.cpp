#include <WiFi.h>
#include <WifiClient.h>
#include <WiFiAP.h>
#include <WiFiManager.h>
#include <WifiConnection.h>

WifiConnection::WifiConnection(String ssid, String password, String autoConnectAPPassword) {
    this->ssid = ssid;
    this->password = password;
    this->autoConnectAPPassword = autoConnectAPPassword;
}

void WifiConnection::wifiConnect() {
    WiFi.mode(WIFI_STA);
    const char* apPassword = autoConnectAPPassword.c_str();

    WiFiManager wm;
    bool res;
    res = wm.autoConnect("AutoConnectAP", apPassword);

    if (!res) {
      Serial.println("Failed to connect");
    }
    else {
      Serial.println("Connected");
    }
}

void WifiConnection::verifyWifi() {
    if (WiFi.status() != WL_CONNECTED) {
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
  }
}