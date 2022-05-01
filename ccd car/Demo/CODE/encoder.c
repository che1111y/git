#include "headfile.h"


int16 dat_left[5],dat_right[5],encoder_left,encoder_right;
float en_suml=0,en_sumr=0; 
int en_datl[5],en_datr[5];
uint8 e,e_val=5;

void encoder_init()
{
	ctimer_count_init(CTIM0_P34);
	ctimer_count_init(CTIM3_P04);
}

void encoder_get()
{
    int i ;
		if(DIR_LEFT == 1)
		{
            for(i=0;i<5;i++)
            {
                dat_left[i] = ctimer_count_read(CTIM0_P34);
            }
		}
		else
		{
            for(i=0;i<5;i++)
            {
                dat_left[i] = ctimer_count_read(CTIM0_P34) * -1;
            }
		}
		
		if(DIR_RIGHT == 1)
		{
            for(i=0;i<5;i++)
            {
                dat_right[i] = ctimer_count_read(CTIM3_P04) * -1;
            }
		}
		else
		{
            for(i=0;i<5;i++)
            {
                dat_right[i] = ctimer_count_read(CTIM3_P04);
            }
		}
		
//        en_suml = ctimer_count_read(CTIM0_P34);
		ctimer_count_clean(CTIM0_P34);
		ctimer_count_clean(CTIM3_P04);
		
        for(e=0;e<e_val;e++)															
        {
            en_datl[e]=dat_left[e];
        }
        en_suml = en_datl[0]*0.05+en_datl[1]*0.1+en_datl[2]*0.15+en_datl[3]*0.3+en_datl[4]*0.4;
        
        for(e=0;e<e_val;e++)															
        {
            en_datr[e]=dat_right[e];
        }
        en_sumr = en_datr[0]*0.05+en_datr[1]*0.1+en_datr[2]*0.15+en_datr[3]*0.3+en_datr[4]*0.4;
        
		encoder_left = en_suml;
		encoder_right = en_sumr;
}