#include "headfile.h"

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
    ips114_showstr(2,0,"ccd    <-");
    ips114_showstr(2,0,"ccd");
    
    ips114_showstr(2,1,"pid");

    ips114_showstr(2,2,"motor");

//    ips114_showstr(2,3,"start");
}
void fun2(void)
{
    fun=2;
    ips114_showstr(2,0,"ccd");

    ips114_showstr(2,1,"pid  <-");
    ips114_showstr(2,1,"pid");
    
    ips114_showstr(2,2,"motor");

//    ips114_showstr(2,3,"start");
}
void fun3(void)
{
    fun=3;
    ips114_showstr(2,0,"ccd");

    ips114_showstr(2,1,"pid");

    ips114_showstr(2,2,"motor  <-");
    ips114_showstr(2,2,"motor");
   
//    ips114_showstr(2,3,"start");
}
void fun4()
{
    fun=4;
    ips114_showstr(0,0,"mid");  
    ips114_showuint16(80,0,mid);
    ips114_showstr(0,1,"df");
    ips114_showuint16(80,1,df);
    ips114_showstr(0,2,"road_wid1");
    ips114_showint16(80,2,road_width1);
    ips114_showstr(0,3,"road_wid2");
    ips114_showint16(80,3,road_width2);
    ips114_showstr(0,4,"B_wid1");
    ips114_showint16(80,4,Broad_width1);
    ips114_showstr(0,5,"B_wid2");
    ips114_showint16(80,5,Broad_width2);
}
void fun5()
{
    fun=5;
    ips114_showstr(0,0,"Lbound");   
    ips114_showuint16(80,0,Lboundary_data);
    ips114_showstr(0,1,"Rbound");
    ips114_showuint16(80,1,Rboundary_data);
    ips114_showstr(0,2,"Lbound2");
    ips114_showint16(80,2,Lboundary_data2);
    ips114_showstr(0,3,"Rbound2");
    ips114_showint16(80,3,Rboundary_data2);
    ips114_showstr(0,4,"Rboundb");
    ips114_showint16(80,4,Rboundary_black);
    ips114_showstr(0,5,"Rboundb2");
    ips114_showint16(80,5,Rboundary_black2);
    ips114_showstr(0,6,"Outb1");
    ips114_showint16(80,6,Outside_black1);
    ips114_showstr(0,7,"Outb2");
    ips114_showint16(80,7,Outside_black2);
}
void fun6()
{
    fun=6;
    /****���PD***/
    ips114_showstr(0,0,"steer_KP");
    ips114_showfloat(80,0,steer_KP,2,3);
    ips114_showstr(0,1,"steer_KD");
    ips114_showfloat(80,1,steer_KD,2,3);
    /******�ٶ�PID**********/
    ips114_showstr(0,2,"L_Speed_P");
    ips114_showfloat(80,2,L_Speed_KP,2,3);
    ips114_showstr(0,3,"L_Speed_I");
    ips114_showfloat(80,3,L_Speed_KI,2,3);
    ips114_showstr(0,4,"R_Speed_P");
    ips114_showfloat(80,4,R_Speed_KP,2,3);
    ips114_showstr(0,5,"R_Speed_I");
    ips114_showfloat(80,5,R_Speed_KI,2,3);
    ips114_showstr(160,0,"<-");
}
void fun7()
{
    fun=7;
    /****���PD***/
    ips114_showstr(0,0,"steer_KP");
    ips114_showfloat(80,0,steer_KP,2,3);
    ips114_showstr(0,1,"steer_KD");
    ips114_showfloat(80,1,steer_KD,2,3);
    /******�ٶ�PID**********/
    ips114_showstr(0,2,"L_Speed_P");
    ips114_showfloat(80,2,L_Speed_KP,2,3);
    ips114_showstr(0,3,"L_Speed_I");
    ips114_showfloat(80,3,L_Speed_KI,2,3);
    ips114_showstr(0,4,"R_Speed_P");
    ips114_showfloat(80,4,R_Speed_KP,2,3);
    ips114_showstr(0,5,"R_Speed_I");
    ips114_showfloat(80,5,R_Speed_KI,2,3);
    ips114_showstr(160,1,"<-");
}
void fun8()
{
    fun=8;
    /****���PD***/
    ips114_showstr(0,0,"steer_KP");
    ips114_showfloat(80,0,steer_KP,2,3);
    ips114_showstr(0,1,"steer_KD");
    ips114_showfloat(80,1,steer_KD,2,3);
    /******�ٶ�PID**********/
    ips114_showstr(0,2,"L_Speed_P");
    ips114_showfloat(80,2,L_Speed_KP,2,3);
    ips114_showstr(0,3,"L_Speed_I");
    ips114_showfloat(80,3,L_Speed_KI,2,3);
    ips114_showstr(0,4,"R_Speed_P");
    ips114_showfloat(80,4,R_Speed_KP,2,3);
    ips114_showstr(0,5,"R_Speed_I");
    ips114_showfloat(80,5,R_Speed_KI,2,3);
    ips114_showstr(160,2,"<-");
}
void fun9()
{
    fun=9;
    /****���PD***/
    ips114_showstr(0,0,"steer_KP");
    ips114_showfloat(80,0,steer_KP,2,3);
    ips114_showstr(0,1,"steer_KD");
    ips114_showfloat(80,1,steer_KD,2,3);
    /******�ٶ�PID**********/
    ips114_showstr(0,2,"L_Speed_P");
    ips114_showfloat(80,2,L_Speed_KP,2,3);
    ips114_showstr(0,3,"L_Speed_I");
    ips114_showfloat(80,3,L_Speed_KI,2,3);
    ips114_showstr(0,4,"R_Speed_P");
    ips114_showfloat(80,4,R_Speed_KP,2,3);
    ips114_showstr(0,5,"R_Speed_I");
    ips114_showfloat(80,5,R_Speed_KI,2,3);
    ips114_showstr(160,3,"<-");
}
void fun10()
{
    fun=10;
    /****���PD***/
    ips114_showstr(0,0,"steer_KP");
    ips114_showfloat(80,0,steer_KP,2,3);
    ips114_showstr(0,1,"steer_KD");
    ips114_showfloat(80,1,steer_KD,2,3);
    /******�ٶ�PID**********/
    ips114_showstr(0,2,"L_Speed_P");
    ips114_showfloat(80,2,L_Speed_KP,2,3);
    ips114_showstr(0,3,"L_Speed_I");
    ips114_showfloat(80,3,L_Speed_KI,2,3);
    ips114_showstr(0,4,"R_Speed_P");
    ips114_showfloat(80,4,R_Speed_KP,2,3);
    ips114_showstr(0,5,"R_Speed_I");
    ips114_showfloat(80,5,R_Speed_KI,2,3);
    ips114_showstr(160,4,"<-");
}
void fun11()
{
    fun=11;
    /****���PD***/
    ips114_showstr(0,0,"steer_KP");
    ips114_showfloat(80,0,steer_KP,2,3);
    ips114_showstr(0,1,"steer_KD");
    ips114_showfloat(80,1,steer_KD,2,3);
    /******�ٶ�PID**********/
    ips114_showstr(0,2,"L_Speed_P");
    ips114_showfloat(80,2,L_Speed_KP,2,3);
    ips114_showstr(0,3,"L_Speed_I");
    ips114_showfloat(80,3,L_Speed_KI,2,3);
    ips114_showstr(0,4,"R_Speed_P");
    ips114_showfloat(80,4,R_Speed_KP,2,3);
    ips114_showstr(0,5,"R_Speed_I");
    ips114_showfloat(80,5,R_Speed_KI,2,3);
    ips114_showstr(160,5,"<-");
}
void fun12()
{
    fun=12;
    ips114_showstr(0,0,"TSpeed_L");    //Ŀ���ٶ�����
    ips114_showuint16(80,0,Target_Speed_L);      //ʵ���ٶ���ʾ
    ips114_showstr(0,1,"TSpeed_R");
    ips114_showuint16(80,1,Target_Speed_R);
    ips114_showstr(0,2,"encoder_l");//��������
    ips114_showuint16(80,2,encoder_left);
    ips114_showstr(0,3,"encoder_r");//��������
    ips114_showint16(80,3,encoder_right);
    ips114_showstr(0,4,"L_Duty");//��������
    ips114_showuint16(80,4,Left_Duty);
    ips114_showstr(0,5,"R_Duty");//��������
    ips114_showint16(80,5,Right_Duty);
    ips114_showstr(160,0,"<-");

}
void fun13()
{
    fun=13;
    ips114_showstr(0,0,"TSpeed_L");    //Ŀ���ٶ�����
    ips114_showuint16(80,0,Target_Speed_L);      //ʵ���ٶ���ʾ
    ips114_showstr(0,1,"TSpeed_R");
    ips114_showuint16(80,1,Target_Speed_R);
    ips114_showstr(0,2,"encoder_l");//��������
    ips114_showuint16(80,2,encoder_left);
    ips114_showstr(0,3,"encoder_r");//��������
    ips114_showint16(80,3,encoder_right);
    ips114_showstr(0,4,"L_Duty");//��������
    ips114_showuint16(80,4,Left_Duty);
    ips114_showstr(0,5,"R_Duty");//��������
    ips114_showint16(80,5,Right_Duty);
    ips114_showstr(160,1,"<-");

}

