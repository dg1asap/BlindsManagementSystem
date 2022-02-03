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

/**
 * @brief Funkcja inkrementująca liczbę sekund co sekundę i zerująca ją, gdy miną 24 godziny. 
 * @param servoScheduler Instancja struktury ServoScheduler
**/
void count(ServoScheduler* servoScheduler);

/**
 * @brief Funkcja zwracająca prawdę, gdy minęły 24 godziny. 
 * @param servoScheduler Instancja struktury ServoScheduler
**/
bool isTimerOutOfScope(ServoScheduler* servoScheduler);

/**
 * @brief Funkcja zerująca liczbę godzin. 
 * @param servoScheduler Instancja struktury ServoScheduler
**/
void resetTimer(ServoScheduler* servoScheduler);

/**
 * @brief Funkcja sprawdzająca, czy roleta może zostać podniesiona. 
 * @param servoScheduler Instancja struktury ServoScheduler
**/
uint16_t canSteerServoUp(ServoScheduler* servoScheduler);

/**
 * @brief Funkcja sprawdzająca, czy roleta może zostać obniżona. 
 * @param servoScheduler Instancja struktury ServoScheduler
**/
uint16_t canSteerServoDown(ServoScheduler* servoScheduler);

/**
 * @brief Funkcja zwracająca prawdę, gdy nastała pora podniesienia rolety. 
 * @param servoScheduler Instancja struktury ServoScheduler
**/
bool isServoUpTime(ServoScheduler* servoScheduler);

/**
 * @brief Funkcja zwracająca prawdę, gdy nastała pora obniżenia rolety. 
 * @param servoScheduler Instancja struktury ServoScheduler
**/
bool isServoDownTime(ServoScheduler* servoScheduler);

/**
 * @brief Funkcja ustawiająca porę podniesienia rolety. 
 * @param servoScheduler Instancja struktury ServoScheduler
 * @param newServoUpTime Pora podniesienia rolety.
**/
void setServoUpTime(ServoScheduler* servoScheduler, uint16_t newServoUpTime);

/**
 * @brief Funkcja ustawiająca porę obniżenia rolety. 
 * @param servoScheduler Instancja struktury ServoScheduler
 * @param newServoUpTime Pora obniżenia rolety.
**/
void setServoDownTime(ServoScheduler* servoScheduler, uint16_t newServoDownTime);

#endif /* INC_SERVOSCHEDULER_H_ */
