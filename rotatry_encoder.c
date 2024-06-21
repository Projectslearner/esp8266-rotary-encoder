/*
    Project name : ESP8266 Rotary Encoder
    Modified Date: 20-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/esp8266-rotary-encoder
*/

// Define the GPIO pins connected to the rotary encoder
const int encoderPinA = D5;  // Encoder A pin
const int encoderPinB = D6;  // Encoder B pin

volatile int encoderPos = 0;  // Current position of the encoder
int lastEncoderA = LOW;       // Previous state of encoder A pin

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  pinMode(encoderPinA, INPUT_PULLUP);  // Set encoder A pin as input with internal pull-up resistor
  pinMode(encoderPinB, INPUT_PULLUP);  // Set encoder B pin as input with internal pull-up resistor

  attachInterrupt(digitalPinToInterrupt(encoderPinA), updateEncoder, CHANGE);  // Attach interrupt to encoder A pin
}

void loop() {
  // Check if the encoder position has changed
  if (encoderPos != 0) {
    Serial.print("Encoder Position: ");
    Serial.println(encoderPos);
    encoderPos = 0;  // Reset encoder position after printing
  }
}

void updateEncoder() {
  int currentEncoderA = digitalRead(encoderPinA);  // Read the current state of encoder A pin

  // Check if the encoder A pin has changed state
  if (currentEncoderA != lastEncoderA) {
    // Check the state of encoder B pin to determine direction
    if (digitalRead(encoderPinB) != currentEncoderA) {
      encoderPos++;
    } else {
      encoderPos--;
    }
    lastEncoderA = currentEncoderA;  // Update lastEncoderA with current state
  }
}
