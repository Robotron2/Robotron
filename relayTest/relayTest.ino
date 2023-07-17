int relayPin = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(relayPin, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  myFunc();
  

}

void myFunc(){
  //anything that you want to write.
  digitalWrite(relayPin, HIGH);
  delay(3000);
  digitalWrite(relayPin, LOW);
  delay(1000);
}
