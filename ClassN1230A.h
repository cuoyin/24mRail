#pragma once
#include "N1230A_API.h"                //Ĭ��λ�� C:\Program Files %28x86%29\Agilent\N1230A\User Files
#pragma comment(lib, "N1230A_VC.lib")  //Ĭ��λ�� C:\Program Files %28x86%29\Agilent\N1230A\User Files

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
	N1230A_RETURN N1230AGetAXSI_1Raw();    //��ȡAXISI_1(��1)λ�á��ٶ�ԭʼֵ������ֵ��N1230A_RETURN�Ĵ�������ö��ֵ
	N1230A_RETURN presetRawALL();         //��մ�����������ԭʼλ��ֵ������ֵ��N1230A_RETURN�Ĵ�������ö��ֵ
	char* getErrStr(N1230A_RETURN err);   //��ȡ����,����ֵ���������������͡��ַ����ĵ�ַ
	void OpenDivice();                   ////�򿪰忨,����myHandle��ֵ
	double round(double number, unsigned int bits);
};

