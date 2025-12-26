# 🌱 Smart IoT Agriculture & Water Monitoring System (ESP32 + Blynk)

This project is an **ESP32-based IoT monitoring and control system** using **Blynk Cloud**.  
It monitors **environmental and water-related parameters** such as **temperature, humidity, soil moisture, water level, and pressure**, and allows **remote control of a water pump** through the **Blynk mobile application**.

---

## 🚀 Features
- 🌡️ Temperature & humidity monitoring (DHT11 / DHT22)
- 🌱 Soil moisture level monitoring
- 💧 Water level monitoring
- ⚙️ Pressure sensor monitoring
- 📱 Real-time sensor data on Blynk app
- 🚰 Remote water pump control using relay
- 🌐 WiFi-based IoT connectivity
- ⏱️ Periodic data updates using BlynkTimer

---

## 🛠️ Hardware Components
- ESP32 Development Board  
- DHT11 / DHT22 Sensor  
- Soil Moisture Sensor  
- Water Level Sensor  
- Pressure Sensor  
- Relay Module  
- Water Pump / Solenoid Valve  
- Power Supply  
- Jumper Wires & Breadboard  

---

## 💻 Software & Tools
- Arduino IDE  
- ESP32 Board Package  
- Blynk IoT Platform (Cloud + Mobile App)  
- Arduino Framework (C/C++)  

---

## ⚙️ Pin Configuration
| Component | ESP32 Pin |
|--------|----------|
| DHT Sensor | GPIO 21 |
| Soil Moisture Sensor | GPIO 34 |
| Water Level Sensor | GPIO 35 |
| Pressure Sensor | GPIO 32 |
| Pump Relay | GPIO 25 / GPIO 26 |

---

## 📱 Blynk Virtual Pins
| Virtual Pin | Function |
|-----------|---------|
| V0 | Temperature |
| V1 | Humidity |
| V2 | Pressure |
| V3 | Soil Moisture |
| V5 | Water Level |
| V6 | Pump ON / OFF |

---

## 🔄 Working Principle
1. ESP32 reads sensor data periodically.
2. Data is sent to **Blynk Cloud** via WiFi.
3. Sensor readings are displayed in real time on the **Blynk app**.
4. User controls the pump remotely using a virtual switch.
5. Relay switches the pump ON or OFF accordingly.

---

## 📁 Project Structure
