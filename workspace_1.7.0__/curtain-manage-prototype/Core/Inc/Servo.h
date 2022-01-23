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

/**
 * @brief Funkcja sprawdzająca, czy można podwyższyć roletę.
 * Jeśli tak, serwomechanizm zaczyna się kręcić i podwyższa roletę.
 * @param servo Instancja struktury Servo.
 * @return Prawda, jeśli roleta nie jest zwinięta do końca.
**/
bool canRollUp(Servo* servo);

/**
 * @brief Funkcja sprawdzająca, czy można obniżyć roletę.
 * Jeśli tak, serwomechanizm zaczyna się kręcić i obniża roletę.
 * @param servo Instancja struktury Servo.
 * @return Prawda, jeśli roleta nie jest rozwinięta do końca.
**/
bool canRollDown(Servo* servo);

/**
 * @brief Funkcja sprawdzająca, czy roleta zmieniła swoją pozycję i czy aktualna pozycja pokrywa się z zadaną.
 * Jeśli tak, serwomechanizm przestaje się kręcić.
 * @param servo Instancja struktury Servo.
 * @return Prawda, jeśli aktualna pozycja pokrywa się z zadaną.
**/
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
