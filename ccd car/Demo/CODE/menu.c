#include "menu.h"
#include "key.h"
uint8   start_flag=0;     //������ɱ�־λ
uint16  start_time=0;     //����ʱ��
uint8 fun=0;
uint8 func_index=0;
//����״̬����
uint8 key1_status = 1;
uint8 key2_status = 1;
uint8 key3_status = 1;
uint8 key4_status = 1;
uint8 key5_status = 1;

//��һ�ο���״̬����
uint8 key1_last_status;
uint8 key2_last_status;
uint8 key3_last_status;
uint8 key4_last_status;
uint8 key5_last_status;

//���ر�־λ
uint8 key1_flag;
uint8 key2_flag;
uint8 key3_flag;
uint8 key4_flag;
uint8 key5_flag;


void (*current_operation_index)(void);


void fun1(void)
{
    fun=1;
    ips114_showstr(2,0,"image <-");
    ips114_showstr(2,0,"image");
    
    ips114_showstr(2,40,"engine");

    ips114_showstr(2,80,"motor");

    ips114_showstr(2,120,"start");
}
void fun2(void)
{
    fun=2;
    ips114_showstr(2,0,"image");

    ips114_showstr(2,40,"engine <-");
    ips114_showstr(2,40,"engine");
    
    ips114_showstr(2,80,"motor");

    ips114_showstr(2,120,"start");
}
void fun3(void)
{
    fun=3;
    ips114_showstr(2,0,"image");

    ips114_showstr(2,40,"engine");

    ips114_showstr(2,80,"motor <-");
    ips114_showstr(2,80,"motor");
    
    ips114_showstr(2,120,"start");
}
void fun4(void)
{
    fun=4;
    ips114_showstr(2,0,"image");

    ips114_showstr(2,40,"engine");

    ips114_showstr(2,80,"motor");

    ips114_showstr(2,120,"start <-");
    ips114_showstr(2,120,"start");
}
void fun5()
{
    fun=5;
//    ips114_showstr(0,60,"LCDW");   //��������ʹ��
//    ips114_showuint8(40,60,j);
//    ips114_showstr(0,80,"LCDH");
//    ips114_showuint8(40,80,k);
//    ips114_showstr(0,100,"steer");
//    ips114_showint16(40,100,steer_duty);
//    ips114_showstr(0,120,"out");
//    ips114_showfloat(40,120,Dir_error,3,3);
//    ips114_showstr(120,80,"<-");
}
void fun6()
{
    fun=6;
//    ips114_showstr(0,60,"LCDW");    //��������ʹ��
//    ips114_showuint8(40,60,j);
//    ips114_showstr(0,80,"LCDH");
//    ips114_showuint8(40,80,k);
//    ips114_showstr(0,100,"cir");
//    ips114_showuint8(40,100,leftcircle_judge_flag);
//    ips114_showuint8(80,100,rightcircle_judge_flag);
//    ips114_showstr(0,120,"shizi");
//    ips114_showuint8(40,120,re_flag_shizi);
//    ips114_showstr(0,140,"sancha");
//    ips114_showuint8(60,140,flag_sancha);
//    ips114_showstr(120,100,"<-");
}
void fun7()
{
    fun=7;
    /****���PD***/
//    ips114_showstr(0,0,"Dir_P");
//    ips114_showfloat(40,0,Dir_P,2,3);
//    ips114_showstr(0,20,"Dir_D");
//    ips114_showfloat(40,20,Dir_D,2,3);
//    /******�ٶ�PID**********/
//    ips114_showstr(0,40,"L_Speed_P");
//    ips114_showfloat(60,40,L_Speed_Kp,2,3);
//    ips114_showstr(0,60,"L_Speed_I");
//    ips114_showfloat(60,60,L_Speed_Ki,2,3);
//    ips114_showstr(0,80,"L_Speed_D");
//    ips114_showfloat(60,80,L_Speed_Kd,2,3);
//    ips114_showstr(120,0,"<-");
}
void fun8()
{
    fun=8;
    /****���PD***/
//    ips114_showstr(0,0,"Dir_P");
//    ips114_showfloat(40,0,Dir_P,2,3);
//    ips114_showstr(0,20,"Dir_D");
//    ips114_showfloat(40,20,Dir_D,2,3);
//    /******�ٶ�PID**********/
//    ips114_showstr(0,40,"L_Speed_P");
//    ips114_showfloat(60,40,L_Speed_Kp,2,3);
//    ips114_showstr(0,60,"L_Speed_I");
//    ips114_showfloat(60,60,L_Speed_Ki,2,3);
//    ips114_showstr(0,80,"L_Speed_D");
//    ips114_showfloat(60,80,L_Speed_Kd,2,3);
//    ips114_showstr(120,20,"<-");
}
void fun9()
{
    fun=9;
    /****���PD***/
//    ips114_showstr(0,0,"Dir_P");
//    ips114_showfloat(40,0,Dir_P,2,3);
//    ips114_showstr(0,20,"Dir_D");
//    ips114_showfloat(40,20,Dir_D,2,3);
//    /******�ٶ�PID**********/
//    ips114_showstr(0,40,"L_Speed_P");
//    ips114_showfloat(60,40,L_Speed_Kp,2,3);
//    ips114_showstr(0,60,"L_Speed_I");
//    ips114_showfloat(60,60,L_Speed_Ki,2,3);
//    ips114_showstr(0,80,"L_Speed_D");
//    ips114_showfloat(60,80,L_Speed_Kd,2,3);
//    ips114_showstr(120,40,"<-");
}
void fun10()
{
    fun=10;
    /****���PD***/
//    ips114_showstr(0,0,"Dir_P");
//    ips114_showfloat(40,0,Dir_P,2,3);
//    ips114_showstr(0,20,"Dir_D");
//    ips114_showfloat(40,20,Dir_D,2,3);
//    /******�ٶ�PID**********/
//    ips114_showstr(0,40,"L_Speed_P");
//    ips114_showfloat(60,40,L_Speed_Kp,2,3);
//    ips114_showstr(0,60,"L_Speed_I");
//    ips114_showfloat(60,60,L_Speed_Ki,2,3);
//    ips114_showstr(0,80,"L_Speed_D");
//    ips114_showfloat(60,80,L_Speed_Kd,2,3);
//    ips114_showstr(120,60,"<-");
}
void fun11()
{
    fun=11;
    /****���PD***/
//    ips114_showstr(0,0,"Dir_P");
//    ips114_showfloat(40,0,Dir_P,2,3);
//    ips114_showstr(0,20,"Dir_D");
//    ips114_showfloat(40,20,Dir_D,2,3);
//    /******�ٶ�PID**********/
//    ips114_showstr(0,40,"L_Speed_P");
//    ips114_showfloat(60,40,L_Speed_Kp,2,3);
//    ips114_showstr(0,60,"L_Speed_I");
//    ips114_showfloat(60,60,L_Speed_Ki,2,3);
//    ips114_showstr(0,80,"L_Speed_D");
//    ips114_showfloat(60,80,L_Speed_Kd,2,3);
//    ips114_showstr(120,80,"<-");
}
void fun12()
{
    fun=12;
//    ips114_showstr(0,0,"GoalSpeed_L");    //Ŀ���ٶ�����
//    ips114_showuint16(80,0,GoalSpeed_L);      //ʵ���ٶ���ʾ
//    ips114_showstr(0,20,"GoalSpeed_R");
//    ips114_showuint8(80,20,GoalSpeed_R);
//    ips114_showstr(0,40,"L_Encoder");//��������
//    ips114_showuint16(80,40,RealSpeed_L);
//    ips114_showstr(0,60,"R_Encoder");//��������
//    ips114_showint16(80,60,RealSpeed_R);
//    ips114_showstr(0,80,"L_output");//��������
//    ips114_showuint16(80,80,L_PwmOut);
//    ips114_showstr(0,100,"L_output");//��������
//    ips114_showint16(80,100,R_PwmOut);
//    ips114_showstr(120,0,"<-");

}
void fun13()
{
    fun=13;
//    ips114_showstr(0,0,"GoalSpeed_L");    //Ŀ���ٶ�����
//    ips114_showuint16(80,0,GoalSpeed_L);
//    ips114_showstr(0,20,"GoalSpeed_R");   //ʵ���ٶ���ʾ
//    tft180_show_uint8(80,20,GoalSpeed_R);
//    ips114_showstr(0,40,"L_Encoder");//��������
//    ips114_showuint16(80,40,RealSpeed_L);
//    ips114_showstr(0,60,"R_Encoder");//��������
//    ips114_showint16(80,60,RealSpeed_R);
//    ips114_showstr(0,80,"L_output");//��������
//    ips114_showuint16(80,80,L_PwmOut);
//    ips114_showstr(0,100,"L_output");//��������
//    ips114_showint16(80,100,R_PwmOut);
//    ips114_showstr(120,20,"<-");

}
void fun14()
{
    fun=14;
//    ips114_showstr(0,0,"GoalSpeed_L");    //Ŀ���ٶ�����
//    ips114_showuint16(80,0,GoalSpeed_L);
//    ips114_showstr(0,20,"GoalSpeed_R");   //ʵ���ٶ���ʾ
//    ips114_showuint8(80,20,GoalSpeed_R);
//    ips114_showstr(0,40,"L_Encoder");//��������
//    ips114_showuint16(80,40,RealSpeed_L);
//    ips114_showstr(0,60,"R_Encoder");//��������
//    ips114_showint16(80,60,RealSpeed_R);
//    ips114_showstr(0,80,"L_output");//��������
//    ips114_showuint16(80,80,L_PwmOut);
//    ips114_showstr(0,100,"L_output");//��������
//    ips114_showint16(80,100,R_PwmOut);
//    ips114_showstr(120,40,"<-");

}
void fun15()
{
    fun=15;
//    ips114_showstr(0,0,"GoalSpeed_L");    //Ŀ���ٶ�����
//    ips114_showuint16(80,0,GoalSpeed_L);
//    ips114_showstr(0,20,"GoalSpeed_R");   //ʵ���ٶ���ʾ
//    ips114_showuint8(80,20,GoalSpeed_R);
//    ips114_showstr(0,40,"L_Encoder");//��������
//    ips114_showuint16(80,40,RealSpeed_L);
//    ips114_showstr(0,60,"R_Encoder");//��������
//    ips114_showint16(80,60,RealSpeed_R);
//    ips114_showstr(0,80,"L_output");//��������
//    ips114_showuint16(80,80,L_PwmOut);
//    ips114_showstr(0,100,"L_output");//��������
//    ips114_showint16(80,100,R_PwmOut);
//    ips114_showstr(120,60,"<-");
}
void fun16()
{
    fun=16;
    /***********��������*************/
    ips114_showstr(15,20,"<<  Start  >>");
    ips114_showstr(15,20,"    Start    ");
    ips114_showstr(15,60,"     3 S     ");
    ips114_showstr(15,100,"<<  Start  >>");
    ips114_showstr(15,100,"    Start    ");
}


