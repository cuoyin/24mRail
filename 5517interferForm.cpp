#include "5517interferForm.h"
#include "N1230A_API.h"      //Ĭ��λ�� C:\Program Files %28x86%29\Agilent\N1230A\User Files

#include <stdio.h>
#include<iostream>
#include <string>
using namespace std;
//���ڴ򿪰忨:
N1230A_HANDLE	myHandle = NULL;
N1230A_LOCATION	pDevice;

//���ڶ�ȡ�����ø�����λ��ֵ
N1230A_INT64 preset;
N1230A_INT64 p1, Value_preset;
N1230A_INT64 ZERO64 = { 0, 0 };


//���ش���
N1230A_RETURN err;

//״ֵ̬
unsigned long	status;

//AXIS_1���ٶ�
long v1;


int main()
{
	System::Windows::Forms::Application::Run(gcnew My5517interfer::My5517interferForm());
	return 0;
}