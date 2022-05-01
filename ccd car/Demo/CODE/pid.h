#ifndef _PID_H_
#define _PID_H_

#include "headfile.h"

int32 PID_Realize(float KP,float KI,float KD, float KT, int32 NowData, int32 Point);
uint32 PID_Increase(float KP,float KI,float KD, int32 NowData, int32 Point);
int32 PID_RIncrease(float KP,float KI,float KD, int32 NowData, int32 Point);
int32 PID_LIncrease(float KP,float KI,float KD, int32 NowData, int32 Point);
//int32 fuzzy_pid();

#endif