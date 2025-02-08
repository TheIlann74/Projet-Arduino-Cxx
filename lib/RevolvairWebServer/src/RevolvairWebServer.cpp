#include "RevolvairWebServer.h"

void RevolvairWebServer::ReadPMS(){
  String json = BuildPMSJson();
  server->send(200, "application/json", json);
}

String RevolvairWebServer::BuildPMSJson(){
  float pm25Value = data->PM_AE_UG_2_5;
  String particleLevel;
  String desc;
  String color;

  if (pm25Value >= 0.0 && pm25Value <= 50.0)
    {
        particleLevel = "Bon";
        desc = "La qualité de l'air est jugée satisfaisante, et la pollution de l'air pose peu ou pas de risque.";
        color = "#009982";
    } else if (pm25Value >= 51.0 && pm25Value <= 100.0)
    {
        particleLevel = "Modéré";
        desc = "La qualité de l’air est acceptable; cependant, pour certains polluants, il peut y avoir un problème de santé modéré pour un très petit nombre de personnes qui sont inhabituellement sensibles à la pollution atmosphérique.";
        color = "#ecde2b";
    } else if (pm25Value >= 101.0 && pm25Value <= 150.0)
    {
        particleLevel = "Mauvais pour les groupes sensibles";
        desc = "Les membres de groupes sensibles peuvent subir des effets sur la santé. Le grand public ne sera probablement pas affecté.";
        color = "#ff991e";
    } else if (pm25Value >= 151.0 && pm25Value <= 200.0)
    {
        particleLevel = "Mauvais pour la santé";
        desc = "Tout le monde peut commencer à ressentir des effets sur la santé; les membres de groupes sensibles peuvent subir des effets plus graves sur la santé.";
        color = "#b00085";
    } else if (pm25Value >= 201.0 && pm25Value <= 300.0)
    {
        particleLevel = "Très mauvais pour la santé";
        desc = "Avertissements sanitaires des conditions d’urgence. La population entière est plus susceptible d’être touchée.";
        color = "#ff000b";
    } else if (pm25Value >= 301.0)
    {
        particleLevel = "Dangereux";
        desc = "Alerte santé: tout le monde peut subir des effets sanitaires plus graves.";
        color = "#ff000b";
    }


  StaticJsonDocument<1024> pms;
  pms["pm25"] = pm25Value;
  pms["level"] = particleLevel;
  pms["desc"] = desc;
  pms["color"] = color;

  String json;
  serializeJson(pms, json);
  Serial.println(json);

  return json;
}

void RevolvairWebServer::ReadDeviceInfo(){
  String json = BuildInfoJson();
  server->send(200, "application/json", json);
}

String RevolvairWebServer::BuildInfoJson(){
  StaticJsonDocument<200> info;
  info["macid"] = WiFi.macAddress(); 
  info["chipid"] = ESP.getEfuseMac();      
  info["ssid"] = WiFi.SSID();
  info["rssi"] = WiFi.RSSI();

  String json;
  serializeJson(info, json);

  return json;
}

void RevolvairWebServer::handleRoot(){
  server->sendHeader("Location", "/index.html",true);
  server->send(302, "text/plain","");
}

void RevolvairWebServer::handleInfo(){
  server->sendHeader("Location", "/info.html",true);
  server->send(302, "text/plain","");
}

String RevolvairWebServer::getContentType(String path){
  if(path.endsWith(".htm")) return "text/html";
  if(path.endsWith(".html")) return "text/html";
  if(path.endsWith(".css")) return "text/css";
  if(path.endsWith(".js")) return "application/javascript";
  if(path.endsWith(".png")) return "image/png";
  if(path.endsWith(".gif")) return "image/gif";
  if(path.endsWith(".jpg")) return "image/jpeg";
  if(path.endsWith(".ico")) return "image/x-icon";
  if(path.endsWith(".xml")) return "text/xml";
  if(path.endsWith(".pdf")) return "application/pdf";
  if(path.endsWith(".zip")) return "application/zip";
  return "text/plain";
}

void RevolvairWebServer::streamFile(String path, String dataType){
  File dataFile = SPIFFS.open(path.c_str(), "r");
  if (server->hasArg("download")) dataType = "application/octet-stream";
  if (server->streamFile(dataFile, dataType) != dataFile.size()) {
  }
  dataFile.close();
}

bool RevolvairWebServer::loadFromSpiffs(String path){
  if(path.endsWith("/")) path += "index.html";

  streamFile(path, getContentType(path));

  return true;
}

void RevolvairWebServer::handleWebRequests(){
  if(loadFromSpiffs(server->uri())) return;
  String message = "File Not Detected\n\n";
  message += "URI: ";
  message += server->uri();
  message += "\nMethod: ";
  message += (server->method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server->args();
  message += "\n";
  for (uint8_t i=0; i<server->args(); i++){
    message += " NAME:"+server->argName(i) + "\n VALUE:" + server->arg(i) + "\n";
  }
  server->send(404, "text/plain", message);
  Serial.println(message);
}

void RevolvairWebServer::begin(){
  SPIFFS.begin();

  this->server->on("/", HTTP_GET, std::bind(&RevolvairWebServer::handleRoot, this));
  this->server->on("/readPMS", HTTP_GET, std::bind(&RevolvairWebServer::ReadPMS, this));
  this->server->on("/readDeviceInfo", HTTP_GET, std::bind(&RevolvairWebServer::ReadDeviceInfo, this));
  
  this->server->on("/pm25value", HTTP_GET, std::bind(&RevolvairWebServer::handleRoot, this));
  this->server->on("/info", HTTP_GET, std::bind(&RevolvairWebServer::handleInfo, this));

  this->server->onNotFound(std::bind(&RevolvairWebServer::handleWebRequests, this));

  this->server->begin();
}

void RevolvairWebServer::handleClient(){
  server->handleClient();
}