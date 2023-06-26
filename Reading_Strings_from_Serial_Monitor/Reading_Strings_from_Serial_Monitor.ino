int redPin =7;
int yellowPin = 8;
int bluePin = 9;
int delayTime = 500;
String myColor;
String msg = "What LED should come on? ";


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg);
  while (Serial.available() == 0) {
  
  }
  myColor = Serial.readString();
  // Serial.println(typeof(Serial.readString()));
  // delay(delayTime);
  if (myColor == red) {
    
    digitalWrite(redPin,HIGH);
    digitalWrite(yellowPin, LOW);
    digitalWrite(bluePin, LOW);
  }
  


  


}
