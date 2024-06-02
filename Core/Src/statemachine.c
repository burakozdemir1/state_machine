/*
 * statemachine.c
 *
 *  Created on: Jun 2, 2024
 *      Author: burak
 */

#include "statemachine.h"


extern int clockCount; // extern ifade initialize edilmez
state_Type current_state;


void(*state_table[])(void)={	state_LD1_function,
								state_LD2_function,
								state_LD3_function,
								state_LD4_function
// çağırılması gereken fonksiyon indeksleirni sırayla verdik  .bu dizi fonksiyonların adreslerini tutyor
// int *array[5] = {a,b,c,d,e};	gibi düşün
};

/*
 * main de state_table yi çağıracağım
 * bu benim state lerimi alacak örneğin STATE_LD1 aldıysa [] buraya init fonksioynu gelip
 * state_LD1_function fonksiyonunu çağırır
 *
 *
 * */

void stateMachine_init(void)
{
	current_state = STATE_LD1;

	clockCount=0;

	HAL_GPIO_WritePin(GPIOA , ld1_Pin , LED_OFF) ;
	HAL_GPIO_WritePin(GPIOA , ld2_Pin , LED_OFF) ;
	HAL_GPIO_WritePin(GPIOA , ld3_Pin , LED_OFF) ;
	HAL_GPIO_WritePin(GPIOA , ld4_Pin , LED_OFF) ;

}



void state_LD1_function(void)
{
	if(clockCount == 1)
	{
		current_state = STATE_LD2;
		HAL_GPIO_WritePin(GPIOA , ld1_Pin , LED_ON) ;
	}


}
void state_LD2_function(void)
{
	if(clockCount == 2)
	{
		current_state = STATE_LD3;
		HAL_GPIO_WritePin(GPIOA , ld1_Pin , LED_ON) ;
		HAL_GPIO_WritePin(GPIOA , ld2_Pin , LED_ON) ;
	}


}
void state_LD3_function(void)
{
	if(clockCount == 3)
	{
		current_state = STATE_LD4;
		HAL_GPIO_WritePin(GPIOA , ld1_Pin , LED_ON) ;
		HAL_GPIO_WritePin(GPIOA , ld2_Pin , LED_ON) ;
		HAL_GPIO_WritePin(GPIOA , ld3_Pin , LED_ON) ;
	}


}
void state_LD4_function(void)
{
	if(clockCount == 4)
	{
		current_state = STATE_LD1;
		HAL_GPIO_WritePin(GPIOA , ld1_Pin , LED_ON) ;
		HAL_GPIO_WritePin(GPIOA , ld2_Pin , LED_ON) ;
		HAL_GPIO_WritePin(GPIOA , ld3_Pin , LED_ON) ;
		HAL_GPIO_WritePin(GPIOA , ld4_Pin , LED_ON) ;

		HAL_Delay(200);

		HAL_GPIO_WritePin(GPIOA , ld1_Pin , LED_OFF) ;
		HAL_GPIO_WritePin(GPIOA , ld2_Pin , LED_OFF) ;
		HAL_GPIO_WritePin(GPIOA , ld3_Pin , LED_OFF) ;
		HAL_GPIO_WritePin(GPIOA , ld4_Pin , LED_OFF) ;
		HAL_Delay(200);

		clockCount=0;
	}


}











