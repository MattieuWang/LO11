
int light1 = 10;
int light2 = 11;
int light3 = 12;
int light4 = 13;
int light5 = 6;
int light6 = 7;
int light7 = 8;
int light8 = 9;

int lights[] = {light1,light2,light3,light4,light5,light6,light7,light8};


char* longToBinaire(uint64_t entier)
{
    int size =8;
    char* binaire = (char*)malloc(size);
    for (int i = 0; i < size; ++i) {
        int bit = (entier>>size - i - 1)&1;
        binaire[i]= 48 + bit;
    }
    
    return binaire;
}

void showBinaire()
{
  for(int i=0;i<=255;i++)
  {
    char* binaire = longToBinaire(i);
    Serial.println(binaire);
    for(int k=0;k<8;k++)
    {
      digitalWrite(lights[k],LOW);
    }
    for(int j=0;j<8;j++)
    {
      if(binaire[j] == 49)
      {
        digitalWrite(lights[8-j-1],HIGH);
      }
    }
    delay(100);
  }
    
}


void setup()
{
  Serial.begin(9600);
 for (int i=6; i<=13; i++) // configuration of pins 2 to 9 in output
 {
  pinMode(i,OUTPUT);
 }
}

void loop()
{
  showBinaire();
//  for(int i=0;i<8;i++)
//  {
//    digitalWrite(lights[i],HIGH);
//    delay(500);
//  }
  

}
