#ifndef INC_LDR_H_
#define INC_LDR_H_

#define NUMBER_OF_LDR_MEASURE 5

#include <stdbool.h>

#include "main.h"
#include "adc.h"

typedef struct _LDR LDR;


uint16_t messureFromLdr[NUMBER_OF_LDR_MEASURE];
uint16_t averageMeasureFromLdr;
uint8_t ldrMeasureNumber;

void SetDarkness(LDR *ldr, bool val);
bool GetDarkness(LDR *ldr);

uint16_t getLightIntensity();
void measureLDR();
bool areNewMeassures();
bool measureIsAutoOfRange();
uint16_t getAverageMeassure();
void setMinLDRreading(uint16_t minLDRreading_);
void setMaxLDRreading(uint16_t maxLDRreading_);
void setUpperLDRControlLimit(uint16_t upperLDRContolLimit_);
void setLowerLDRControlLimit(uint16_t lowerLDRControlLimit_);
bool isAboverUpperLimit();
bool isBelowLowerLimit();
uint16_t getMinLDRreading();
uint16_t getMaxLDRreading();
uint16_t getUpperLDRControlLimit();
uint16_t getLowerLDRControlLimit();


#endif /* INC_LDR_H_ */