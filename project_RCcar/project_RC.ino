#include <Servo.h>

const int ECHO = 10;          
const int TRIG = 9;           
const int SERVO_PIN = 6;      
const int LINE_SENSOR = A0;   
const int LED = 13;           

const int IN1 = 2;            
const int IN2 = 3;            
const int IN3 = 4;            
const int IN4 = 5;            

Servo scanServo;

const int LEFT_ANGLE = 10;    
const int CENTER_ANGLE = 90;
const int RIGHT_ANGLE = 170;  

void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  //모터 모두 정지
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  // 모터 모두 전진
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH); 
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  //왼쪽 모터는 후진, 오른쪽 모터는 전진하여 좌회전
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);  
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  //왼쪽 모터는 전진, 오른쪽 모터는 후진하여 우회전
}

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(LINE_SENSOR, INPUT);
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopCar(); 
  
  scanServo.attach(SERVO_PIN);
  scanServo.write(CENTER_ANGLE); //서보모터 중앙 정렬시키기
  delay(2000); 
}

void loop() {
  //초음파 거리 측정 (FCA ADAS)
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  unsigned long duration = pulseIn(ECHO, HIGH, 12000); 
  unsigned long distance = duration * 17 / 1000;

  //FCA 긴급 장애물 회피, TCRT5000 센서 전선이 감지 될수도 있어서 최소거리 5cm 추가 
  if (distance > 5 && distance < 22) {
    stopCar();               
    digitalWrite(LED, HIGH); 
    delay(100); 
    
    turnRight();             
    delay(1200);  
    
    stopCar();
    delay(100);
  }
  else {
    digitalWrite(LED, LOW);
    
    // 기본 주행 상태는 직진
    moveForward();

    // 서보모터 스캔
    scanServo.write(LEFT_ANGLE);
    delay(280); 
    int leftVal = digitalRead(LINE_SENSOR);

    scanServo.write(RIGHT_ANGLE);
    delay(280); 
    int rightVal = digitalRead(LINE_SENSOR);

    scanServo.write(CENTER_ANGLE); // 중앙 복귀

    // 4. 주행 판단
    // 왼쪽에만 검은선 있을 시 좌회전, 오른쪽에만 검은 선 있을 시 우회전, 그 외에는 직진
    if (leftVal == HIGH && rightVal == LOW) {
      turnLeft();
      delay(120);
    } 
    else if (leftVal == LOW && rightVal == HIGH) {
      turnRight();
      delay(120);
    } 
    else {
      moveForward();
    }
  }
}
