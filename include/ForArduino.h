
// http://www.avrfreaks.net/forum/avr-c-micro-how?name=PNphpBB2&file=viewtopic&t=59453
#ifndef ForArduino_h
#define ForArduino_h

#include <stdlib.h>

#ifdef ARDUINO
// void * operator new(size_t size)
// {
//   return malloc(size);
// }
//
// void operator delete(void * ptr)
// {
//   free(ptr);
// }
//
// void * operator new[](size_t size)
// {
//     return malloc(size);
// }
//
// void operator delete[](void * ptr)
// {
//     free(ptr);
// }
#include "Arduino.h"
#endif
#endif
