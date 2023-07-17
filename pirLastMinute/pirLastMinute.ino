int relayPin = 9;                // choose the pin for the relay
int pirPin = 8;               // choose the input pin (for PIR sensor)
int lightState;

 
void setup() {
  pinMode(relayPin, OUTPUT);      // declare LED as output
  pinMode(pirPin, INPUT);     // declare sensor as input
  Serial.begin(9600);
}
 
void loop(){
  checkState();
  if(lightState == 1){
    digitalWrite(relayPin, LOW);
   }
   else{
      digitalWrite(relayPin, HIGH);
    }
  delay(500);
}

void checkState(){
  int sensorValue = digitalRead(pirPin);
  Serial.print("SensorValue: ");
  Serial.println(sensorValue);

  if(sensorValue == 1 ){
      lightState = 1;
      Serial.println("LightState = 1");
    }
  else if(sensorValue == 0){
    Serial.print("delaying... ");
      lightState = 0;
      delay(100);
    }
  else{
      lightState = 0;
    }

}
