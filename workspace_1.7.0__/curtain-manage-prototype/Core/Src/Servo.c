#include "Servo.h"

struct _Servo {
	//int x;
};

uint16_t blind_height = 3;
uint16_t current_blind_positon = 3;
uint16_t newBlindPosition = 3;

void steerBlind() {
	if (canRollDownBlind()) {
		rollDownBlind();
	} else if (canRollUpBlind()) {
		rollUpBlind();
	} else if (canStopRollingBlind()) {
		stopRollingBlind();
	}
}

void increaseBlindPositionByLength(uint16_t length) {
	uint16_t newBlindPosition_ = length + newBlindPosition;
	if (canSetBlindPosition(newBlindPosition_)) {
		setBlindPosition(newBlindPosition_);
	}
}

bool canSetBlindPosition(uint16_t newBlindPosition_) {
	return !isLongerThanBlind(newBlindPosition_) && isPositiveLength(newBlindPosition_);
}

void setBlindPosition(uint16_t newBlindPosition_) {
	if (canSetBlindPosition(newBlindPosition_)) {
		newBlindPosition = newBlindPosition_;
	}
}

void setBlindPositionToMax() {
	newBlindPosition = blind_height;
}

void setBlindPositionToMin() {
	newBlindPosition = 0;
}

bool canRollUpBlind() {
	return isBelowNewBlindPosition() && isRolledMaxUp();
}

bool canRollDownBlind() {
	return isAboveNewBlindPosition() && isRolledMaxDown();
}

bool canStopRollingBlind() {
	return current_blind_positon == newBlindPosition;
}

bool isRolledMaxUp() {
	return current_blind_positon < blind_height;
}

bool isRolledMaxDown() {
	return current_blind_positon > 0;
}

bool isBelowNewBlindPosition() {
	return current_blind_positon < newBlindPosition;
}

bool isAboveNewBlindPosition() {
	return current_blind_positon > newBlindPosition;
}

bool isLongerThanBlind(uint16_t blindLength) {
	return blindLength > blind_height;
}

bool isPositiveLength(uint16_t blindLength) {
	return blindLength >= 0;
}

void rollDownBlind() {
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 1394);
	current_blind_positon--;
}

void rollUpBlind() {
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 1568);
	current_blind_positon++;
}

void stopRollingBlind() {
//	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 1474);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 1460);
}