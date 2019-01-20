int Echo1 = 8;
int Trigger1 = 7;
int Echo2 = 13;
int Trigger2 = 12;
//#define Trigger1 8
//#define Echo2 A5
//#define Trigger2 A4

int duration, distance;

//#include <SoftwareSerial.h>
//SoftwareSerial bluetooth(10, 11);  //RX, TX

void setup()
{
   pinMode(Echo1, INPUT);
   pinMode(Echo2, INPUT);
   pinMode(Trigger1, OUTPUT);
   pinMode(Trigger2, OUTPUT);
   Serial.begin(9600);
}

void loop()
{
  ultrasonic_sensor(Trigger1, Echo1);
  delay(30);
  ultrasonic_sensor(Trigger2, Echo2);
  delay(30);
  
}

void ultrasonic_sensor(int trigPin, int echoPin)
{
  digitalWrite(trigPin, LOW);
  //delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;
  Serial.print(echoPin);
  Serial.print("  = ");
  Serial.println(distance);
  delay(100);
}
