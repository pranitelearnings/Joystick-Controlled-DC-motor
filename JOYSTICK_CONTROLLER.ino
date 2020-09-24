#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#define joystick     A0
#define pwm1         5
#define pwm2         4
#define pwm3         3
#define pwm4         2
 
int motor_control;
 
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Joystick ");
  lcd.setCursor(0,1);
  lcd.print("controlled motor");
  pinMode(pwm1,   OUTPUT);
  pinMode(pwm2,   OUTPUT);
  pinMode(pwm3,   OUTPUT);
  pinMode(pwm4,   OUTPUT);
}
 
void loop() {
  while(1)
  {
  motor_control = analogRead(joystick);
  motor_control >>= 1;
  if(motor_control > 255){
    digitalWrite(pwm2, 0);
    analogWrite(pwm1, (motor_control - 256));
    digitalWrite(pwm4, 0);
    analogWrite(pwm3, (motor_control - 256));
  }
  else
    if(motor_control < 255){
      digitalWrite(pwm1, 0);
      analogWrite(pwm2, (255 - motor_control));
      digitalWrite(pwm3, 0);
      analogWrite(pwm4, (255 - motor_control));
    }
    else{
      digitalWrite(pwm1, 0);
      digitalWrite(pwm2, 0);
      digitalWrite(pwm3, 0);
      digitalWrite(pwm4, 0);
    }
  }
}
