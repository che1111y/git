#include "headfile.h"

int Target_direction = 0,Steer_PWMoutput = 704,Mid_Value = 704;
float steer_KP = 0,
      steer_KD = 0,
	  steer_KT = 0;

void steer_init()
{
	pwm_init(PWMB_CH1_P74, 50, 704);//1240max——left//185max——right//mid 709
}

//void dc_Steer_Control()
//{
//    if(cbh>=0&&sideway_flag!=1&&sideway_flag!=3)//右
//    {   
//      if(ad_value2<0&&ad_value3<0)
//      {
//          steer_KP = 1.6;
//          steer_KD = 30.5;
//      }
//      
//      else
//      {

//          if(cbh<=30)
//        {
//          steer_KP = 4.2;
//          steer_KD = 60.5;
//        }
//        if(cbh<=60&&cbh>30)
//        {
//          steer_KP = 6.5;
//          steer_KD = 90.0;
//        }
//        if(cbh<=100&&cbh>60)
//        {
//          steer_KP = 11.5;
//          steer_KD = 139.8;
//        }
//      }
//	  
//      Steer_PWMoutput = Mid_Value + PID_Realize(steer_KP,0,steer_KD,steer_KT, cbh, Target_direction);
//    }
//	
//    if(cbh<0&&sideway_flag!=1&&sideway_flag!=3)//左
//    {
//      if(ad_value2<0&&ad_value3<0)
//      {
//          steer_KP = 0.1;
//          steer_KD = 1.5;
//      }
//      else
//      {
//        if(cbh>=-30)
//        {
//          steer_KP = 4.8;
//          steer_KD = 65;
//        }
//        if(cbh>=-60&&cbh<-30)
//        {
//          steer_KP = 7.2;
//          steer_KD = 85.0;
//        }
//        if(cbh>=-100&&cbh<-60)
//        {
//          steer_KP = 12.5;
//          steer_KD = 125.5;
//        }
//      }
//        
//      Steer_PWMoutput = Mid_Value + PID_Realize(steer_KP,0,steer_KD,steer_KT, cbh, Target_direction);
//      
//    }
//}
void ccd_Steer_Control()
{
    if(sz_flag!=1)
    {
        if(df<30&&df>-30)
        {
            steer_KP = 1.15;//speed180以内 p=1.35 d=2.3
            steer_KD = 2.3;
        }
        else if(df>-60&&df<-30)
        {
            steer_KP = 1.85;//speed230以内 p=0.15 d=2.1
            steer_KD = 2.5;
        }
        else if(df<60&&df>30)
        {
            steer_KP = 1.85;//speed230以内 p=0.15 d=2.1
            steer_KD = 2.4;
        }
        else
        {
            steer_KP = 2.35;//speed230以内 p=0.15 d=2.1
            steer_KD = 2.7;
        }
        
    }
    Steer_PWMoutput = Mid_Value - PID_Realize(steer_KP,0,steer_KD,steer_KT, df, Target_direction);
}
	
void steer_output(int Steer)//steer_left765  //steer_right635
{
    if (Steer >= 765)			
	{
		Steer = 765;
	}
	else if (Steer <= 635)
	{
		Steer = 635;
	}
	pwm_duty(PWMB_CH1_P74, Steer);	
}
