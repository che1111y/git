#include "headfile.h"

float ccd_cbh11,ccd_cbh12,ccd_cbh21,ccd_cbh22;
int Lboundary_data,Rboundary_data,Lboundary_data2,Rboundary_data2;
int mid=64,df,ts_hold;
int road_width1,road_width2;

int black,Rboundary_black,Lboundary_black,Rboundary_black2,Lboundary_black2;
int outblack_cbh1,outblack_cbh2;
int Outside_black1,Outside_black2;
float black_cbh11,black_cbh12,black_cbh21,black_cbh22;
int Broad_width1,Broad_width2;

uint8 Auto = 0; //��̬��ֵ
int16 Threshold = 400;

uint16 ccd_valu[128][4];
uint16  ccd_valu1[128][4],ccd_value[128],ccd_sum[128];

/**
*  @name   : ccd_filter
*  @tips   : ccd�˲�
*/
void ccd_filter()
{
    int16  i,j,k,temp;
    
    for(j=0;j<4;j++)    
     {  
         for(i=0;i<128;i++)     
         {
          ccd_valu[i][j]=ccd_data[i];      
         }
     }
     
     for(i=0;i<128;i++)
     {
        for(j=0;j<4;j++)
        {
           for(k=0;k<4-j;k++)
           {
              if(ccd_valu1[i][k] > ccd_valu1[i][k+1])        //ǰ��ıȺ���Ĵ�  ����н���
              {
                 temp = ccd_valu1[i][k+1];
                 ccd_valu1[i][k+1] = ccd_valu1[i][k];
                 ccd_valu1[i][k] = temp;
              }
           }
        }
     }
     
    for(i=0;i<128;i++)    
     {
        ccd_sum[i] = ccd_valu[i][1] + ccd_valu[i][2] + ccd_valu[i][3];
        ccd_value[i] = ccd_sum[i] / 3;
     }
     
}

uint16 ccd_valu2[128][4];
uint16  ccd_valu2[128][4],ccd_value2[128],ccd_sum2[128];

/**
*  @name   : ccd_filter2
*  @tips   : ccd2�˲�
*/
void ccd_filter2()
{
    int16  i,j,k,temp;
    
    for(j=0;j<4;j++)    
     {  
         for(i=0;i<128;i++)     
         {
          ccd_valu2[i][j]=ccd_data2[i];      
         }
     }
     
     for(i=0;i<128;i++)
     {
        for(j=0;j<4;j++)
        {
           for(k=0;k<4-j;k++)
           {
              if(ccd_valu2[i][k] > ccd_valu2[i][k+1])        //ǰ��ıȺ���Ĵ�  ����н���
              {
                 temp = ccd_valu2[i][k+1];
                 ccd_valu2[i][k+1] = ccd_valu2[i][k];
                 ccd_valu2[i][k] = temp;
              }
           }
        }
     }
     
    for(i=0;i<128;i++)    
     {
        ccd_sum2[i] = ccd_valu2[i][1] + ccd_valu2[i][2] + ccd_valu2[i][3];
        ccd_value2[i] = ccd_sum2[i] / 3;
     }
}

 /**
*  @name   : Ccd_cbh
*  @tips   : CCDͼ���Ⱥ�
*/
uint8 ImageDiff[128];
void Ccd_cbh(uint8 *image)
{
	uint8 i;
	for(i = 0;i < 128 ;i++)
	{
		*(ImageDiff+i) = abs(*(image+i) - *(image+i+6))/(*(image+i) + *(image+i+6)); //�������� ����ֵ
		
	}
}

/**
*  @name   : CCD_Average
*  @tips   : 
*/
uint16 CCD_Average(uint8 *image)
{
	uint8 i;
	uint16 sum = 0;
	uint16 ccd_average1;
	
		for(i = 0; i < 128; i++)
		{
			sum += *(image + i);
			
		}

	ccd_average1 = sum / 128;
        
	return ccd_average1;
}

/**
*  @name   : Auto_Threshold
*  @tips   : ��̬��ֵ����
*/
uint16 Sum = 0;
uint16 cbh_Average = 0;
uint16 AD_Average = 0;
uint8  Auto_Threshold(uint8 *image)
{
	uint8 i;
	uint8 New_Threshold;
	Sum = 0;
    
	for(i = 0;i < 128;i++)
	{
		*(ImageDiff + i) = abs(*(image+i) - *(image+i+6))*1000/(*(image+i) + *(image+i+6)); //�������� ����ֵ
		Sum += *(ImageDiff + i); //���
	}
    
	cbh_Average = Sum / 128; //ƽ�����
	AD_Average = CCD_Average(image); //CCDƽ����ѹֵ
	New_Threshold = AD_Average / 6 + cbh_Average; //��ֵ
	
	return New_Threshold;
}

