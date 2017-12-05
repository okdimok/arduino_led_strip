// #include "tests.h"
// #include "ForArduino.h"
// #include "Arduino.h"


// using namespace std;

void setup(){
	// pinMode(LED_BUILTIN, OUTPUT);
	Serial.begin(115200);
}

int i = 0;

void loop(){
	// test_program();
	i+=1;
	Serial.println("Bew!");
	Serial.print(i);
	// digitalWrite(LED_BUILTIN, 1);
	// delay(100);
	// digitalWrite(LED_BUILTIN, 0);
	// delay(100);
}
