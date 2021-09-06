// Import required libraries
#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>

// Set your access point network credentials
const char* ssid = "My Chi";
const char* password = "0937352636h@";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

//void readTemp() {
//  return "8";
//}
void setup() {
  // put your setup code here, to run once:
  // Serial port for debugging purposes
  Serial.begin(115200);
  Serial.println();

  // Setting the ESP as an access point
  Serial.print("Setting AP (Access Point)…");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", "8");
  });

//  bool status;
//
//  // default settings
//  // (you can also pass in a Wire library object like &Wire2)
//  status = bme.begin(0x76);  
//  if (!status) {
//    Serial.println("Could not find a valid BME280 sensor, check wiring!");
//    while (1);
//  }
  
  // Start server
  server.begin();

}

void loop() {
  // put your main code here, to run repeatedly:

}
