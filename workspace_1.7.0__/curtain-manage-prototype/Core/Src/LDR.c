#include "LDR.h"

LDR ldr = {{0}, 0, 1, 1, 3000, 2000, 500, false};

//void LDR_Init(LDR* ldr)
//{
//	memset(ldr->messures, 0, sizeof ldr->messures);
//	ldr->averageMeasure = 0;
//	ldr->measureNumber = 1;
//	ldr->minReading = 1;
//	ldr->maxReading = 3000;
//	ldr->upperControlLimit = 2000;
//	ldr->lowerControlLimit = 500;
//}

uint16_t getLightIntensity(LDR* ldr) {
	HAL_ADC_PollForConversion(&hadc, HAL_MAX_DELAY);

	uint16_t lightIntensity;
	/* Check if the continous conversion of regular channel is finished */
	if ((HAL_ADC_GetState(&hadc) & HAL_ADC_STATE_REG_EOC) == HAL_ADC_STATE_REG_EOC)
		lightIntensity = HAL_ADC_GetValue(&hadc); /* Get the converted value of regular channel */

	return lightIntensity;
}

void measure(LDR* ldr) {
	ldr->messures[ldr->measureNumber - 1] = getLightIntensity(ldr);
	ldr->measureNumber++;

	if (measureIsAutoOfRange(ldr))
		ldr->measureNumber = 1;
}

bool measureIsAutoOfRange(LDR* ldr) {
	return ldr->measureNumber > NUMBER_OF_LDR_MEASURE;
}

bool areNewMeassures(LDR* ldr) {
	return ldr->measureNumber >= NUMBER_OF_LDR_MEASURE;
}

uint16_t getAverageMeassure(LDR* ldr) {
	ldr->averageMeasure = 0;
	for (int i = 0; i < NUMBER_OF_LDR_MEASURE; i++)
		ldr->averageMeasure += ldr->messures[i];

	return (ldr->averageMeasure/NUMBER_OF_LDR_MEASURE);
}

uint16_t convertPercentToValue(LDR* ldr, uint16_t percent) {
	uint16_t range = ldr->maxReading - ldr->minReading;
	return (ldr->minReading + (range * percent / 100));
}

uint16_t convertLDRvalueToPercent(LDR* ldr, uint16_t ldrValue) {
	return ((ldrValue / ldr->maxReading)*100);
}

bool isAboveUpperLimit(LDR* ldr) {
	return getAverageMeassure(ldr) > ldr->upperControlLimit;
}

bool isBelowLowerLimit(LDR* ldr) {
	return getAverageMeassure(ldr) < ldr->lowerControlLimit;
}

void setMinReading(LDR* ldr, uint16_t minReading_) {
	ldr->minReading = minReading_;
}

void setMaxReading(LDR* ldr, uint16_t maxReading_) {
	ldr->maxReading = maxReading_;
}

void setUpperControlLimit(LDR* ldr, uint16_t upperContolLimit_) {
	ldr->upperControlLimit = upperContolLimit_;
}

void setLowerControlLimit(LDR* ldr, uint16_t lowerControlLimit_) {
	ldr->lowerControlLimit = lowerControlLimit_;
}

uint16_t getMinReading(LDR* ldr) {
	return ldr->minReading;
}

uint16_t getMaxReading(LDR* ldr) {
	return ldr->maxReading;
}

uint16_t getUpperControlLimit(LDR* ldr) {
	return ldr->upperControlLimit;
}

uint16_t getLowerControlLimit(LDR* ldr) {
	return ldr->lowerControlLimit;
}

bool isTurnOn(LDR* ldr) {
	return ldr->turnOn;
}

void turn0n(LDR* ldr) {
	ldr->turnOn = true;
}

void turnOff(LDR* ldr) {
	ldr->turnOn = false;
}
