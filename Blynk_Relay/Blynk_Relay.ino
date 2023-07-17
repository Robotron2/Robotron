#define BLYNK_TEMPLATE_ID "TMPL2Bdu8UYh5"
#define BLYNK_TEMPLATE_NAME "ESP Home Automation"
#define BLYNK_AUTH_TOKEN ""


#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#define relayPin 14

char auth[] = "7zaFIKZ-g92Ytwh2Hid19p0R-vHjfeLu";
char ssid[] = "robot";
char pass[] = "TheoMagJaph";

BlynkTimer timer;

void setup() {
  // put your setup code here, to run once:
  pinMode(relayPin, OUTPUT);
  Blynk.begin(auth, ssid, pass);

  digitalWrite(relayPin, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  timer.run();

}
