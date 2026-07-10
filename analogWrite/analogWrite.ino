const int LED = 9;

void setup() {
  pinMode(LED, OUTPUT);//9번핀을 아웃풋으로 설정
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 256; i++){
    analogWrite(LED, i);//3, 5,6,9,10,11번핀으로는 analogWirte로 0부터 256까지 펄스폭변조PWM를 통해 전류를 조절할 수 있다.
    delay(10);
  }
  for(int i=255;i>=0;i--){
    analogWrite(LED, i);
    delay(10);
  }
}
