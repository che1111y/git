#include "headfile.h"


void main()
{
	DisableGlobalIRQ();
	board_init();
	init();
	EnableGlobalIRQ();
    while(1)
	{                                                                                                                                                                                                                                                                                                                                                                                                                    
        //bee = 0;
        //menu();
        display();
        //NiMing(encoder_left, encoder_right, Right_Duty, Left_Duty, Target_Speed);
        //ccd_up();
        //VCAN();
        //wx_key();
    }
}


