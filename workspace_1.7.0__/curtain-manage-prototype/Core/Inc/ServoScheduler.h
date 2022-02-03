#ifndef INC_SERVOSCHEDULER_H_
#define INC_SERVOSCHEDULER_H_

#include "main.h"

/**
 * @brief Struktura przechowująca zmienne związane z zarzadzniem harmonogramem wysterowywującym serwomechanizm.
**/
typedef struct ServoScheduler {
	/** Zmienna ozanczająca pozwolenie na sterowanie serwomechanizmem w górę. **/
	bool isServoUpOn;
	/** Zmienna ozanczająca pozwolenie na sterowanie serwomechanizmem w dół. **/
	bool isServoDownOn;
	/** Zmienna przechowująca czas wyrażony w sekundach po wystąpieniu którego serwomechanizm zostanie wysterowany w górę. **/
	uint16_t servoUpTime;
	/** Zmienna przechowująca czas wyrażony w sekundach po wystąpieniu którego serwomechanizm zostanie wysterowany w dół. **/
	uint16_t servoDownTime;
	/** Zegar czasu wyrażany w sekundach. **/
	uint16_t timer;
} ServoScheduler;

/**
 * @brief Instancja struktury ServoScheduler, z przypisanymi parametrami początkowymi.
**/
extern ServoScheduler servoScheduler;


/**
 * @brief Funkcja zwracająca true jeśli funckjonalność wysterowywania serwomechanizmu w górę jest włączona. 
 * @param servoScheduler Instancja struktury ServoScheduler
 * @return true jeśli funckjonalność wysterowywania serwomechanizmu w górę jest włączona. 
**/
bool isServoUpOn(ServoScheduler* servoScheduler);

/**
 * @brief Funkcja zwracająca true jeśli funckjonalność wysterowywania serwomechanizmu w dół jest włączona. 
 * @param servoScheduler Instancja struktury ServoScheduler
 * @return true jeśli funckjonalność wysterowywania serwomechanizmu w dół jest włączona. 
**/
bool isServoDownOn(ServoScheduler* servoScheduler);

/**
 * @brief Fukcja włączająca fukcjonalność wysterowywania serwomechanizmu w górę
 * @param servoScheduler Instancja struktury ServoScheduler
**/
void turnOnServoUp(ServoScheduler* servoScheduler);

/**
 * @brief Fukcja włączająca fukcjonalność wysterowywania serwomechanizmu w dół 
 * @param servoScheduler Instancja struktury ServoScheduler
**/
void turnOnServoDown(ServoScheduler* servoScheduler);

/**
 * @brief Fukcja wyłączająca fukcjonalność wysterowywania serwomechanizmu w górę
 * @param servoScheduler Instancja struktury ServoScheduler
**/
void turnOffServoUp(ServoScheduler* servoScheduler);

/**
 * @brief Fukcja wyłączająca fukcjonalność wysterowywania serwomechanizmu w dół 
 * @param servoScheduler Instancja struktury ServoScheduler
**/
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
