#include "headfile.h"


uint8 send_test_dat[] = "wireless ch573 demo\r\n";

void main()
{
	DisableGlobalIRQ();
    sys_clk = 30000000;     //����ϵͳƵ��Ϊ30MHz
	board_init();
    
	init();
	EnableGlobalIRQ();
    while(1)
	{              
        Key_Driver();
//        wireless_ch573_send_buff(send_test_dat, sizeof(send_test_dat)); //��ʼ������ ���������Ϣ  
//		P52 = 0;	
        //delay_ms(1000);        
        //bee = 0;
        //NiMing(encoder_left, encoder_right, Right_Duty, Left_Duty, Target_Speed);
        //ccd_up();
        //VCAN();
        //wx_key();
    }
}

