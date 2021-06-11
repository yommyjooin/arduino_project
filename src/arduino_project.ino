//CH.2 Analog Input-Output, CH.3 2)Tilt Switch
#include "talkie.h"
#define interval 1500 // 15초간 대기
Talkie voice;
const uint8_t sp1[] PROGMEM = {0x00, 0x2d, 0x6e, 0x34, 0x24, 0xdd, 0xe2, 0x34, 0x15, 0xd5, 0xa8, 0x76, 0x56, 0xd2, 0x14, 0xf8, 0xd9, 0x22, 0xc8, 0xed, 0x92, 0xf1, 0x71, 0xb7, 0x42, 0x37, 0x4d, 0x81, 0xa3, 0xc2, 0x06, 0x5c, 0x2b, 0x03, 0xfc, 0x0e, 0x0f, 0x51, 0x32, 0x38, 0xee, 0x23, 0xbb, 0xd5, 0xd9, 0x61, 0x49, 0x89, 0xca, 0xe5, 0x74, 0x8b, 0x23, 0x25, 0xba, 0x4f, 0xdc, 0x05, 0x1e, 0xfc, 0x2a, 0x77, 0x49, 0x5a, 0x04, 0x94, 0x67, 0xbd, 0x24, 0xf1, 0x60, 0x99, 0xd9, 0x4f, 0x93, 0xc6, 0x87, 0x11, 0x6a, 0x2e, 0x55, 0x97, 0x2e, 0x8e, 0x84, 0x5b, 0x67, 0x9d, 0x5b, 0x78, 0xf0, 0xd7, 0x31, 0xa3, 0x6a, 0xe2, 0xc1, 0x0f, 0x96, 0x89, 0xa4, 0x8d, 0x83, 0xf7, 0x52, 0xa4, 0xea, 0x2c, 0x1a, 0xf7, 0x1b, 0x95, 0x6a, 0x7c, 0x28, 0x9a, 0x6e, 0x5d, 0xbc, 0xf1, 0x21, 0xb9, 0xbb, 0x0d, 0xd1, 0x25, 0x87, 0xe0, 0xfe, 0xd6, 0xd9, 0x97, 0x1e, 0x9c, 0x87, 0x5b, 0xe5, 0x5c, 0xba, 0xf1, 0x86, 0xf1, 0xf4, 0xab, 0x12, 0xb3, 0x03, 0xc6, 0xf6, 0xaf, 0x6a, 0x56, 0x42, 0x18, 0xcf, 0xbf, 0xc1, 0x52, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x30, 0x68, 0xc8, 0x4a, 0x8b, 0x71, 0xd5, 0x10, 0xc7, 0x47, 0x08, 0x3c, 0x32, 0x43, 0x93, 0x1e, 0x9e, 0xbb, 0x2e, 0xb7, 0x68, 0xbc, 0x44, 0xd4, 0xd6, 0x45, 0x7c, 0x49, 0xd0, 0x81, 0xff, 0xca, 0x50, 0x3b, 0x45, 0x8e, 0x28, 0x32, 0xcb, 0x1c, 0x2f, 0x9e, 0xb5, 0x09, 0x32, 0x6e, 0x72, 0x78, 0x31, 0x22, 0xc4, 0xb8, 0xf1, 0x12, 0xf8, 0xd6, 0x0c, 0xc3, 0x36, 0x49, 0x45, 0xcb, 0x33, 0x02, 0x93, 0x2c, 0x91, 0x4f, 0x4b, 0x33, 0x5c, 0x72, 0x44, 0x39, 0x2c, 0xd8, 0x79, 0xe9, 0x11, 0x55, 0x8d, 0x40, 0x97, 0xb9, 0x47, 0x14, 0xa5, 0x9a, 0x44, 0x67, 0x2f, 0x91, 0xb6, 0x29, 0x64, 0x5d, 0x12, 0x0c, 0x90, 0xae, 0x4c, 0x2c, 0x49, 0xb0, 0x1a, 0x76, 0x73, 0xb5, 0xd8, 0x49, 0xeb, 0xcc, 0xcc, 0x92, 0x1d, 0x17, 0x0d, 0x8c, 0x0b, 0x31, 0x4e, 0xe3, 0x74, 0xf0, 0x59, 0xdc, 0xbd, 0xb5, 0x33, 0xc1, 0xa7, 0x54, 0xae, 0x24, 0xcd, 0x06, 0x57, 0xaa, 0x48, 0xea, 0x1c, 0xdf, 0x34, 0x65, 0x0f, 0x6e, 0x7c, 0x42, 0x9f, 0x5d, 0xcc, 0xa9, 0xf1, 0x89, 0x42, 0x52, 0x75, 0xc3, 0xda, 0x27, 0x8a, 0xc1, 0xcc, 0x0d, 0xeb, 0x9c, 0xc0, 0x7b, 0x33, 0x73, 0x6a, 0x52, 0x7c, 0x66, 0xc3, 0xa2, 0x24, 0xb1, 0x09, 0xa8, 0xd1, 0xe8, 0xd4, 0x36, 0x00, 0xf0, 0xff}

const int button = 2;   // 버튼
const int tilt = 4;     // 기울기 센서
const int led = 8;      // led
const int speaker = 10; // 앰프 모듈

int absDiff, diff;        // diff : 오차, absDiff : 오차의 절댓값

int stdSensorValue = 0; // 기준 기울기 상태 저장
int sensorValue = 0;    // 현재 기울기 상태 저장 
int buttonState = 0;       // 버튼 상태 저장

void setup() {
  pinMode(tilt, INPUT);
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
  pinMode(speaker, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  
  buttonState = digitalRead(button); // 버튼상태 받아오기
  Serial.print("01_buttonState(버튼상태) : ");
  Serial.println(buttonState);
  sensorValue = analogRead(tilt); // 기울기 상태 받아오기
  Serial.print("02_sensorValue(현재센서값) : ");
  Serial.println(sensorValue); // 센서값 출력
  diff = sensorValue - stdSensorValue;         // default값과 현재 값의 차이
  absDiff = diff > 0 ? diff : diff * -1;  // 차이값을 양의 값으로 반환.


  if(buttonState == HIGH) {               // 전원 버튼 클릭하면 (= 도난 방지 모드 시작)
    stdSensorValue = analogRead(tilt);    // 현재 기울기 값 받기
    Serial.print("03_stdSensorValue(기준센서값) : ");
    Serial.println(stdSensorValue);
    Serial.print("04_absDiff(오차) : ");
    Serial.println(absDiff);

    if(absDiff >= 10) { // 오차가 10 이상일 경우
      timeCurr = millis();  // 시간 재기
  
      if((timeCurr - timePrev) >= interval){  // 15초 이상 지속되면
          // 버튼 눌러서 도난 방지 모드 끄기 전(버튼 다시 눌리기 전)까지 소리 내기
          voice.say(sp1);
          delay(200);
      }
      else{
        delay(2);
      }
    }
  timePrev = timeCurr;
  Serial.print("5초만 쉴게요\n");
  delay(5000);
}