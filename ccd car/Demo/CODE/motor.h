#ifndef _motor_H_
#define _motor_H_

#include "headfile.h"

extern uint16 PWM_LeftOut,PWM_RightOut,Now_speed,PWM_Out;
extern float Target_Speed_L,Target_Speed_R;
extern uint16 Left_Duty,Right_Duty;
extern float L_Speed_KP,//150//45//30
             L_Speed_KI,//6//1.8
             L_Speed_KD;
extern float R_Speed_KP,//150//45//30
             R_Speed_KI,//6//1.8
             R_Speed_KD;

void motor_init();
void PWM_Output(int R_Duty,int L_Duty);
void PWM_Control(void);

#endif