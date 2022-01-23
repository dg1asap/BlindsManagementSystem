#ifndef INC_SERVO_H_
#define INC_SERVO_H_

#include "main.h"

typedef struct Servo {
	uint16_t maxPosition;
	uint16_t currentPositon;
	uint16_t newPosition;
} Servo;

extern Servo servo;

void steer(Servo* servo);
void increasePositionBy(Servo* servo, uint16_t length);
bool canSetPosition(Servo* servo, uint16_t newPosition_);
void setPosition(Servo* servo, uint16_t newPosition_);
void setPositionToMax(Servo* servo);
void setPositionToMin(Servo* servo);
bool canRollUp(Servo* servo);
bool canRollDown(Servo* servo);
bool canStopRolling(Servo* servo);
bool isRolledMaxUp(Servo* servo);
bool isRolledMaxDown(Servo* servo);
bool isBelowNewPosition(Servo* servo);
bool isAboveNewPosition(Servo* servo);
bool isLongerThan(Servo* servo, uint16_t blindLength);
bool isPositiveLength(Servo* servo, uint16_t blindLength);
void rollDown(Servo* servo);
void rollUp(Servo* servo);
void stopRolling();

#endif /* INC_SERVO_H_ */
