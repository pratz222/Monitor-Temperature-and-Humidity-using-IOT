/*
CAPSTONE PROJECT 1 : Monitoring home parameters (Temperatur/Humidity) over THINGSPEAK CLOUD
~ PRATYUSH
*/

#include <ESP8266WiFi.h>
#include <DHT.h>
#include <ThingSpeak.h>
 
const char *ssid =  "FBI OPEN UP!";  
const char *pass =  "Prak@222";
 
 
DHT dht(D5, DHT11);
 
WiFiClient client;
 
long myChannelNumber = 1773491;
const char myWriteAPIKey[] = "LUVIEJA92TWR4YQ8";
 
void setup() {
 
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
  Serial.println();
  Serial.println("NodeMCU is connected!");
  Serial.println(WiFi.localIP());
  dht.begin();
  ThingSpeak.begin(client);
}
 
void loop() {
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.println("Temperature: " + (String) t);
  Serial.println("Humidity: " + (String) h);
  ThingSpeak.writeField(myChannelNumber, 1, t, myWriteAPIKey);
  ThingSpeak.writeField(myChannelNumber, 2, h, myWriteAPIKey);
  delay(2000);
}
