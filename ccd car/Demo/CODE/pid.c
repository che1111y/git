#include "headfile.h"

float Realize_SumError  = 0,
	  Realize_LastError = 0,	
	  Realize_PrevError = 0,	
	  Realize_LastData  = 0;

// λ��ʽPID����
int32 PID_Realize(float KP,float KI,float KD,float KT, int32 NowData, int32 Point)
{

	int32 Realize,Error;	// ���ó���ʵ������

	Error = NowData - Point;	// ���㵱ǰ���
	Realize_SumError += KI * Error;	// ������
	
	if (Realize_SumError > KT)			//�����޷�
	{
		Realize_SumError = KT;
	}
	else if (Realize_SumError < -KT)
	{
		Realize_SumError = -KT;
	}
	
	Realize = KP * Error
			+ Realize_SumError
			+ KD *(Error - Realize_LastError);
//			+ PID[KB] * (NowData- LastData); //΢������
	
	Realize_PrevError = Realize_LastError;	// ����ǰ�����
	Realize_LastError = Error;		  	// �����ϴ����
	Realize_LastData  = NowData;			// �����ϴ�����

	return Realize;	// ����ʵ��ֵ
}


float Increase_SumError  = 0,
      Increase_LastError = 0,	
	  Increase_PrevError = 0,	
	  Increase_LastData  = 0;

// ����ʽPID����
uint32 PID_Increase(float KP,float KI,float KD, int32 NowData, int32 Point)
{
	
	static int32 iError,	//��ǰ���
		Increase;	//���ó���ʵ������

	iError = Point - NowData;	// ���㵱ǰ���

	Increase +=  KP * (iError - Increase_LastError)
			  + KI * iError
			  + KD * (iError - 2 * Increase_LastError + Increase_PrevError);
	
	Increase_PrevError = Increase_LastError;	// ����ǰ�����
	Increase_LastError = iError;		  	// �����ϴ����
    if(Increase>30000)
        Increase = 30000;
	
    if(Increase<-30000)
        Increase = -30000;
    
	return Increase;	// ��������
}

float Increase_LSumError  = 0,
      Increase_LLastError = 0,	
	  Increase_LPrevError = 0,	
	  Increase_LLastData  = 0;

// ����ʽPID����
int32 PID_LIncrease(float KP,float KI,float KD, int32 NowData, int32 Point)
{
	
	static int32 iError,	//��ǰ���
		Increase;	//���ó���ʵ������

	iError = Point - NowData;	// ���㵱ǰ���

	Increase +=  KP * (iError - Increase_LLastError)
			  + KI * iError
			  + KD * (iError - 2 * Increase_LLastError + Increase_LPrevError);
	
    if(Increase>20000)
    {
        Increase = 20000;
    }
	
    if(Increase<-20000)
    {
        Increase = -20000;
    }
    
	Increase_LPrevError = Increase_LLastError;	// ����ǰ�����
	Increase_LLastError = iError;		  	// �����ϴ����
	
	return Increase;	// ��������
}


float Increase_RSumError  = 0,
      Increase_RLastError = 0,	
	  Increase_RPrevError = 0,	
	  Increase_RLastData  = 0;

// ����ʽPID����
int32 PID_RIncrease(float KP,float KI,float KD, int32 NowData, int32 Point)
{
	
	static int32 iError,	//��ǰ���
		Increase;	//���ó���ʵ������

	iError = Point - NowData;	// ���㵱ǰ���

	Increase +=  KP * (iError - Increase_RLastError)
			  + KI * iError
			  + KD * (iError - 2 * Increase_RLastError + Increase_RPrevError);
    if(Increase>20000)
    {
        Increase = 20000;
    }
	
    if(Increase<-20000)
    {
        Increase = -20000;
    }
    
    Increase_RPrevError = Increase_RLastError;	// ����ǰ�����
	Increase_RLastError = iError;		  	// �����ϴ����
	
	return Increase;	// ��������
}
//int32 fuzzy_pid()
//{

//}