#include "esp32-mqtt.h"

//==============OLED DISPLAY=========================
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
Adafruit_SSD1306 display(16);
//===================================================
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  setupCloudIoT();
  // init and get the time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  getTimestamp();
//==============================================
  dht.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  delay(1000);
  display.clearDisplay();
  display.setTextColor(WHITE);
//==============================================
}

unsigned long lastMillis = 0;
void loop() {
  mqttClient->loop();
  delay(10);  // <- fixes some issues with WiFi stability

  if (!mqttClient->connected()) {
    connect();
  }

  // publish a message roughly every second.
  if (millis() - lastMillis > 60000) {
    lastMillis = millis();
    publishTelemetry(completeJSON());
    Serial.println(completeJSON());
  }

  // clear display
  //Device_id
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Device_id: ");
  display.setTextSize(1);
  display.setCursor(70,0);
  display.print(device_id);
  //temperature
  display.setTextSize(1);
  display.setCursor(0,10);
  display.print("Temperature: ");
  display.setTextSize(1);
  display.setCursor(75,10);
  display.print(Tem);
  display.print(" ");
  display.setTextSize(1);
  display.cp437(true);
  display.write(167);
  display.setTextSize(1);
  display.print("C");
  //timeStamp
  display.setTextSize(1);
  display.setCursor(0, 20);
  display.print(getTimestamp());
  display.display();
  }
