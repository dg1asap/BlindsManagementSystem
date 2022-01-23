#include "myutilities.h"

uint8_t stringCompare(char array1[], char array2[], uint16_t length) {
	uint8_t comVAR = 0, i;
	for (i=0; i<length; i++)
	{
		if (array1[i] == array2[i]) comVAR++;
		else comVAR = 0;
	}
	if (comVAR == length) return 1;
	else return 0;
}

char *getLastN(char *str, size_t n) {
    size_t len = strlen(str);
    return (char *)str + len - n;
}

uint16_t getLastWordAsInt(char *str) {
    char *word = strrchr(str, ' ') + 1;
    return (uint16_t)atoi(word);
}
