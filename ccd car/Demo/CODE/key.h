#ifndef _key_H_
#define _key_H_


extern int pwm;

#define KEY1				P70                     //��
#define KEY2				P36                     //��
#define KEY3			    P71                    //��
#define KEY4				P37                    //��
#define KEY5				P41                     //ȷ��
#define bmKEY1			P45                     //��
#define bmKEY2			P46                     //��
#define bmKEY3			P53                    //��
#define bmKEY4			P13                    //��

void key_init();
void key(void);
void wx_key();

#endif