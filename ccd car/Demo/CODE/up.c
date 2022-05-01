#include "headfile.h"

void uart2_putbuff (uint8 *buff, uint16 len)
{
    while(len--)
    {
         uart_putchar(UART_2,*buff);
         buff++;
    }
}

void vcan_sendware(uint8 *wareaddr, uint16 waresize)
{ 
    uint8 cmdf[2] = {0x03, 0xfc};
    uint8 cmdr[2] = {0xfc, 0x03};
   
    uart_putbuff(UART_2,cmdf,sizeof(cmdf));
    uart_putbuff(UART_2,wareaddr,waresize);
    uart_putbuff(UART_2,cmdr,sizeof(cmdr));
}
uint16 warebuf[1];

void VCAN()
{
    warebuf[0]=555;
    
//    warebuf[0]=encoder_right;
//    warebuf[1]=encoder_left;
//    warebuf[2]=Right_Duty;
//    warebuf[3]=Left_Duty;
//    warebuf[4]=Target_Speed;
    
    vcan_sendware((uint8 *)warebuf,sizeof(warebuf));
}


#define BYTE0(dwTemp)       (*(char *)(&dwTemp))     //取出低字节
#define BYTE1(dwTemp)       (*((char *)(&dwTemp) + 1))     //    取存储在此变量下一内存字节的内容
#define BYTE2(dwTemp)       (*((char *)(&dwTemp) + 2))
#define BYTE3(dwTemp)       (*((char *)(&dwTemp) + 3))

uint8 Data_to_Send[100];

void NiMing(int16 A, int16 B, int16 C,int16 D,int16 E)
{
    static uint8 _cnt = 0;
	static uint8 i;
	static uint8 sumcheck = 0;
	static uint8 addcheck = 0;
    
    _cnt = 0;
    sumcheck = 0;
    addcheck = 0;
	
	Data_to_Send[_cnt++] = 0xAA;
	Data_to_Send[_cnt++] = 0xFF;
	Data_to_Send[_cnt++] = 0xF1;
	Data_to_Send[_cnt++] = 10;
	Data_to_Send[_cnt++] = BYTE1(A);
	Data_to_Send[_cnt++] = BYTE0(A);
	Data_to_Send[_cnt++] = BYTE1(B);
	Data_to_Send[_cnt++] = BYTE0(B);
	Data_to_Send[_cnt++] = BYTE1(C);
	Data_to_Send[_cnt++] = BYTE0(C);
	Data_to_Send[_cnt++] = BYTE1(D);
	Data_to_Send[_cnt++] = BYTE0(D);
    Data_to_Send[_cnt++] = BYTE1(E);
	Data_to_Send[_cnt++] = BYTE0(E);
	
	for(i = 0; i < _cnt; i++)
	{
		sumcheck += Data_to_Send[i];
		addcheck += sumcheck;
	}

	Data_to_Send[_cnt++] = sumcheck;
	Data_to_Send[_cnt++] = addcheck;
    uart_putbuff(UART_1,Data_to_Send,_cnt);
}

void ccd_up()
{
	if(KEY1==1){
        
    if(tsl1401_finish_flag){
        
		//发送图像到上位机
		//ccd_send_data(UART_1, ccd_data);
        ccd_send_data(UART_1, ccd_value);
        //ips_show_ccd1(ccd_value);
        
		//采集完成标志位清除			
		tsl1401_finish_flag = 0;	
    }
	}
	
	if(KEY1==0){  
		if(tsl1401_finish_flag2){
        
		//发送图像到上位机
		//ccd_send_data(UART_1, ccd_data);
        ccd_send_data(UART_1, ccd_value2);
        //ips_show_ccd2(ccd_value2);
        
		//采集完成标志位清除			
		tsl1401_finish_flag2 = 0;	
    }
	}
}