# ESP8266 Rotary Encoder Project

#### Project Overview
This project demonstrates how to interface a rotary encoder with an ESP8266 microcontroller to detect rotational movements and determine the direction of rotation. Rotary encoders are widely used in various applications where precise positional information or user input is required.

#### Components Needed
- **ESP8266 Microcontroller**
- **Rotary Encoder**
- **Jumper Wires**

#### Block diagram


#### Circuit Setup
1. **Connecting the Rotary Encoder to ESP8266:**
   - Connect the CLK (Clock) pin of the rotary encoder to GPIO pin D5 on the ESP8266.
   - Connect the DT (Data) pin of the rotary encoder to GPIO pin D6 on the ESP8266.
   - Connect the SW (Switch) pin of the rotary encoder to ground.
   - Ensure a common ground (GND) connection between the ESP8266 and the rotary encoder.

#### Instructions
1. **Setup:**
   - Initialize serial communication at a baud rate of 9600 for debugging purposes.
   - Configure both encoder pins (D5 and D6) as inputs with internal pull-up resistors using `pinMode()`.
   - Attach an interrupt to the CLK pin (D5) using `attachInterrupt()` to detect changes in encoder position.

2. **Operation:**
   - In the `loop()` function:
     - Check if the encoder position (`encoderPos`) has changed since the last check.
     - If there is a change, determine the direction of rotation based on the state of the DT pin (D6) relative to the CLK pin (D5).
     - Print the current encoder position to the Serial Monitor whenever it changes.

3. **Interrupt Service Routine (`updateEncoder()`):**
   - This function is triggered whenever there is a change in the CLK pin (D5).
   - Read the current state of the CLK pin and compare it with the previous state (`lastEncoderA`).
   - Depending on the state of the DT pin (D6), increment or decrement the `encoderPos` variable to track the encoder position.
   - Update `lastEncoderA` with the current state for the next comparison.

#### Applications
- **User Input Devices:** Adjust settings or values (e.g., volume control, menu navigation).
- **Rotational Position Sensing:** Monitor position changes in mechanical systems.
- **Incremental Measurement:** Counting events or steps based on rotational movement.

#### Notes
- **Interrupt Usage:** Using interrupts allows precise detection of encoder movements without polling.
- **Debouncing:** Mechanical encoders may require debouncing techniques to ensure accurate readings.
- **Serial Output:** Use the Serial Monitor to observe changes in encoder position and direction.

---

#### Useful Links
🌐 [ProjectsLearner - ESP8266 Rotary Encoder](https://projectslearner.com/learn/esp8266-rotary-encoder)  
📧 [Email](mailto:projectslearner@gmail.com)  
📸 [Instagram](https://www.instagram.com/projectslearner/)  
📘 [Facebook](https://www.facebook.com/projectslearner)  
▶️ [YouTube](https://www.youtube.com/@ProjectsLearner)  
📘 [LinkedIn](https://www.linkedin.com/in/projectslearner)

Created with ❤️ by ProjectsLearner