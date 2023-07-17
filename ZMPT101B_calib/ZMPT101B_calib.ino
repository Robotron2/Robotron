#include <EmonLib.h>

#define voltageCalib 310

EnergyMonitor emonl;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  emonl.voltage(1, voltageCalib, 1.7);

}

void loop() {
  // put your main code here, to run repeatedly:
  emonl.calcVI(25, 1000);
  float supplyVoltage = emonl.Vrms;
  Serial.print("Voltage: ");
  Serial.println(supplyVoltage);

}
