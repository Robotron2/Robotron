int yellowPin = 6;
int redPin = 9;
int yellowTime = 500;
int redTime = 500;
int yellowBlink = 3;
int redBlink = 5;
int j;

void setup() {
  // put your setup code here, to run once:
  pinMode(yellowPin, OUTPUT);  
  pinMode(redPin, OUTPUT);  
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (j = 10; j>=1; j--) {
    Serial.println(j);
  }
  Serial.println();
}
