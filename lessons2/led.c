int i=0;
void setup()
{
  for(i=0;i<10;i++)
  {
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  for(i=0;i<10;)
  {
    digitalWrite(i, HIGH);
    digitalWrite(i+1, HIGH);
    delay(200); // Wait for 1000 millisecond(s)
    digitalWrite(i, LOW);
    digitalWrite(i+1,LOW);
    delay(200); // Wait for 1000 millisecond(s)
    i=i+2;
  }
}