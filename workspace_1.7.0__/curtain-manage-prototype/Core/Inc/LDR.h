#ifndef INC_LDR_H_
#define INC_LDR_H_

#include "main.h"
#include "adc.h"

#define NUMBER_OF_LDR_MEASURE 5

typedef struct LDR {
	uint16_t messures[NUMBER_OF_LDR_MEASURE];
	uint16_t averageMeasure;
	uint8_t measureNumber;
	uint16_t minReading;
	uint16_t maxReading;
	uint16_t upperControlLimit;
	uint16_t lowerControlLimit;
} LDR;

extern LDR ldr;
//void LDR_Init(LDR* ldr);

/**
 * @brief Wskazuje poziom naświetlenia fotorezystora.
 * Wyjście fotorezystora podłączone jest do przetwornika analogowego-cyfrowego, który zwraca zdyskretyzowaną wartość natężenia światła.
 * @param ldr Instancja struktury LDR.
 * @return Wartość natężenia światła.
**/
uint16_t getLightIntensity(LDR* ldr);

/**
 * @brief Zapisuje ostatni pommiar.
 * Zapisuje ostatni pomiar do tablicy ostatnich pomiarów. Jeśli rozmiar tablicy został przekroczony, zapisuje pomiary na początku tablicy.
 * @param ldr Instancja struktury LDR.
**/
void measure(LDR* ldr);

/**
 * @brief Funkcja informująca, czy został przekroczony rozmiar tablicy.
 * Jeśli aktualna pozycja tablicy, gdzie będzie zapisana jasność, wychodzi poza tablicę, zwraca prawdę.
 * @param ldr Instancja struktury LDR.
 * @return Prawda, gdy aktualna pozycja wychodzi poza tablicę.
**/
bool measureIsAutoOfRange(LDR* ldr);

/**
 * @brief Funkcja informująca, czy tablica została wypełniona nowymi pomiarami.
 * Jeśli tak, następuje wystarowanie rolety.
 * @param ldr Instancja struktury LDR.
 * @return Prawda, gdy liczba nowych pomiarów jest równa wielkości tablicy.
**/
bool areNewMeassures(LDR* ldr);

/**
 * @brief Liczenie średniej ostatnich pomiarów.
 * Ostatecznym pomiarem jest średnia pięciu ostatnich pomiarów. Ma to zapobiec sterowaniu rolety przez przypadkowe i krótkotrwałe czynniki zewnętrzne.
 * @param ldr Instancja struktury LDR.
 * @return Średnia arytmetyczna ostatnich pięciu pomiarów.
**/
uint16_t getAverageMeassure(LDR* ldr);

/**
 * @brief Zamienia natężenie światła z procentów na wartości bezwzględne.
 * Deklarowany jest przedział, w którym ADC zwraca wartości i znając procent wyznacza się wartość bezwzględną.
 * @param ldr Instancja struktury LDR.
 * @param percent Procent przedziału.
 * @return Wartość odpowiadająca zadanemu procentowi, mieszcząca się w zbiorze wartości.
**/
uint16_t convertPercentToValue(LDR* ldr, uint16_t percent);

/**
 * @brief Zamienia natężenie światła z wartości bezwzględnej na procent przedziału.
 * Liczony jest stosunek wartości zwróconej przez ADC do maksymalnej możliwej do przyjęcia wartości.
 * @param ldr Instancja struktury LDR.
 * @param ldrValue Wartość z zadanego przedziału.
 * @return Wartość bezwzględna, mieszcząca się w zbiorze wartości.
**/
uint16_t convertLDRvalueToPercent(LDR* ldr, uint16_t ldrValue);

/**
 * @brief Funkcja informująca, czy natężenia światła zza okna przekracza wartość, dla której roleta zostaje podniesiona.
 * Jeśli tak, zostaje wywołana funkcja podnosząca roletę do góry.
 * @param ldr Instancja struktury LDR.
 * @return Prawda, jeśli natężenie za oknem jest większe od natężenie progowego, dla którego roleta się podnosi.
**/
bool isAboveUpperLimit(LDR* ldr);

