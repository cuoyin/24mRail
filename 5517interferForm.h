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
	/// My5517interferForm ժҪ
	/// </summary>
	public ref class My5517interferForm : public System::Windows::Forms::Form
	{
		marshal_context^ context = gcnew marshal_context(); //����System::String^��std::string֮���ת�� 
		double p_convert = 0.999728766 * 632.99137e-6 / 1024 / 2; //std air, pmi//ԭʼλ��������ʵ�����ݣ�mm����ת������
		double v_convert = (632.99137)*10  / pow(2,22); //ԭʼ�ٶ�������ʵ�����ݣ�mm/s����ת������

	
		
	public:
		My5517interferForm(void)
		{
			InitializeComponent();
			//
			//TODO:  �ڴ˴���ӹ��캯������
			//
		}

	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
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
		/// ����������������
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����֧������ķ��� - ��Ҫ�޸�
		/// ʹ�ô���༭���޸Ĵ˷��������ݡ�
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
			this->lbl_Position->Font = (gcnew System::Drawing::Font(L"����", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Position->Location = System::Drawing::Point(138, 21);
			this->lbl_Position->Name = L"lbl_Position";
			this->lbl_Position->Size = System::Drawing::Size(95, 20);
			this->lbl_Position->TabIndex = 2;
			this->lbl_Position->Text = L"λ��(mm)";
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
			this->lbl_Velocity->Font = (gcnew System::Drawing::Font(L"����", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Velocity->Location = System::Drawing::Point(677, 21);
			this->lbl_Velocity->Name = L"lbl_Velocity";
			this->lbl_Velocity->Size = System::Drawing::Size(117, 20);
			this->lbl_Velocity->TabIndex = 4;
			this->lbl_Velocity->Text = L"�ٶ�(mm/s)";
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
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->groupBox1->Location = System::Drawing::Point(36, 114);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(418, 92);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"�忨����";
			// 
			// btn_openDevice
			// 
			this->btn_openDevice->Font = (gcnew System::Drawing::Font(L"����", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->btn_openDevice->Location = System::Drawing::Point(8, 35);
			this->btn_openDevice->Name = L"btn_openDevice";
			this->btn_openDevice->Size = System::Drawing::Size(177, 38);
			this->btn_openDevice->TabIndex = 7;
			this->btn_openDevice->Text = L"�򿪰忨";
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
			this->Font = (gcnew System::Drawing::Font(L"����", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
			this->Name = L"My5517interferForm";
			this->Text = L"5517��·����";
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

#pragma region  <timer> ��500ms��ȡ��ˢ��λ�á��ٶ����ݲ�������
		private: System::Void tmrAxis1_Reflash_Tick(System::Object^  sender, System::EventArgs^  e) {
			try
			{
				ClassN1230A  o_readRawPos;             //ʵ��������ȡ����λ���ٶȡ����ܲ�ִ��
				err = o_readRawPos.N1230AGetAXSI_1Raw();
				long long  posValue1_longlong = p1.msb * pow(2,32)  + p1.lsb;
				double posValue1 = posValue1_longlong *p_convert;
				double velocity1 = v1* v_convert;
				ClassN1230A o_keep_5dec;

				double posValue1_keep5dec = o_keep_5dec.round(posValue1,4);//����5λС��
				double velocity1_keep5dec = o_keep_5dec.round(velocity1,3);//����4λС��

				if (err != N1230A_SUCCESS)throw(err);
				
				txt_Velocity->BackColor = System::Drawing::Color::PaleTurquoise;//���ı��򱳾�ɫΪ����ɫ
				txt_Position1->BackColor = System::Drawing::Color::PaleTurquoise;
				this->txt_Position1->ForeColor = System::Drawing::SystemColors::WindowText;//��������ɫ
				
				txt_Position1->Text = posValue1_keep5dec.ToString();
				txt_Velocity->Text = Convert::ToString(velocity1_keep5dec);
			}

			catch (N1230A_RETURN err) {
				//��char*��Ӧ�ַ���ת��Ϊstring����
				string cup, changeToStr;
				char* pErrType; char* sub_pErr;
				ClassN1230A  o_getErr;              //ʵ��������ȡ�������͡�����
				pErrType = o_getErr.getErrStr(err); //ִ�С���ȡ�������͡�
				sub_pErr = pErrType;                //��pErrType�ĵ�ַ��ֵ��sub_pErr
				while (*sub_pErr != '\0')
				{
					cup = *(sub_pErr);
					sub_pErr++;
					changeToStr = changeToStr + cup;
				}
				txt_Velocity->BackColor = System::Drawing::Color::Yellow; //���ı��򱳾�ɫΪ��ɫ
				this->txt_Position1->BackColor = System::Drawing::Color::Yellow; //���ı��򱳾�ɫΪ��ɫ
				this->txt_Position1->ForeColor = System::Drawing::Color::Red;  //��������ɫ
				txt_Position1->Text = context->marshal_as<System::String^>(changeToStr);//��ʾ�忨�����Ĵ�����ʾ��
				this->tmrAxis1_Reflash->Enabled = false;
			}
		}
#pragma endregion
	
		
	

#pragma region <����Preset>���������Ĵ�������λ��ֵ
private: System::Void btn_presetAll_Click(System::Object^  sender, System::EventArgs^  e) {
	
	ClassN1230A preset;
	err = preset.presetRawALL();
	this->tmrAxis1_Reflash->Enabled = true; //���Զ�ȡ����
}
#pragma endregion
			 
#pragma region <�������豸>�򿪰忨����ȡmyHandleֵ

private: System::Void btn_openDevice_Click(System::Object^  sender, System::EventArgs^  e) {
	try {
		ClassN1230A o_open; o_open.OpenDivice();//ʵ�������򿪰忨�����ܲ�ִ��
		
		if (err != N1230A_SUCCESS)throw(err);  //err != N1230A_SUCCESS ����ת������
		
	}
	catch (N1230A_RETURN err) {
		//��char*��Ӧ�ַ���ת��Ϊstring����
		string cup, changeToStr;
		char* pErrType; char* sub_pErr;
		ClassN1230A  o_getErr;              //ʵ��������ȡ�������͡�����
		pErrType = o_getErr.getErrStr(err); //ִ�С���ȡ�������͡�
		sub_pErr = pErrType;                //��pErrType�ĵ�ַ��ֵ��sub_pErr
		while (*sub_pErr != '\0')
		{
			cup = *(sub_pErr);
			sub_pErr++;
			changeToStr = changeToStr + cup;
		}
		txt_Velocity->BackColor = System::Drawing::Color::Yellow;
		this->txt_Position1->BackColor = System::Drawing::Color::Yellow;
		this->txt_Position1->ForeColor = System::Drawing::Color::Red;
		txt_Position1->Text = context->marshal_as<System::String^>(changeToStr);//��ʾ�忨�����Ĵ�����ʾ��
	}
	
}
#pragma endregion
};
}
