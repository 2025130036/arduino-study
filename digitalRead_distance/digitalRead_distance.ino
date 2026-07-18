const int ECHO = 9;
const int TRIG = 10;
//아날로그센서처럼 전압이 변하는게 아닌 echo가 HIGH인 시간을 측정하는 것이므로 digitalRead라 할 수 있음.

void setup() {
  Serial.begin(9600);
  pinMode(ECHO, INPUT);//echo는 초음파 왕복 시간이 입력되는 곳(pulseIn)이므로 input
  pinMode(TRIG, OUTPUT);//trig는 초음파 발사 신호를 보내는 곳이므로 output
}

void loop() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  //Trigger 핀 안정화를 위해 2us동안 LOW로 떨어트리기
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);//10us동안 trig에 5V를 전가해서 초음파가 발사되게함. 이보다 적으면 초음파 발사 안될수도 있으며, 많으면 시간적으로 비효율적
  digitalWrite(TRIG, LOW);
  unsigned int distance = pulseIn(ECHO, HIGH) * 17 / 1000;//오버플로우 방지 unsigned
  //echo에서 초음파를 송신할때부터 수신할때까지 5V(HIGH)가 되는데, 이 사이의 시간을 측정해주는 것이 pulseIn함수
  //마이크로초 us, 즉 10의 -6승 m 단위로 반환.
  //pulseIn(10의 -6승m) * 340(초음파의 속도 m/s) / 2(왕복시간) / 10000(10의 4승) 공식을 통해 대상과의 거리를 cm단위로 얻을 수 있다.
  Serial.print(distance);
  Serial.println(" cm");
  delay(200);//0.2초
}
