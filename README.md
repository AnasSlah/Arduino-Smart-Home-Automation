Smart Home Automation & Safety System 🏠⚡

📌 Project Overview
This project is an integrated system based on the Arduino Uno microcontroller, designed to provide smart solutions for home automation and ensure environmental safety. The system combines motion sensing for automatic control of lighting, and air quality monitoring with gas leak detection to proactively operate ventilation systems. It also features real-time system status and data display via an LCD screen. The entire circuit was designed and simulated using the Tinkercad platform.

⚙️ Hardware Components
Arduino Uno: The central microcontroller that manages the system's logic.

Gas Sensor: Detects any gas leaks or smoke in the surrounding environment.

PIR Motion Sensor: Detects the presence of people within its range.

LCD Display (16x2): Provides a user interface to display alerts and real-time sensor readings.

Servo Motor: Represents smart motion mechanisms (e.g., smart door locks or automatic window opening for ventilation).

Relay Modules: Used to separate and isolate low-voltage control circuits from high-voltage loads.

DC Motor: Acts as an exhaust fan for ventilation.

Light Bulb: Represents the home lighting system.

✨ Key Features & Mechanism
Emergency Response System (Gas Leak Protection):
Upon detecting abnormal levels of gas or smoke, the microcontroller sends a signal to the relay to automatically turn on the exhaust fan (DC Motor). It also displays an immediate warning message on the LCD screen and commands the servo motor to open ventilation outlets.

Smart Lighting & Automation:
The PIR sensor detects surrounding motion. When a person's entry is detected, the second relay is activated to turn on the light bulb, saving energy, and the system status is instantly updated on the screen.

Real-time Monitoring:
The system continuously updates data on the LCD screen to ensure the user stays informed about the surrounding environment's status (e.g., safe status, motion detected, or hazard alert).

🛠️ Technologies Used
C++ (Arduino IDE)

Tinkercad (Simulation & Circuit Design)

Embedded Systems Logic


<img width="1208" height="657" alt="image" src="https://github.com/user-attachments/assets/90e51b6b-360f-4c75-93fa-fa65d6c0d994" />

<img width="940" height="696" alt="{0E9E8CA3-633D-4122-82CF-DD5BC80C8D77}" src="https://github.com/user-attachments/assets/88e12a28-224d-4d7e-81d8-15087e411b92" />

<img width="1393" height="584" alt="{5ABD1075-8CC1-4288-872A-2EACCC07D5B5}" src="https://github.com/user-attachments/assets/6dea8169-3823-4c1f-9513-041a092e5182" />
