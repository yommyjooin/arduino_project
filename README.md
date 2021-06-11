# arduino_project

**알고리즘**

도난 방지 장치 위에 물품 배치

→  블루투스 모듈과 연결(Serial 창에서 2를 순서대로 입력해야 함)

→  BTserial(Bluetooth Terminal)에서 a를 입력하여 도난 방지 시스템 시작

→ 현재 기울기 값과 조도 값을 받는다 

→ z_now와 light_now 변수에 현재 기울기 값 저장  

→ 조도 값 또는 기울기 값에 변화가 있다면

→ 음성 신호 출력 + Bluetooth Terminal에 메세지 전송

→ BTserial(Bluetooth Terminal)에서 b를 입력하여 도난 방지 시스템 종료

*헤더파일*
libraries 폴더에 talkie 
