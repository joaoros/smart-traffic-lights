#include <Ultrasonic.h>

const int trigger = 12;
const int echo = 13;

const int firstRed = 3;
const int firstYellow = 5;
const int firstGreen = 6;
const int secondRed = 7;
const int secondYellow = 8;
const int secondGreen = 9;

int duration = 0;
int distance = 0;

void setup() 
{
  pinMode(trigger , OUTPUT);
  pinMode(echo , INPUT);
  
  pinMode(firstRed , OUTPUT);
  pinMode(firstYellow , OUTPUT);
  pinMode(firstGreen , OUTPUT);
  pinMode(secondRed , OUTPUT);
  pinMode(secondYellow , OUTPUT);
  pinMode(secondGreen , OUTPUT);
  
  Serial.begin(9600);

}

void loop()
{
  digitalWrite(trigger, LOW);
  delayMicroseconds(5);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);


  duration = pulseIn(echo , HIGH);
  distance = (duration/2) / 29.1 ;
  // dividing by two because it goes to ways (sensor-object-sensor) and after dividing it again 
  // by 29.1μs/cm (1/340.3 m/s [speed of sound] = 0.00291 seconds per meter or 29.1μs/cm)
  Serial.println(distance);
  

  if ( distance >= 5)
  {
    delay(2000);
    digitalWrite(firstRed, LOW);
    digitalWrite(firstYellow, HIGH);
    digitalWrite(firstGreen, LOW);
    digitalWrite(secondRed, HIGH);
    digitalWrite(secondYellow, LOW);
    digitalWrite(secondGreen, LOW);

    delay(3000);
    digitalWrite(firstRed, HIGH);
    digitalWrite(firstYellow, LOW);
    digitalWrite(firstGreen, LOW);
    digitalWrite(secondRed, LOW);
    digitalWrite(secondYellow, LOW);
    digitalWrite(secondGreen, HIGH);

    delay(30000);
    digitalWrite(firstRed, HIGH);
    digitalWrite(firstYellow, LOW);
    digitalWrite(firstGreen, LOW);
    digitalWrite(secondRed, LOW);
    digitalWrite(secondYellow, HIGH);
    digitalWrite(secondGreen, LOW);

    delay(3000);
    digitalWrite(firstRed, LOW);
    digitalWrite(firstYellow, LOW);
    digitalWrite(firstGreen, HIGH);
    digitalWrite(secondRed, HIGH);
    digitalWrite(secondYellow, LOW);
    digitalWrite(secondGreen, LOW);

    delay(20000);
  }
  else
  {
    digitalWrite(firstRed, LOW);
    digitalWrite(firstYellow, LOW);
    digitalWrite(firstGreen, HIGH);
    digitalWrite(secondRed, HIGH);
    digitalWrite(secondYellow, LOW);
    digitalWrite(secondGreen, LOW);
  }
}
