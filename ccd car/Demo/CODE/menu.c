#include "menu.h"
#include "key.h"
uint8   start_flag=0;     //出库完成标志位
uint16  start_time=0;     //出库时间
uint8 fun=0;
uint8 func_index=0;
//开关状态变量
uint8 key1_status = 1;
uint8 key2_status = 1;
uint8 key3_status = 1;
uint8 key4_status = 1;
uint8 key5_status = 1;

//上一次开关状态变量
uint8 key1_last_status;
uint8 key2_last_status;
uint8 key3_last_status;
uint8 key4_last_status;
uint8 key5_last_status;

//开关标志位
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
//    ips114_showstr(0,60,"LCDW");   //测量赛道使用
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
//    ips114_showstr(0,60,"LCDW");    //测量赛道使用
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
    /****舵机PD***/
//    ips114_showstr(0,0,"Dir_P");
//    ips114_showfloat(40,0,Dir_P,2,3);
//    ips114_showstr(0,20,"Dir_D");
//    ips114_showfloat(40,20,Dir_D,2,3);
//    /******速度PID**********/
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
    /****舵机PD***/
//    ips114_showstr(0,0,"Dir_P");
//    ips114_showfloat(40,0,Dir_P,2,3);
//    ips114_showstr(0,20,"Dir_D");
//    ips114_showfloat(40,20,Dir_D,2,3);
//    /******速度PID**********/
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
    /****舵机PD***/
//    ips114_showstr(0,0,"Dir_P");
//    ips114_showfloat(40,0,Dir_P,2,3);
//    ips114_showstr(0,20,"Dir_D");
//    ips114_showfloat(40,20,Dir_D,2,3);
//    /******速度PID**********/
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
    /****舵机PD***/
//    ips114_showstr(0,0,"Dir_P");
//    ips114_showfloat(40,0,Dir_P,2,3);
//    ips114_showstr(0,20,"Dir_D");
//    ips114_showfloat(40,20,Dir_D,2,3);
//    /******速度PID**********/
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
    /****舵机PD***/
//    ips114_showstr(0,0,"Dir_P");
//    ips114_showfloat(40,0,Dir_P,2,3);
//    ips114_showstr(0,20,"Dir_D");
//    ips114_showfloat(40,20,Dir_D,2,3);
//    /******速度PID**********/
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
//    ips114_showstr(0,0,"GoalSpeed_L");    //目标速度配置
//    ips114_showuint16(80,0,GoalSpeed_L);      //实际速度显示
//    ips114_showstr(0,20,"GoalSpeed_R");
//    ips114_showuint8(80,20,GoalSpeed_R);
//    ips114_showstr(0,40,"L_Encoder");//编码器左
//    ips114_showuint16(80,40,RealSpeed_L);
//    ips114_showstr(0,60,"R_Encoder");//编码器右
//    ips114_showint16(80,60,RealSpeed_R);
//    ips114_showstr(0,80,"L_output");//编码器左
//    ips114_showuint16(80,80,L_PwmOut);
//    ips114_showstr(0,100,"L_output");//编码器右
//    ips114_showint16(80,100,R_PwmOut);
//    ips114_showstr(120,0,"<-");

}
void fun13()
{
    fun=13;
//    ips114_showstr(0,0,"GoalSpeed_L");    //目标速度配置
//    ips114_showuint16(80,0,GoalSpeed_L);
//    ips114_showstr(0,20,"GoalSpeed_R");   //实际速度显示
//    tft180_show_uint8(80,20,GoalSpeed_R);
//    ips114_showstr(0,40,"L_Encoder");//编码器左
//    ips114_showuint16(80,40,RealSpeed_L);
//    ips114_showstr(0,60,"R_Encoder");//编码器右
//    ips114_showint16(80,60,RealSpeed_R);
//    ips114_showstr(0,80,"L_output");//编码器左
//    ips114_showuint16(80,80,L_PwmOut);
//    ips114_showstr(0,100,"L_output");//编码器右
//    ips114_showint16(80,100,R_PwmOut);
//    ips114_showstr(120,20,"<-");

}
void fun14()
{
    fun=14;
//    ips114_showstr(0,0,"GoalSpeed_L");    //目标速度配置
//    ips114_showuint16(80,0,GoalSpeed_L);
//    ips114_showstr(0,20,"GoalSpeed_R");   //实际速度显示
//    ips114_showuint8(80,20,GoalSpeed_R);
//    ips114_showstr(0,40,"L_Encoder");//编码器左
//    ips114_showuint16(80,40,RealSpeed_L);
//    ips114_showstr(0,60,"R_Encoder");//编码器右
//    ips114_showint16(80,60,RealSpeed_R);
//    ips114_showstr(0,80,"L_output");//编码器左
//    ips114_showuint16(80,80,L_PwmOut);
//    ips114_showstr(0,100,"L_output");//编码器右
//    ips114_showint16(80,100,R_PwmOut);
//    ips114_showstr(120,40,"<-");

}
void fun15()
{
    fun=15;
//    ips114_showstr(0,0,"GoalSpeed_L");    //目标速度配置
//    ips114_showuint16(80,0,GoalSpeed_L);
//    ips114_showstr(0,20,"GoalSpeed_R");   //实际速度显示
//    ips114_showuint8(80,20,GoalSpeed_R);
//    ips114_showstr(0,40,"L_Encoder");//编码器左
//    ips114_showuint16(80,40,RealSpeed_L);
//    ips114_showstr(0,60,"R_Encoder");//编码器右
//    ips114_showint16(80,60,RealSpeed_R);
//    ips114_showstr(0,80,"L_output");//编码器左
//    ips114_showuint16(80,80,L_PwmOut);
//    ips114_showstr(0,100,"L_output");//编码器右
//    ips114_showint16(80,100,R_PwmOut);
//    ips114_showstr(120,60,"<-");
}
void fun16()
{
    fun=16;
    /***********三秒启动*************/
    ips114_showstr(15,20,"<<  Start  >>");
    ips114_showstr(15,20,"    Start    ");
    ips114_showstr(15,60,"     3 S     ");
    ips114_showstr(15,100,"<<  Start  >>");
    ips114_showstr(15,100,"    Start    ");
}


