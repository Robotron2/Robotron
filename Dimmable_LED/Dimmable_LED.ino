int potPIN = A0;
int ledPIN = 5;
int potVal;
float ledVal;

void setup() {
  // put your setup code here, to run once:
  pinMode(potPIN, INPUT);
  pinMode(ledPIN, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPIN);
  ledVal = (255./1023.)*potVal;
  analogWrite(ledPIN, ledVal);
  Serial.println(ledVal);

}
