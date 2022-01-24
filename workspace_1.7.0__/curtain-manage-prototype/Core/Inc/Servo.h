#ifndef INC_SERVO_H_
#define INC_SERVO_H_

#include "main.h"

/**
 * @brief Struktura przechowująca kluczowe zmienne związane z serwomechanizmem.
**/
typedef struct Servo {
    /** Maksymalna pozycja serwomechanizmu, odpowiadająca rolecie maksymalnie zwiniętej. **/
	uint16_t maxPosition;

    /** Obecna pozycja mechanizmu. **/
	uint16_t currentPositon;
	
    /** Następna pozycja serwomechanizmu. **/
    uint16_t newPosition;
} Servo;

/**
 * @brief Instancja struktury Servo, z przypisanymi parametrami początkowymi.
**/
extern Servo servo;

/**
 * @brief Funkcja podejmująca decyzję o ruchu rolety.
 * Decyzja zależy od tego, czy roleta nie jest w skrajnych pozycjach.
 * @param servo Instancja struktury Servo.
**/
void steer(Servo* servo);

/**
 * @brief Funkcja przesuwa serwo ku maksimum o zadaną wartość. Jeśli parametr będzie ujemny, przesuwa serwo ku minimum. Jeśli zadany parametr nie będzie pozwalał na wysterowanie rolety z powodu wyjścia poza minimum lub maksimum, parametr nie zostanie zmieniony, a serwo nie wysteruje się. 
 * @param servo Instancja struktury Servo.
 * @param length Długość, o którą ma zostać przesunięte serwo.
**/
void increasePositionBy(Servo* servo, uint16_t length);

/**
 * @brief Funkcja sprawdzająca, czy nowa pozycja rolety mieści się między maksimum a minimum.
 * @param servo Instancja struktury Servo.
 * @param newPosition_ Nowa pozycja rolety.
 * @return Prawda, jeżeli nowa pozycja rolety mieści się między maksimum a minimum.
**/
bool canSetPosition(Servo* servo, uint16_t newPosition_);

/**
 * @brief Funkcja ustawiająca nową pozycję rolety.
 * @param servo Instancja struktury Servo.
 * @param newPosition_ Nowa pozycja rolety.
**/
void setPosition(Servo* servo, uint16_t newPosition_);

/**
 * @brief Ustawia pozycję rolety na maksymalną.
 * @param servo Instancja struktury Servo.
**/
void setPositionToMax(Servo* servo);

/**
 * @brief Ustawia pozycję rolety na minimalną.
 * @param servo Instancja struktury Servo.
**/
void setPositionToMin(Servo* servo);

void setMaxPositon(Servo* servo, uint16_t maxPosition_);
uint16_t getMaxPositon(Servo* servo);

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

/**
 * @brief Funkcja sprawdzająca, czy roleta jest maksymalnie zwinięta.
 * @param servo Instancja struktury Servo.
 * @return Prawda, jeśli aktualna pozycja jest równa maksymalnej.
**/
bool isRolledMaxUp(Servo* servo);

/**
 * @brief Funkcja sprawdzająca, czy roleta jest maksymalnie rozwinięta.
 * @param servo Instancja struktury Servo.
 * @return Prawda, jeśli aktualna pozycja jest równa minimalnej.
**/
bool isRolledMaxDown(Servo* servo);

/**
 * @brief Funkcja sprawdzająca, czy roleta jest pod żądaną pozycją.
 * @param servo Instancja struktury Servo.
 * @return Prawda, jeśli roleta jest pod żądaną pozycją.
**/
bool isBelowNewPosition(Servo* servo);

/**
 * @brief Funkcja sprawdzająca, czy roleta jest nad żądaną pozycją.
 * @param servo Instancja struktury Servo.
 * @return Prawda, jeśli roleta jest nad żądaną pozycją.
**/
bool isAboveNewPosition(Servo* servo);

/**
 * @brief Sprawdza, czy długość rolety jest mniejsza od zadanego parametru.
 * @param servo Instancja struktury Servo.
 * @param blindLength Porównywana długość rolety.
 * @return Prawda, jeżeli długość rolety jest mniejsza od zadanego parametru.
**/
bool isShorterThan(Servo* servo, uint16_t blindLength);

/**
 * @brief Funkcja sprawdzająca, czy długość rolety jest większa lub równa 0.
 * @param servo Instancja struktury Servo.
 * @return Prawda, jeśli długość rolety jest większa lub równa 0.
**/
bool isPositiveLength(Servo* servo, uint16_t blindLength);

/**
 * @brief Funkcja obniżająca roletę.
 * Wywołuje macro, wprawiające serwo w ruch przeciwny do ruchu wskazówek zegara.
 * @param servo Instancja struktury Servo.
**/
void rollDown(Servo* servo);

/**
 * @brief Funkcja podwyższająca roletę.
 * Wywołuje macro, wprawiające serwo w ruch zgodny do ruchu wskazówek zegara.
 * @param servo Instancja struktury Servo.
**/
void rollUp(Servo* servo);

/**
 * @brief Funkcja zatrzymująca serwomechanizm.
 * Wywołuje macro, nadające serwomechanizmowi zerową prędkość.
**/
void stopRolling();

#endif /* INC_SERVO_H_ */
