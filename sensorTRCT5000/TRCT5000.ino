//왼쪽에 led가 있게 놓은 상태에서 왼쪽 위 캐소드(GND연결)
//왼쪽 아래 애노드(220옴 저항을 거쳐 5V연결)
//오른쪽 위 이미터(GND)
//오른쪽 아래 컬렉터(10k저항 거쳐 5V), 컬렉터 다리와 A0 연결

void setup() {
  Serial.begin(9600); // 시리얼 통신 시작
}

void loop() {
  int sensorValue = analogRead(A0); // A0 핀에서 센서 값 읽기
  Serial.print("TCRT5000 Value: ");
  Serial.println(sensorValue);
  
  delay(200); // 0.2초 대기
}
