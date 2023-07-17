int pirPin = 8;   
int relayPin = 9;
int relayState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pirPin, INPUT);
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);  /* Define baud rate for serial communication */
  delay(600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
 Serial.println(relayState);
 checkState();
 while(relayState == 1){
  digitalWrite(relayPin, LOW);
  checkState();
 }
  
  if(relayState == 0){
    delay(1000);
    digitalWrite(relayPin, HIGH); 
  }
  
  else{
    checkState();
  }
  
}

void checkState(){
  int sensorOutput = digitalRead(pirPin);
  if(sensorOutput == 1){
    relayState = 1;
  }
  else if(sensorOutput == 0 && relayState == 1){
    relayState = 0;
    delay(1000);
  }
  else if(sensorOutput == 0){
    relayState = 0;
  }
  Serial.print("Sensor Output: ");
  Serial.println(sensorOutput);
 
}
