/*
  To upload through terminal you can use: curl -F "image=@firmware.bin" esp8266-webupdate.local/update
*/

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>

WiFiEventHandler stationConnectedHandler;
WiFiEventHandler stationDisconnectedHandler;
ESP8266WebServer httpServer(80);
ESP8266HTTPUpdateServer httpUpdater;
const char* serverIndex = "HELLO";
int a=0;

void setup(void){
        pinMode(LED_BUILTIN, OUTPUT);
      digitalWrite(LED_BUILTIN, HIGH);
  //WiFi.softAP(ssid, password);             // Start the access point
  WiFi.softAP("lampadina_costy");             // Start the access point
  stationConnectedHandler = WiFi.onSoftAPModeStationConnected(&onStationConnected);
  stationDisconnectedHandler = WiFi.onSoftAPModeStationDisconnected (&onStationDisconnected);

  Serial.begin(115200);

    httpServer.on("/", HTTP_GET, [](){
      httpServer.sendHeader("Connection", "close");
      httpServer.sendHeader("Access-Control-Allow-Origin", "*");
      httpServer.send(200, "text/html", serverIndex);
    });
  httpUpdater.setup(&httpServer);
  httpServer.begin();

}

void loop(void){
  httpServer.handleClient();
  delay(1);
  
  if(a==1){
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level
  delay(500);                      // Wait for a second
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  a=0;
    }
}

void onStationConnected(const WiFiEventSoftAPModeStationConnected& evt) {
  //a=1;
  digitalWrite(LED_BUILTIN, LOW); 
}

void onStationDisconnected(const WiFiEventSoftAPModeStationDisconnected& evt) {
  //a=1;
  digitalWrite(LED_BUILTIN, HIGH); 
}
