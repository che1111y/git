#ifndef adc_h
#define adc_h

#include "headfile.h"

extern int cbh;
extern float ad_value1,ad_value2,ad_value3,ad_value4;

void dc_init();
float Get_ADC(uint16 x);
void ADC(void);

#endif
