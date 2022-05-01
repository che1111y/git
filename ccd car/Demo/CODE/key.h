#ifndef _key_H_
#define _key_H_


extern int pwm;

#define KEY1				P70                     //下
#define KEY2				P36                     //上
#define KEY3			    P71                    //左
#define KEY4				P37                    //右
#define KEY5				P41                     //确定
#define bmKEY1			P45                     //下
#define bmKEY2			P46                     //上
#define bmKEY3			P53                    //左
#define bmKEY4			P13                    //右

void key_init();
void key(void);
void wx_key();

#endif