key_table code_table[30]=
{
    //current,up,down,enter
    {0,3,1,4,(*fun1)},//��һ�㣬  ��ʾ<<  IMAGE  >>��ENGINE��MOTOR��START
    {1,0,2,6,(*fun2)},//��һ�㣬  ��ʾ  IMAGE�� <<  ENGINE  >>��MOTOR��START
    {2,1,3,11,(*fun3)},//��һ�㣬��ʾ  IMAGE ��ENGINE��<<  MOTOR  >>��START
    {3,2,0,15,(*fun4)},//��һ�㣬��ʾ  IMAGE ��ENGINE��MOTOR��  <<  START  >>

    
    {4,5,5,0,(*fun5)},//�ڶ���
    {5,4,4,0,(*fun6)},//�ڶ���


    {6,10,7,1,(*fun7)},//�ڶ���
    {7,6,8,1,(*fun8)},//�ڶ���
    {8,7,9,1,(*fun9)},//�ڶ���
    {9,8,10,1,(*fun10)},//�ڶ���
    {10,9,6,1,(*fun11)},//�ڶ���


    {11,14,12,2,(*fun12)},//�ڶ���
    {12,11,13,2,(*fun13)},//�ڶ���
    {13,12,14,2,(*fun14)}, //�ڶ���
    {14,13,11,2,(*fun15)}, //�ڶ���

    {15,15,15,3,(*fun16)},//�ڶ���
};

