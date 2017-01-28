#include "Arduino.h"
#include "factorial.h"
//The setup function is called once at startup of the sketch
int counter;
void setup()
{
// Add your initialization code here
	Serial.begin(9600);
	Serial.println("Setup");
}

// The loop function is called in an endless loop
void loop()
{
	Serial.print("the next factorial...");
	Serial.println(factorial(counter));
	counter = (counter+1)%4;
	delay(1000);
//Add your repeated code here
}
