#include "headfile.h"

uint16 PWM_LeftOut,PWM_RightOut,Now_speed = 0,PWM_Out=0;
float Target_Speed = 0;
uint16 Left_Duty = 0,Right_Duty = 0;
float Speed_KP = 20.0,//150//45//30
	  Speed_KI = 1.8,//6//1.8
	  Speed_KD = 0;


/**
*  @name   : motor_init
*  @author : chelly
*  @tips   : 电机初始化
*/
void motor_init()
{
  pwm_init(PWMA_CH1P_P60, 10000, 0);
  pwm_init(PWMA_CH2P_P62, 10000, 0);
  pwm_init(PWMA_CH3P_P64, 10000, 0);
  pwm_init(PWMA_CH4P_P66, 10000, 0);
}

/**
*  @name   : PWM_Output
*  @author : chelly
*  @tips   : 电机输出
*/
void PWM_Output(int R_Duty,int L_Duty)
{
    if(R_Duty >= 0)
    {
        R_Duty = (R_Duty>4500? 4500:R_Duty);
        pwm_duty(PWMA_CH1P_P60, 0);
        pwm_duty(PWMA_CH2P_P62, R_Duty);
    }
    else
    {
        R_Duty = (R_Duty<-4500? -4500:R_Duty);
        pwm_duty(PWMA_CH1P_P60, -R_Duty);						        
        pwm_duty(PWMA_CH2P_P62, 0);					        
    }
    if(L_Duty >= 0)
    {
        L_Duty = (L_Duty>4500? 4500:L_Duty);
        pwm_duty(PWMA_CH3P_P64, 0);					        
        pwm_duty(PWMA_CH4P_P66, L_Duty);							
    }
    else
    {
        Left_Duty = (L_Duty<-4500? -4500:L_Duty);
        pwm_duty(PWMA_CH3P_P64, -L_Duty);					                
        pwm_duty(PWMA_CH4P_P66, 0);				        
    }
	
}

/**
*  @name   : PWM_Control
*  @tips   : 电机控制
*/
void PWM_Control(void)
{
      if(sc_flag != 1||sc_flag != 2||sc_flag != 3
      ||sc_flag != 5||sc_flag != 6||sc_flag != 7)
      {
        if(df<40&&df>-40)
        {
            Target_Speed =210;//30
        }
//        else if(df>-60&&df<-30)
//        {
//            Target_Speed =70;//30
//        }
//        else if(df<60&&df>30)
//        {
//            Target_Speed =70;//30
//        }
        else 
        {
            Target_Speed =190;//30
        }
     }
//    if(cbh<10 && cbh>-10)
//    {
//        Target_Speed = 45;//55
//    }
//    else if((cbh>10 && cbh<30)||(cbh<-10 && cbh>-30))
//    {
//        Target_Speed = 30;//40
//    }
//    else
//    {
//        Target_Speed =200;//30
//    }
//  if(ad_value3<10&&ad_value2<10)
//  {
//     pwm_duty(PWMA_CH1P_P60, 0);
//     pwm_duty(PWMA_CH2P_P62, 0);
//     pwm_duty(PWMA_CH3P_P64, 0);					        
//     pwm_duty(PWMA_CH4P_P66, 0);
//  }
//  else
//  { 
//    PWM_Out = PID_Increase(Speed_KP,Speed_KI,Speed_KD, encoder_left, Target_Speed);
    Left_Duty = PID_LIncrease(Speed_KP,Speed_KI,Speed_KD, encoder_left, Target_Speed);
    Right_Duty = PID_RIncrease(Speed_KP,Speed_KI,Speed_KD, encoder_right, Target_Speed);
//  }
}

  
