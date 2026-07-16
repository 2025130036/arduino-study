const int tempPin = A0;
int sensorValue;
float voltage;
float temp;

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(tempPin);//아날로그값(0부터 1023까지)읽어오기
  voltage = sensorValue * (5000.0 / 1024.0);//LM35센서는 온도에 비례해 0도일때 0V, 1도마다 10mV(0.01V)씩 출력전압을 바꾸므로 다시 변환
  temp = voltage / 10.0;//전압 10mV당 1도이므로 10으로 나눠 온도 구하기
  Serial.print("Current Temperature: ");
  Serial.print(temp);
  Serial.println(" C");
  
  delay(1000);
}
