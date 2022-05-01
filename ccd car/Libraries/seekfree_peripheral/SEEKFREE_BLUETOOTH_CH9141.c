/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2021,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ����������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		��ɿƼ�����ת����ģ��
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		IAR 8.3 or MDK 5.33
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2021-08-27
 * @note		
					���߶��壺
					------------------------------------ 
					    ����ת����      ��Ƭ��                        
    					RX              �鿴SEEKFREE_BLUETOOTH_CH9141.h�ļ��е�BLUETOOTH_CH9141_UART_TX�궨��
    					TX              �鿴SEEKFREE_BLUETOOTH_CH9141.h�ļ��е�BLUETOOTH_CH9141_UART_RX�궨��
    					RTS             �鿴SEEKFREE_BLUETOOTH_CH9141.h�ļ��е�BLUETOOTH_CH9141_RTS_PIN�궨��
                        CTS             ����
    					CMD             ���ջ�������
					------------------------------------ 
 ********************************************************************************************************************/
#include "stdio.h"
#include "string.h"
#include "board.h"
#include "zf_gpio.h"
#include "zf_uart.h"
#include "zf_nvic.h"
#include "zf_delay.h"
#include <string.h>

#include "SEEKFREE_BLUETOOTH_CH9141.h"


uint8 uart_data;
uint8 uart_flag;

vuint8 at_mode = 0;         //0:����͸��ģʽ 1:ATģʽ 2:ģ�鸴λ��
vuint8 at_mode_num;         //atģʽʱ����ָʾ���ݽ��յ�����
vuint8 at_mode_data[30];    //����at����Ļ���
vuint8 at_mode_cmd_flag;    //OKӦ��������ճɹ��ı�־λ

uint8 mac_address[17];      //����mac��ַ


uint8 bluetooth_ch9141_rx_buffer;


static  fifo_struct     bluetooth_ch9141_fifo;
static  uint8           bluetooth_ch9141_buffer[BLUETOOTH_CH9141_BUFFER_SIZE];  // ���ݴ������

static          uint8   bluetooth_ch9141_data;

//-------------------------------------------------------------------------------------------------------------------
// @brief       FIFO ��ʼ�� ���ض�Ӧ������
// @param       *fifo           FIFO ����ָ��
// @param       *buffer_addr    Ҫ���صĻ�����
// @param       size            ��������С
// @return      fifo_state_enum ����״̬
// Sample usage:
//-------------------------------------------------------------------------------------------------------------------
fifo_state_enum fifo_init (fifo_struct *fifo, uint8 *buffer_addr, uint32 size)
{
    if(buffer_addr == NULL)
        return FIFO_BUFFER_NULL;
    fifo->buffer    = buffer_addr;
    fifo->head      = 0;
    fifo->end       = 0;
    fifo->size      = size;
    fifo->max       = size;
    return FIFO_SUCCESS;
}