/**
 * @brief Funkcja informująca, czy natężenia światła zza okna jest mniejsza od wartości, dla której roleta zostaje opuszczona.
 * Jeśli tak, zostaje wywołana funkcja opuszczająca roletę do dołu.
 * @param ldr Instancja struktury LDR.
 * @return Prawda, jeśli natężenie za oknem jest mniejsze od natężenie progowego, dla którego roleta się opuszcza.
**/
bool isBelowLowerLimit(LDR* ldr);

/**
 * @brief Funkcja ustawiająca fabryczne natężenie światła, po przekroczeniu którego roleta się opuszcza.
 * Funkcja przypisuje swój parametr polu struktury.
 * @param ldr Instancja struktury LDR.
 * @param minReading_ Nowe natężenie światła, po przekroczeniu którego roleta się opuści.
**/
void setMinReading(LDR* ldr, uint16_t minReading_);

/**
 * @brief Funkcja ustawiająca fabryczne natężenie światła, po przekroczeniu którego roleta się podnosi.
 * Funkcja przypisuje swój parametr polu struktury.
 * @param ldr Instancja struktury LDR.
 * @param maxReading_ Nowe natężenie światła, po przekroczeniu którego roleta się podniesie.
**/
void setMaxReading(LDR* ldr, uint16_t maxReading_);

/**
 * @brief Funkcja ustawiająca natężenie światła, po przekroczeniu którego roleta się podnosi.
 * Funkcja przypisuje swój parametr polu struktury.
 * @param ldr Instancja struktury LDR. 
 * @param upperContolLimit_ Nowe natężenie światła, po przekroczeniu którego roleta się podniesie.
**/
void setUpperControlLimit(LDR* ldr, uint16_t upperContolLimit_);

/**
 * @brief Funkcja ustawiająca natężenie światła, po przekroczeniu którego roleta się opuszcza.
 * Funkcja przypisuje swój parametr polu struktury.
 * @param ldr Instancja struktury LDR. 
 * @param lowerControlLimit_ Nowe natężenie światła, po przekroczeniu którego roleta się opuści.
**/
void setLowerControlLimit(LDR* ldr, uint16_t lowerControlLimit_);

/**
 * @brief Funkcja zwracająca fabryczne natężenie światła, po przekroczeniu którego roleta się opuszcza.
 * Fabryczne natężenie światła może się różnić w zależności od fotorezystora. Zostanie ono wyświetlone w aplikacji.
 * @param ldr Instancja struktury LDR.
 * @return 
**/
uint16_t getMinReading(LDR* ldr);

/**
 * @brief Funkcja zwracająca fabryczne natężenie światła, po przekroczeniu którego roleta się podnosi.
 * Fabryczne natężenie światła może się różnić w zależności od fotorezystora. Zostanie ono wyświetlone w aplikacji.
 * @param ldr Instancja struktury LDR.
 * @return 
**/
uint16_t getMaxReading(LDR* ldr);

/**
 * @brief Funkcja zwracająca natężenie światła, po przekroczeniu którego roleta się podnosi.
 * Zostanie ono wyświetlone w aplikacji.
 * @param ldr Instancja struktury LDR.
 * @return Natężenie światła, po przekroczeniu którego roleta się podnosi.
**/
uint16_t getUpperControlLimit(LDR* ldr);

/**
 * @brief Funkcja zwracająca aktualne natężenie światła, po przekroczeniu którego roleta się opuszcza.
 * Zostanie ono wyświetlone w aplikacji.
 * @param ldr Instancja struktury LDR.
 * @return Natężenie światła, po przekroczeniu którego roleta się opuszcza.
**/
uint16_t getLowerControlLimit(LDR* ldr);


#endif /* INC_LDR_H_ */
