#ifndef INC_SERVO_H_
#define INC_SERVO_H_

typedef struct _Servo Servo;

#include "main.h"

uint16_t blind_height;
uint16_t current_blind_positon;
uint16_t newBlindPosition;

void steerBlind();
void increaseBlindPositionByLength(uint16_t length);
bool canSetBlindPosition(uint16_t newBlindPosition_);
void setBlindPosition(uint16_t newBlindPosition_);
void setBlindPositionToMax();
void setBlindPositionToMin();
bool canRollUpBlind();
bool canRollDownBlind();
bool canStopRollingBlind();
bool isRolledMaxUp();
bool isRolledMaxDown();
bool isBelowNewBlindPosition();
bool isAboveNewBlindPosition();
bool isLongerThanBlind(uint16_t blindLength);
bool isPositiveLength(uint16_t blindLength);
void rollDownBlind();
void rollUpBlind();
void stopRollingBlind();





#endif /* INC_SERVO_H_ */
