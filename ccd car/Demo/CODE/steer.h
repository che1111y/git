#ifndef _STEER_H_
#define _STEER_H_

#include "headfile.h"

extern int Target_direction,Steer_PWMoutput,Mid_Value;
extern float steer_KP,
      steer_KD,
	  steer_KT;

void steer_init();
void steer_output(int Steer);
void dc_Steer_Control();
void ccd_Steer_Control();

#endif