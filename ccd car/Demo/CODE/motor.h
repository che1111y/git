#ifndef _motor_H_
#define _motor_H_

#include "headfile.h"

extern uint16 PWM_LeftOut,PWM_RightOut,Now_speed,PWM_Out;
extern float Target_Speed;
extern uint16 Left_Duty,Right_Duty;
extern float Speed_KP,
			Speed_KI,
			Speed_KD;

void motor_init();
void PWM_Output(int R_Duty,int L_Duty);
void PWM_Control(void);

#endif