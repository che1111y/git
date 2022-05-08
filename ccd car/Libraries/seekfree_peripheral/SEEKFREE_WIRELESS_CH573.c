/*********************************************************************************************************************
 * �����������ݰ�Ȩ������ɿƼ����У�δ����������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		��ɿƼ�����ת����ģ��
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		MDK FOR C251 V9.60
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2022-03-7
 * @note		
// *************************** ����Ӳ������˵�� ***************************
//      ģ��ܽ�            ��Ƭ���ܽ�
//      RX                  �鿴SEEKFREE_WIRELESS_CH573.h�ļ���WIRELESS_CH573_UART_RX�궨������� Ĭ�� P03
//      TX                  �鿴SEEKFREE_WIRELESS_CH573.h�ļ���WIRELESS_CH573_UART_TX�궨������� Ĭ�� P02
//      RTS                 �鿴SEEKFREE_WIRELESS_CH573.h�ļ���RTS_PIN�궨������� Ĭ�� P07
//      GND                 ��Դ��
//      VCC                 5V��Դ
 ********************************************************************************************************************/
#include "SEEKFREE_WIRELESS_CH573.h"
#include "zf_uart.h"


//-------------------------------------------------------------------------------------------------------------------
//  @brief      573ת����ģ��ص�����
//  @param      NULL
//  @return     void					
//  @since      v1.0
//  Sample usage:	
//  @note       
//-------------------------------------------------------------------------------------------------------------------
void wireless_ch573_callback(void)
{
		uint8 wireless_573_rx_buffer = WIRELESS_CH573_DATA_BUF;
		//�ӵ�һ���ֽں�Ƭ��������봮���жϣ�ͨ���ڴ˴���ȡwireless_573_rx_buffer����ȡ������
}




//-------------------------------------------------------------------------------------------------------------------
//  @brief      573ת����ģ���ʼ��
//  @param      NULL
//  @return     void					
//  @since      v1.0
//  Sample usage:	
//  @note       
//-------------------------------------------------------------------------------------------------------------------
void wireless_ch573_init(void)
{
    wireless_type = WIRELESS_CH573;
    //������ʹ�õĲ�����Ϊ115200��Ϊ573ת����ģ���Ĭ�ϲ����ʣ�������������������������ģ�鲢�޸Ĵ��ڵĲ�����

		uart_init(WIRELESS_CH573_UART, WIRELESS_CH573_UART_TX_PIN, WIRELESS_CH573_UART_RX_PIN, WIRELESS_CH573_UART_BAUD, WIRELESS_CH573_TIMER_N);	//��ʼ������    
    
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      573ת����ģ�� ���ͺ���
//  @param      buff        ��Ҫ���͵����ݵ�ַ
//  @param      len         ���ͳ���
//  @return     uint32      ʣ��δ���͵��ֽ���   
//  @since      v1.0
//  Sample usage:	
//  @note       
//-------------------------------------------------------------------------------------------------------------------
uint32 wireless_ch573_send_buff(uint8 *buff, uint16 len)
{
    while(len>30)
    {
        if(RTS_PIN == 1)  
        {
            return len;//ģ��æ,���������ǰ����ʹ��while�ȴ� �����ʹ�ú���ע�͵�while�ȴ�����滻��if���
        }
        //while(RTS_PIN);  //���RTSΪ�͵�ƽ���������������
        uart_putbuff(WIRELESS_CH573_UART,buff,30);

        buff += 30; //��ַƫ��
        len -= 30;//����
    }
    
    if(RTS_PIN == 1)  
    {
        return len;//ģ��æ,���������ǰ����ʹ��while�ȴ� �����ʹ�ú���ע�͵�while�ȴ�����滻��if���
    }
    //while(RTS_PIN);  //���RTSΪ�͵�ƽ���������������
    uart_putbuff(WIRELESS_CH573,buff,len);//������������
    
    return 0;
}



