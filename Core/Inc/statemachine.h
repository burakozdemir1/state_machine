/*
 * statemachine.h
 *
 *  Created on: Jun 2, 2024
 *      Author: burak
 */

#ifndef INC_STATEMACHINE_H_
#define INC_STATEMACHINE_H_

#include "main.h" // gpio ları dahil ettik

#define LED_OFF 0
#define LED_ON 	1

void stateMachine_init(void);
void state_LD1_function(void);
void state_LD2_function(void);
void state_LD3_function(void);
void state_LD4_function(void);

typedef enum
{
	STATE_LD1=0,
	STATE_LD2,
	STATE_LD3,
	STATE_LD4


}state_Type;




#endif /* INC_STATEMACHINE_H_ */
