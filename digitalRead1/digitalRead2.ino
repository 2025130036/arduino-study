const int LED = 9;
const int BUTTON = 2;
boolean lastButton = LOW;
boolean currentButton = LOW;
boolean ledOn = false;
//버튼의 바운싱 문제(버튼을 누르고 몇ms동안 상태가 진동하는 문제)를 해결하기 위해 현재 버튼 상태와 과거 버튼 상태를 보여주는 변수를 만들고, LED 스위칭을 편하게 하기 위해 ledOn 변수 추가

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

boolean debounce(boolean last)
{
  boolean current = digitalRead(BUTTON);
  if(last != current){
    delay(5);
    current = digitalRead(BUTTON);
  }
  return current;
}//버튼의 바운싱은 대충 5ms정도 진행되기 때문에 5ms를 기다리고 버튼상태를 반환함

void loop() {
  currentButton = debounce(lastButton);
  if(lastButton ==LOW && currentButton == HIGH){//버튼을 누르면 ledOn상태가 바뀜
    ledOn = !ledOn;
  }
  lastButton = currentButton;
  digitalWrite(LED, ledOn);
}
//회로자체는 1과 같기 때문에 사진은 생략.
//2026-07-13
