// #include "tests.h"
// #include "ForArduino.h"
// #include "Arduino.h"


// using namespace std;

void setup(){
	pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){
	// test_program();
	digitalWrite(LED_BUILTIN, 1);
	delay(100);
	digitalWrite(LED_BUILTIN, 0);
	delay(100);
}
