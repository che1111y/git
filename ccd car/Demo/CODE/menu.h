/*
 * menu.h
 *
 *  Created on: 2021年11月17日
 *      Author: Administrator
 */
#ifndef _menu_h
#define _menu_h

#include "headfile.h"

typedef struct
{
    uint8 current;
    uint8 up;//向上翻索引号
    uint8 down;//向下翻索引号
    uint8 enter;//确认索引号
    void (*current_operation)(void);
}key_table;


void Key_Driver(void);


#endif
