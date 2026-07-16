const int POT = 0;
int val = 0;

void setup() {
  Serial.begin(9600);//컴퓨터와의 시리얼통신을 위한 함수. 시리얼 통신은 차후 자세히 배울 예정.9600은 통신속도, 초당 전송되는 비트수. 9600이 일반적
}

void loop() {
  val = analogRead(POT);
  Serial.println(val);
  delay(500);
}
