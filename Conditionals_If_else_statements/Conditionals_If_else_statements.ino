int analogPin = A2;
int warningLed = 9;
int safeLed = 10;
float readVal;
float varVoltageOut;
int waitTime = 200;


void setup() {
  // put your setup code here, to run once:
  pinMode(analogPin, INPUT);
  pinMode(warningLed,OUTPUT);
  pinMode(safeLed,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(analogPin);
  varVoltageOut = (5./1023.)* readVal;


  if (varVoltageOut >= 4.10) {
    digitalWrite(safeLed, HIGH);
    digitalWrite(warningLed, HIGH);
    delay(waitTime);
    digitalWrite(warningLed, LOW);
    digitalWrite(safeLed, LOW);
    delay(waitTime);
    
  }
  else if (varVoltageOut <= 4.00) {
    digitalWrite(safeLed, HIGH);
  }
   Serial.print("V-out = ");
  Serial.print( varVoltageOut);
  Serial.print(" volt");
  Serial.println("");
  delay(waitTime);

}
