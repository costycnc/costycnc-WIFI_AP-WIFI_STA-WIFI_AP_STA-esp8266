
 
//http://www.martyncurrey.com/esp8266-and-the-arduino-ide-part-9-websockets/

#include <WebSocketsServer.h>
 
WebSocketsServer webSocket = WebSocketsServer(81);
 char res[50];

 
void setup()
{
 
  Serial.begin(115200);
  Serial.println();
  Serial.println("Serial started at 115200");
  Serial.println();
 

 
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
}
 
void loop()
{
    webSocket.loop();
 
}
 
void webSocketEvent(byte num, WStype_t type, uint8_t * payload, size_t length)
{
  if(type == WStype_TEXT)
  {   

      for (int i = 0; i <= length; i++) {
    res[i]=char(payload[i]);
  }
      Serial.println(res); 
      webSocket.broadcastTXT("ok");
    
  }
 
  else 
  {

    
    Serial.print("WStype = ");   Serial.println(type);  
    Serial.print("WS payload = ");
    for(int i = 0; i < length; i++) { Serial.print((char) payload[i]); }
    Serial.println();
 
  }
}
