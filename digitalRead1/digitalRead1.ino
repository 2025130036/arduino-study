const int LED = 9;
const int BUTTON = 2;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);//2번핀을 INPUT으로 설정한다. 다만 기본적으로 핀모드는 INPUT이기 때문에 필요는 없지만 확실하게 하기 위해

}

void loop() {
  if(digitalRead(BUTTON)==LOW)//버튼이 눌리지 않았을 때
  {
    digitalWrite(LED, LOW);
  }
  else//버튼이 눌렸을 때 LED 키기
  {
    digitalWrite(LED, HIGH);
  }
}
