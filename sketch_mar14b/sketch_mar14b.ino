
int A = 10;
int B = 11;
int C = 12;
int D = 13;
int E = 6;
int F = 7;
int G = 8;
//int light8 = 9;

int lights[] = {A,B,C,D,E,F,G};

int dg0[] = {A,B,C,D,E,F};
int dg1[] = {B,C};
int dg2[] = {A,B,G,E,D};
int dg3[] = {A,B,G,C,D};
int dg4[] = {F,G,B,C};
int dg5[] = {A,F,G,C,D};
int dg6[] = {A,F,G,E,C,D};
int dg7[] = {A,B,C};
int dg8[] = {A,B,C,D,E,F,G};
int dg9[] = {A,B,C,D,F,G};

//int digitals[][] = {dg0,dg1,dg2,dg3,dg4,dg5,dg6,dg7,dg8,dg9};

int digitals[][7] = {{A,B,C,D,E,F},{B,C},{A,B,G,E,D},
                  {A,B,G,C,D},{F,G,B,C},{A,F,G,C,D},
                  {A,F,G,E,C,D},{A,B,C},{A,B,C,D,E,F,G},{A,B,C,D,F,G}};
 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=6;i<=13;i++)
    pinMode(i,OUTPUT);
}


//数位板显示
void afficher()
{
  for(int i=0;i<99;i++){
        int single = i%10;
        int tens = (i-i%10)/10;
        
        for(int k=0;k<sizeof(lights)/sizeof(lights[0]);k++)
        {
          digitalWrite(lights[k],LOW);
        }

        for(int flag=0;flag<20;flag++)
        {
          
            for(int j=0;j<sizeof(digitals[single])/sizeof(digitals[single][0]);j++)
            {
              digitalWrite(digitals[single][j],HIGH);
           
            }
            delay(10);
            for(int k=0;k<sizeof(lights)/sizeof(lights[0]);k++)
            {
              digitalWrite(lights[k],LOW);
            }
            digitalWrite(9,HIGH);
    
            for(int j=0;j<sizeof(digitals[tens])/sizeof(digitals[tens][0]);j++)
            {
              digitalWrite(digitals[tens][j],HIGH);
             
            }
            delay(10);
            for(int k=0;k<sizeof(lights)/sizeof(lights[0]);k++)
            {
              digitalWrite(lights[k],LOW);
            }
            digitalWrite(9,LOW);
        }
        
        
        
      }
}

void loop() {
  // put your main code here, to run repeatedly:

  afficher();
      

}
