# Hardware Connection Guide

## ESP32 Pin Configuration

| Component | ESP32 Pin | Purpose |
|-----------|-----------|---------|
| WiFi LED | GPIO2 | Status indicator |
| I2C SDA | GPIO21 | Blynk communication |
| I2C SCL | GPIO22 | Blynk communication |

## Arduino Uno Pin Configuration

| Component | Arduino Pin | Purpose |
|-----------|------------|---------|
| Ultrasonic Trigger | Pin 5 | Send pulse |
| Ultrasonic Echo | Pin 6 | Receive pulse |
| Servo Control | Pin 9 | Door servo |
| LED Red | Pin 10 | Color control |
| LED Green | Pin 11 | Color control |
| LED Blue | Pin 12 | Color control |

## Breadboard Connections

1. Power bus: 5V from Arduino
2. Ground bus: GND from Arduino
3. Ultrasonic sensor:
   - VCC → 5V
   - GND → GND
   - TRIG → Pin 5
   - ECHO → Pin 6
4. Servo motor:
   - VCC → 5V
   - GND → GND
   - Signal → Pin 9
5. RGB LED:
   - Common → GND
   - Red pin → Pin 10 (through 330Ω resistor)
   - Green pin → Pin 11 (through 330Ω resistor)
   - Blue pin → Pin 12 (through 330Ω resistor)
