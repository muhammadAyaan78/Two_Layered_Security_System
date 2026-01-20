#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_TEMPLATE_NAME "SafeSecurity"
#define BLYNK_AUTH_TOKEN "YourAuthToken"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YourWiFiSSID";         // Replace with your WiFi
char pass[] = "YourWiFiPassword";     // Replace with your password

const int pirPin = 14;          // PIR sensor pin (GPIO14)
const int vibrationPin = 27;    // Vibration sensor pin (GPIO27)
const int buzzerPin = 26;       // Buzzer pin (GPIO26)

bool motionDetected = false;
bool vibrationDetected = false;

unsigned long vibrationStartTime = 0;
unsigned long intrusionDuration = 0;

BlynkTimer timer;

void setup() {
  Serial.begin(115200);

  pinMode(pirPin, INPUT);
  pinMode(vibrationPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L, updateIntrusionTime); // Call every 1s
}

void loop() {
  Blynk.run();
  timer.run();

  int pirState = digitalRead(pirPin);
  int vibState = digitalRead(vibrationPin);

  // Handle PIR motion
  if (pirState == HIGH && !motionDetected) {
    motionDetected = true;
    digitalWrite(buzzerPin, HIGH);
    delay(2000);
    digitalWrite(buzzerPin, LOW);
    Blynk.logEvent("motion_detected", "⚠️ Someone is near the safe!");
    delay(10000);  // Debounce
  } else if (pirState == LOW) {
    motionDetected = false;
  }

  // Handle Vibration
  if (vibState == HIGH && !vibrationDetected) {
    vibrationDetected = true;
    vibrationStartTime = millis();
    Blynk.logEvent("break_in", "🚨 Break-in detected!");
  }

  if (vibState == LOW && vibrationDetected) {
    vibrationDetected = false;
    intrusionDuration = 0;
    Blynk.virtualWrite(V1, intrusionDuration);  // Reset timer
  }
}

void updateIntrusionTime() {
  if (vibrationDetected) {
    intrusionDuration = (millis() - vibrationStartTime) / 1000;
    Blynk.virtualWrite(V1, intrusionDuration);
  }
}
