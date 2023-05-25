int analogPin = A2;
float readVal;
float varVoltageOut;
int waitTime = 750;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(analogPin);
  varVoltageOut = (5./1023.)* readVal;
  Serial.print("V-out = ");
  Serial.print( varVoltageOut);
  Serial.print(" volt");
  Serial.println("");
  delay(waitTime);
  

}
