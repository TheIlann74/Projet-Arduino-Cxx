#include <Arduino.h>
/* WiFi */
const char* ssid = "network";
const char* password = "password";
const char* autoConnectAPPassword = "password";

/* API PATH */
const char* API_GET_PM_VALUE_URL = "url";

String API_BASE_URL = "url";
String STATION_USER = "user name";
String STATION_SLUG = "station name slug";
String API_STATION_POST_URL = API_BASE_URL + "stations/" + STATION_SLUG + "/measures";
String API_GET_PM25_URL = API_BASE_URL + "stations/" + STATION_SLUG + "/measures/pm25";
String API_GET_STATION_URL = API_BASE_URL + "stations/" + STATION_SLUG + "/";
String API_TOKEN = "token";

/* Bluetooth */
//#define USE_BLUETOOTH