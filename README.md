# Two_Layered_Security_System
A cost-effective IoT-based intrusion detection system built using ESP32 and Blynk IoT, designed to reduce false alarms through dual-sensor verification. The system detects unauthorized access using motion and vibration sensing, triggers local alerts, and sends real-time notifications with timestamped logs to a cloud dashboard.

 Project Overview

This project implements a two-layered security logic where an intrusion is confirmed only when both motion (PIR) and vibration (SW-420) sensors are triggered. This layered approach significantly improves reliability compared to single-sensor systems.

Upon intrusion detection, the system:

Activates visual and audible alerts (RGB LED + buzzer)

Sends real-time push notifications via Blynk

Logs intrusion events with accurate timestamps using NTP

 Technologies & Components

Microcontroller: ESP32 Dev Kit

Sensors: PIR Motion Sensor (HC-SR501), SW-420 Vibration Sensor

Actuators: RGB LED, Active Buzzer, Push Button

Cloud Platform: Blynk IoT (Mobile App & Web Dashboard)

Programming Language: Arduino C++

Connectivity: Wi-Fi (2.4 GHz)

 System Features

 Dual-sensor intrusion detection to minimize false positives

 Real-time mobile and web notifications

 Timestamped intrusion logs synced via NTP

 Visual status indication using RGB LEDs

 Audible alarm with manual override switch

 Remote monitoring and system reset via Blynk

 Detection Logic

Idle State: Green LED (System Ready)

Motion Only: Blue LED + presence notification

Motion + Vibration:

Red LED + buzzer

Intrusion alert notification

Timestamped log entry in Blynk

 Testing & Validation

Individual testing of sensors, Wi-Fi, and cloud communication

Full-stack integration testing (hardware + cloud)

Live dashboard verification for real-time responsiveness

 Future Enhancements

Camera module integration for image capture

Door reed switch for enhanced intrusion confirmation

Cloud logging using Firebase or Google Sheets

Voice alerts using DFPlayer Mini or TTS

Battery backup for power failure protection

 Use Cases

Home security systems

Small offices or shops

IoT learning and prototyping projects
