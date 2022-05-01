#include "headfile.h"


float                v[6]; 
uint16              var_guiyihua_min[4]={0,0,0,0};
uint16              var_guiyihua_max[4]={0,0,0,0};
float ad_value1,ad_value2,ad_value3,ad_value4;
uint16 g_ValueOfAD[6]={0};
int cbh;

/*********************************��ʼ��***********************************/
void dc_init()
{
	adc_init(ADC_P00,ADC_SYSclk_DIV_2);
	adc_init(ADC_P01,ADC_SYSclk_DIV_2);
	adc_init(ADC_P05,ADC_SYSclk_DIV_2);
	adc_init(ADC_P06,ADC_SYSclk_DIV_2);
}

float Get_ADC(uint16 x)
{
     uint16  i,j,k,temp;
     uint16  ad_valu[4][5],ad_valu1[4],ad_sum[4];

     for(i=0;i<5;i++)     
     {  
          ad_valu[0][i]=adc_once(ADC_P00, ADC_10BIT);  
          ad_valu[1][i]=adc_once(ADC_P01, ADC_10BIT);    
          ad_valu[2][i]=adc_once(ADC_P05, ADC_10BIT);  
          ad_valu[3][i]=adc_once(ADC_P06, ADC_10BIT); 
          
     }
     
     for(i=0;i<4;i++)
    {
      for(j=0;j<5;j++)  
      {       
          if(ad_valu[i][j]>var_guiyihua_max[j]) 
              var_guiyihua_max[j]=ad_valu[i][j];
          if(ad_valu[i][j]<var_guiyihua_min[j])
              var_guiyihua_min[j]=ad_valu[i][j];
      }
    }
     
     /*====================ð������==========================*/
     for(i=0;i<4;i++)
     {
        for(j=0;j<5;j++)
        {
           for(k=0;k<5-j;k++)
           {
              if(ad_valu[i][k] > ad_valu[i][k+1])        //ǰ��ıȺ���Ĵ�  ����н���
              {
                 temp = ad_valu[i][k+1];
                 ad_valu[i][k+1] = ad_valu[i][k];
                 ad_valu[i][k] = temp;
              }
           }
        }
     }
     /*=====================ð������==========================*/
     
     
     /*====================��ֵƽ���˲�=========================*/
     for(i=0;i<4;i++)    
     {
        ad_sum[i] = ad_valu[i][1] + ad_valu[i][2] + ad_valu[i][3];
        ad_valu1[i] = ad_sum[i] / 3;
     }
     
    /*====================��ֵƽ���˲�=========================*/
     
     /*=======================��һ��============================= */
    for(j=0;j<5;j++)
    {
      if(var_guiyihua_min[j]>=ad_valu1[j])    
          {var_guiyihua_min[j]=(int)ad_valu1[j];}
      
      if(var_guiyihua_max[j]<=ad_valu1[j])    
          {var_guiyihua_max[j]=(int)ad_valu1[j];}
      
    }
  for(j=0;j<5;j++)
  {
    v[j]=(uint32)((float)(ad_valu1[j]-var_guiyihua_min[j])/(float)(var_guiyihua_max[j]-var_guiyihua_min[j])*100.0);
  }
  /*=========================��һ��============================= */
  
  return v[x];
}

void ADC(void)
{
//      ad_value1 = adc_once(ADC_P00, ADC_10BIT);
//      ad_value2 = adc_once(ADC_P01, ADC_10BIT);
//      ad_value3 = adc_once(ADC_P05, ADC_10BIT);
//      ad_value4 = adc_once(ADC_P06, ADC_10BIT);
    
      ad_value1 = Get_ADC(0);
      ad_value2 = Get_ADC(1);
      ad_value3 = Get_ADC(2);
      ad_value4 = Get_ADC(3);
      cbh = (int)(((ad_value2 - ad_value3)/(ad_value2 + ad_value3))*100.0);
}