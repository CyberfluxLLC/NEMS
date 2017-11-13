#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <FS.h>
 
const char *ssid   =   "CPE_B546D8_2.4G";      // WiFi SSID
const char *password = "72815252";      // WiFi password
 
//create server
ESP8266WebServer server (80);
 
void updateGpio(){
  String gpio = server.arg("id");
  String state = server.arg("state");
  String success = "1";
  String pin = "D5";
  pin = gpio;


  if (pin == "D5"){
      Serial.print("Hello\n");
      while (Serial.available()>1) {
        String rxdata = Serial.readStringUntil('\n');
        if (rxdata.equals("H1") ) {
            state = "1";
          }
        else if (rxdata.equals("H0") ) {
            state = "0";
          }
        String json = "{\"gpio\":\"" + String(gpio) + "\",";
        json += "\"state\":\"" + String(state) + "\",";
        json += "\"success\":\"" + String(success) + "\"}";
          
        server.send(201, "application/json", json);
    }

    }
  else if (pin == "D6"){
      Serial.print("Hi\n");
      while (Serial.available()>1) {
        String rxdata = Serial.readStringUntil('\n');
        if (rxdata.equals("h1") ) {
            state = "1";
          }
        else if (rxdata.equals("h0") ) {
            state = "0";
          }
        String json = "{\"gpio\":\"" + String(gpio) + "\",";
        json += "\"state\":\"" + String(state) + "\",";
        json += "\"success\":\"" + String(success) + "\"}";
          
        server.send(201, "application/json", json);
    }
    }
  else if (pin == "D7"){
      Serial.print("Bye\n");
      while (Serial.available()>1) {
        String rxdata = Serial.readStringUntil('\n');
        if (rxdata.equals("B1") ) {
            state = "1";
          }
        else if (rxdata.equals("B0") ) {
            state = "0";
          }
        String json = "{\"gpio\":\"" + String(gpio) + "\",";
        json += "\"state\":\"" + String(state) + "\",";
        json += "\"success\":\"" + String(success) + "\"}";
          
        server.send(201, "application/json", json);
    }
    }
  else if (pin == "D8"){
      Serial.print("Kachifo\n");
      while (Serial.available()>1) {
        String rxdata = Serial.readStringUntil('\n');
        if (rxdata.equals("K1") ) {
            state = "1";
          }
        else if (rxdata.equals("K0") ) {
            state = "0";
          }
        String json = "{\"gpio\":\"" + String(gpio) + "\",";
        json += "\"state\":\"" + String(state) + "\",";
        json += "\"success\":\"" + String(success) + "\"}";
          
        server.send(201, "application/json", json);
    }
    }

  
 
} 
 

 
void setup() {
  Serial.begin ( 115200 );
  WiFi.begin ( ssid, password );
  Serial.println ( "" );

  // Wait for connection
  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }

  Serial.println ( "" );
  Serial.print ( "Connected to " );
  Serial.println ( ssid );
  Serial.print ( "IP address: " );
  Serial.println ( WiFi.localIP() );
  if (!SPIFFS.begin())
  {
    // Serious problem
    Serial.println("SPIFFS Mount failed");
  } else {
 
    Serial.println("SPIFFS Mount succesfull");
  }
 
 
  server.on("/gpio", updateGpio);
 /* HTTP_POST, []() {
    updateGpio();
  } */
  
  server.serveStatic("/js", SPIFFS, "/js");
  server.serveStatic("/css", SPIFFS, "/css");
  server.serveStatic("/img", SPIFFS, "/img");
  server.serveStatic("/", SPIFFS, "/index.html"); 
 
  server.begin();
  Serial.println ( "HTTP server started" ); 
 
}
 
void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
  delay(100);
}
