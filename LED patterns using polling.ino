int green1=3;
int green2=4;
int green3=5;
int yellow1=6;
int yellow2=7;
int red=9 ;
int blue=8;
int button=2;

int delay1=600;

int x = 0;
bool y = 0;
int array1[7] = {red,yellow1,blue,green2,green1,yellow1,green3};
int array2[4]= {green1,green3,yellow2,red};
int array3[7]= {green1,green2,green3,yellow1,yellow2,blue,red};
int array4[7]={green1,green2,green3,yellow1,yellow2,blue,red};

long holdingTime;
long previousHoldingTime;
unsigned long firstButtonPressTime;
byte buttonState;
byte previousButtonState = HIGH;


void setup() {
Serial.begin(9600);
pinMode(button,INPUT_PULLUP);
pinMode(green1,OUTPUT);
pinMode(green2,OUTPUT);
pinMode(green3,OUTPUT);
pinMode(yellow1,OUTPUT);
pinMode(yellow2,OUTPUT);
pinMode(red,OUTPUT);
pinMode(blue,OUTPUT);
}

void loop()
{
  pushbutton();
  //testpatt();
}
  
void pattern1(int delay1)
{
  while(y == 0 && x == 1){
         axio();
         for(int i = 0; i <= 3;i++)
        {
          axio();
          digitalWrite(array2[i],HIGH);
          delay(delay1);
          axio();
          digitalWrite(array2[i],LOW);
          delay(delay1);
           axio();
        }
    }
}

void pattern2(int delay2)
{
  while(y == 0 && x == 2)
  {
          axio();
          for(int i = 0; i <= 6; i++)
        {
          axio();
          digitalWrite(array4[i],HIGH);
          digitalWrite(array4[i+1],HIGH);
          delay(delay2);
          axio();
          digitalWrite(array4[i],LOW);
          digitalWrite(array4[i+1],LOW);
          delay(delay2);
           axio();
        }
  }
}

void pattern3(int delay3)
{
     while(y == 0 && x == 3)
    {
        axio();
        for(int i = 0; i <= 6;i++)
      {
        axio();
        digitalWrite(array3[i],HIGH);
        delay(delay3);
         axio();
        digitalWrite(array3[i],LOW);
        delay(delay3);
         axio();
      }
    }
}

void pattern4(int delay4)
{  
    while (y == 0 && x == 4){
        axio();
        digitalWrite(red,HIGH);
        delay(delay4);
        axio();
        digitalWrite(yellow1,HIGH);
        digitalWrite(yellow2,HIGH);
        delay(delay4);
        axio();
        digitalWrite(red,LOW);
        digitalWrite(green1,HIGH);
        digitalWrite(green2,HIGH);
        digitalWrite(green3,HIGH);
        delay(100);
        axio();
        digitalWrite(yellow1,LOW);
        digitalWrite(yellow2,LOW);
        delay(delay4);
        axio();
        digitalWrite(yellow1,HIGH);
        digitalWrite(yellow2,HIGH);
        delay(delay4);
        axio();
        digitalWrite(green1,LOW);
        digitalWrite(green2,LOW);
        digitalWrite(green3,LOW);
        digitalWrite(red,HIGH);
        delay(100);
        axio();
        digitalWrite(yellow1,LOW);
        digitalWrite(yellow2,LOW);
        delay(100);
        axio();
        } 
}

void pattern5(int delay5)
{
  while(y == 0 && x == 5)
  {
      axio();
      for(int i = 0 ; i<=6 ;i++)
      {
        axio();
        digitalWrite(array1[i],HIGH);
        delay(delay5);
         axio();
        digitalWrite(array1[i],LOW);
        delay(delay5);
         axio();
        }
  }
}

void testpatt()
{
  digitalWrite(green1,HIGH);
  digitalWrite(green2,HIGH);
  digitalWrite(green3,HIGH);
  digitalWrite(yellow1,HIGH);
  digitalWrite(yellow2,HIGH);
  digitalWrite(blue,HIGH);
  digitalWrite(red,HIGH);
  delay(delay1);
  off();
  delay(delay1);
}
  
int detectpress(int buttonState){
  if (buttonState == LOW && previousButtonState == HIGH && (millis() - firstButtonPressTime) > 200) 
  {
    firstButtonPressTime = millis();
  }
  holdingTime = (millis() - firstButtonPressTime);

  if (holdingTime > 50) 
  {
    if (buttonState == HIGH && previousButtonState == LOW) 
    {
      if (holdingTime <= 2000)
      {
        Serial.println("short button press"); 
        ShortP();

      }
      if (holdingTime > 2000) 
      {
        Serial.println("long button press"); 
        LongP();
      }
    }
  }
   previousButtonState = buttonState;
   previousHoldingTime = holdingTime;
    }

void ShortP()
{
        if(x <= 5){
          switch(x){
            case 0:
            testpatt();
            break;
            
            case 1:
            y = 0;
            delay1 = delay1/2;
            pattern1(delay1);
            break;
            
            case 2:
            y = 0;
            delay1 = delay1/2;
            pattern2(delay1);
            break;
            
            case 3:
            y = 0;
            delay1 = delay1/2;
            pattern3(delay1);
            break;
            
            case 4:
            y = 0;
            delay1 = delay1/2;
            pattern4(delay1);
            break;
            
            case 5:
            y = 0;
            delay1 = delay1/2;
            pattern5(delay1);
            break;
            }
          }   
}

void LongP()
{
   x++;
        if (x <= 5){
          switch(x){
            case 1:
            y = 0;
            delay1 = 600;
            pattern1(delay1);
            break;
            
            case 2:
            y = 0;
            delay1 = 600;
            pattern2(delay1);
            break;
            
            case 3:
            y = 0;
            delay1 = 600;
            pattern3(delay1);
            break;
            
            case 4:
            y = 0;
            delay1 = 600;
            pattern4(delay1);
            break;
            
            case 5:
            y = 0;
            delay1 = 600;
            pattern5(delay1);
            break;
            }
          }else if(x == 6){
          x = 0;
          delay1=600;
          }
}

void pushbutton(){
  buttonState = digitalRead(button);
  detectpress(buttonState);
  }


void axio()
{
   buttonState = digitalRead(button);
   if ( buttonState == 0){
      detectpress(buttonState);
      y = 1;
   }else
      y = 0;
}

void off()
{
  digitalWrite(green1,LOW);
  digitalWrite(green2,LOW);
  digitalWrite(green3,LOW);
  digitalWrite(yellow1,LOW);
  digitalWrite(yellow2,LOW);
  digitalWrite(blue,LOW);
  digitalWrite(red,LOW);
}
