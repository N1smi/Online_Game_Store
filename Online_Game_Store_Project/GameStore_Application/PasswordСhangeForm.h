#pragma once

namespace GameStore_Application {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Сводка для PasswordСhangeForm
	/// </summary>
	public ref class PasswordСhangeForm : public System::Windows::Forms::Form
	{
	public:
		Client* MyClient;
		PasswordСhangeForm(Client* MyClientCopy)
		{
			MyClient = MyClientCopy;
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~PasswordСhangeForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ LabelChangePassword;
	private: System::Windows::Forms::TextBox^ textBoxOldPassword;
	private: System::Windows::Forms::Label^ LabelOldPassword;
	private: System::Windows::Forms::Label^ LabelNewPassword;
	private: System::Windows::Forms::TextBox^ textBoxNewPassword;
	private: System::Windows::Forms::Label^ labelConfirmPassword;
	private: System::Windows::Forms::TextBox^ textBoxConfirmPassword;
	private: System::Windows::Forms::Button^ ChangePasswordButton;






	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->LabelChangePassword = (gcnew System::Windows::Forms::Label());
			this->textBoxOldPassword = (gcnew System::Windows::Forms::TextBox());
			this->LabelOldPassword = (gcnew System::Windows::Forms::Label());
			this->LabelNewPassword = (gcnew System::Windows::Forms::Label());
			this->textBoxNewPassword = (gcnew System::Windows::Forms::TextBox());
			this->labelConfirmPassword = (gcnew System::Windows::Forms::Label());
			this->textBoxConfirmPassword = (gcnew System::Windows::Forms::TextBox());
			this->ChangePasswordButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// LabelChangePassword
			// 
			this->LabelChangePassword->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->LabelChangePassword->AutoSize = true;
			this->LabelChangePassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->LabelChangePassword->Location = System::Drawing::Point(76, 9);
			this->LabelChangePassword->Name = L"LabelChangePassword";
			this->LabelChangePassword->Size = System::Drawing::Size(254, 32);
			this->LabelChangePassword->TabIndex = 4;
			this->LabelChangePassword->Text = L"Password change";
			this->LabelChangePassword->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBoxOldPassword
			// 
			this->textBoxOldPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBoxOldPassword->Location = System::Drawing::Point(12, 83);
			this->textBoxOldPassword->Name = L"textBoxOldPassword";
			this->textBoxOldPassword->Size = System::Drawing::Size(400, 34);
			this->textBoxOldPassword->TabIndex = 5;
			this->textBoxOldPassword->UseSystemPasswordChar = true;
			// 
			// LabelOldPassword
			// 
			this->LabelOldPassword->AutoSize = true;
			this->LabelOldPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelOldPassword->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->LabelOldPassword->Location = System::Drawing::Point(12, 55);
			this->LabelOldPassword->Name = L"LabelOldPassword";
			this->LabelOldPassword->Size = System::Drawing::Size(134, 25);
			this->LabelOldPassword->TabIndex = 6;
			this->LabelOldPassword->Text = L"Old Password";
			this->LabelOldPassword->Click += gcnew System::EventHandler(this, &PasswordСhangeForm::LabelOldPassword_Click);
			// 
			// LabelNewPassword
			// 
			this->LabelNewPassword->AutoSize = true;
			this->LabelNewPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelNewPassword->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->LabelNewPassword->Location = System::Drawing::Point(12, 127);
			this->LabelNewPassword->Name = L"LabelNewPassword";
			this->LabelNewPassword->Size = System::Drawing::Size(142, 25);
			this->LabelNewPassword->TabIndex = 8;
			this->LabelNewPassword->Text = L"New Password";
			// 
			// textBoxNewPassword
			// 
			this->textBoxNewPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBoxNewPassword->Location = System::Drawing::Point(12, 155);
			this->textBoxNewPassword->Name = L"textBoxNewPassword";
			this->textBoxNewPassword->Size = System::Drawing::Size(400, 34);
			this->textBoxNewPassword->TabIndex = 7;
			this->textBoxNewPassword->UseSystemPasswordChar = true;
			// 
			// labelConfirmPassword
			// 
			this->labelConfirmPassword->AutoSize = true;
			this->labelConfirmPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->labelConfirmPassword->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->labelConfirmPassword->Location = System::Drawing::Point(12, 200);
			this->labelConfirmPassword->Name = L"labelConfirmPassword";
			this->labelConfirmPassword->Size = System::Drawing::Size(214, 25);
			this->labelConfirmPassword->TabIndex = 10;
			this->labelConfirmPassword->Text = L"Confirm your Password";
			// 
			// textBoxConfirmPassword
			// 
			this->textBoxConfirmPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBoxConfirmPassword->Location = System::Drawing::Point(12, 228);
			this->textBoxConfirmPassword->Name = L"textBoxConfirmPassword";
			this->textBoxConfirmPassword->Size = System::Drawing::Size(400, 34);
			this->textBoxConfirmPassword->TabIndex = 9;
			this->textBoxConfirmPassword->UseSystemPasswordChar = true;
			// 
			// ChangePasswordButton
			// 
			this->ChangePasswordButton->AutoSize = true;
			this->ChangePasswordButton->BackColor = System::Drawing::SystemColors::Highlight;
			this->ChangePasswordButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ChangePasswordButton->ForeColor = System::Drawing::SystemColors::Control;
			this->ChangePasswordButton->Location = System::Drawing::Point(12, 268);
			this->ChangePasswordButton->Name = L"ChangePasswordButton";
			this->ChangePasswordButton->Size = System::Drawing::Size(148, 49);
			this->ChangePasswordButton->TabIndex = 12;
			this->ChangePasswordButton->Text = L"Change";
			this->ChangePasswordButton->UseVisualStyleBackColor = false;
			this->ChangePasswordButton->Click += gcnew System::EventHandler(this, &PasswordСhangeForm::ChangePasswordButton_Click);
			// 
			// PasswordСhangeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(424, 326);
			this->Controls->Add(this->ChangePasswordButton);
			this->Controls->Add(this->labelConfirmPassword);
			this->Controls->Add(this->textBoxConfirmPassword);
			this->Controls->Add(this->LabelNewPassword);
			this->Controls->Add(this->textBoxNewPassword);
			this->Controls->Add(this->LabelOldPassword);
			this->Controls->Add(this->textBoxOldPassword);
			this->Controls->Add(this->LabelChangePassword);
			this->MaximizeBox = false;
			this->Name = L"PasswordСhangeForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"PasswordСhangeForm";
			this->Load += gcnew System::EventHandler(this, &PasswordСhangeForm::PasswordСhangeForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void PasswordСhangeForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void LabelOldPassword_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void ChangePasswordButton_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string OldPassword = marshal_as<std::string>(textBoxOldPassword->Text);
	std::string NewPassword = marshal_as<std::string>(textBoxNewPassword->Text);
	std::string ConfirmPassword = marshal_as<std::string>(textBoxConfirmPassword->Text);

	try {
		User checkUser;
		checkUser.set_password(OldPassword);

		if (!MyClient->check_password(OldPassword)) {
			throw std::logic_error("The password is incorrect");
		}

		if (NewPassword != ConfirmPassword) {
			throw std::logic_error("The passwords you entered don't match");
		}

		MyClient->set_password(NewPassword);

		this->Close();
	}
	catch (const std::exception& ex) {
		MessageBox::Show(gcnew String(ex.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
};
}
