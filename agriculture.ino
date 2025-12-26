
#define BLYNK_PRINT Serial
#include <WiFi.h>  // ESP32 uses WiFi.h
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

char auth[] = "hf59Q6b2pVoOgjYw7fvbh4cLgoTnB_2H";
char ssid[] = "Internet";
char pass[] = "bIGBOOTY28";

#define DHTPIN 21        // GPIO for DHT sensor (adjust if needed)
#define DHTTYPE DHT11     // Change to DHT22 if needed
DHT dht(DHTPIN, DHTTYPE);

#define SOIL_MOISTURE_PIN 34
#define WATER_LEVEL_PIN 35
#define PRESSURE_SENSOR_PIN 32
#define PUMP_RELAY_PIN 25  // Relay for water pump

BlynkTimer timer;

void sendSensorData() {
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();
    int soilMoisture = analogRead(SOIL_MOISTURE_PIN);
    int waterLevel = analogRead(WATER_LEVEL_PIN);
    int pressure = analogRead(PRESSURE_SENSOR_PIN);

    if (isnan(temperature) || isnan(humidity)) {
        Serial.println("Failed to read DHT sensor!");
        return;
    }

    Blynk.virtualWrite(V0, temperature);
    Blynk.virtualWrite(V1, humidity);
    Blynk.virtualWrite(V2, map(pressure, 0, 4095, 900, 1100));
    Blynk.virtualWrite(V3, map(soilMoisture, 0, 4095, 0, 100));
    Blynk.virtualWrite(V5, map(waterLevel, 0, 4095, 0, 100));

    Serial.print("Temp: "); Serial.print(temperature);
    Serial.print(" | Humidity: "); Serial.print(humidity);
    Serial.print(" | Pressure: "); Serial.print(pressure);
    Serial.print(" | Soil Moisture: "); Serial.print(soilMoisture);
    Serial.print(" | Water Level: "); Serial.println(waterLevel);
}

// Control the pump via Blynk switch
BLYNK_WRITE(V6) {
    int pumpState = param.asInt();
    digitalWrite(PUMP_RELAY_PIN, pumpState);
    Serial.println(pumpState ? "Pump ON" : "Pump OFF");
}

void setup() {
    Serial.begin(115200);
    Blynk.begin(auth, ssid, pass);
    pinMode(PUMP_RELAY_PIN, OUTPUT);
    digitalWrite(PUMP_RELAY_PIN, LOW);
    dht.begin();

    timer.setInterval(2000L, sendSensorData);
}

void loop() {
    Blynk.run();
    timer.run();
}





// Required for Blynk 2.0 (Copy these from Blynk Cloud)
#define BLYNK_TEMPLATE_ID "Your_Template_ID"
#define BLYNK_TEMPLATE_NAME "Your_Project_Name"

#define BLYNK_PRINT Serial  // Enable serial debug

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "YOUR_BLYNK_AUTH_TOKEN";  // From Blynk Device Info
char ssid[] = "YOUR_WIFI_SSID";         // Your WiFi SSID
char pass[] = "YOUR_WIFI_PASSWORD";     // Your WiFi Password

#define SENSOR_PIN 34  // Analog pin for sensor (e.g., voltage, current)
#define RELAY_PIN  26  // Digital pin for relay or any output

BlynkTimer timer;  // Timer for sending data to Blynk

// Function to read sensor data and send it to Blynk
void sendSensorData() {
    int sensorValue = analogRead(SENSOR_PIN);  // Read sensor
    float voltage = (sensorValue / 4095.0) * 3.3;  // Convert to voltage (ESP32 uses 12-bit ADC)

    Serial.print("Sensor Value: ");
    Serial.println(sensorValue);
    
    Serial.print("Voltage: ");
    Serial.println(voltage);

    Blynk.virtualWrite(V0, voltage);  // Update gauge widget on V0
}

// Function to control relay via Blynk switch
BLYNK_WRITE(V1) {
    int switchState = param.asInt();  // Read switch state from app (1 = ON, 0 = OFF)
    digitalWrite(RELAY_PIN, switchState);  // Set relay state
    Serial.print("Relay State: ");
    Serial.println(switchState);
}

void setup() {
    Serial.begin(115200);
    pinMode(SENSOR_PIN, INPUT);
    pinMode(RELAY_PIN, OUTPUT);

    Blynk.begin(auth, ssid, pass);
    
    // Call sendSensorData() every 1 second
    timer.setInterval(1000L, sendSensorData);
}

void loop() {
    Blynk.run();
    timer.run();
}

