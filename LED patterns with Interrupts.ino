int green1=3;
int green2=4;
int green3=5;
int yellow1=6;
int yellow2=7;
int red=9 ;
int blue=8;
int button=18;
int x =0;
bool button_Press = false;

int delay1=600;
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
attachInterrupt(digitalPinToInterrupt(button), pushbutton, CHANGE);
}

void loop() 
{
patternPlay();
}
  
void detectpress(int buttonState){
  if (buttonState == LOW && previousButtonState == HIGH && (millis() - firstButtonPressTime) > 200) 
  {
    firstButtonPressTime = millis();
  }
  holdingTime = (millis() - firstButtonPressTime);

  if (holdingTime > 50) 
  {
    if (buttonState == HIGH && previousButtonState == LOW) 
    {
      if (holdingTime <= 400)
      {
        Serial.println("short button press");
        delay1 = delay1/2;
      }
      if (holdingTime > 400) 
      {
        Serial.println("long button press");
        delay1 = 600;
        x++;
      }
    }
  }
   previousButtonState = buttonState;
   previousHoldingTime = holdingTime;
}

void pushbutton()
{
       button_Press = true;
       buttonState = digitalRead(button);
       detectpress(buttonState);
}

void pattern1(int delay1)
{
   for(int i = 0; i <= 3;i++)
  {
    digitalWrite(array2[i],HIGH);
    delay(delay1);
    digitalWrite(array2[i],LOW);
    delay(delay1);
  }
}
void pattern2(int delay2)
{
  for(int i = 0; i <= 6; i++)
  {
  digitalWrite(array4[i],HIGH);
  digitalWrite(array4[i+1],HIGH);
  delay(delay2);
  digitalWrite(array4[i],LOW);
  digitalWrite(array4[i+1],LOW);
  delay(delay2);
  }
}    

void pattern3(int delay3)
{
    for(int i = 0; i <= 6;i++)
  {
    digitalWrite(array3[i],HIGH);
    delay(delay3);
    digitalWrite(array3[i],LOW);
    delay(delay3);
  }
}

void pattern4(int delay4)
{
digitalWrite(red,HIGH);
delay(delay4);
digitalWrite(yellow1,HIGH);
digitalWrite(yellow2,HIGH);
delay(delay4);
digitalWrite(red,LOW);
digitalWrite(green1,HIGH);
digitalWrite(green2,HIGH);
digitalWrite(green3,HIGH);
delay(delay4);
digitalWrite(yellow1,LOW);
digitalWrite(yellow2,LOW);
delay(delay4);
digitalWrite(yellow1,HIGH);
digitalWrite(yellow2,HIGH);
delay(delay4);
digitalWrite(green1,LOW);
digitalWrite(green2,LOW);
digitalWrite(green3,LOW);
digitalWrite(red,HIGH);
delay(delay4);
digitalWrite(yellow1,LOW);
digitalWrite(yellow2,LOW);
}

void  pattern5(int delay5){
  for(int i = 0 ; i<=6 ;i++){
    digitalWrite(array1[i],HIGH);
    delay(delay5);
    digitalWrite(array1[i],LOW);
    delay(delay5);
    }
}

void off(){
   digitalWrite(green1,LOW);
  digitalWrite(green2,LOW);
  digitalWrite(green3,LOW);
  digitalWrite(yellow1,LOW);
  digitalWrite(yellow2,LOW);
  digitalWrite(blue,LOW);
  digitalWrite(red,LOW);
}

void patternPlay()
{
    if (x <= 5){
  switch (x){
    case 0:
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
 
    break;

    case 1:
    pattern1(delay1);
    break;

    case 2:
    pattern2(delay1);
    break;

    case 3:
    pattern3(delay1);
    break;

    
    case 4:
    pattern4(delay1);
    break;

    case 5:
    pattern5(delay1);
    break;
  }}
  else if (x == 6){
    delay1 = 300;
    x = 0;
    }
  
}
