#include "headfile.h"
int x , y , z , m , n , a , b , c , p , i , d ;                                //x�����������£�y���ν���ת����m�μ��������£�z�μ��������ң�n , a ��b , c
int io_input_state1,io_input_state2,io_input_state3,io_input_state4,io_input_state5;
extern float ad_value1,ad_value2,ad_value3,ad_value4;
extern int cbh;
extern int16 counter1_data,counter2_data; 
extern int16 mpu3050_gyro_x,mpu3050_gyro_y,mpu3050_gyro_z;

/*********************************��ʼ��***********************************/
void menu_init()
{
      ips114_init();
      ips114_clear(BLUE);
}

/*=======================���������==========================*/
void menu0()
{	
  if(y==0)
  {
    ips114_showstr(0, 0,"image");// ͼ����Ϣ

    ips114_showstr(0, 1,"magnetic");//���
 
    ips114_showstr(0, 2,"motor"); //�������
  
    ips114_showstr(0, 3,"pid"); //PID
   
    ips114_showstr(0, 4,"start"); //��ʼ����
  
    ips114_showstr(75, x,"<-"); //ѡ��
       if(x>4)
         x=0;
  }
      
}       
/*=======================���������==========================*/

/*=======================����ͷ�������==========================*///x�����������£�y���ν���ת����m�μ��������£�z�μ���������
void menu1()
{	

   if(x==0 && y==1)
   {
      ips114_showstr(0, 0,"image");// ͼ����Ϣ
      ips114_showstr(0, 7,"back"); //����
       if(m==1)
      ips114_showstr(75, 7,"<-"); //ѡ��
      if(m>1)
        m=0;
   }
    
   if(x==0 && y==1 && m==1)
   {
      if(io_input_state5==0)
      {
         ips114_clear(BLUE);
         y=0;
         m=0;
      }
    }
}       
/*=======================����ͷ�������==========================*/



/*=======================��Ž������==========================*///x�����������£�y���ν���ת����m�μ��������£�z�μ���������
void menu2()
{	
   if(x==1 && y==1)
   {
      ips114_showstr(0, 0, "ADC_1 CH0");
      ips114_showfloat(120, 0, ad_value1,3,3);
      ips114_showstr(0, 1, "ADC_1 CH2");
      ips114_showfloat(120, 1, ad_value2,3,3);
      ips114_showstr(0, 2, "ADC_1 CH3");
      ips114_showfloat(120, 2, ad_value3,3,3);
      ips114_showstr(0, 3, "ADC_1 CH5");
      ips114_showfloat(120, 3, ad_value4,3,3);
      ips114_showstr(0, 4, "cbh");
      ips114_showint16(120, 4, cbh);
      ips114_showstr(0, 7,"back"); //����
      if(m==1)
      ips114_showstr(75, 7,"<-"); //ѡ��
      if(m>1)
         m=0;
   }
    
   if(x==1 && y==1 && m==1)
   {
      if(io_input_state5==0)
      {
         ips114_clear(BLUE);
         y=0;
         m=0;
      }
   }
}  
/*=======================��Ž������==========================*/


/*=======================����������==========================*///x�����������£�y���ν���ת����m�μ��������£�z�μ���������
void menu3()
{	

   if(x==2 && y==1)
   {
      ips114_showstr(0, 1,"encoder_left");
      ips114_showstr(0, 3,"encoder_right");
      ips114_showstr(0, 5,"Target_Speed");
      ips114_showstr(0, 7,"back"); //����
      if(m==2)
      ips114_showstr(125, 7,"<-"); //ѡ��
       if(m>2)
         m=0;
   }
    

   if(x==2 && y==1 && m==2)
   {
      if(io_input_state5==0)
      {
         ips114_clear(BLUE);
         y=0;
         m=0;
      }
   }
}  

/*=======================����������==========================*/


/*=======================PID�������==========================*///x�����������£�y���ν���ת����m�μ��������£�z�μ���������
void menu4()
{	
   if(x==3 && y==1)
   {
      ips114_showstr(0, 1,"P");
      ips114_showuint16(50, 1,p);
      ips114_showstr(0, 3,"I");
      ips114_showuint16(50, 3,i);
      ips114_showstr(0, 5,"D");
      ips114_showuint16(50, 5,d);
      ips114_showstr(0, 7,"back"); //����
      if(m==3)
      ips114_showstr(100, 7,"<-"); //ѡ��
       if(m>3)
         m=0;
   }
    
         if(x==3 && y==1 && m==3)
         {
           if(io_input_state5==0)
           {
             ips114_clear(BLUE);
             y=0;
             m=0;
           }
         }
}   
/*=======================PID�������==========================*/


/*=====================start=======================*/
void menu5()
{	
  if(x==4 && y==1)
  {
      ips114_showstr(115, 4,"1");
      delay_ms(1000);
      ips114_showstr(115, 4,"2");
      delay_ms(1000);
      ips114_showstr(115, 4,"3");
      delay_ms(1000);
      ips114_showstr(100, 4,"start!!!!!");
      delay_ms(1000);
      ips114_clear(BLUE);
      y=0;
      m=0;
    
  }
}   
/*=====================start=======================*/

/*=====================�˵�������=======================*/
void menu()
{
     wx_key();
     menu0();
     menu1();
     menu2();
     menu3();
     menu4();
     menu5();
}

/*=====================�˵�������=======================*/
int dat;
void display()
{
    dat = DIR_LEFT;
    ips114_showfloat(0, 0, ccd_cbh11,3,3);
    ips114_showfloat(0, 1, ccd_cbh12,3,3);
    ips114_showfloat(0, 2, ccd_cbh21,3,3);
    ips114_showfloat(0, 3, ccd_cbh22,3,3);
	
//	  ips114_showfloat(0, 0, black_cbh11,3,3);
//    ips114_showfloat(0, 1, black_cbh12,3,3);
//    ips114_showfloat(0, 2, black_cbh21,3,3);
//    ips114_showfloat(0, 3, black_cbh22,3,3);
    
//    ips114_showint16(100, 0, ad_value1);
//    ips114_showint16(100, 1, ad_value2);
//    ips114_showint16(100, 2, ad_value3);
//    ips114_showint16(100, 3, ad_value4);
    
    ips114_showint16(100, 0, Rboundary_data);
    ips114_showint16(100, 1, Lboundary_data);
	ips114_showint16(100, 2, Rboundary_data2);
    ips114_showint16(100, 3, Lboundary_data2);
	
//	  ips114_showint16(100, 0, Rboundary_black);
//    ips114_showint16(100, 1, Lboundary_black);
//		ips114_showint16(100, 2, Rboundary_black2);
//    ips114_showint16(100, 3, Lboundary_black2);
		
    ips114_showint16(100, 4, mid);
    ips114_showint16(100, 5, df);
		ips114_showint16(100, 6, road_width1);
//    ips114_showint16(100, 7, road_width2);
		ips114_showint16(100, 7, Broad_width2);
    
//    ips114_showint16(0, 4, cbh);
    ips114_showint16(0, 5, sc_flag);
    //ips114_showint16(0, 6, Outside_black2);
    
//      ips114_showfloat(0, 1, Speed_KI,3,3);
//      ips114_showfloat(0, 2, Speed_KP,3,3);
    
}

