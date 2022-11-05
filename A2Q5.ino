#include <ESP8266WiFi.h>

const String WIFI_NAME = "Praful";
const String WIFI_PASSWORD = "1231231239";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Connecting to... ");
  Serial.println(WIFI_NAME);
  WiFi.begin(WIFI_NAME, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Trying to connect to Wifi Network");
  }
  Serial.println("");
  Serial.println("Successfully connected to WiFi network");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("MAC address: ");
  Serial.println(WiFi.macAddress());
}

void loop() {
  // put your main code here, to run repeatedly:
}