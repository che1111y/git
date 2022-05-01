#ifndef _ENCODER_H_
#define _ENCODER_H_

#include "headfile.h"

#define DIR_RIGHT P77
#define DIR_LEFT P35

extern int16 dat_left[5],dat_right[5],encoder_left,encoder_right;

void encoder_init();
void encoder_get();

#endif