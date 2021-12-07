/*! \file funkcje.h
    \brief Zbior uzytych funkcji.

    Wszytskie autorskie funkcje uzyte w projekcie.
*/

/*! \fn SetLCDValues(int zad, int wyj)
    \brief Ustawienie danych na wyswietlaczu.

    \param zad Wartosc zadana.
    \param wyj Wartosc pomiarowa.
*/

/*! \fn ReadIntegerLight(int* val)
    \brief Pobranie wartosci z czujnika jako wartosc calkowita.

    \param val Wskaźnik na zmienna przechowujaca zmierzona wartosc.
*/

/*! \fn SetPWM(int wej, int wyj, arm_pid_instance_f32 * PID,TIM_HandleTypeDef *htim3)
    \brief Ustawienie wartosci pwm sterujacego dioda, na podstawie regulatora PID.

    \param wej Wartosc zadana.
    \param val Wartosc zmierzona.
    \param val wskaznik na strukture PID.
    \param val wskaznik na taimer odpowiadajacy za pwm.
*/
#include "arm_math.h"
#include "main.h"
#ifndef INC_FUNKCJE_H_
#define INC_FUNKCJE_H_

void SetLCDValues(int zad, int wyj);
void ReadIntegerLight(int* val);
void SetPWM(int wej, int wyj, arm_pid_instance_f32 * PID,TIM_HandleTypeDef *htim3);
#endif /* INC_FUNKCJE_H_ */
