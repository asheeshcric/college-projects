#include<SoftwareSerial.h>
SoftwareSerial BT(10, 12);

#define LeftEnable 6
#define RightEnable 9
#define LM1 4
#define LM2 5
#define RM1 2
#define RM2 3
int thres = 250;
int k = 0;

void setup()
{
    pinMode(LM1, OUTPUT);
    pinMode(LM2, OUTPUT);
    pinMode(RM1, OUTPUT);
    pinMode(RM2, OUTPUT);
    pinMode(LeftEnable, OUTPUT);
    pinMode(RightEnable, OUTPUT);
    Serial.begin(9600);
    BT.begin(9600);
}

void loop()
{
    if(BT.available())
    {
        char data = BT.read();
        Serial.println(data);
        
        if(data == 'W' || k == 1)
        {
             k = 1;
             Serial.println(k);
             automatic();
        }
        if( data == 'w')
        {
            k = 0;
        }
        
        if( k != 1)
       { 
          Serial.println(k);
          switch(data)
          {
              case 'F':
                        forward();
                        break;
              case 'R':
                        right();
                        break;
              case 'L':
                        left();
                        break;
              case 'B':
                        backward();
                        break;
              case 'S':
                        stop_bot();
                        break;
              default:
                        stop_bot();
                        break;
          }
       }
    }
}

void automatic()
{
    int s1 = analogRead(A0);
    int s2 = analogRead(A1);
    int s3 = analogRead(A2);
    Serial.print(s1);
    Serial.print(" ");
    Serial.print(s2);
    Serial.print(" ");
    Serial.println(s3);
    
    /*if(s1 == 1 && s2 == 0 && s3 == 0)
    {
                sensorleft();
                //left();
    }
    else if(s1 == 0 && s2 == 1 && s3 == 0)
    {
                sensorforward();
                //forward();
    }
    else if(s1 == 0 && s2 == 0 && s3 == 1)
    {
                sensorright();
                //right();
    }
    else if(s1 == 1 && s2 == 1 && s3 == 0)
    {
                sensorleft();
    }
    else if(s1 == 0 && s2 == 1 && s3 == 1)
    {
                sensorright();
    }
    else
    {
                stop_bot();
    }*/
    
   if(s1 < thres && s2 > thres && s3 > thres)
   {
       sensorleft();
   }
   else if(s1 > thres && s2 < thres && s3 > thres)
   {
       sensorforward();
   }
   else if(s1 > thres && s2 > thres && s3 < thres)
   {
       sensorright();
   }
   else if(s1 < thres && s2 < thres && s3 > thres)
   {
       sensorleft();
   }
   else if(s1 > thres && s2 < thres && s3 < thres)
   {
       sensorright();
   }
   else
   {
       stop_bot();
   }
}    
                
      

void forward()
{
    Serial.println("Forward Manual");
    analogWrite(LeftEnable, 200);
    digitalWrite(LM1, 1);
    digitalWrite(LM2, 0);
    analogWrite(RightEnable, 200);
    digitalWrite(RM1, 1);
    digitalWrite(RM2, 0);
}

void right()
{
    Serial.println("Right Manual");
    analogWrite(LeftEnable, 200);
    digitalWrite(LM1, 1);
    digitalWrite(LM2, 0);
    analogWrite(RightEnable, 100);
    digitalWrite(RM1, 0);
    digitalWrite(RM2, 1);
}

void left()
{
    Serial.println("Left Manual");
    analogWrite(RightEnable, 200);
    analogWrite(LeftEnable, 100);
    digitalWrite(RM1, 1);
    digitalWrite(RM2, 0);
    digitalWrite(LM1, 0);
    digitalWrite(LM2, 1);
}

void backward()
{
    Serial.println("Backward Manual");
    analogWrite(LeftEnable, 200);
    analogWrite(RightEnable, 200);
    digitalWrite(LM1, 0);
    digitalWrite(LM2, 1);
    digitalWrite(RM1, 0);
    digitalWrite(RM2, 1);
}

void stop_bot()
{
    analogWrite(LeftEnable, 0);
    analogWrite(RightEnable, 0);
    digitalWrite(LM1, 0);
    digitalWrite(LM2, 0);
    digitalWrite(RM1, 0);
    digitalWrite(RM2, 0);
}

void sensorforward()
{
    Serial.println("Auto Forward");
    analogWrite(LeftEnable, 150);
    analogWrite(RightEnable, 150);
    digitalWrite(LM1, 1);
    digitalWrite(LM2, 0);
    digitalWrite(RM1, 1);
    digitalWrite(RM2, 0);
}

void sensorright()
{
    Serial.println("Auto Right Turn");
    analogWrite(LeftEnable, 150);
    analogWrite(RightEnable, 80);
    digitalWrite(LM1, 1);
    digitalWrite(LM2, 0);
    digitalWrite(RM1, 0);
    digitalWrite(RM2, 1);
}

void sensorleft()
{
    Serial.println("Auto Left Turn");
    analogWrite(LeftEnable, 80);
    analogWrite(RightEnable, 150);
    digitalWrite(LM1, 0);
    digitalWrite(LM2, 1);
    digitalWrite(RM1, 1);
    digitalWrite(RM2, 0);
}
               
