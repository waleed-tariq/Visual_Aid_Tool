#include <NewPing.h>
#define TRIGGER_PIN 11
#define ECHO_PIN 12
#define MAX_DISTANCE 5000

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

#include <Servo.h>

const int trigPin = 11;
const int echoPin = 12;

long duration;
long distance;

// Declare the Servo pin 
int servo1Pin = 3; 
// Create a servo object 
Servo Servo1; 

// Declare the Servo pin 
int servo2Pin = 5; 
// Create a servo object 
Servo Servo2; 

// Declare the Servo pin 
int servo3Pin = 6; 
// Create a servo object 
Servo Servo3; 

void setup() {
  // put your setup code here, to run once:

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Servo1.attach(servo1Pin);
  Servo2.attach(servo2Pin);
  Servo3.attach(servo3Pin);
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:

  delay(50);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  Serial.print("Ping: ");
  int distance = sonar.convert_cm(uS);
  Serial.print(distance); // Convert ping time to distance and print result (0 = outside set distance range, no ping echo)
  Serial.println("cm");


  if (distance <= 15 && distance > 0){
      Servo1.write(180);
      Servo2.write(180);
      Servo3.write(180);
  }
    else if (distance > 15 && distance <= 30){
    Servo1.write(180);
    Servo2.write(180);
    Servo3.write(1);
    
  }
  else if (distance > 30 && distance <= 45) {
    Servo1.write(180);
    Servo2.write(1);
    Servo3.write(1);
  }
  else {
    Servo1.write(1);
    Servo2.write(1);
    Servo3.write(1);
  }
 


}
