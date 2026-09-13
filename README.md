<img width="1280" height="640" alt="git (1)" src="https://github.com/user-attachments/assets/8920b256-2ba8-4988-b824-5351134eb4bd" />


# The Unapproachable Trash Can 🎯

## Basic Details

### Team Name: 404:Purpose Not found

### Team Members

* Member: Ajil Reji - Saintgits College of Engineering
* Member: Bhagath C R - Saintgits College of Engineering

### Project Description

An autonomous, passive-aggressive mobile trash can that actively refuses to do its job. Built using an ESP32, dual ultrasonic sensors, an L298N driver, and a 2WD chassis, it detects approaching humans and runs in the opposite direction, stopping only when completely cornered.

### The Problem (that doesn't exist)

Standard smart dustbins make waste disposal entirely too effortless, convenient, and boring by politely staying in place and opening their lids on command.

### The Solution (that nobody asked for)

We inverted the entire human-robot interaction paradigm: when you approach from the front, it reverses away; when you sneak up from behind, it dashes forward. If boxed in simultaneously from both sides, it enters an existential emergency-stop state.

## Technical Details

### Technologies/Components Used

For Software:

* C/C++
* ESP32 Arduino Core
* Arduino IDE
* Git / GitHub

For Hardware:

* 1× ESP32 Development Board (Main controller)
* 2× HC-SR04 Ultrasonic Sensors (Front/rear dynamic distance sensing)
* 1× L298N Dual H-Bridge Motor Driver Module
* 2× TT Geared DC Motors with Wheels (2WD differential drive)
* 1× 2WD Robot Chassis with Caster Wheel
* 1× 2S 18650 Li-ion Battery Pack (7.4 V nominal, 8.4 V peak)
* 1× SPST Rocker/Toggle Switch
* 1× 470 µF Electrolytic Capacitor (Motor decoupling)
* 2× 1 kΩ Resistors (ECHO voltage divider upper leg)
* 2× 2.2 kΩ Resistors (ECHO voltage divider lower leg to scale 5 V to ~3.4 V)
* 1× Mini Breadboard & Jumper Wires
* 1× Lightweight Plastic Trash Can Container

**Hardware Specifications & Thresholds:**

* Detection Trigger Distance: 40 cm
* Anti-Jitter Deadband: 3 cm
* Emergency / Pinch Zone: ~18 cm
* Logic Level: 3.3 V CMOS (Protected via resistor divider on GPIO 34 & 35)

### Implementation

For Software:

# Installation

```bash
# Clone the repository
git clone https://github.com/your-username/Useless-Project-3.0.git
cd Useless-Project-3.0

# Install ESP32 Board Support in Arduino IDE:
# Preferences -> Additional Board Manager URLs -> Add:
# https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json

```

# Run

```bash
# 1. Open src/useless_project_3.0.ino in Arduino IDE
# 2. Select Board: "ESP32 Dev Module"
# 3. Select your serial port
# 4. Press "Upload"

```

### Project Documentation

For Software:
### Project Demo
# Video

*Video demonstration covering: (1) Stationary idle state, (2) Rear avoidance maneuver, (3) Front escape drive, and (4) Pinch-zone emergency stop*

## Team Contributions

* Ajil Reji: Embedded firmware development, 2WD chassis mechanical assembly, motor control algorithms, and power distribution wiring.
* Bhagath C R: Firmware architecture, ESP32 dual ultrasonic sensor integration, voltage divider protection circuits, and state machine tuning.

---

Made with ❤️ at TinkerHub Useless Projects
![Static Badge](https://img.shields.io/badge/TinkerHub-24?color=%23000000&link=https%3A%2F%2Fwww.tinkerhub.org%2F)
![Static Badge](https://img.shields.io/badge/UselessProjects--26-26?link=https%3A%2F%2Ftinkerhub.org%2Fevents%2F1M8ORET9A1%2Fuseless-projects-3.0)



