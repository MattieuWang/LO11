
int light1 = 10;
int light2 = 11;
int light3 = 12;
int light4 = 13;
int light5 = 6;
int light6 = 7;
int light7 = 8;
int light8 = 9;

int lights[] = {light1,light2,light3,light4,light5,light6,light7,light8};


void chenillard(int interval)
{
  for(int i=0;i<8;i++)
  {
    digitalWrite(lights[i],HIGH);
    delay(interval*100);
    digitalWrite(lights[i],LOW);
  }
}

void setup()
{
  Serial.begin(9600);
 for (int i=6; i<=13; i++) // configuration of pins 2 to 9 in output
 {
  pinMode(i,OUTPUT);
 }

  for(int i=2; i<=5;i++)
  {
    pinMode(i,INPUT);
  }
  
 
}

void loop()
{
  chenillard(2);
  int a = digitalRead(2);
  Serial.println(a);

}
