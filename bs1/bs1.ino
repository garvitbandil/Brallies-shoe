//pins of US and BUZZER
int const trigPin = 10;
int const echoPin = 9;
int const buzzPin = 7;
int const motor= 4;
void setup()
{
pinMode(trigPin, OUTPUT); // trig pin will have p nbulses output
pinMode(echoPin, INPUT); // echo pin should be input to get pulse width
pinMode(buzzPin, OUTPUT); // buzz pin is output to control buzzering
pinMode(motor, OUTPUT);
}
void loop()
{
// distance of obstackle in cm
int duration, distance;
// Output pulse with 1ms width on trigPin
digitalWrite(trigPin, HIGH);
delay(1);
digitalWrite(trigPin, LOW);
// Measure the pulse input in echo pin
duration = pulseIn(echoPin, HIGH);
// Distance is half the duration devided by 29.1 (from datasheet)
distance = (duration/2) / 29.1;
// if distance less than 0.5 meter and more than 0 (0 or less means over range)
if (distance <= 10)
{
digitalWrite(buzzPin, HIGH);
}
else
{
digitalWrite(buzzPin, LOW);
}
if (distance<=20)
{
  digitalWrite(motor, HIGH);
  tone(motor,1760);
}
else
{
  digitalWrite(motor, LOW);
}
delay(60);
}