void Key_Driver(void)
{
    //���水��״̬
    key1_last_status = key1_status;
    key2_last_status = key2_status;
    key3_last_status = key3_status;
    key4_last_status = key4_status;
    key5_last_status = key5_status;
    //��ȡ��ǰ����״̬
    key1_status = DOWN;
    key2_status = UP;
    key3_status = CENTER;
    key4_status = RIGHT;
    key5_status = LEFT;
    //��⵽��������֮��  ���ſ���λ��־λ
    if(key1_status && !key1_last_status)    key1_flag = 1;
    if(key2_status && !key2_last_status)    key2_flag = 1;
    if(key3_status && !key3_last_status)    key3_flag = 1;
    if(key4_status && !key4_last_status)    key4_flag = 1;
    if(key5_status && !key5_last_status)    key5_flag = 1;

    //��־λ��λ֮�󣬿���ʹ�ñ�־λִ���Լ���Ҫ�����¼�
    if(key1_flag)
    {
        key1_flag = 0;//ʹ�ð���֮��Ӧ�������־λ
        ips114_clear(BLUE);//ע��ÿ�ΰ��°�������һ����
        func_index = code_table[func_index].up;//���ܺ���������ֵΪ�����е�up����ֵ
    }

    if(key2_flag)
    {
        key2_flag = 0;//ʹ�ð���֮��Ӧ�������־λ
        ips114_clear(BLUE);//ע��ÿ�ΰ��°�������һ����
        func_index = code_table[func_index].down;//���ܺ���������ֵΪ�����е�down����ֵ
    }

    if(key3_flag)
    {
        key3_flag = 0;//ʹ�ð���֮��Ӧ�������־λ
        ips114_clear(BLUE);//ע��ÿ�ΰ��°�������һ����
        func_index = code_table[func_index].enter;//���ܺ���������ֵΪ�����е�enter����ֵ
    }

    if(key4_flag)
    {
        key4_flag = 0;//ʹ�ð���֮��Ӧ�������־λ
//        if(fun==5){;}
//        else if(fun==6)
//        {
//            k -= 1;
//        }
//        else if(fun==7)
//            Dir_P -= 0.1 ;
//        else if(fun==8)
//            Dir_D -= 1 ;
//        else if(fun==9)
//            L_Speed_Kp -= 0.1;
//        else if(fun==10)
//            L_Speed_Ki -= 0.05;
//        else if(fun==11)
//            L_Speed_Kd -= 0.1;
//        else if(fun==12)
//            GoalSpeed_L -= 100;
    }

    if(key5_flag)
    {
        key5_flag = 0;//ʹ�ð���֮��Ӧ�������־λ
//        if(fun==5){;}
//        else if(fun==6)
//        {
//            j -= 1;
//        }
//        else if(fun==7)
//            Dir_P += 0.1 ;
//        else if(fun==8)
//            Dir_D += 1 ;
//        else if(fun==9)
//            L_Speed_Kp += 0.1;
//        else if(fun==10)
//            L_Speed_Ki += 0.05;
//        else if(fun==11)
//            L_Speed_Kd += 0.1;
//        else if(fun==12)
//            GoalSpeed_L += 100;
    }


    current_operation_index = code_table[func_index].current_operation;
    (*current_operation_index)();//ִ�е�ǰ��������
}