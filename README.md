# Infant Incubator Project

## Overview
This project involves the creation of a model infant incubator that provides real-time monitoring of temperature, humidity, and heart rate. The system is equipped with alarms for under-temperature conditions and procedures to reset the temperature to the desired level. Additionally, a color sensor is included to detect symptoms of jaundice in infants.

## Materials Used
1. **Arduino Board**
   - Acts as the central controller, managing the various sensors and actuators.

2. **DHT Sensor (DHT11 )**
   - Measures the temperature and humidity within the incubator.

3. **Pulse Sensor**
   - Monitors the infant's heart rate.

4. **Color Sensor (TCS3200 or TCS2300)**
   - Detects jaundice symptoms by analyzing the skin color of the infant. Triggers an alarm if severe jaundice is detected.

5. **Liquid Crystal Display (LCD)**
   - Displays temperature, humidity, and heart rate readings.

6. **Relay Module**
   - Controls a heating element (e.g., a yellow heat lamp) to adjust the temperature if it falls below the desired level.

## Features
- **Real-time Monitoring:**
  - Continuously measures and displays temperature, humidity, and heart rate.
- **Temperature Control:**
  - Automatically activates a heating element if the temperature drops below a preset threshold.
  - Deactivates the heating element once the temperature returns to the desired level.
- **Jaundice Detection:**
  - Uses a color sensor to detect symptoms of jaundice and triggers an alarm if necessary.
- **Alarms:**
  - Alerts users in case of under-temperature or severe jaundice.

## Setup and Installation
1. **Hardware Setup:**
   - Connect the DHT sensor to the Arduino for temperature and humidity readings.
   - Attach the pulse sensor to the Arduino for heart rate monitoring.
   - Mount the color sensor inside the incubator and connect it to the Arduino.
   - Connect the LCD to the Arduino for displaying sensor readings.
   - Set up the relay module to control the heating element.

2. **Software Setup:**
   - Install the Arduino IDE on your computer.
   - Install necessary libraries for the sensors (e.g., `DHT`, `PulseSensorPlayground`, `TCS3200`).
   - Upload the provided Arduino sketch to the Arduino board.


## Usage Instructions
1. **Power On:**
   - Ensure the Arduino and all connected components are properly powered.
2. **Monitor Readings:**
   - Observe the temperature, humidity, and heart rate on the LCD display.
3. **Respond to Alarms:**
   - If an alarm sounds due to under-temperature or jaundice detection, take appropriate action as guided by the system.
4. **Adjust Settings:**
   - Modify the `TEMPERATURE_THRESHOLD` in the Arduino sketch as needed to suit specific requirements.

## Troubleshooting
- **No Readings on LCD:**
  - Check all connections and ensure the LCD is properly initialized in the code.
- **Sensors Not Working:**
  - Verify the correct pins and libraries are used in the Arduino sketch.
- **Heating Element Not Activating:**
  - Ensure the relay module is connected and functioning correctly.

