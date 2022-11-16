#include <Arduino.h>
#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>

#define USE_SERIAL Serial
#define INPUT_PIN 4
#define LED_PIN 2

WiFiMulti wifiMulti;

String lastValue;

void setup() {

  Serial.begin(115200);

  pinMode(INPUT_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }

  wifiMulti.addAP("Praful", "12345678");
  wifiMulti.run();
  if (wifiMulti.run() == WL_CONNECTED) {
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
  }
  // server.begin();
  lastValue = "0";
}

void loop() {
  // wait for WiFi connection
  if ((wifiMulti.run() == WL_CONNECTED)) {
    String webUrl;
    if (digitalRead(INPUT_PIN) == LOW) {
      digitalWrite(LED_PIN, HIGH);
      //digitalWrite(BUZZ_PIN,HIGH);
    } else {
      digitalWrite(LED_PIN, LOW);
      // digitalWrite(BUZZ_PIN,LOW);
    }

    if (digitalRead(LED_PIN) == HIGH) {
      if (lastValue == "0") {
        webUrl = "https://iottest2022.000webhostapp.com/update.php?name=ledon&status=1";
        updateServer(webUrl);
        lastValue = "1";
      }
    } else {
      if (lastValue == "1") {
        webUrl = "https://iottest2022.000webhostapp.com/update.php?name=ledoff&status=0";
        updateServer(webUrl);
        lastValue = "0";
      }
    }
  }
  delay(100);
}


void updateServer(String webUrl) {
  HTTPClient http;
  Serial.print("[HTTP] begin...\n");
  // configure traged server and url
  http.begin(webUrl);  //HTTP

  Serial.print("[HTTP] GET...\n");
  // start connection and send HTTP header
  int httpCode = http.GET();

  // httpCode will be negative on error
  if (httpCode > 0) {
    // HTTP header has been send and Server response header has been handled
    Serial.printf("[HTTP] GET... code: %d\n", httpCode);

    // file found at server
    if (httpCode == HTTP_CODE_OK) {
      String payload = http.getString();
      Serial.println(payload);
    }
  } else {
    Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }

  http.end();
}