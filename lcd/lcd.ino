#include <LiquidCrystal.h>//lcd사용하기 위해서 필요한 기본 라이브러리
LiquidCrystal lcd(12,11,5,4,3,2);//lcd에 사용할 핀 설정

void setup() {
  lcd.begin(16, 2);  //lcd의 크기 설정. 1602모델은 가로 16칸 세로 2칸
  lcd.print("hello, world!");  //lcd에 출력
}

void loop() {
  lcd.noDisplay();  //lcd 화면 끄기
  delay(500);  //0.5초 대기
  lcd.display();  //화면 키기
  delay(500);
  lcd.setCursor(2, 1); // 두 번째 줄, 2칸 띄우고 시작
  lcd.print("KAU let's go!");
  delay(1000);
  lcd.clear();           //화면 모두 지우기
  lcd.setCursor(0,0);  //첫번째줄 처음부터 시작
  lcd.print("Arduino LCD");

}
