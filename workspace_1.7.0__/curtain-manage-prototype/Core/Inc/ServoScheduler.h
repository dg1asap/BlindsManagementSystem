#ifndef INC_SERVOSCHEDULER_H_
#define INC_SERVOSCHEDULER_H_

#include "main.h"

typedef struct ServoScheduler {
	bool isServoUpOn;
	bool isServoDownOn;
	uint16_t servoUpTime;
	uint16_t servoDownTime;
	uint16_t timer;
} ServoScheduler;

extern ServoScheduler servoScheduler;

bool isServoUpOn(ServoScheduler* servoScheduler);
bool isServoDownOn(ServoScheduler* servoScheduler);
void turnOnServoUp(ServoScheduler* servoScheduler);
void turnOnServoDown(ServoScheduler* servoScheduler);
void turnOffServoUp(ServoScheduler* servoScheduler);
void turnOffServoDown(ServoScheduler* servoScheduler);
void count(ServoScheduler* servoScheduler);
bool isTimerOutOfScope(ServoScheduler* servoScheduler);
void resetTimer(ServoScheduler* servoScheduler);
uint16_t canSteerServoUp(ServoScheduler* servoScheduler);
uint16_t canSteerServoDown(ServoScheduler* servoScheduler);
bool isServoUpTime(ServoScheduler* servoScheduler);
bool isServoDownTime(ServoScheduler* servoScheduler);
void setServoUpTime(ServoScheduler* servoScheduler, uint16_t newServoUpTime);
void setServoDownTime(ServoScheduler* servoScheduler, uint16_t newServoDownTime);

#endif /* INC_SERVOSCHEDULER_H_ */
