#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

#define S1 8
#define S2 9
#define S3 10
#define S4 11

#define LT 6
#define BT 7
void setup()
{
  pinMode(IN1, OUTPUT);//输入1
  pinMode(IN2, OUTPUT);//输入2
  pinMode(IN3, OUTPUT);//输入3
  pinMode(IN4, OUTPUT);//输入4
  pinMode(S1, OUTPUT);//片选1
  pinMode(S2, OUTPUT);//片选2
  pinMode(S3, OUTPUT);//片选3
  pinMode(S4, OUTPUT);//片选4
  
  pinMode(LT,OUTPUT);//测试
  pinMode(BT,OUTPUT);//消隐
  
  digitalWrite(LT,HIGH);
  digitalWrite(BT,HIGH);
  
  digitalWrite(S1,HIGH);
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  digitalWrite(S4,HIGH);
  Serial.begin(9600);
}
byte income1=0,income2=0,income3=0,income4=0;
byte income[100];
int n=0;
void loop()
{
   if(Serial.available()>0)
  {
    digitalWrite(S1,HIGH);
    digitalWrite(S2,HIGH);
    digitalWrite(S3,HIGH);
    digitalWrite(S4,LOW);
    income1=Serial.read(); 
    income1=income1-'0';
    digitalWrite(2,income1&0x1);
    digitalWrite(3,(income1>>1)&0x1);
    digitalWrite(4,(income1>>2)&0x1);
    digitalWrite(5,(income1>>3)&0x1);
  	delay(2000);
    //
    digitalWrite(S3,LOW);
    digitalWrite(S2,HIGH);
    digitalWrite(S4,HIGH);
    digitalWrite(S1,HIGH); 
    income1=income1-'0';
    digitalWrite(2,income1&0x1);
    digitalWrite(3,(income1>>1)&0x1);
    digitalWrite(4,(income1>>2)&0x1);
    digitalWrite(5,(income1>>3)&0x1);
    delay(10);
      
    digitalWrite(S4,LOW);
    digitalWrite(S2,HIGH);
    digitalWrite(S3,HIGH);
    digitalWrite(S1,HIGH);
    income2=Serial.read(); 
    income2=income2-'0';
    digitalWrite(2,income2&0x1);
    digitalWrite(3,(income2>>1)&0x1);
    digitalWrite(4,(income2>>2)&0x1);
    digitalWrite(5,(income2>>3)&0x1);
    delay(2000);
    //
    
    digitalWrite(S2,LOW);
    digitalWrite(S1,HIGH);
    digitalWrite(S3,HIGH);
    digitalWrite(S4,HIGH);
    income1=income1-'0';
    digitalWrite(IN1,income1&0x1);
    digitalWrite(IN2,(income1>>1)&0x1);
    digitalWrite(IN3,(income1>>2)&0x1);
    digitalWrite(IN4,(income1>>3)&0x1);
  	delay(10);
     
    digitalWrite(S3,LOW);
    digitalWrite(S1,HIGH);
    digitalWrite(S2,HIGH);
    digitalWrite(S4,HIGH);
    income2=income2-'0';
    digitalWrite(IN1,income2&0x1);
    digitalWrite(IN2,(income2>>1)&0x1);
    digitalWrite(IN3,(income2>>2)&0x1);
    digitalWrite(IN4,(income2>>3)&0x1);
  	delay(10);
    digitalWrite(S4,LOW);
    digitalWrite(S2,HIGH);
    digitalWrite(S1,HIGH);
    digitalWrite(S3,HIGH);
  	income3=Serial.read();
    
    income3=income3-'0';
    digitalWrite(IN1,income3&0x1);
    digitalWrite(IN2,(income3>>1)&0x1);
    digitalWrite(IN3,(income3>>2)&0x1);
    digitalWrite(IN4,(income3>>3)&0x1);
  	delay(2000);
    //
    digitalWrite(S1,LOW);
    digitalWrite(S2,HIGH);
    digitalWrite(S3,HIGH);
    digitalWrite(S4,HIGH);
    
    income1=income1-'0';
    digitalWrite(IN1,income1&0x1);
    digitalWrite(IN2,(income1>>1)&0x1);
    digitalWrite(IN3,(income1>>2)&0x1);
    digitalWrite(IN4,(income1>>3)&0x1);
  	delay(10);
     
    digitalWrite(S2,LOW);
    digitalWrite(S1,HIGH);
    digitalWrite(S3,HIGH);
    digitalWrite(S4,HIGH);
    
    income2=income2-'0';
    digitalWrite(IN1,income2&0x1);
    digitalWrite(IN2,(income2>>1)&0x1);
    digitalWrite(IN3,(income2>>2)&0x1);
    digitalWrite(IN4,(income2>>3)&0x1);
  	delay(10);
    digitalWrite(S3,LOW);
    digitalWrite(S2,HIGH);
    digitalWrite(S1,HIGH);
    digitalWrite(S4,HIGH);
    
    income3=income3-'0';
    digitalWrite(IN1,income3&0x1);
    digitalWrite(IN2,(income3>>1)&0x1);
    digitalWrite(IN3,(income3>>2)&0x1);
    digitalWrite(IN4,(income3>>3)&0x1);
  	delay(10);
    digitalWrite(S4,LOW);
    digitalWrite(S2,HIGH);
    digitalWrite(S3,HIGH);
    digitalWrite(S1,HIGH);
  	income4=Serial.read();
    
    income4=income4-'0';
    digitalWrite(IN1,income4&0x1);
    digitalWrite(IN2,(income4>>1)&0x1);
    digitalWrite(IN3,(income4>>2)&0x1);
    digitalWrite(IN4,(income4>>3)&0x1);
  	delay(2000);
     income[0]=income1;
     income[1]=income2;
     income[2]=income3;
     income[3]=income4;
     for(n=1;;n++)
     {
        digitalWrite(S1,LOW);
        digitalWrite(S2,HIGH);
        digitalWrite(S3,HIGH);
        digitalWrite(S4,HIGH);

        income[n]=income[n]-'0';
        digitalWrite(IN1,income[n]&0x1);
        digitalWrite(IN2,(income[n]>>1)&0x1);
        digitalWrite(IN3,(income[n]>>2)&0x1);
        digitalWrite(IN4,(income[n]>>3)&0x1);
        delay(10);

        digitalWrite(S2,LOW);
        digitalWrite(S1,HIGH);
        digitalWrite(S3,HIGH);
        digitalWrite(S4,HIGH);

        income[n+1]=income[n+1]-'0';
        digitalWrite(IN1,income[n+1]&0x1);
        digitalWrite(IN2,(income[n+1]>>1)&0x1);
        digitalWrite(IN3,(income[n+1]>>2)&0x1);
        digitalWrite(IN4,(income[n+1]>>3)&0x1);
        delay(10);
        digitalWrite(S3,LOW);
        digitalWrite(S2,HIGH);
        digitalWrite(S1,HIGH);
        digitalWrite(S4,HIGH);

        income[n+2]=income[n+2]-'0';
        digitalWrite(IN1,income[n+2]&0x1);
        digitalWrite(IN2,(income[n+2]>>1)&0x1);
        digitalWrite(IN3,(income[n+2]>>2)&0x1);
        digitalWrite(IN4,(income[n+2]>>3)&0x1);
        delay(10);
        digitalWrite(S4,LOW);
        digitalWrite(S2,HIGH);
        digitalWrite(S3,HIGH);
        digitalWrite(S1,HIGH);
        income[n+3]=Serial.read();

        income[n+3]=income[n+3]-'0';
        digitalWrite(IN1,income[n+3]&0x1);
        digitalWrite(IN2,(income[n+3]>>1)&0x1);
        digitalWrite(IN3,(income[n+3]>>2)&0x1);
        digitalWrite(IN4,(income[n+3]>>3)&0x1);
        delay(2000);
     }
  }
  
  
  
}