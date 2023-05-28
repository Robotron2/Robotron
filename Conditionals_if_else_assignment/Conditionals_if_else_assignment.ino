int delayTime = 250;
int redLED = 10;
int yellowLED = 9;
int blueLED = 8;
int analogPIN = A0;
int analogVal;
float Vout;


void setup() {
  // put your setup code here, to run once:
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogVal = analogRead(analogPIN);
  Vout = (5./1023.) * analogVal;
  Serial.println(Vout);
  delay(delayTime);
  
  if (Vout <= 3.0) {
    digitalWrite(blueLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
  }else if (Vout > 3 && Vout <= 4) {
    digitalWrite(blueLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);
  }else if (Vout > 4 && Vout < 4.49) {
    digitalWrite(blueLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);
  }else if (Vout > 4.49 ) {
    digitalWrite(blueLED, HIGH);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, HIGH);
    delay(delayTime - 50);
     digitalWrite(blueLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
  }

}
