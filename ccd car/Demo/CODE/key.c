#include "headfile.h"

int pwm;

//���뿪��
uint8 key1_boma=0;
uint8 key2_boma=0;
uint8 key3_boma=0;
uint8 key4_boma=0;

///*����ȥ����������> ����ֵ�����·��� 1 �����򷵻� 0 */
//uint8 Read_Key_Q(gpio_pin_enum key)
//{
//    if(gpio_get_level(key) == 0)
//    {
//        system_delay(10);//�ӳ�10Ms
//        if( gpio_get_level(key) == 0)
//        {
//            while(gpio_get_level(key) == 0);
//            return 1;
//        }
//    }
//    return 0;
//}

/***************���뿪��**************/
//void boma_set(void)
//{
//    //���뿪��
//    key1_boma  =  gpio_get_level(SW1);
//    key2_boma  =  gpio_get_level(SW2);
//}
