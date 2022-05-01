#include "headfile.h"

float Realize_SumError  = 0,
	  Realize_LastError = 0,	
	  Realize_PrevError = 0,	
	  Realize_LastData  = 0;

// 位置式PID控制
int32 PID_Realize(float KP,float KI,float KD,float KT, int32 NowData, int32 Point)
{

	int32 Realize,Error;	// 最后得出的实际增量

	Error = NowData - Point;	// 计算当前误差
	Realize_SumError += KI * Error;	// 误差积分
	
	if (Realize_SumError > KT)			//积分限幅
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
//			+ PID[KB] * (NowData- LastData); //微分先行
	
	Realize_PrevError = Realize_LastError;	// 更新前次误差
	Realize_LastError = Error;		  	// 更新上次误差
	Realize_LastData  = NowData;			// 更新上次数据

	return Realize;	// 返回实际值
}


float Increase_SumError  = 0,
      Increase_LastError = 0,	
	  Increase_PrevError = 0,	
	  Increase_LastData  = 0;

// 增量式PID控制
uint32 PID_Increase(float KP,float KI,float KD, int32 NowData, int32 Point)
{
	
	static int32 iError,	//当前误差
		Increase;	//最后得出的实际增量

	iError = Point - NowData;	// 计算当前误差

	Increase +=  KP * (iError - Increase_LastError)
			  + KI * iError
			  + KD * (iError - 2 * Increase_LastError + Increase_PrevError);
	
	Increase_PrevError = Increase_LastError;	// 更新前次误差
	Increase_LastError = iError;		  	// 更新上次误差
    if(Increase>30000)
        Increase = 30000;
	
    if(Increase<-30000)
        Increase = -30000;
    
	return Increase;	// 返回增量
}

float Increase_LSumError  = 0,
      Increase_LLastError = 0,	
	  Increase_LPrevError = 0,	
	  Increase_LLastData  = 0;

// 增量式PID控制
int32 PID_LIncrease(float KP,float KI,float KD, int32 NowData, int32 Point)
{
	
	static int32 iError,	//当前误差
		Increase;	//最后得出的实际增量

	iError = Point - NowData;	// 计算当前误差

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
    
	Increase_LPrevError = Increase_LLastError;	// 更新前次误差
	Increase_LLastError = iError;		  	// 更新上次误差
	
	return Increase;	// 返回增量
}


float Increase_RSumError  = 0,
      Increase_RLastError = 0,	
	  Increase_RPrevError = 0,	
	  Increase_RLastData  = 0;

// 增量式PID控制
int32 PID_RIncrease(float KP,float KI,float KD, int32 NowData, int32 Point)
{
	
	static int32 iError,	//当前误差
		Increase;	//最后得出的实际增量

	iError = Point - NowData;	// 计算当前误差

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
    
    Increase_RPrevError = Increase_RLastError;	// 更新前次误差
	Increase_RLastError = iError;		  	// 更新上次误差
	
	return Increase;	// 返回增量
}
//int32 fuzzy_pid()
//{

//}