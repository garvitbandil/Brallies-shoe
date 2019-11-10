//pins of US and BUZZER
int const trigPin = 10;
int const echoPin = 9;
int const buzzPin = 4;
int const motor= 7;
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
tone(buzzPin,1261);    
    // Waits some time to turn off
    delay(50);
    //Turns the buzzer off
    noTone(buzzPin); 
}
else if (distance <= 20)
{
  digitalWrite(buzzPin, HIGH);
tone(buzzPin,2500);    
    // Waits some time to turn off
    delay(150);
    //Turns the buzzer off
    noTone(buzzPin); 
}
else if (distance <= 30)
{
  digitalWrite(buzzPin, HIGH);
tone(buzzPin,2500);    
    // Waits some time to turn off
    delay(300);
    //Turns the buzzer off
    noTone(buzzPin); 
}
else
{
digitalWrite(buzzPin, LOW);
}
if (distance<=30)
{
  digitalWrite(motor, HIGH);
  
}
else if (distance <= 60)
{
  digitalWrite(motor, HIGH);
  tone(motor,10000);    
    // Waits some time to turn off
    delay(50);
    //Turns the buzzer off
    noTone(motor); 
 
 
}
else
{
  digitalWrite(motor, LOW);
}
delay(60);
}