//-------------------------------------------------------------------------------------------------------------------
// @brief       FIFO ͷָ��λ��
// @param       *fifo           FIFO ����ָ��
// @param       offset          ƫ����
// @return      void
// Sample usage:
//-------------------------------------------------------------------------------------------------------------------
void fifo_head_offset (fifo_struct *fifo, uint32 offset)
{
    fifo->head += offset;

    while(fifo->max <= fifo->head)                                              // �����Χ���������������С ֱ��С����󻺳�����С
    {
        fifo->head -= fifo->max;
    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief       FIFO βָ��λ��
// @param       *fifo           FIFO ����ָ��
// @param       offset          ƫ����
// @return      void
// Sample usage:
//-------------------------------------------------------------------------------------------------------------------
void fifo_end_offset (fifo_struct *fifo, uint32 offset)
{
    fifo->end += offset;

    while(fifo->max <= fifo->end)                                               // �����Χ���������������С ֱ��С����󻺳�����С
    {
        fifo->end -= fifo->max;
    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief       FIFO ���û�����
// @param       *fifo           FIFO ����ָ��
// @return      void
// Sample usage:
//-------------------------------------------------------------------------------------------------------------------
void fifo_clear (fifo_struct *fifo)
{
    fifo->head      = 0;
    fifo->end       = 0;
    fifo->size      = fifo->max;
}

//-------------------------------------------------------------------------------------------------------------------
// @brief       FIFO ��ѯ��ǰ���ݸ���
// @param       *fifo           FIFO ����ָ��
// @return      void
// Sample usage:
//-------------------------------------------------------------------------------------------------------------------
uint32 fifo_used (fifo_struct *fifo)
{
    return (fifo->max - fifo->size);
}

//-------------------------------------------------------------------------------------------------------------------
// @brief       �� FIFO ��д������
// @param       *fifo           FIFO ����ָ��
// @param       *dat            ������Դ������ָ��
// @param       length          ��Ҫд������ݳ���
// @return      fifo_state_enum ����״̬
// Sample usage:                if(fifo_write_buffer(&fifo,data,32)!=FIFO_SUCCESS) while(1);
//-------------------------------------------------------------------------------------------------------------------
fifo_state_enum fifo_write_buffer (fifo_struct *fifo, uint8 *dat, uint32 length)
{
    uint32 temp_length;

    if(length < fifo->size)                                                     // ʣ��ռ��㹻װ�±�������
    {
        DisableGlobalIRQ();
        temp_length = fifo->max - fifo->head;                                   // ����ͷָ����뻺����β���ж��ٿռ�

        if(length > temp_length)                                                // ���뻺����β���Ȳ���д������ ���λ������ֶβ���
        {
            memcpy(&fifo->buffer[fifo->head], dat, temp_length);                // ������һ������
            fifo_head_offset(fifo, temp_length);                                // ͷָ��ƫ��
            dat += temp_length;                                                 // ��ȡ����ƫ��
            memcpy(&fifo->buffer[fifo->head], dat, length - temp_length);       // ������һ������
            fifo_head_offset(fifo, length - temp_length);                       // ͷָ��ƫ��
        }
        else
        {
            memcpy(&fifo->buffer[fifo->head], dat, length);                     // һ������д��
            fifo_head_offset(fifo, length);                                     // ͷָ��ƫ��
        }

        fifo->size -= length;                                                   // ������ʣ�೤�ȼ�С
        DisableGlobalIRQ();
    }
    else
    {
        return FIFO_SPACE_NO_ENOUGH;
    }

    return FIFO_SUCCESS;
}

//-------------------------------------------------------------------------------------------------------------------
// @brief       �� FIFO ��ȡ����
// @param       *fifo           FIFO ����ָ��
// @param       *dat            Ŀ�껺����ָ��
// @param       *length         ��ȡ�����ݳ��� ���û����ô����������ᱻ�޸�
// @param       flag            �Ƿ��� FIFO ״̬ ��ѡ���Ƿ���ն�ȡ������
// @return      fifo_state_enum ����״̬
// Sample usage:                if(fifo_read_buffer(&fifo,data,32,FIFO_READ_ONLY)!=FIFO_SUCCESS) while(1);
//-------------------------------------------------------------------------------------------------------------------
fifo_state_enum fifo_read_buffer (fifo_struct *fifo, uint8 *dat, uint32 *length, fifo_operation_enum flag)
{
    uint8 data_check = 0;
    uint32 temp_length;

    if(*length > fifo_used(fifo))
    {
        *length = (fifo->max - fifo->size);                                     // ������ȡ�ĳ���
        data_check = 1;                                                         // ��־���ݲ���
    }

    temp_length = fifo->max - fifo->end;                                        // ����βָ����뻺����β���ж��ٿռ�
    if(*length <= temp_length)                                                  // �㹻һ���Զ�ȡ���
    {
        if(NULL != dat)    memcpy(dat, &fifo->buffer[fifo->end], *length);      // һ���Զ�ȡ���
    }
    else
    {
        if(NULL != dat)
        {
            memcpy(dat, &fifo->buffer[fifo->end], temp_length);                 // ������һ������
            memcpy(&dat[temp_length], &fifo->buffer[0], *length - temp_length); // �����ڶ�������
        }
    }

    if(flag == FIFO_READ_AND_CLEAN)                                             // ���ѡ���ȡ������ FIFO ״̬
    {
        DisableGlobalIRQ();
        fifo_end_offset(fifo, *length);                                         // �ƶ� FIFO ͷָ��
        fifo->size += *length;
        EnableGlobalIRQ();
    }

    return (data_check?FIFO_DATA_NO_ENOUGH:FIFO_SUCCESS);
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ����ת����ģ�� �����жϻص�����
//  @param      void
//  @return     void
//  Sample usage:
//  @note       �ú�����ISR�ļ� �����жϳ��򱻵���
//-------------------------------------------------------------------------------------------------------------------
void bluetooth_ch9141_uart_callback (void)
{
    // ��ȡ���ߴ��ڵ����� ������λ���ձ�־
    bluetooth_ch9141_data = BLUETOOTH_CH9141_DATA_BUF;
    fifo_write_buffer(&bluetooth_ch9141_fifo, &bluetooth_ch9141_data, 1);       // ���� FIFO
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ����ת����ģ���ʼ��
//  @param      mode            ����ģʽ MASTER_MODE(����)����SLAVE_MODE(�ӻ�)
// @return      uint8           ��ʼ��״̬ 0-�ɹ� 1-ʧ��
//  Sample usage:
//-------------------------------------------------------------------------------------------------------------------
uint8 bluetooth_ch9141_init (void)
{
    wireless_type = WIRELESS_CH9141;
    // ������ʹ�õĲ�����Ϊ115200 Ϊ����ת����ģ���Ĭ�ϲ����� ����������������ʹ����λ���޸�ģ�����
    fifo_init(&bluetooth_ch9141_fifo, bluetooth_ch9141_buffer, BLUETOOTH_CH9141_BUFFER_SIZE);
    uart_init(BLUETOOTH_CH9141_INDEX, BLUETOOTH_CH9141_TX_PIN, BLUETOOTH_CH9141_RX_PIN, BLUETOOTH_CH9141_BUAD_RATE, BLUETOOTH_CH9141_TIMER);
    return 0;
}



//-------------------------------------------------------------------------------------------------------------------
//  @brief      ����ת����ģ�� ���ͺ���
//  @param      buff            ��Ҫ���͵����ݵ�ַ
//  @param      len             ���ͳ���
//  @return     uint32          ʣ��δ���͵��ֽ���
//  Sample usage:
//-------------------------------------------------------------------------------------------------------------------
uint32 bluetooth_ch9141_send_buff (uint8 *buff, uint32 len)
{
    uint16 time_count = 0;
    while(len > 30)
    {
        time_count = 0;
        while(BLUETOOTH_CH9141_RTS_PIN && time_count++ < BLUETOOTH_CH9141_TIMEOUT_COUNT)  // ���RTSΪ�͵�ƽ���������������
            delay_ms(1);
        if(time_count >= BLUETOOTH_CH9141_TIMEOUT_COUNT)
            return len;                                                         // ģ��æ,���������ǰ����ʹ��while�ȴ� �����ʹ�ú���ע�͵�while�ȴ�����滻��if���
        uart_putbuff(BLUETOOTH_CH9141_INDEX, buff, 30);

        buff += 30;                                                             // ��ַƫ��
        len -= 30;                                                              // ����
    }

    time_count = 0;
    while(BLUETOOTH_CH9141_RTS_PIN && time_count++ < BLUETOOTH_CH9141_TIMEOUT_COUNT)      // ���RTSΪ�͵�ƽ���������������
        delay_ms(1);
    if(time_count >= BLUETOOTH_CH9141_TIMEOUT_COUNT)
        return len;                                                             // ģ��æ,���������ǰ����ʹ��while�ȴ� �����ʹ�ú���ע�͵�while�ȴ�����滻��if���
    uart_putbuff(BLUETOOTH_CH9141_INDEX, buff, len);                            // ������������

    return 0;
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ����ת����ģ�� ��ȡ����
//  @param      buff            �洢�����ݵ�ַ
//  @param      len             ����
//  @return     uint32          ʵ�ʶ�ȡ�ֽ���
//  Sample usage:
//-------------------------------------------------------------------------------------------------------------------
uint32 bluetooth_ch9141_read_buff (uint8 *buff, uint32 len)
{
    uint32 data_len = len;
    fifo_read_buffer(&bluetooth_ch9141_fifo, buff, &data_len, FIFO_READ_AND_CLEAN);
    return data_len;
}




