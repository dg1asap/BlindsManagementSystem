#include "ServoScheduler.h"

ServoScheduler servoScheduler = {false, false, 0, 0, 0};

bool isServoUpOn(ServoScheduler* servoScheduler) {
	return servoScheduler->isServoUpOn;
}

bool isServoDownOn(ServoScheduler* servoScheduler) {
	return servoScheduler->isServoDownOn;
}

void turnOnServoUp(ServoScheduler* servoScheduler) {
	servoScheduler->isServoUpOn = true;
}

void turnOnServoDown(ServoScheduler* servoScheduler) {
	servoScheduler->isServoDownOn = true;
}

void turnOffServoUp(ServoScheduler* servoScheduler) {
	servoScheduler->isServoUpOn = false;
}

void turnOffServoDown(ServoScheduler* servoScheduler) {
	servoScheduler->isServoDownOn = false;
}

void count(ServoScheduler* servoScheduler) {
	servoScheduler->timer++;
	if (isTimerOutOfScope(servoScheduler))
		resetTimer(servoScheduler);
}

bool isTimerOutOfScope(ServoScheduler* servoScheduler) {
	return servoScheduler->timer == 86400; // 86400s == 24h
}

void resetTimer(ServoScheduler* servoScheduler) {
	servoScheduler->timer = 0;
}

uint16_t canSteerServoUp(ServoScheduler* servoScheduler) {
	if (isServoUpOn(servoScheduler))
		return isServoUpTime(servoScheduler);
	return false;
}

uint16_t canSteerServoDown(ServoScheduler* servoScheduler) {
	if (isServoDownOn(servoScheduler))
		return isServoDownTime(servoScheduler);
	return false;
}

bool isServoUpTime(ServoScheduler* servoScheduler) {
	return servoScheduler->servoUpTime == servoScheduler->timer;
}

bool isServoDownTime(ServoScheduler* servoScheduler) {
	return servoScheduler->servoDownTime == servoScheduler->timer;
}

void setServoUpTime(ServoScheduler* servoScheduler, uint16_t newServoUpTime) {
	servoScheduler->servoUpTime = servoScheduler->timer + newServoUpTime;
	if (servoScheduler->servoUpTime > 86400)
		servoScheduler->servoUpTime = servoScheduler->servoUpTime - 86400;
}

void setServoDownTime(ServoScheduler* servoScheduler, uint16_t newServoDownTime) {
	servoScheduler->servoDownTime = servoScheduler->timer + newServoDownTime;
	if (servoScheduler->servoDownTime > 86400)
		servoScheduler->servoDownTime = servoScheduler->servoDownTime - 86400;
}
