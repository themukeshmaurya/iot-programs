// A2Q5. Connect ESP with Wifi and print the IP and MAC address of the device.

#include <ESP8266WiFi.h>

const String WIFI_NAME = "Praful";
const String WIFI_PASSWORD = "12345678";

void setup() {
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
}