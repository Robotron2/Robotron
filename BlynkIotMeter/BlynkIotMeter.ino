#include "EmonLib.h"
#include <EEPROM.h>
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include "Blynk.h"
#include <BlynkSimpleEsp32.h>

int relayPin = 18;
int relayState = 0;

#define BLYNK_TEMPLATE_ID "TMPL2M-Q4CJzg"
#define BLYNK_TEMPLATE_NAME "BlynkEnergyMeter"
#define BLYNK_AUTH_TOKEN "aGN69nYL9DRyqcUouai8r1-gRAiS4jpQ"

 
EnergyMonitor emon;

#define vCalibration 83.3 
#define currCalibration 0.50
#define virtualRelayPin V4


 
BlynkTimer timer;
char auth[] = "aGN69nYL9DRyqcUouai8r1-gRAiS4jpQ";
char ssid[] = "robot";
char pass[] = "robotron";
 
float kWh = 0;
unsigned long lastmillis = millis();
 
void myTimerEvent()
{
  emon.calcVI(20, 2000);
  kWh = kWh + emon.apparentPower * (millis() - lastmillis) / 3600000000.0;
  yield();
  Serial.print("Vrms: ");
  Serial.print(emon.Vrms, 2);
  Serial.print("V");
  EEPROM.put(0, emon.Vrms);
  delay(100);
 
  Serial.print("\tIrms: ");
  Serial.print(emon.Irms, 4);
  Serial.print("A");
  EEPROM.put(4, emon.Irms);
  delay(100);
 
  Serial.print("\tPower: ");
  Serial.print(emon.apparentPower, 4);
  Serial.print("W");
  EEPROM.put(8, emon.apparentPower);
  delay(100);
 
  Serial.print("\tkWh: ");
  Serial.print(kWh, 5);
  Serial.println("kWh");
  EEPROM.put(12, kWh);
 
  lastmillis = millis();
 
  Blynk.virtualWrite(V0, emon.Vrms);
  Blynk.virtualWrite(V1, emon.Irms);
  Blynk.virtualWrite(V2, emon.apparentPower);
  Blynk.virtualWrite(V3, kWh);
  Blynk.virtualWrite(V4, relayState);
}

 BLYNK_WRITE(virtualRelayPin) {
  relayState = param.asInt();
  digitalWrite(relayPin, relayState);
}

BLYNK_CONNECTED() {
  Blynk.syncVirtual(virtualRelayPin);
}


 
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  emon.voltage(35, vCalibration, 1.7);  // Voltage: input pin, calibration, phase_shift
  emon.current(34, currCalibration);    // Current: input pin, calibration.
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);
}
 
void loop()
{
  if(relayState == 1){
    digitalWrite(relayPin, LOW); //turns on
  }
  if(relayState == 0){
    digitalWrite(relayPin, HIGH); //turns off
  }
  Blynk.run();
  timer.run();
  
}
