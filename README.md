# arduino_project


https://user-images.githubusercontent.com/62279741/122161494-c9c8aa00-ceac-11eb-8dc7-8043ab3cda39.mp4




## 구현 배경

카페 등의 공공 장소에서 잠시 자리를 비울 때, <br>
행여나 내 물건이 없어질까 불안한 마음이 들곤 합니다. <br>
불안감 해소+도둑에게 경각심?

내 물건에 다른 사람의 손이 닿는 즉시 소리가 송출되고 알림이 전송됩니다.

## 개발 목표

- 소프트웨어와 하드웨어의 연동<br>
- 블루투스르 이용하여 원격지에서도 조작 및 상황 인지 

## 알고리즘

도난 방지 장치 위에 물품 배치<br>
→  블루투스 모듈과 연결(Serial 창에서 2를 순서대로 입력해야 함)<br>
→  BTserial(Bluetooth Terminal)에서 a를 입력하여 도난 방지 시스템 시작<br>
→ 현재 기울기 값과 조도 값을 받음<br>
→ z_now와 light_now 변수에 현재 기울기 값 저장<br>
→ 조도 값 또는 기울기 값에 변화가 있다면<br>
→ 음성 신호 출력 + Bluetooth Terminal에 메세지 전송<br>
→ BTserial(Bluetooth Terminal)에서 b를 입력하여 도난 방지 시스템 종료<br>

## 헤더파일

arduino libraries폴더에 talkie 압축 풀기

