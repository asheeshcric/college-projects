int LM1 = 5;
int LM2 = 4;
int RM1 = 3;
int RM2 = 2;
int LeftEnable = 6;
int RightEnable = 9;

int Echo1 = 8;
int Trigger1 = 7;
int Echo2 = 13;
int Trigger2 = 12;


char input;
int a = 0;
int threshold = 10;
int pace = 100;

#include <SoftwareSerial.h>
SoftwareSerial BT(10, 11);
void setup()
{
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(LeftEnable, OUTPUT);
  pinMode(RightEnable, OUTPUT);
  
  pinMode(Echo1, INPUT);
  pinMode(Echo2, INPUT);
  pinMode(Trigger1, OUTPUT);
  pinMode(Trigger2, OUTPUT);
  BT.begin(9600);
  
}

void loop()
{
  if(BT.available())
    input = BT.read();
  
  //Serial.println(input);
  
  if(input == 'W')
    a = 1;
  else if(input == 'U')
    a = 0;
  else{}
  
  if(a == 0)
    manual(); 
  else if(a == 1)
  {
    automatic();
    input = BT.read();
    if(input == 'U')
      a = 0;
  }
}

void automatic()
{
  int distance1, distance2;
  distance1 = ultrasonic_sensor(Trigger1, Echo1);
  delay(30);
  distance2 = ultrasonic_sensor(Trigger2, Echo2);
  delay(30);
  Serial.print("leftSensor= ");
  Serial.print(distance1);
  Serial.print("\t\t\t");
  Serial.print("RightSensor= ");
  Serial.println(distance2);
  if(distance1 <= threshold && distance2 > threshold)
    left(100,120);
  else if(distance1 > threshold && distance2 <= threshold)
    right(120,100);
  else
    forward(70,70);
}

float ultrasonic_sensor(int trigPin, int echoPin)
{
  float duration, distance;
  digitalWrite(trigPin, LOW);
  //delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;
  return distance;
}

void manual()
{
  switch(input)
  {
    case 'F':
              forward(pace, pace);
              Serial.println('F');
              break;
    case 'B':
              backward(pace, pace);
              break;
    case 'R':
              right(pace, pace);
              break;
    case 'L':
              left(pace, pace);
              break;
    case 'I':
              slight_right(pace, pace);
              break;
    case 'G':
              slight_left(pace, pace);
              break;
    case 'H':
              back_left(pace, pace);
              break;
    case 'J':
              back_right(pace, pace);
              break;
    case '0':
              pace = 100;
              break;
    case '1':
              pace = 110;
              break;
    case '2':
              pace = 120;
              break;
    case '3':
              pace = 140;
              break;
    case '4':
              pace = 160;
              break;
    case '5':
              pace = 180;
              break;
    case '6':
              pace = 200;
              break;
    case '7':
              pace = 220;
              break;
    case '8':
              pace = 230;
              break;
    case '9':
              pace = 240;
              break;
    case '10':
              pace = 255;
              break;
    
    default:
              stop_bot(0, 0);
              break;
  }
}

void forward(int en1, int en2)
{
    analogWrite(LeftEnable, en1);
    analogWrite(RightEnable, en2);
    digitalWrite(LM1, 1);
    digitalWrite(LM2, 0);
    digitalWrite(RM1, 1);
    digitalWrite(RM2, 0);
}
void backward(int en1, int en2)
{
    analogWrite(LeftEnable, en1);
    analogWrite(RightEnable, en2);
    digitalWrite(LM1, 0);
    digitalWrite(LM2, 1);
    digitalWrite(RM1, 0);
    digitalWrite(RM2, 1);
}
void right(int en1, int en2)
{
    analogWrite(LeftEnable, en1);
    analogWrite(RightEnable, en2);
    digitalWrite(LM1, 1);
    digitalWrite(LM2, 0);
    digitalWrite(RM1, 0);
    digitalWrite(RM2, 1);
}
void left(int en1, int en2)
{
    analogWrite(LeftEnable, en1);
    analogWrite(RightEnable, en2);
    digitalWrite(LM1, 0);
    digitalWrite(LM2, 1);
    digitalWrite(RM1, 1);
    digitalWrite(RM2, 0);
}
void slight_right(int en1, int en2)
{
    analogWrite(LeftEnable, en1);
    analogWrite(RightEnable, en2);
    digitalWrite(LM1, 1);
    digitalWrite(LM2, 0);
    digitalWrite(RM1, 1);
    digitalWrite(RM2, 1);
}
void slight_left(int en1, int en2)
{
    analogWrite(LeftEnable, en1);
    analogWrite(RightEnable, en2);
    digitalWrite(LM1, 1);
    digitalWrite(LM2, 1);
    digitalWrite(RM1, 1);
    digitalWrite(RM2, 0);
}
void back_left(int en1, int en2)
{
    analogWrite(LeftEnable, en1);
    analogWrite(RightEnable, en2);
    digitalWrite(LM1, 1);
    digitalWrite(LM2, 1);
    digitalWrite(RM1, 0);
    digitalWrite(RM2, 1);
}
void back_right(int en1, int en2)
{
    analogWrite(LeftEnable, en1);
    analogWrite(RightEnable, en2);
    digitalWrite(LM1, 0);
    digitalWrite(LM2, 1);
    digitalWrite(RM1, 1);
    digitalWrite(RM2, 1);
}
void stop_bot(int en1, int en2)
{
    analogWrite(LeftEnable, en1);
    analogWrite(RightEnable, en2);
    digitalWrite(LM1, 1);
    digitalWrite(LM2, 1);
    digitalWrite(RM1, 1);
    digitalWrite(RM2, 1);
}
