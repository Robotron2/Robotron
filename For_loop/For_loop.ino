int yellowPin = 6;
int redPin = 9;
int delayTime = 750;

void setup() {
  // put your setup code here, to run once:
  pinMode(yellowPin, OUTPUT);  
  pinMode(redPin, OUTPUT);  

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(yellowPin, HIGH);
  delay(delayTime);
  digitalWrite(yellowPin, LOW);
  delay(delayTime);
  digitalWrite(yellowPin, HIGH);
  delay(delayTime);
  digitalWrite(yellowPin, LOW);
  delay(delayTime);
  digitalWrite(yellowPin, HIGH);
  delay(delayTime);
  digitalWrite(yellowPin, LOW);
  delay(delayTime);

  digitalWrite(redPin, HIGH);
  delay(delayTime);
  digitalWrite(redPin, LOW);
  delay(delayTime);
  digitalWrite(redPin, HIGH);
  delay(delayTime);
  digitalWrite(redPin, LOW);
  delay(delayTime);
  digitalWrite(redPin, HIGH);
  delay(delayTime);
  digitalWrite(redPin, LOW);
  delay(delayTime);
  digitalWrite(redPin, HIGH);
  delay(delayTime);
  digitalWrite(redPin, LOW);
  delay(delayTime);
  digitalWrite(redPin, HIGH);
  delay(delayTime);
  digitalWrite(redPin, LOW);
  delay(delayTime);



}
