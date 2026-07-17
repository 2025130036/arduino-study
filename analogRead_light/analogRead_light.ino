const int SENSOR = 0;//A0
const int LED = 9;
const int MIN_SENSOR = 200;
const int MAX_SENSOR = 700;//센서의 입력값은 0~1023이지만 별도로 최소/최댓값을 만들어 구현
int val = 0;//센서 입력값


void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  val = analogRead(SENSOR);
  val = constrain(val, MIN_SENSOR, MAX_SENSOR);    // 센서 범위 제한 (MIN 이하 -> MIN, MAX 이상 -> MAX)
  val = map(val, MIN_SENSOR, MAX_SENSOR, 255, 0);  // 밝을수록 LED는 어둡게, 어두울수록 밝게
  analogWrite(LED, val);
}
