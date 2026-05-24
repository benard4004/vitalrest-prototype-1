#include <Wire.h>
#include <AccelAndGyro.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);
AccelAndGyro mpu;

#define BUZZER_PIN 4
float sensitivity = 2200.0;
unsigned long alarmTime = 5000;

float oldZ = 0.0;
unsigned long lastMove = 0;

void setup() {
  Wire.begin();
  pinMode(BUZZER_PIN, OUTPUT);
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while(1); 
     digitalWrite(BUZZER_PIN, LOW);
  }

  mpu.begin();
  lastMove = millis();
  
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  float currentZ = mpu.getAccelZ();
  float difference = abs(currentZ - oldZ);
  oldZ = currentZ;

  if (difference > sensitivity) {
    lastMove = millis();
  }

  unsigned long timeSinceLastMove = millis() - lastMove;


  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(35, 0);
  display.print("VITALREST");

  if (timeSinceLastMove > alarmTime) {
    display.setTextSize(2);
    display.setCursor(15, 25);
    display.print("! APNEA !");
    

    digitalWrite(BUZZER_PIN, HIGH); 
  } else {
    digitalWrite(BUZZER_PIN, LOW);
    display.setTextSize(1);
    display.setCursor(0, 25);
    display.print("Status: Monitoring");
    
    int bar = map(timeSinceLastMove, 0, alarmTime, 128, 0);
    display.fillRect(0, 40, constrain(bar, 0, 128), 8, SSD1306_WHITE);
  }


  display.setTextSize(1);
  display.setCursor(0, 55);
  display.print("No Breath: ");
  display.print(timeSinceLastMove / 1000);
  display.print("s");
  
  display.display(); 
  
  delay(100); 
}