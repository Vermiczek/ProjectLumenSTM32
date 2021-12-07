/*
 * funkcje.c
 *
 *  Created on: Feb 27, 2020
 *      Author: Vermik
 */

#include <funkcje.h>
#include "bh1750.h"

void SetLCDValues(int zad, int wyj)
{
	 lcd_clear();	//! Czyszczenie ekranu
	 char bufor[100]; ///< buffor wyswietlacza
	 lcd_put_cur(0,0);
	 if(zad <=190&&zad >=0) //! Przedzial skutecznosci sterowania.
		 sprintf(&bufor, "Lx_zad= %d", zad);
	 else if(zad>190) //! Pojedyncza dioda LED nie osiagnie wiekszej swiatlosci.
		 sprintf(&bufor, "I SEE FIRE");
	 else //! Dioda LED nie pochlonie swiatla.
		 sprintf(&bufor, "Dotarles na dno");
	 lcd_send_string(bufor);
	 lcd_put_cur(1,0);
	 sprintf(&bufor, "Lx_pom= %d", wyj);
	 lcd_send_string(bufor);
}
void ReadIntegerLight(int* val)
{
	float temp; ///< tymczasowa zmienna do przechowania danych z czujnika.
	BH1750_ReadLight(&temp); //! Odczyt danych z czujnika
	*val=(int)temp; //! Przypisanie pobranych danych do globalnej zmiennej
}
void SetPWM(int wej, int wyj, arm_pid_instance_f32 * PID,TIM_HandleTypeDef *htim3)
{
//
	int uchyb =wej-wyj; ///< uchyb sterowania
	int pid_return= arm_pid_f32(PID, uchyb); //! wartosc wypelnienia pwm zwrocona przez regulator PID

	if(pid_return<0) //! nie moze byc ujemnego wypelnienia
		pid_return=0;
	else if(pid_return >1000) //! nie moze byc wiekszego wypelnienia niz 100%
		pid_return=1000;

	__HAL_TIM_SET_COMPARE(htim3,TIM_CHANNEL_3, pid_return); //! ustawienie wypelnienia PWM
}
