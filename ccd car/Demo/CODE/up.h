#ifndef _outputdata_H
#define _outputdata_H


void uart2_putbuff (uint8 *buff, uint16 len);
void vcan_sendware(uint8 *wareaddr, uint16 waresize);
void VCAN();
void ccd_up();
void NiMing(int16 A, int16 B, int16 C,int16 D,int16 E);
#endif 
