/*********************************************************************************************************************
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		逐飞科技无线转串口模块
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ3184284598)
 * @version    		查看doc内version文件 版本说明
 * @Software 		MDK FOR C251
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2022-03-7
 * @note		
// *************************** 例程硬件连接说明 ***************************
//      模块管脚            单片机管脚
//      RX                  查看SEEKFREE_WIRELESS_CH573.h文件中WIRELESS_CH573_UART_RX宏定义的引脚 默认 P03
//      TX                  查看SEEKFREE_WIRELESS_CH573.h文件中WIRELESS_CH573_UART_TX宏定义的引脚 默认 P02
//      RTS                 查看SEEKFREE_WIRELESS_CH573.h文件中RTS_PIN宏定义的引脚 默认 P07
//      GND                 电源地
//      VCC                 5V电源
 ********************************************************************************************************************/
#ifndef _SEEKFREE_WIRELESS_CH573_H_
#define _SEEKFREE_WIRELESS_CH573_H_


#include "common.h"

#define WIRELESS_CH573_UART        		UART_4         //CH573转串口模块 所使用到的串口     
#define WIRELESS_CH573_UART_TX_PIN    	UART4_RX_P02
#define WIRELESS_CH573_UART_RX_PIN    	UART4_TX_P03
#define WIRELESS_CH573_TIMER_N    		TIM_2
#define WIRELESS_CH573_UART_BAUD   		115200
#define WIRELESS_CH573_DATA_BUF           S4BUF



#define RTS_PIN P10 			//定义流控位引脚  指示当前模块是否可以接受数据  0可以继续接收  1不可以继续接收
//#define CMD_PIN P05 			//定义命令引脚


void wireless_ch573_init(void);
void wireless_ch573_callback(void);

uint32 wireless_ch573_send_buff(uint8 *buff, uint16 len);



#endif
