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
//��մ�����������ԭʼλ��ֵ������ֵ��N1230A_RETURN�Ĵ�������ö��ֵ
N1230A_RETURN ClassN1230A::presetRawALL()
{
	err = N1230APresetRawAll(myHandle, ZERO64, ZERO64, ZERO64, &status);//����������
	//err = N1230APresetRaw(myHandle,AXIS_1, ZERO64, &status);//��������
	return err;
}

//��ȡAXISI_1(��1)λ�á��ٶ�ԭʼֵ������ֵ��N1230A_RETURN�Ĵ�������ö��ֵ
N1230A_RETURN ClassN1230A::N1230AGetAXSI_1Raw()
{
	N1230A_RETURN err;
	err = N1230AGetRawPosVel(myHandle, AXIS_1, &p1, &v1);
	return err;
}

//�򿪰忨,����myHandle��ֵ
void  ClassN1230A::OpenDivice()
{
	N1230ADefaultDevice(&pDevice);
	err = N1230AOpen(&pDevice, &myHandle, NULL);
}

//��ȡ���� ����ֵ���������������ַ����ĵ�ַ
char* ClassN1230A::getErrStr(N1230A_RETURN err)
{
	char* err_type;
	err_type = N1230AGetErrStr(err);
	return err_type;
} 
//��double��������λС��������
double ClassN1230A::round(double number, unsigned int bits)
{
	long long integerpart = number;//ȡ����
	number -= integerpart;
	for (unsigned int i = 0; i < bits; ++i)//ȡ�����С�����г�10����
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