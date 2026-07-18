#include <Servo.h>
//서브모터 구동을 위해서는 필수

const int R = A0;//가변저항 A0
const int MOTOR = 9;//모터 제어선 9번핀
int val, angle;

Servo myServo;

void setup() {
  myServo.attach(MOTOR);//myServo객체를 MOTOR핀에 연결
}

void loop() {
  val = analogRead(R);//가변저항 값 읽기
  angle = map(val, 0, 1023, 179, 0);//map을 이용해 가변저항의 각도에 따라 0~179도 변환. 서브모터는 0~180도 가능하지만 안정성을 위해 179도까지
  myServo.write(angle);//서브모터 각도를 angle으로 정하기
  delay(50);//0.05초마다 움직이기 
}
