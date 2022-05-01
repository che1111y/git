#include "headfile.h"

void init()
{
    //uart_init(UART_2, UART2_RX_P10, UART2_TX_P11, 115200, TIM_2);
    pit_timer_ms(TIM_4, 1);
    pit_timer_ms(TIM_1, 5);
    pit_timer_ms(TIM_3, 5);
	//dc_init();
	motor_init();
	menu_init();
    encoder_init();
	steer_init();
    ccd_init();
    //gpio_mode(P0_2,GPO_PP);
}
