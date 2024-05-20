#include <NewPing.h>

#define TRIGGER_PIN 26   
#define ECHO_PIN 13
#define MAX_DISTANCE 200 

#define BUZZER_PIN 14
#define BUZZER_SHORT_DELAY 50 


#define DISTANCE_THRESHOLD_1 5    
#define DISTANCE_THRESHOLD_2 10   
#define DISTANCE_THRESHOLD_3 20   
#define DISTANCE_THRESHOLD_4 30   
#define DISTANCE_THRESHOLD_5 40   
#define DISTANCE_THRESHOLD_6 50   
#define DISTANCE_THRESHOLD_7 75   
#define DISTANCE_THRESHOLD_8 100  
#define DISTANCE_THRESHOLD_9 150  

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

void setup() {
  Serial.begin(115200); 
  pinMode(BUZZER_PIN, OUTPUT);
}


int calculateDelay(int distance) {
  if (distance < DISTANCE_THRESHOLD_1) {
    return BUZZER_SHORT_DELAY / 4;
  } else if (distance < DISTANCE_THRESHOLD_2) {
    return BUZZER_SHORT_DELAY / 2;
  } else if (distance < DISTANCE_THRESHOLD_3) {
    return BUZZER_SHORT_DELAY;
  } else if (distance < DISTANCE_THRESHOLD_4) {
    return BUZZER_SHORT_DELAY * 2;
  } else if (distance < DISTANCE_THRESHOLD_5) {
    return BUZZER_SHORT_DELAY * 3;
  } else if (distance < DISTANCE_THRESHOLD_6) {
    return BUZZER_SHORT_DELAY * 4;
  } else if (distance < DISTANCE_THRESHOLD_7) {
    return BUZZER_SHORT_DELAY * 5;
  } else if (distance < DISTANCE_THRESHOLD_8) {
    return BUZZER_SHORT_DELAY * 6;
  } else if (distance < DISTANCE_THRESHOLD_9) {
    return BUZZER_SHORT_DELAY * 8;
  } else {
    return BUZZER_SHORT_DELAY * 10; 
  }
}

void loop() {
  delay(50); 
  unsigned int distance = sonar.ping_cm(); 

  if (distance == 0) {
    Serial.println("Out of range");
  } else {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    
    int delayTime = calculateDelay(distance);
    tone(BUZZER_PIN, 220); 
    delay(delayTime);
    noTone(BUZZER_PIN); 
  }
}
