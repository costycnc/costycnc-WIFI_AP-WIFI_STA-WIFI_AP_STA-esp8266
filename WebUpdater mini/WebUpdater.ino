
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>

ESP8266WebServer httpServer(80);
ESP8266HTTPUpdateServer httpUpdater;


void setup(void){
  //WiFi.softAP(ssid, password);             // Start the access point
  WiFi.softAP("lampadina_costy1");             // Start the access point

  httpUpdater.setup(&httpServer);
  httpServer.begin();

}

void loop(void){
  httpServer.handleClient();
  delay(1);
 
}
