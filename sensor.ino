#define trigpin 10
#define echopin 13

float duration,distance;
 
void setup() {
Serial.begin (9600);
pinMode(trigpin, OUTPUT);
pinMode(echopin, INPUT);

}

void loop() {
// Write a pulse to the HC-SR04 triger pin
digitalWrite(trigpin, LOW);
delayMicroseconds(2);
digitalWrite(trigpin, HIGH);
delayMicroseconds(10);
digitalWrite(trigpin, LOW);
//Measure the response from the HC-SR04 Echo pin
duration = pulseIn (echopin, HIGH);
// Determine distance from duration
// Use 343 meters per second as speed of sound
distance = (duration / 2) * 0.0343;
// send results to serial Monitor
Serial.print("distance= ");
if (distance >= 400) { 
Serial.println("in range"); 
delay(500);
}
 else if (distance <= 2){
    Serial.println("out of range");
    delay(1000); 
  }

else{
Serial.print(distance);
Serial.println("cm");
delay(500);
}

}
