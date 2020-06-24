#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);//用接口引脚的数字初始化库
void setup() 
{
  lcd.begin(16, 2);//设置LCD的列数和行数
  lcd.print("hello, world!");//打印一条信息到LCD上
}

void loop() 
{  
  lcd.setCursor(0, 1);// 将光标设置为第0列，第1行
  lcd.print(millis() / 1000);//打印自重置后的秒数
}
 