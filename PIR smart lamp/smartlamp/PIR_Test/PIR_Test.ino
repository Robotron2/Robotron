int pirPin = 8;   
int ledPin = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);  /* Define baud rate for serial communication */
}

void loop() {
  // put your main code here, to run repeatedly:
   int sensor_output;
   sensor_output = digitalRead(pirPin);
   
   Serial.print("Sensor Output: ");
   Serial.println(sensor_output);
   if(sensor_output == 0){
      delay(2000);
      digitalWrite(ledPin, LOW);
      Serial.println("LED off!!");
   }
      
   if(sensor_output == 1){
    digitalWrite(ledPin, HIGH);
    Serial.println("LED on!!");
    
   }
   delay(1000);
   
}
