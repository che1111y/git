/*
 * menu.h
 *
 *  Created on: 2021��11��17��
 *      Author: Administrator
 */
#ifndef _menu_h
#define _menu_h

#include "headfile.h"

typedef struct
{
    uint8 current;
    uint8 up;//���Ϸ�������
    uint8 down;//���·�������
    uint8 enter;//ȷ��������
    void (*current_operation)(void);
}key_table;


void Key_Driver(void);


#endif
