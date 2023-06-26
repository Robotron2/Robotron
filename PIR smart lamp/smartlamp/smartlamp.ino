//PIR

int relayPin = 13;               // choose the pin for the relay
int inputPin = 8;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
 
void setup() {
  pinMode(relayPin, OUTPUT);      // declare relay as output
  pinMode(inputPin, INPUT);     // declare sensor as input
 
  Serial.begin(9600);
}
 
void loop(){
  val = digitalRead(inputPin);  // read input value
  
  if (val == HIGH)	// check if the input is HIGH
  {            
    digitalWrite(relayPin, HIGH);  // turn on the relay which in turn turns on the light.
	
    if (pirState == LOW) 
	{
      Serial.println("Motion detected!");	// print on output change
      pirState = HIGH;
    }
  } 
  else 
  {
    digitalWrite(relayPin, LOW); // turn the relay off, and the light goes off.
	
    if (pirState == HIGH)
	{
      Serial.println("Motion ended!");	// print on output change
      pirState = LOW;
    }
  }
}