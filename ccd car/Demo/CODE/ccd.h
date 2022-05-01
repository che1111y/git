#ifndef ccd_h
#define ccd_h

#include "headfile.h"

extern float ccd_cbh11,ccd_cbh12,ccd_cbh21,ccd_cbh22;
extern int Lboundary_data,Rboundary_data,Lboundary_data2,Rboundary_data2;
extern int mid,df;
extern int road_width1,road_width2;

extern int black,Rboundary_black,Lboundary_black,Rboundary_black2,Lboundary_black2;
extern float black_cbh11,black_cbh12,black_cbh21,black_cbh22;
extern int Broad_width1,Broad_width2;
extern int outblack_cbh1,outblack_cbh2;
extern int Outside_black1,Outside_black2;

extern uint8 Auto; //¶¯Ì¬ãÐÖµ
extern int16 Threshold;

extern uint16 ccd_valu[128][4];
extern uint16  ccd_valu1[128][4],ccd_value[128],ccd_sum[128];

extern uint16 ccd_valu2[128][4];
extern uint16  ccd_valu2[128][4],ccd_value2[128],ccd_sum2[128];
extern int ccd_bina_data[128];


void ccd_bina();
void ccd_filter();
void ccd_filter2();
void Ccd_cbh(uint8 *image);
uint16 CCD_Average(uint8 *image);
uint8  Auto_Threshold(uint8 *image);
void ccd_xj();

#endif