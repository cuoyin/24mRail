#include "ClassN1230A.h"
#include <string>
#include "N1230A_API.h"
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <wtypes.h>
#include <winbase.h>


ClassN1230A::ClassN1230A()
{
	
}


ClassN1230A::~ClassN1230A()
{
}
//清空错误并重置所有原始位置值，返回值：N1230A_RETURN的错误类型枚举值
N1230A_RETURN ClassN1230A::presetRawALL()
{
	err = N1230APresetRawAll(myHandle, ZERO64, ZERO64, ZERO64, &status);//所有轴重置
	//err = N1230APresetRaw(myHandle,AXIS_1, ZERO64, &status);//单轴重置
	return err;
}

//读取AXISI_1(轴1)位置、速度原始值，返回值：N1230A_RETURN的错误类型枚举值
N1230A_RETURN ClassN1230A::N1230AGetAXSI_1Raw()
{
	N1230A_RETURN err;
	err = N1230AGetRawPosVel(myHandle, AXIS_1, &p1, &v1);
	return err;
}

//打开板卡,配置myHandle的值
void  ClassN1230A::OpenDivice()
{
	N1230ADefaultDevice(&pDevice);
	err = N1230AOpen(&pDevice, &myHandle, NULL);
}

//获取错误 返回值：表述错误类型字符串的地址
char* ClassN1230A::getErrStr(N1230A_RETURN err)
{
	char* err_type;
	err_type = N1230AGetErrStr(err);
	return err_type;
} 
//将double保留若干位小数并返回
double ClassN1230A::round(double number, unsigned int bits)
{
	long long integerpart = number;//取整数
	number -= integerpart;
	for (unsigned int i = 0; i < bits; ++i)//取整后的小数进行乘10处理
	{
		number *= 10;
	}
	number = (long long)(number + 0.5);
	for (unsigned int i = 0; i<bits; ++i)
	{
		number /= 10;
	}
	return integerpart + number;
}