#define BLYNK_PRINT Serial  /*  include Blynk Serial */
#include <WiFi.h>    /*ESP32 WiFi Library*/
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#define BLYNK_TEMPLATE_ID "TMPL2ng7KqhDv"
#define BLYNK_TEMPLATE_NAME "WifiLightE32"
#define BLYNK_AUTH_TOKEN "1IqVWv_hCH1BJY5d5VfsrAESfdKdA_-K"

// Enter device Authentication Token
char auth[] ="dgCnR1bb……………………qU8RXnc";

//Enter your WIFI SSID and password
char ssid[] = "Type Your Network SSID";
char pass[] = "Type Your Network Password";

void setup(){
  Serial.begin(9600);  /*Baud rate for serial communication*/
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop(){
  Blynk.run();
}
