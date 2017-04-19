// zoomkat 7-30-11 serial I/O string test
// type a string in serial monitor. then send or enter
// for IDE 0019 and later

#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pin
#define LEDPin 13 // Onboard LED

int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
}

// the loop function runs over and over again forever
void loop() {
  /*
  digitalWrite(LEDPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LEDPin, LOW);    // turn the LED off by making the voltage LOW
  delay(3000);                       // wait for a second
  */
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance (in cm) based on the speed of sound.
  distance = duration/58.2;
  
  if (distance >= maximumRange || distance <= minimumRange){
//    Serial.println("-1");
    Serial.println(distance);
//    digitalWrite(LEDPin, HIGH); 
  } else{
    Serial.println(distance);
//    digitalWrite(LEDPin, LOW); 
  }
  
  // Delay 50ms before next reading.
  delay(50);
}