key_table code_table[30]=
{
    //current,up,down,enter
    {0,3,1,4,(*fun1)},//第一层，  显示<<  IMAGE  >>、ENGINE、MOTOR、START
    {1,0,2,6,(*fun2)},//第一层，  显示  IMAGE、 <<  ENGINE  >>、MOTOR、START
    {2,1,3,11,(*fun3)},//第一层，显示  IMAGE 、ENGINE、<<  MOTOR  >>、START
    {3,2,0,15,(*fun4)},//第一层，显示  IMAGE 、ENGINE、MOTOR、  <<  START  >>

    
    {4,5,5,0,(*fun5)},//第二层
    {5,4,4,0,(*fun6)},//第二层


    {6,10,7,1,(*fun7)},//第二层
    {7,6,8,1,(*fun8)},//第二层
    {8,7,9,1,(*fun9)},//第二层
    {9,8,10,1,(*fun10)},//第二层
    {10,9,6,1,(*fun11)},//第二层


    {11,14,12,2,(*fun12)},//第二层
    {12,11,13,2,(*fun13)},//第二层
    {13,12,14,2,(*fun14)}, //第二层
    {14,13,11,2,(*fun15)}, //第二层

    {15,15,15,3,(*fun16)},//第二层
};

void Key_Driver(void)
{
    //保存按键状态
    key1_last_status = key1_status;
    key2_last_status = key2_status;
    key3_last_status = key3_status;
    key4_last_status = key4_status;
    key5_last_status = key5_status;
    //读取当前按键状态
    key1_status = DOWN;
    key2_status = UP;
    key3_status = CENTER;
    key4_status = RIGHT;
    key5_status = LEFT;
    //检测到按键按下之后  并放开置位标志位
    if(key1_status && !key1_last_status)    key1_flag = 1;
    if(key2_status && !key2_last_status)    key2_flag = 1;
    if(key3_status && !key3_last_status)    key3_flag = 1;
    if(key4_status && !key4_last_status)    key4_flag = 1;
    if(key5_status && !key5_last_status)    key5_flag = 1;

    //标志位置位之后，可以使用标志位执行自己想要做的事件
    if(key1_flag)
    {
        key1_flag = 0;//使用按键之后，应该清除标志位
        ips114_clear(BLUE);//注意每次按下按键才清一次屏
        func_index = code_table[func_index].up;//功能函数的索引值为数组中的up索引值
    }

    if(key2_flag)
    {
        key2_flag = 0;//使用按键之后，应该清除标志位
        ips114_clear(BLUE);//注意每次按下按键才清一次屏
        func_index = code_table[func_index].down;//功能函数的索引值为数组中的down索引值
    }

    if(key3_flag)
    {
        key3_flag = 0;//使用按键之后，应该清除标志位
        ips114_clear(BLUE);//注意每次按下按键才清一次屏
        func_index = code_table[func_index].enter;//功能函数的索引值为数组中的enter索引值
    }

    if(key4_flag)
    {
        key4_flag = 0;//使用按键之后，应该清除标志位
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
        key5_flag = 0;//使用按键之后，应该清除标志位
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
    (*current_operation_index)();//执行当前操作函数
}