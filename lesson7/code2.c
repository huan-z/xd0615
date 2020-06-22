#include <MsTimer2.h>     //定时器库的头文件
int pinInterrupt=2;
int tick = 0; 
byte num=0;
void onTimer()
{
  num=tick+64;  
  num=num-'0';
  digitalWrite(3,num&0x1);
  digitalWrite(4,(num>>1)&0x1);
  digitalWrite(5,(num>>2)&0x1);
  digitalWrite(6,(num>>3)&0x1);
  tick++;
  if(tick==10)
  {
  	tick=0;
  }
}
void clear()
{
	tick=0;
}
void setup()
{
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
  
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  MsTimer2::set(1000, onTimer); 
  MsTimer2::start(); 
  attachInterrupt(digitalPinToInterrupt(pinInterrupt),clear,CHANGE);
 
}
 
void loop()
{
  
}
