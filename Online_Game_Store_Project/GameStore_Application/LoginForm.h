#pragma once
#include "RegistrationForm.h"

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	/// 

	public ref class LoginForm : public System::Windows::Forms::Form
	{
	private:
		GameStore* MyGameStore;
	public:
		LoginForm(void)
		{
			MyGameStore = new GameStore();
			(*MyGameStore).load_users("E:\\GitHub\\Online_Game_Store\\Online_Game_Store_Project\\Users.csv");
			InitializeComponent();
		
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ ToRegistrationForm;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->ToRegistrationForm = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// ToRegistrationForm
			// 
			this->ToRegistrationForm->BackColor = System::Drawing::SystemColors::Control;
			this->ToRegistrationForm->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->ToRegistrationForm->ForeColor = System::Drawing::SystemColors::Highlight;
			this->ToRegistrationForm->Location = System::Drawing::Point(338, 12);
			this->ToRegistrationForm->Name = L"ToRegistrationForm";
			this->ToRegistrationForm->Size = System::Drawing::Size(132, 40);
			this->ToRegistrationForm->TabIndex = 0;
			this->ToRegistrationForm->Text = L"Sign Up";
			this->ToRegistrationForm->UseVisualStyleBackColor = false;
			this->ToRegistrationForm->Click += gcnew System::EventHandler(this, &LoginForm::ToRegistrationForm_Click);
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(482, 453);
			this->Controls->Add(this->ToRegistrationForm);
			this->MaximizeBox = false;
			this->Name = L"LoginForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"LoginForm";
			this->Load += gcnew System::EventHandler(this, &LoginForm::LoginForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void LoginForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void ToRegistrationForm_Click(System::Object^ sender, System::EventArgs^ e) {
		GameStore_Application::RegistrationForm^ regForm = gcnew GameStore_Application::RegistrationForm(MyGameStore);
		regForm->Owner = this;
		regForm->Show();
		this->Hide();
	}
	};
}
