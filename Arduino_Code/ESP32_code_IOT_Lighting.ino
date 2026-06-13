
#define BLYNK_TEMPLATE_ID   "......"
#define BLYNK_TEMPLATE_NAME "........"               
#define BLYNK_AUTH_TOKEN    ".........."
#define RED_PIN   15 
#define GREEN_PIN 2
#define BLUE_PIN  19

#include <WiFi.h>             
#include <BlynkSimpleEsp32.h>    
char auth[] = BLYNK_AUTH_TOKEN; char ssid[] = "......."; char pass[] = ".......";

void setup() {
  pinMode(RED_PIN, OUTPUT); pinMode(GREEN_PIN, OUTPUT); pinMode(BLUE_PIN, OUTPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
}

BLYNK_WRITE(V0) {
  int r = param.asInt();
  analogWrite(RED_PIN, r);
}

BLYNK_WRITE(V1) {
  int g = param.asInt();
  analogWrite(GREEN_PIN, g);
}

BLYNK_WRITE(V2) {
  int b = param.asInt();
  analogWrite(BLUE_PIN, b);
}