/**
*  @name   : ccd_xj
*  @tips   : CCDѰ��
*/
int black_flag,all_black1,all_black2,all_white1,all_white2;
void ccd_xj()
{
    int i,j;
    
    for(j=0;j<128;j++)
    {
        if(ccd_value[j]>230)
        {
            break;
        }
        else if(j==128)
        {
            all_black1 = 1;
        }
        if(ccd_value2[j]>230)
        {
            break;
        }
        else  if(j==128)
        {
            all_black2 = 1;
        }
        
        if(ccd_value[j]<230)
        {
            break;
        }
        else if(j==128)
        {
            all_white1 = 1;
        }
        
        if(ccd_value2[j]<230)
        {
            break;
        }
        else  if(j==128)
        {
            all_white2 = 1;
        }
    }
    
//    if(Auto == 1) { //������̬��ֵ
//		Threshold = Auto_Threshold(line);
//	}
//	for(j=50;j<80;j++)
//	{
		if(ccd_value2[mid]>230&&all_black2!=0&&all_white2!=0)//�м�>230ɨ�ױߣ�<230ɨ�ڱ�
		{
			Rboundary_black = 0;
			Lboundary_black = 0;
			Rboundary_black2 = 0;
			Lboundary_black2 = 0;
		}
//		if(ccd_value[j]<240)
		else
		{
              
			  for(i=mid;i<123;i++)
				{
						black_cbh11=(float)(ccd_value[i+5]-ccd_value[i])/(ccd_value[i]+ccd_value[i+5])*1000;

						if(black_cbh11>Threshold)
						{
								Rboundary_black = i;
								break;
						}
						else
						{
								Rboundary_black = 123;
						}
				} 
				
				for(i=mid;i<123;i++)
				{
						black_cbh21=(float)(ccd_value2[i+5]-ccd_value2[i])/(ccd_value2[i]+ccd_value2[i+5])*1000;

						if(black_cbh21>Threshold)
						{
								Rboundary_black2 = i;
								break;
						}
						else
						{
								Rboundary_black2 = 123;
						}
				} 
    
				for(i=mid;i>=5;i--)
				{   
						black_cbh12=(float)(ccd_value[i-5]-ccd_value[i])/(ccd_value[i]+ccd_value[i-5])*1000;
        
						if(black_cbh12>Threshold)
						{
								Lboundary_black = i;
								break;
						}
						else
						{
								Lboundary_black = 5;
						}
				}
    
				for(i=mid;i>=5;i--)
				{   
				black_cbh22=(float)(ccd_value2[i-5]-ccd_value2[i])/(ccd_value2[i]+ccd_value2[i-5])*1000;
			
						if(black_cbh22>Threshold)
						{
								Lboundary_black2 = i;
								break;
						}
						else
						{
								Lboundary_black2 = 5;
						}
				}
                //�����
                for(i=0;i<128;i++)
				{   
				outblack_cbh1=(float)(ccd_value[i+5]-ccd_value[i])/(ccd_value[i]+ccd_value[i+5])*1000;
			
						if(outblack_cbh1>Threshold)
						{
								Outside_black1 = i;
								break;
						}
						else
						{
								Outside_black1 = 0;
						}
				}
                
                for(i=128;i>=0;i--)
				{   
				outblack_cbh2=(float)(ccd_value[i-5]-ccd_value[i])/(ccd_value[i]+ccd_value[i-5])*1000;
			
						if(outblack_cbh2>Threshold)
						{
								Outside_black2 = i;
								break;
						}
						else
						{
								Outside_black2 = 127;
						}
				}
		}
//	}
    
    //ccd_data[128]//128�����ݣ��м�64����64������ɨ��
    for(i=mid;i<123;i++)
    {
        ccd_cbh11=(float)(ccd_value[i]-ccd_value[i+5])/(ccd_value[i]+ccd_value[i+5])*1000;

        if(ccd_cbh11>Threshold)
        {
            
            Rboundary_data = i;
            break;
        }
        else
        {
            Rboundary_data = 123;
        }
    } 
    
    for(i=mid;i<123;i++)
    {
		ccd_cbh21=(float)(ccd_value2[i]-ccd_value2[i+5])/(ccd_value2[i]+ccd_value2[i+5])*1000;

		if(ccd_cbh21>Threshold)
        {
            
            Rboundary_data2 = i;
            break;
        }
        else
        {
            Rboundary_data2 = 123;
        }
    } 
    
    for(i=mid;i>=5;i--)
    {   
        ccd_cbh12=(float)(ccd_value[i]-ccd_value[i-5])/(ccd_value[i]+ccd_value[i-5])*1000;
        
        if(ccd_cbh12>Threshold)
        {
            Lboundary_data = i;
            break;
        }
        else
        {
            Lboundary_data = 5;
        }
    }
    
     for(i=mid;i>=5;i--)
    {   
		ccd_cbh22=(float)(ccd_value2[i]-ccd_value2[i-5])/(ccd_value2[i]+ccd_value2[i-5])*1000;
	
        if(ccd_cbh22>Threshold)
        {
            Lboundary_data2 = i;
            break;
        }
        else
        {
            Lboundary_data2 = 5;
        }
    }
    
    mid = (Lboundary_data + Rboundary_data)/2;
    df = Lboundary_data + Rboundary_data - 127;
		road_width1 = Rboundary_data - Lboundary_data;
		road_width2 = Rboundary_data2 - Lboundary_data2;
		Broad_width1 = Rboundary_black - Lboundary_black;
		Broad_width2 = Rboundary_black2 - Lboundary_black2;
}


