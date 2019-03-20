#include <SoftwareSerial.h>
SoftwareSerial BT(11, 10); //Rx, Tx

#include <Servo.h>
Servo mys1, mys2, mys3, mys4, mys5, mys6;

int a1, a2, a3, a4, a5, a6;  //Potentiometer Values
int pos1[2000], pos2[2000], pos3[2000], pos4[2000], pos5[2000], pos6[2000];  //Positional Arrays for Servo Motors
int mpos1, mpos2, mpos3, mpos4, mpos5, mpos6;                          //Current positions of Servo Motors

int shift = 8;   //Least count angle for Servo Motors

char input;
int blue = 0;

int record_pinbutton = 22;
int play_pinbutton = 23;
int record_pin, play_pin;
int record_length;


//SETUP MODE
void setup()
{
  Serial.begin(9600);
  BT.begin(9600);
  
  mys1.attach(4);
  mys2.attach(5);
  mys3.attach(6);
  mys4.attach(7);
  mys5.attach(8);
  mys6.attach(9);
  
  mpos1 = 90;
  mpos2 = 90;
  mpos3 = 90;
  mpos4 = 90;
  mpos5 = 90;
  mpos6 = 90;
  
  mys1.write(mpos1);      //Initial States of all Servo Motors
  mys2.write(mpos2);
  mys3.write(mpos3);
  mys4.write(mpos4);
  mys5.write(mpos5);
  mys6.write(mpos6);
  
  pinMode(record_pinbutton, INPUT);
  pinMode(play_pinbutton, INPUT);
}


//PROGRAM LOOP
void loop()
{
  if(blue == 0)
  {
    if(BT.available())
      input = BT.read();
    Serial.print("Input from Bluetooth = ");
    Serial.println(input);
  }
  else
  {
    input = 'N';
    blue = 0;
  }
  switch(input)
      {
        case 'A':
          if(mpos1 > shift)
            mpos1 = mpos1 - shift;
          mys1.write(mpos1);
          blue = 1;
          Serial.print("1st Servo Angle = ");
          Serial.println(mpos1);
          break;
        case 'a':
          if(mpos1 < (180-shift))
            mpos1 = mpos1 + shift;
          mys1.write(mpos1);
          blue = 1;
          Serial.print("1st Servo Angle = ");
          Serial.println(mpos1);
          break;
        case 'B':
          if(mpos2 > shift)
            mpos2 = mpos2 - shift;
          mys2.write(mpos2);
          blue = 1;
          Serial.print("2nd Servo Angle = ");
          Serial.println(mpos2);
          break;
        case 'b':
          if(mpos2 < (180-shift))
            mpos2 = mpos2 + shift;
          mys2.write(mpos2);
          blue = 1;
          Serial.print("2nd Servo Angle = ");
          Serial.println(mpos2);
          break;
        case 'C':
          if(mpos3 > shift)
            mpos3 = mpos3 - shift;
          mys3.write(mpos3);
          blue = 1;
          Serial.print("3rd Servo Angle = ");
          Serial.println(mpos3);
          break;
        case 'c':
          if(mpos3 < (180-shift))
            mpos3 = mpos3 + shift;
          mys3.write(mpos3);
          blue = 1;
          Serial.print("3rd Servo Angle = ");
          Serial.println(mpos3);
          break;
        case 'D':
          if(mpos4 > shift)
            mpos4 = mpos4 - shift;
          mys4.write(mpos4);
          blue = 1;
          Serial.print("4th Servo Angle = ");
          Serial.println(mpos4);
          break;
        case 'd':
          if(mpos4 < (180-shift))
            mpos4 = mpos4 + shift;
          mys4.write(mpos4);
          blue = 1;
          Serial.print("4th Servo Angle = ");
          Serial.println(mpos4);
          break;
        case 'E':
          if(mpos5 > shift)
            mpos5 = mpos5 - shift;
          mys5.write(mpos5);
          blue = 1;
          Serial.print("5th Servo Angle = ");
          Serial.println(mpos5);
          break;
        case 'e':
          if(mpos5 < (180-shift))
            mpos5 = mpos5 + shift;
          mys5.write(mpos5);
          blue = 1;
          Serial.print("5th Servo Angle = ");
          Serial.println(mpos5);
          break;
        case 'F':
          if(mpos6 > shift)
            mpos6 = mpos6 - shift;
          mys6.write(mpos6);
          blue = 1;
          Serial.print("6th Servo Angle = ");
          Serial.println(mpos6);
          break;
        case 'f':
          if(mpos1 < (180-shift))
            mpos6 = mpos6 + shift;
          mys6.write(mpos6);
          blue = 1;
          Serial.print("6th Servo Angle = ");
          Serial.println(mpos6);
          break;  
        default:
          Serial.println("NOTHING IS PRESSED - SHOWING N");
          check_function();  //To check the record and play status
          break;
      }
}


