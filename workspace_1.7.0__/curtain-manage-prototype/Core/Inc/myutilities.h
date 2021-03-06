#ifndef INC_MYUTILITIES_H_
#define INC_MYUTILITIES_H_

#include <string.h>
#include <stdlib.h>

#include "main.h"

uint8_t stringCompare(char array1[], char array2[], uint16_t length);
char *getLastN(char *str, size_t n);
uint16_t getLastWordAsInt(char *str);

#endif /* INC_MYUTILITIES_H_ */
