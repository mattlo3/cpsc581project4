#include <Servo.h>

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin

const int ledPin =  13;      // the number of the LED pin

const int servoPin = 3;

Servo Servo1;
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  
  Servo1.attach(servoPin);
  Servo1.write(15);

  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  // Show the state of pushbutton on serial monitor
  Serial.println(buttonState);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, LOW);
    
    Servo1.write(75);
    delay(1500);
    Servo1.write(15);
    delay(5000);
  } else {
    // turn LED off:
    
    digitalWrite(ledPin, HIGH);
  }
  // Added the delay so that we can see the output of button
  // delay(100);
}