//CHECKING THE STATUS OF RECORD AND PLAY
void check_function()
{
  Serial.println("Check Function Started");
  record_pin = digitalRead(record_pinbutton);
  play_pin = digitalRead(play_pinbutton);
  if(record_pin)
    record();
  else if(play_pin)
    play();
  else
    free_mode();
}

//RECORD MODE
void record()
{
  Serial.println("RECORDING.......................");
  delay(1000);
  int i;
    for(i=0; i<=1999; i++)
    {
          a1 = analogRead(A0); 
          a1 = map(a1, 0, 1023, 0, 179);
          a2 = analogRead(A1); 
          a2 = map(a2, 0, 1023, 0, 179);
          a3 = analogRead(A2); 
          a3 = map(a3, 0, 1023, 0, 179);
          a4 = analogRead(A3); 
          a4 = map(a4, 0, 1023, 0, 179);
          a5 = analogRead(A4); 
          a5 = map(a5, 0, 1023, 0, 179);
          a6 = analogRead(A5); 
          a6 = map(a6, 0, 1023, 0, 179);
          
          Serial.print(a1);
          Serial.print("\t");
          Serial.print(a2);
          Serial.print("\t");
          Serial.print(a3);
          Serial.print("\t");
          Serial.print(a4);
          Serial.print("\t");
          Serial.print(a5);
          Serial.print("\t");
          Serial.println(a6);
          
          pos1[i] = a1;
          pos2[i] = a2;
          pos3[i] = a3;
          pos4[i] = a4;
          pos5[i] = a5;
          pos6[i] = a6;
          
          mys1.write(a1);
          mys2.write(a2);
          mys3.write(a3);
          mys4.write(a4);
          mys5.write(a5);
          mys6.write(a6);
          
          record_length = i;  //To measure the duration of RECORDING LENGTH   
          
          int x = digitalRead(record_pinbutton);
          if(x)
          {
            Serial.println("RECORDING STOPPED!");
            delay(1000);
            break;
          }
          delay(15);
   }
}


//PLAY MODE
void play()
{
  Serial.println("PLAYING.................");
  delay(1000);
  int play_status = 1;
  
  while(1)
  {
      for(int i = 0; i <= record_length; i++)
      {
        mys1.write(pos1[i]);
        mys2.write(pos2[i]);
        mys3.write(pos3[i]);
        mys4.write(pos4[i]);
        mys5.write(pos5[i]);
        mys6.write(pos6[i]);
        
        int y = digitalRead(play_pinbutton);
        if(y)
        {
           Serial.println("PLAY LOOP STOPPED!");
           play_status = 0;
           delay(1000);
           break;
        }
        delay(15);  
      }
      if(!play_status)
        break;
  }
}


//FREE MODE - POTENTIOMETER MODE
void free_mode()
{
  a1 = analogRead(A0);
  a1 = map(a1, 0, 1023, 0, 179);
  a2 = analogRead(A1);
  a2 = map(a2, 0, 1023, 0, 179);
  a3 = analogRead(A2);
  a3 = map(a3, 0, 1023, 0, 179);
  a4 = analogRead(A3);
  a4 = map(a4, 0, 1023, 0, 179);
  a5 = analogRead(A4);
  a5 = map(a5, 0, 1023, 0, 179);
  a6 = analogRead(A5);
  a6 = map(a6, 0, 1023, 0, 179);
  
  mys1.write(a1);
  mys2.write(a2);
  mys3.write(a3);
  mys4.write(a4);
  mys5.write(a5);
  mys6.write(a6);
  delay(20);
}
