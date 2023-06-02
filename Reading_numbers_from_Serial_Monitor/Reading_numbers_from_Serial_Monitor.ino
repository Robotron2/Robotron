int numBlinks;
int j;
int redPin = 9;
int blinkTime = 500;
String msg = "How many blinks do you want? ";
String msg2 = "Your number is: ";


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg);
  while (Serial.available()==0) {

  }
  numBlinks = Serial.parseInt();
  for (j=1; j<= numBlinks; j++) {
    digitalWrite(redPin, HIGH);
    delay(blinkTime);
    digitalWrite(redPin, LOW);
    delay(blinkTime);

  }
  
}
