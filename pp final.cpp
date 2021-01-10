//need to change this file to .ino to run it.

#include <Ultrasonic.h> // adding ultrasonic sensor's library 

const int trig = 12; // setting the pin of ultrassonic sensor' trigger
const int echo = 13; // setting the pin of ultrassonic sensor' echo

const int red1 = 8; // setting the pins of traffic lights' leds
const int yellow1 = 7;
const int green1 = 6;
const int green2 = 5;
const int yellow2 = 4;
const int red2 = 3;

int duration = 0;
int distance = 0;

void setup() 
{
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
  
  pinMode(red1 , OUTPUT);
  pinMode(yellow1 , OUTPUT);
  pinMode(green1 , OUTPUT);
  pinMode(green2 , OUTPUT);
  pinMode(yellow2 , OUTPUT);
  pinMode(red2 , OUTPUT);
  
  Serial.begin(9600); // starting connection to monitor serial and setting time recommended in ms

}

void loop()
{
  digitalWrite(trig, LOW); // "cleaning" the trigger
  delayMicroseconds(5);
  digitalWrite(trig, HIGH); // triggering
  delayMicroseconds(10);
  digitalWrite(trig, LOW);


  duration = pulseIn(echo , HIGH); // setting the const "duration" to get the time between the trigger and the returning
  distance = (duration/2) / 29.1 ; // dividing by two because it goes to ways (sensor-object-sensor) and after dividing it again by 29.1μs/cm (1/340.3 m/s [speed of sound] = 0.00291 seconds per meter or 29.1μs/cm)
  Serial.println(distance); // printing the distance in monitor serial
  

  if ( distance >= 5) // if the sensor detects a car (5cm is the minimum distance detected by the HC-SR04)...
  {
    delay(2000); // the main traffic lights turns yellow...
    digitalWrite(VERMELHO1, LOW);
    digitalWrite(AMARELO1, HIGH);
    digitalWrite(VERDE1, LOW);
    digitalWrite(VERMELHO2, HIGH);
    digitalWrite(AMARELO2, LOW);
    digitalWrite(VERDE2, LOW);
    delay(3000); // ... and after it turns red and the traffic lights of the side street turns green... 
    digitalWrite(VERMELHO1, HIGH);
    digitalWrite(AMARELO1, LOW);
    digitalWrite(VERDE1, LOW);
    digitalWrite(VERMELHO2, LOW);
    digitalWrite(AMARELO2, LOW);
    digitalWrite(VERDE2, HIGH);
    delay(30000); // and it stays that way for 30s and after turns yellow...
    digitalWrite(VERMELHO1, HIGH);
    digitalWrite(AMARELO1, LOW);
    digitalWrite(VERDE1, LOW);
    digitalWrite(VERMELHO2, LOW);
    digitalWrite(AMARELO2, HIGH);
    digitalWrite(VERDE2, LOW);
    delay(3000); // ... and after red, and the main traffic lights turns green again....
    digitalWrite(VERMELHO1, LOW);
    digitalWrite(AMARELO1, LOW);
    digitalWrite(VERDE1, HIGH);
    digitalWrite(VERMELHO2, HIGH);
    digitalWrite(AMARELO2, LOW);
    digitalWrite(VERDE2, LOW);
    delay(20000); // ... for at least 20s... this makes the traffic lights of the side street can't change the situation in this time.
  }
  else // if any other car be detected by the sensor, the traffic lights of main street stays green
  {
    digitalWrite(VERMELHO1, LOW);
    digitalWrite(AMARELO1, LOW);
    digitalWrite(VERDE1, HIGH);
    digitalWrite(VERMELHO2, HIGH);
    digitalWrite(AMARELO2, LOW);
    digitalWrite(VERDE2, LOW);
  }
}
