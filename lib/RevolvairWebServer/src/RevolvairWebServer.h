#pragma once
#include <WiFi.h>
#include <WebServer.h>
#include <FS.h>
#include <SPIFFS.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <PmsManager.h>

class RevolvairWebServer {
public: 
    RevolvairWebServer(WebServer &server, PmsManager::DATA &data) : server(&server), data(&data) {}
    void begin();
    void handleClient();
private: 
    WebServer *server;
    PmsManager::DATA *data;

    void ReadPMS();
    void ReadDeviceInfo();

    String BuildPMSJson();
    String BuildInfoJson();

    void handleRoot();
    void handleInfo();

    String getContentType(String path);
    void streamFile(String path, String dataType);
    bool loadFromSpiffs(String path);
    void handleWebRequests();
};