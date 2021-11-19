#pragma once
#include "N1230A_API.h"                //默认位置 C:\Program Files %28x86%29\Agilent\N1230A\User Files
#pragma comment(lib, "N1230A_VC.lib")  //默认位置 C:\Program Files %28x86%29\Agilent\N1230A\User Files

extern N1230A_RETURN err;
extern N1230A_INT64 p1;
extern long v1;
extern N1230A_HANDLE		myHandle;
extern N1230A_LOCATION		pDevice;
extern unsigned long	    status;
extern N1230A_INT64          Value_preset;
extern int num;
extern N1230A_INT64 ZERO64;

class ClassN1230A
{
public:
	ClassN1230A();
	~ClassN1230A();
	N1230A_RETURN N1230AGetAXSI_1Raw();    //读取AXISI_1(轴1)位置、速度原始值，返回值：N1230A_RETURN的错误类型枚举值
	N1230A_RETURN presetRawALL();         //清空错误并重置所有原始位置值，返回值：N1230A_RETURN的错误类型枚举值
	char* getErrStr(N1230A_RETURN err);   //获取错误,返回值：“表述错误类型”字符串的地址
	void OpenDivice();                   ////打开板卡,配置myHandle的值
	double round(double number, unsigned int bits);
};

