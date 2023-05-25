int PIN_9 = 9

void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(PIN_9, HIGH);
  delay(2000);
  digitalWrite(PIN_9, LOW);
  delay(1000);

}
