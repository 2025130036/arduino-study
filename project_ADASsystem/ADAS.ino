#include <LiquidCrystal.h>
#include <Servo.h>

const int ECHO = 10;  //초음파센서 echo
const int TRIG = 9;  // 초음파센서 트리거
const int SERVO = 6; // 서브모터 제어핀
const int VRX = A1; //조이스틱 x축
const int VRY = A0;  //조이스틱 y축
const int CLICK = 8; //조이스틱 클릭(SW)핀
const int LED = 13; //경고표시용 빨간LED

Servo myServo;
LiquidCrystal lcd(12,11,5,4,3,2);

int steeringAngle = 90;

void setup() {
  lcd.begin(16, 2);
  pinMode(LED, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);
  myServo.attach(SERVO);
  lcd.setCursor(0, 0);      
  lcd.print(" Simulation     ");
  lcd.setCursor(0, 1);
  lcd.print("      Start!    ");
  myServo.write(steeringAngle);
  delay(2000);//2초대기
  lcd.clear();
}

void loop() {
  //로직1. 거리측정
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);//trig핀 안정화
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);//초음파 발사
  digitalWrite(TRIG, LOW);
  unsigned long duration = pulseIn(ECHO, HIGH, 30000);//timeout 30000us를 넘으면 0반환, 최대 5m정도까지 측정 가능
  unsigned long distance = duration * 17 / 1000;
  //digitalRead_distance와 달라진점 : int를 long으로 바꾸어 확실하게 오버플로우 방지, pulseIn timeout 추가하여 안정성 확보


  //로직2. 조이스틱에 맞춰 서브모터 조작. or 위험시 FCA ADAS 발동
  if(distance > 0 && distance < 15){
    steeringAngle = 135;//15cm 이내 장애물 있을시 회피각도로 조향
    lcd.setCursor(0,0);
    lcd.print("    CAUTION!    ");
    lcd.setCursor(0,1);
    lcd.print(" FCA is working ");
    digitalWrite(LED, HIGH);
  }
  else{
    int joyX = analogRead(VRX);
    int joyY = analogRead(VRY);
    steeringAngle = map(joyX, 0, 1023, 0, 179);
    digitalWrite(LED, LOW);
    const char* status = "Stop ";
    // 읽기 전용 문자열 리터럴을 가리키는 포인터 사용 (상황에 따라 가리키는 문자열 주소 변경 가능)
    if(joyY > 712){
      status = "Accel";  // 전진 상태 주소 대입
    }
    else if(joyY < 312){
      status = "Back ";
    }
    lcd.setCursor(0,0);
    lcd.print(" status : ");//FCA 작동시에 써진 lcd 잔상을 없애기 위해 모든칸을 사용하여 덮어씌우기
    lcd.print(status);
    lcd.print(" ");//이전 화면 잔상 방지를 위해 16칸 맞춤
    lcd.setCursor(0,1);
    if(distance == 0){
      lcd.print("can't gain dist ");//초음파센서가 0을 반환했을 때
    }
    else{
      lcd.print("dist : ");
      lcd.print(distance);
      lcd.print(" cm");
      if(distance >= 100){
        lcd.print("   ");
      }
      else{
        lcd.print("    ");
      }
    }

  }
  myServo.write(steeringAngle); // 최종 결정된 각도로 서보모터 제어
  delay(100);  // 시스템 안정화를 위한 0.1초 딜레이

}
