#ifndef INC_MYLIBRARY_H_
#define INC_MYLIBRARY_H_

#include <string.h>

#include "main.h"
#include "tim.h"
#include "rtc.h"
#include "myutilities.h"

extern UART_HandleTypeDef huart1;

/**
 * @brief Struktura przechowująca kluczowe zmienne związane z modułem bluetooth.
**/
typedef struct Bluetooth {
	/** Ciąg znaków wysyłany do modułu bluetooth **/
	char buffer[50];

	/** Indeks aktualnie przesyłanego znaku **/
	uint8_t buffer_index;

	/** Licznik czasu odczytu z bufora u celu optymalnego przesyłu danych. **/
	uint8_t timer_count;
} Bluetooth;

/**
 * @brief Instancja struktury Bluetooth, z przypisanymi parametrami początkowymi.
**/
extern Bluetooth bluetooth;

/**
 * @brief Funkcja obsługująca komendy wysłane do modułu bluetooth.
 * @param bluetooth Instancja struktury Bluetooth.
**/
void msgHandler(Bluetooth* bluetooth);

/**
 * @brief Funkcja ustawiająca roletę w najwyższym punkcie.
 * @param bluetooth Instancja struktury Bluetooth.
**/
void handleSerwoMaxUp(Bluetooth* bluetooth);

/**
 * @brief Funkcja ustawiająca roletę w najniższym punkcie.
 * @param bluetooth Instancja struktury Bluetooth.
**/
void handleSerwoMaxDown(Bluetooth* bluetooth);

/**
 * @brief Funkcja zwiększająca pozycję rolety o 1.
 * @param bluetooth Instancja struktury Bluetooth.
**/
void handleSerwoUp(Bluetooth* bluetooth);

/**
 * @brief Funkcja zmniejszająca pozycję rolety o 1.
 * @param bluetooth Instancja struktury Bluetooth.
**/
void handleSerwoDown(Bluetooth* bluetooth);

/**
 * @brief Funkcja ustawiająca fabryczne natężenie światła, po przekroczeniu którego roleta się opuszcza.
 * @param bluetooth Instancja struktury Bluetooth.
**/
void handleSetMinLDRreading(Bluetooth* bluetooth);

/**
 * @brief Funkcja ustawiająca fabryczne natężenie światła, po przekroczeniu którego roleta się podnosi.
 * @param bluetooth Instancja struktury Bluetooth.
**/
void handleSetMaxLDRreading(Bluetooth* bluetooth);

/**
 * @brief Funkcja ustawiająca górną wartość odczytu z fotorezystora, dla którego następuje wysterowanie.
 * @param bluetooth Instancja struktury Bluetooth.
**/
void handleSetUpperLDRcontrolLimit(Bluetooth* bluetooth);

/**
 * @brief Funkcja ustawiająca dolną wartość odczytu z fotorezystora, dla którego następuje wysterowanie.
 * @param bluetooth Instancja struktury Bluetooth.
**/
void handleSetLowerLDRcontrolLimit(Bluetooth* bluetooth);

/**
 * @brief Funkcja zwracająca fabryczne natężenie światła, po przekroczeniu którego roleta się opuszcza.
 * @param bluetooth Instancja struktury Bluetooth.
**/
void handlePrintMinLDRreading(Bluetooth* bluetooth);

/**
 * @brief Funkcja zwracająca fabryczne natężenie światła, po przekroczeniu którego roleta się podnosi.
 * @param bluetooth Instancja struktury Bluetooth.
**/
void handlePrintMaxLDRreading(Bluetooth* bluetooth);

/**
 * @brief Funkcja zwracająca górną wartość odczytu z fotorezystora, dla którego następuje wysterowanie.
 * @param bluetooth Instancja struktury Bluetooth.
**/
void handlePrintUpperLDRcontrolLimit(Bluetooth* bluetooth);

/**
 * @brief Funkcja zwracająca dolną wartość odczytu z fotorezystora, dla którego następuje wysterowanie.
 * @param bluetooth Instancja struktury Bluetooth.
**/
void handlePrintLowerLDRcontrolLimit(Bluetooth* bluetooth);

/**
 * @brief Funkcja obsługująca ustawienie maksymalnej długości serwo.
 * @param bluetooth Instancja struktury Bluetooth.
**/
void handleSetServoMaxPosition(Bluetooth* bluetooth);

/**
 * @brief Funkcja obsługująca wypisanie maksymalnej długości serwo.
 * @param bluetooth Instancja struktury Bluetooth.
**/
void handlePrintServoMaxPosition(Bluetooth* bluetooth);

/**
 * @brief Funkcja obsługująca niestandardową komendę.
 * @param bluetooth Instancja struktury Bluetooth.
**/
void handleIncorrectCommand(Bluetooth* bluetooth);

/**
 * @brief Funkcja obsługująca porę podwyższenia się rolety.
 * @param bluetooth Instancja struktury Bluetooth.
**/
void handleTimerUp(Bluetooth* bluetooth);

/**
 * @brief Funkcja obsługująca porę obniżenia się rolety.
 * @param bluetooth Instancja struktury Bluetooth.
**/
void handleTimerDown(Bluetooth* bluetooth);

/**
 * @brief Funkcja włączająca tryb automatyczny, gdzie za sterowanie odpowiada fotorezystor.
 * @param bluetooth Instancja struktury Bluetooth.
**/
void handleTurnOnLDR(Bluetooth* bluetooth);

/**
 * @brief Funkcja wyłączająca tryb automatyczny, gdzie za sterowanie odpowiada fotorezystor.
 * @param bluetooth Instancja struktury Bluetooth.
**/
void handleTurnOffLDR(Bluetooth* bluetooth);

/**
 * @brief Funkcja włączająca tryb harmonogramu dla rozwinięcia rolety.
 * @param bluetooth Instancja struktury Bluetooth.
**/
void handleSchedulerUpTurnOn(Bluetooth* bluetooth);

/**
 * @brief Funkcja wyłączająca tryb harmonogramu dla rozwinięcia rolety.
 * @param bluetooth Instancja struktury Bluetooth.
**/
void handleSchedulerUpTurnOff(Bluetooth* bluetooth);

/**
 * @brief Funkcja włączająca tryb harmonogramu dla zwinięcia rolety.
 * @param bluetooth Instancja struktury Bluetooth.
**/
void handleSchedulerDownTurnOn(Bluetooth* bluetooth);

/**
 * @brief Funkcja wyłączająca tryb harmonogramu dla zwinięcia rolety.
 * @param bluetooth Instancja struktury Bluetooth.
**/
void handleSchedulerDownTurnOff(Bluetooth* bluetooth);

/**
 * @brief Funkcja wyświetlająca informację na ekranie.
 * @param bluetooth Instancja struktury Bluetooth.
 * @param text Ciąg znaków, który ma być wyświetlony.
 * @param value Wartość, która ma by wyświetlona.
**/
void printValue(Bluetooth* bluetooth, char* text, uint16_t value);

#endif /* INC_MYLIBRARY_H_ */
