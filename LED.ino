const int LED = 9;//9번핀을 브레드보드와 연결, 9번핀 - 220옴저항 - LED - GND를 직렬로 연결

void setup(){
  pinMode(LED, OUTPUT);//인풋 아웃풋 설정
}

void loop(){
  for(int i = 0;i<20;i++){
    digitalWrite(LED, HIGH);
    delay(i*100);
    digitalWrite(LED, LOW);
    delay(i*200);
  }//깜박이는 시간을 계속 바꿈
}
