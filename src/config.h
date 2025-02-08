#include <Arduino.h>
/* WiFi */
const char* ssid = "FIRE-NETWORK";
const char* password = "12345678";
const char* autoConnectAPPassword = "12345678";

/* API PATH */
const char* API_GET_PM_VALUE_URL = "https://staging.revolvair.org/api/revolvair/aqi/usepa/fr";

String API_BASE_URL = "https://staging.revolvair.org/api/revolvair/";
String STATION_USER = "Anthony Rusnak";
String STATION_SLUG = "fire-station";
String API_STATION_POST_URL = API_BASE_URL + "stations/" + STATION_SLUG + "/measures";
String API_GET_PM25_URL = API_BASE_URL + "stations/" + STATION_SLUG + "/measures/pm25";
String API_GET_STATION_URL = API_BASE_URL + "stations/" + STATION_SLUG + "/";
String API_TOKEN = "eyJ0eXAiOiJKV1QiLCJhbGciOiJSUzI1NiJ9.eyJhdWQiOiIxIiwianRpIjoiNTIxNmU2ZmFhZDA4MjlhODI0YzA2NWExYjQ5MDI0NjEwZTA3ZDk0ZTBkMDUyNzU2YTliN2M4ZWVlNDY3MjUxODllNGU0ZmE3YjY5ZDQ3NzkiLCJpYXQiOjE3MjYyMzMyNjMuMTc1MzgzLCJuYmYiOjE3MjYyMzMyNjMuMTc1Mzg2LCJleHAiOjE3NTc3NjkyNjMuMTU5OTM4LCJzdWIiOiI3MTMiLCJzY29wZXMiOltdfQ.T9K4h9vYR8oJNaIaAo8ABtJ7BT63KEsFwDZeN5gCCAZTs8WYonoK1xblok4bARNd11x_GrVRNJMxuceLc58d99z7rxXd4HkBNxeVFiTtWC7b58rM5YVDZhREJetVvdcCRCdJZ2eL1tVnhSggCHlD4YrGy7bbC6O5Epr4L4KWVn9_zTdTRW2KUE0aqgOIn6kUH3GLf1sMkohIJb7cbRZq-qY20_q3V8bEtacAsoZmrafMgT_1E5n78RNciZDS8zK1dj_bDVHNt3q2G6jSwmGbgPCaZXKuMDaBHZAqMg6EbcSuKLQmn1hw5TGto_3QbVJgQUKjFk_Dh25n_M8aN3yLPUXFWWN5DFwCGG_DMowyPBlE-6QDbTrMDawaX-VNST3cntbfvOHvCdzhfqXc1fJbkI4A_Y_Tq21LaOo3mXaldVGFdhSRP6JAdey7L07EKnVsQcemnYoIEKRM-a_7EFYlJzl3jmvImUQwZtXapHHlJqinyD6ptJ95Z181vRyUywjnVcOBibkBuZadORFnetGrrpa6OnLxfw_wlcXKHegZk1wSfJ3gX7R96ACUac-SX8CaHfq55xXK5y4B4BqbhOWXK-dtSDiIRqxbn22IHrpcDA_LPTZp_q2ztJgLn1o9PjJ-PHHUdLXztn4fP2PpT1k1dICUOE1nPGT8ojcHYDR58u0";

/* Bluetooth */
//#define USE_BLUETOOTH
