//일정량 이상의 빛에 반응하는 스피커

#include "pitches.h"
int notes[] = {NOTE_C4, NOTE_D4, NOTE_G4};

const int light = A0;
const int speaker = 13;

int sensorValue = 0;

void setup(){
  pinMode(speaker, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  sensorValue = analogRead(light);
  Serial.println(sensorValue);
  
  if(sensorValue>250){
    tone(13, notes[1], 20);
    digitalWrite(4, HIGH);
  }
  else{
    digitalWrite(4,LOW);
  }
    delay(2);
}
