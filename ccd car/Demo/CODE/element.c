#include "headfile.h"


int sideway_flag=0,cirque_flag=0;
int side_cnt,d_cnt;

void judge()
{
    if(ad_value1>70&&ad_value1<90
       &&ad_value2>55&&ad_value2<75
       &&ad_value3>55&&ad_value3<75
       &&ad_value4>45&&ad_value4<60){
        
        bee = 0;
        
        if(sideway_flag == 0){
            sideway_flag = 1;
        }
        
        if(side_cnt>5000){
            sideway_flag++;
            side_cnt=0;
        }
        
        if(sideway_flag>4){
            sideway_flag=0;
        }
    }
    
    if(ad_value1>35&&ad_value1<45
    &&ad_value2>15&&ad_value2<30
    &&ad_value3>35&&ad_value3<45
    &&ad_value4>35&&ad_value4<55){ 
        
        bee = 0;
        
        if(sideway_flag == 0){
            sideway_flag = 1;
        }
        
        if(side_cnt>4000){
            sideway_flag++;
            side_cnt=0;
        }
        
        if(sideway_flag>4){
            sideway_flag=0;
        }
    }
}

    
void sideway()
{
    switch(sideway_flag){
        case 1:
            Steer_PWMoutput = 635;
            d_cnt++;
            if(d_cnt == 750){
                bee = 1;
                sideway_flag = 2;
                d_cnt = 0;
            }
            break;
            
        case 3:
            Steer_PWMoutput = 795;
            d_cnt++;
            if(d_cnt == 750){
                bee = 1;
                sideway_flag = 4;
                d_cnt = 0;
            }
            break;
            
//        case 5:
//            Steer_PWMoutput = 795;
//            d_cnt++;
//            if(d_cnt == 2000){
//                sideway_flag = 6;
//                d_cnt = 0;
//            }
//            break;
//            
//        case 7:
//            Steer_PWMoutput = 795;
//            d_cnt++;
//            if(d_cnt == 2000){
//                sideway_flag = 8;
//                d_cnt = 0;
//            }
//            break;
            
        default:
            break;
    }
        
}

void cirque()
{
    if(cirque_flag==1){
    }
    
}

int sz_flag,flag_0;
void ccd_sz()
{
//	int i;
	
	for(i=0;i<128;i++)
     {
			 if(ccd_value[i]<200)
			 {
				 break;
			 }
			 else if(i==127)
			 {
				 flag_0 = 1;
			 }
		 }
	if(Lboundary_data<10&&Rboundary_data>120
		&&Lboundary_data2>40&&Rboundary_data2<80
		&&flag_0 == 1)
		{
			sz_flag =1 ;
		}
		
	if(sz_flag == 1)
	{
		Steer_PWMoutput = 704;
//    if(Lboundary_data>35&&Rboundary_data<105
//			&&Lboundary_data2>35&&Rboundary_data2<105)
		if(road_width1<70&&road_width2<40)
		{
			sz_flag = 0;
			flag_0 = 0;
		}
	}
}

int sc_flag = 0;
void ccd_sc()
{
	if(Lboundary_data<20&&Rboundary_data>103&&
        Broad_width2>20
		&&sc_flag == 0
        &&Outside_black1>20&&Outside_black2<107)
    //中间黑30-90//如果黑道宽度大于20
    //左边黑线Outside_black1>15//右边黑线Outside_black2<112
	{
		 bee = 0;
		 sc_flag =1 ;
	}
	if(sc_flag == 1)
	{
		Steer_PWMoutput = 765;
//    if(Lboundary_data>35&&Rboundary_data<105
//			&&Lboundary_data2>35&&Rboundary_data2<105)
		if(road_width1<70&&road_width2<40)
		{
			bee = 1;
			sc_flag = 2;
		}
	}
	
	
	if(Lboundary_data<15&&Rboundary_data>113
		&&Broad_width2>15
		&&sc_flag == 2)
	{
		 bee = 0;
		 sc_flag =3 ;
	}
	if(sc_flag == 3)
	{
		Steer_PWMoutput = 635;
		if(road_width1<70&&road_width2<40)
		{
			bee = 1;
			sc_flag = 4;
		}
	}
	
	if(Lboundary_data<15&&Rboundary_data>115
		&&Broad_width2>15
		&&sc_flag == 4)
	{
		 bee = 0;
		 sc_flag =5 ;
	}
	if(sc_flag == 5)
	{
		Steer_PWMoutput = 765;
//    if(Lboundary_data>35&&Rboundary_data<105
//			&&Lboundary_data2>35&&Rboundary_data2<105)
		if(road_width1<70&&road_width2<40)
		{
			bee = 1;
			sc_flag = 6;
		}
	}
	
	if(Lboundary_data<15&&Rboundary_data>115
		&&Broad_width2>15
		&&sc_flag == 6)
	{
		 bee = 0;
		 sc_flag = 7;
	}
		if(sc_flag == 7)
	{
		Steer_PWMoutput = 635;
		if(road_width1<70&&road_width2<40)
		{
			bee = 1;
			sc_flag = 0;
		}
	}
}