key_table code_table[30]=
{
    //current,up,down,enter
    {0,3,1,3,(*fun1)},//��һ�㣬  ��ʾ<<  ccd  >>��steer��motor
    {1,0,2,5,(*fun2)},//��һ�㣬  ��ʾ  ccd�� <<  steer  >>��motor
    {2,1,3,11,(*fun3)},//��һ�㣬��ʾ  ccd ��steer��<<  motor  >>

    {3,4,4,0,(*fun4)},//�ڶ���,��ʾccd����
    {4,3,3,0,(*fun5)},//�ڶ���


    {5,10,6,1,(*fun6)},//�ڶ���,��ʾpid����
    {6,5,7,1,(*fun7)},//�ڶ���
    {7,6,8,1,(*fun8)},//�ڶ���
    {8,7,9,1,(*fun9)},//�ڶ���
    {9,8,10,1,(*fun10)},//�ڶ���
    {10,9,5,1,(*fun11)},//�ڶ���

    {11,12,12,2,(*fun12)},//�ڶ���,��ʾmotor����
    {12,11,11,2,(*fun13)},//�ڶ���

//    {0,3,1,4,(*fun1)},//��һ�㣬  ��ʾ<<  ccd  >>��steer��motor
//    {1,0,2,6,(*fun2)},//��һ�㣬  ��ʾ  ccd�� <<  steer  >>��motor
//    {2,1,3,11,(*fun3)},//��һ�㣬��ʾ  ccd ��steer��<<  motor  >>
//    {3,2,0,15,(*fun4)},//��һ�㣬��ʾ  ccd ��steer��motor

//    
//    {4,5,5,0,(*fun5)},//�ڶ���
//    {5,4,4,0,(*fun6)},//�ڶ���


//    {6,10,7,1,(*fun7)},//�ڶ���
//    {7,6,8,1,(*fun8)},//�ڶ���
//    {8,7,9,1,(*fun9)},//�ڶ���
//    {9,8,10,1,(*fun10)},//�ڶ���
//    {10,9,6,1,(*fun11)},//�ڶ���


//    {11,14,12,2,(*fun12)},//�ڶ���
//    {12,11,13,2,(*fun13)},//�ڶ���
//    {13,12,14,2,(*fun14)}, //�ڶ���
//    {14,13,11,2,(*fun15)}, //�ڶ���

//    {15,15,15,3,(*fun16)},//�ڶ���
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
        if(fun==6)
            steer_KP        -= 0.05;
        else if(fun==7)
            steer_KD        -= 0.1 ;
        else if(fun==8)
            L_Speed_KP      -= 5 ;
        else if(fun==9)
            L_Speed_KI      -= 0.2;
        else if(fun==10)
            R_Speed_KP      -= 5;
        else if(fun==11)
            R_Speed_KI      -= 0.2;
        else if(fun==12)
            Target_Speed_L  -= 10;
        else if(fun==13)
            Target_Speed_R  -= 10;
    }

    if(key5_flag)
    {
        key5_flag = 0;//ʹ�ð���֮��Ӧ�������־λ
        if(fun==6)
            steer_KP        += 0.05;
        else if(fun==7)
            steer_KD        += 0.1 ;
        else if(fun==8)
            L_Speed_KP      += 5 ;
        else if(fun==9)
            L_Speed_KI      += 0.2;
        else if(fun==10)
            R_Speed_KP      += 5;
        else if(fun==11)
            R_Speed_KI      += 0.2;
        else if(fun==12)
            Target_Speed_L  += 10;
        else if(fun==13)
            Target_Speed_R  += 10;
    }


    current_operation_index = code_table[func_index].current_operation;
    (*current_operation_index)();//ִ�е�ǰ��������
}