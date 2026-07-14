const int RED = 9;
const int BLUE = 11;
const int GREEN = 10;
const int BUTTON = 2;

boolean lastButton = LOW;
boolean currentButton = LOW;

int ledMode = 0;


void setup() {
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BUTTON, INPUT);
}

boolean debounce(boolean last)//digitalRead 때 했던 것 재활용
{
  boolean current = digitalRead(BUTTON);
  if(last != current){
    delay(5);
    current = digitalRead(BUTTON);
  }
  return current;
}

void setMode(int mode)//각 모드마다 RGB의 출력 제어하는 함수
{
  if(mode == 1){
    digitalWrite(RED, HIGH);
    digitalWrite(BLUE, LOW);
    digitalWrite(GREEN, LOW);
  }
  else if(mode == 2){
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, LOW);
  }
  else if(mode == 3){
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, HIGH);
  }
  else if(mode == 4){
    analogWrite(RED, 127);
    analogWrite(GREEN, 0);
    analogWrite(BLUE, 127);
  }
  else if(mode == 5){
    analogWrite(RED, 0);
    analogWrite(GREEN, 127);
    analogWrite(BLUE, 127);
  }
  else if(mode == 6){
    analogWrite(RED, 127);
    analogWrite(GREEN, 127);
    analogWrite(BLUE, 0);
  }
  else if(mode == 7){
    analogWrite(RED, 85);
    analogWrite(GREEN, 85);
    analogWrite(BLUE, 85);
  }
  else{
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
  }
}

void loop() {
  currentButton = debounce(lastButton);
  if(lastButton ==LOW && currentButton == HIGH){
    ledMode++;//버튼이 눌릴때마다 모드 바꾸기
  }
  lastButton = currentButton;
  if(ledMode == 8){
    ledMode = 0;//ledMode가 8이면 모드 초기화
  }
  setMode(ledMode);//모드 설정
}

