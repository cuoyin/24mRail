#pragma once
#include<iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include "ClassN1230A.h"
#include "math.h"

#include <msclr/marshal_cppstd.h>
namespace My5517interfer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;
	using namespace std;

	/// <summary>
	/// My5517interferForm 摘要
	/// </summary>
	public ref class My5517interferForm : public System::Windows::Forms::Form
	{
		marshal_context^ context = gcnew marshal_context(); //用于System::String^与std::string之间的转化 
		double p_convert = 0.999728766 * 632.99137e-6 / 1024 / 2; //std air, pmi//原始位置数据与实际数据（mm）的转换因子
		double v_convert = (632.99137)*10  / pow(2,22); //原始速度数据与实际数据（mm/s）的转换因子

	
		
	public:
		My5517interferForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~My5517interferForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  txt_Position1;
	private: System::Windows::Forms::Label^  AXIS_1;
	private: System::Windows::Forms::Label^  lbl_Position;
	private: System::Windows::Forms::TextBox^  txt_Velocity;

	private: System::Windows::Forms::Label^  lbl_Velocity;
	private: System::Windows::Forms::Timer^  tmrAxis1_Reflash;

	private: System::Windows::Forms::Button^  btn_presetAll;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  btn_openDevice;

	private: System::ComponentModel::IContainer^  components;
	protected:
	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要修改
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->txt_Position1 = (gcnew System::Windows::Forms::TextBox());
			this->AXIS_1 = (gcnew System::Windows::Forms::Label());
			this->lbl_Position = (gcnew System::Windows::Forms::Label());
			this->txt_Velocity = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Velocity = (gcnew System::Windows::Forms::Label());
			this->tmrAxis1_Reflash = (gcnew System::Windows::Forms::Timer(this->components));
			this->btn_presetAll = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btn_openDevice = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// txt_Position1
			// 
			this->txt_Position1->BackColor = System::Drawing::Color::PaleTurquoise;
			this->txt_Position1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_Position1->Location = System::Drawing::Point(124, 49);
			this->txt_Position1->Name = L"txt_Position1";
			this->txt_Position1->ReadOnly = true;
			this->txt_Position1->Size = System::Drawing::Size(522, 44);
			this->txt_Position1->TabIndex = 0;
			// 
			// AXIS_1
			// 
			this->AXIS_1->AutoSize = true;
			this->AXIS_1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AXIS_1->Location = System::Drawing::Point(32, 58);
			this->AXIS_1->Name = L"AXIS_1";
			this->AXIS_1->Size = System::Drawing::Size(75, 23);
			this->AXIS_1->TabIndex = 1;
			this->AXIS_1->Text = L"AXIS_1";
			// 
			// lbl_Position
			// 
			this->lbl_Position->AutoSize = true;
			this->lbl_Position->Font = (gcnew System::Drawing::Font(L"宋体", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Position->Location = System::Drawing::Point(138, 21);
			this->lbl_Position->Name = L"lbl_Position";
			this->lbl_Position->Size = System::Drawing::Size(95, 20);
			this->lbl_Position->TabIndex = 2;
			this->lbl_Position->Text = L"位置(mm)";
			// 
			// txt_Velocity
			// 
			this->txt_Velocity->BackColor = System::Drawing::Color::PaleTurquoise;
			this->txt_Velocity->Font = (gcnew System::Drawing::Font(L"Times New Roman", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_Velocity->Location = System::Drawing::Point(664, 49);
			this->txt_Velocity->Name = L"txt_Velocity";
			this->txt_Velocity->ReadOnly = true;
			this->txt_Velocity->Size = System::Drawing::Size(246, 44);
			this->txt_Velocity->TabIndex = 3;
			// 
			// lbl_Velocity
			// 
			this->lbl_Velocity->AutoSize = true;
			this->lbl_Velocity->Font = (gcnew System::Drawing::Font(L"宋体", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Velocity->Location = System::Drawing::Point(677, 21);
			this->lbl_Velocity->Name = L"lbl_Velocity";
			this->lbl_Velocity->Size = System::Drawing::Size(117, 20);
			this->lbl_Velocity->TabIndex = 4;
			this->lbl_Velocity->Text = L"速度(mm/s)";
			// 
			// tmrAxis1_Reflash
			// 
			this->tmrAxis1_Reflash->Interval = 500;
			this->tmrAxis1_Reflash->Tick += gcnew System::EventHandler(this, &My5517interferForm::tmrAxis1_Reflash_Tick);
			// 
			// btn_presetAll
			// 
			this->btn_presetAll->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_presetAll->Location = System::Drawing::Point(210, 36);
			this->btn_presetAll->Margin = System::Windows::Forms::Padding(5);
			this->btn_presetAll->Name = L"btn_presetAll";
			this->btn_presetAll->Size = System::Drawing::Size(177, 38);
			this->btn_presetAll->TabIndex = 6;
			this->btn_presetAll->Text = L"Preset All";
			this->btn_presetAll->UseVisualStyleBackColor = true;
			this->btn_presetAll->Click += gcnew System::EventHandler(this, &My5517interferForm::btn_presetAll_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->btn_openDevice);
			this->groupBox1->Controls->Add(this->btn_presetAll);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->groupBox1->Location = System::Drawing::Point(36, 114);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(418, 92);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"板卡操作";
			// 
			// btn_openDevice
			// 
			this->btn_openDevice->Font = (gcnew System::Drawing::Font(L"宋体", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->btn_openDevice->Location = System::Drawing::Point(8, 35);
			this->btn_openDevice->Name = L"btn_openDevice";
			this->btn_openDevice->Size = System::Drawing::Size(177, 38);
			this->btn_openDevice->TabIndex = 7;
			this->btn_openDevice->Text = L"打开板卡";
			this->btn_openDevice->UseVisualStyleBackColor = true;
			this->btn_openDevice->Click += gcnew System::EventHandler(this, &My5517interferForm::btn_openDevice_Click);
			// 
			// My5517interferForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(965, 234);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->lbl_Velocity);
			this->Controls->Add(this->txt_Velocity);
			this->Controls->Add(this->lbl_Position);
			this->Controls->Add(this->AXIS_1);
			this->Controls->Add(this->txt_Position1);
			this->Font = (gcnew System::Drawing::Font(L"宋体", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
			this->Name = L"My5517interferForm";
			this->Text = L"5517单路调试";
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

#pragma region  <timer> 隔500ms读取并刷新位置、速度数据并检测错误
		private: System::Void tmrAxis1_Reflash_Tick(System::Object^  sender, System::EventArgs^  e) {
			try
			{
				ClassN1230A  o_readRawPos;             //实例化“读取单轴位置速度”功能并执行
				err = o_readRawPos.N1230AGetAXSI_1Raw();
				long long  posValue1_longlong = p1.msb * pow(2,32)  + p1.lsb;
				double posValue1 = posValue1_longlong *p_convert;
				double velocity1 = v1* v_convert;
				ClassN1230A o_keep_5dec;

				double posValue1_keep5dec = o_keep_5dec.round(posValue1,4);//保留5位小数
				double velocity1_keep5dec = o_keep_5dec.round(velocity1,3);//保留4位小数

				if (err != N1230A_SUCCESS)throw(err);
				
				txt_Velocity->BackColor = System::Drawing::Color::PaleTurquoise;//调文本框背景色为天蓝色
				txt_Position1->BackColor = System::Drawing::Color::PaleTurquoise;
				this->txt_Position1->ForeColor = System::Drawing::SystemColors::WindowText;//调字体颜色
				
				txt_Position1->Text = posValue1_keep5dec.ToString();
				txt_Velocity->Text = Convert::ToString(velocity1_keep5dec);
			}

			catch (N1230A_RETURN err) {
				//将char*对应字符串转换为string类型
				string cup, changeToStr;
				char* pErrType; char* sub_pErr;
				ClassN1230A  o_getErr;              //实例化“获取错误类型”功能
				pErrType = o_getErr.getErrStr(err); //执行“获取错误类型”
				sub_pErr = pErrType;                //将pErrType的地址赋值给sub_pErr
				while (*sub_pErr != '\0')
				{
					cup = *(sub_pErr);
					sub_pErr++;
					changeToStr = changeToStr + cup;
				}
				txt_Velocity->BackColor = System::Drawing::Color::Yellow; //调文本框背景色为黄色
				this->txt_Position1->BackColor = System::Drawing::Color::Yellow; //调文本框背景色为黄色
				this->txt_Position1->ForeColor = System::Drawing::Color::Red;  //调字体会红色
				txt_Position1->Text = context->marshal_as<System::String^>(changeToStr);//显示板卡反馈的错误提示；
				this->tmrAxis1_Reflash->Enabled = false;
			}
		}
#pragma endregion
	
		
	

#pragma region <按键Preset>清空所有轴的错误并重置位置值
private: System::Void btn_presetAll_Click(System::Object^  sender, System::EventArgs^  e) {
	
	ClassN1230A preset;
	err = preset.presetRawALL();
	this->tmrAxis1_Reflash->Enabled = true; //尝试读取数据
}
#pragma endregion
			 
#pragma region <按键打开设备>打开板卡并获取myHandle值

private: System::Void btn_openDevice_Click(System::Object^  sender, System::EventArgs^  e) {
	try {
		ClassN1230A o_open; o_open.OpenDivice();//实例化“打开板卡”功能并执行
		
		if (err != N1230A_SUCCESS)throw(err);  //err != N1230A_SUCCESS 则跳转到报错
		
	}
	catch (N1230A_RETURN err) {
		//将char*对应字符串转换为string类型
		string cup, changeToStr;
		char* pErrType; char* sub_pErr;
		ClassN1230A  o_getErr;              //实例化“获取错误类型”功能
		pErrType = o_getErr.getErrStr(err); //执行“获取错误类型”
		sub_pErr = pErrType;                //将pErrType的地址赋值给sub_pErr
		while (*sub_pErr != '\0')
		{
			cup = *(sub_pErr);
			sub_pErr++;
			changeToStr = changeToStr + cup;
		}
		txt_Velocity->BackColor = System::Drawing::Color::Yellow;
		this->txt_Position1->BackColor = System::Drawing::Color::Yellow;
		this->txt_Position1->ForeColor = System::Drawing::Color::Red;
		txt_Position1->Text = context->marshal_as<System::String^>(changeToStr);//显示板卡反馈的错误提示；
	}
	
}
#pragma endregion
};
}
