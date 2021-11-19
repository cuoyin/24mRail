#include "5517interferForm.h"
#include "N1230A_API.h"      //默认位置 C:\Program Files %28x86%29\Agilent\N1230A\User Files

#include <stdio.h>
#include<iostream>
#include <string>
using namespace std;
//用于打开板卡:
N1230A_HANDLE	myHandle = NULL;
N1230A_LOCATION	pDevice;

//用于读取或重置干涉仪位置值
N1230A_INT64 preset;
N1230A_INT64 p1, Value_preset;
N1230A_INT64 ZERO64 = { 0, 0 };


//返回错误
N1230A_RETURN err;

//状态值
unsigned long	status;

//AXIS_1的速度
long v1;


int main()
{
	System::Windows::Forms::Application::Run(gcnew My5517interfer::My5517interferForm());
	return 0;
}