#include <ESP8266WiFi.h>        // Include the Wi-Fi library

int a=0;

WiFiEventHandler stationConnectedHandler;

void setup() {
      pinMode(LED_BUILTIN, OUTPUT);
      digitalWrite(LED_BUILTIN, HIGH);
  //WiFi.softAP(ssid, password);             // Start the access point
  WiFi.softAP("costycnc1");             // Start the access point
  stationConnectedHandler = WiFi.onSoftAPModeStationConnected(&onStationConnected);
}

void loop() { 

  if(a==1){
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level
  delay(500);                      // Wait for a second
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  a=0;
    }
  }

void onStationConnected(const WiFiEventSoftAPModeStationConnected& evt) {
  a=1;
}
