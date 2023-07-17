int relayPin = 4;
int sensorPin = 5;
int sensorState;
bool relayState;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  delay(600);

}

void loop() {
  // put your main code here, to run repeatedly:
  checkState();
  if(sensorState == 1){
      digitalWrite(relayPin, LOW);
      relayState = true;  
  }
  else if(sensorState == 0 && relayState == true){
      
      checkState();
      Serial.println("Waiting...");
//      delay(4000);
      if(sensorState == 0){
        digitalWrite(relayPin, HIGH);
        }
      else{
        digitalWrite(relayPin, LOW);
        }
    }
  else{
      digitalWrite(relayPin, HIGH);
      }
  Serial.println(sensorState);
  delay(1000);
}

void checkState(){
  int sensorValue = digitalRead(sensorPin);
  if(sensorValue == 1){
    sensorState =1;
  }
  else{
    sensorState = 0;
  }
  return sensorState;
  
}
