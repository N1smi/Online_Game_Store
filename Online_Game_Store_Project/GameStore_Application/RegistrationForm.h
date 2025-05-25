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
  /// —водка дл€ RegistrationForm
  /// </summary>
  /// 
  /// 

  public ref class RegistrationForm : public System::Windows::Forms::Form
  {
  public:
    GameStore* MyGameStoreCopy;
    RegistrationForm(GameStore* MyGameStore)
    {
      MyGameStoreCopy = MyGameStore;
      InitializeComponent();
      //
      //TODO: добавьте код конструктора
      //
    }

  protected:
    /// <summary>
    /// ќсвободить все используемые ресурсы.
    /// </summary>
    ~RegistrationForm()
    {
      if (components)
      {
        delete components;
      }
    }
  private: System::Windows::Forms::TextBox^ textBoxLogin;
  private: System::Windows::Forms::Label^ LabelLogin;
  private: System::Windows::Forms::Label^ Label_Registration;
  private: System::Windows::Forms::Label^ LabelCreatePassword;
  private: System::Windows::Forms::TextBox^ TextBoxCreatePassword;



  private: System::Windows::Forms::Label^ LabelConfirmPassword;
  private: System::Windows::Forms::TextBox^ TextBoxConfirmPassword;




  private: System::Windows::Forms::Button^ RegisterButton;

  protected:

  protected:

  private:
    /// <summary>
    /// ќб€зательна€ переменна€ конструктора.
    /// </summary>
    System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
    /// <summary>
    /// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
    /// содержимое этого метода с помощью редактора кода.
    /// </summary>
    void InitializeComponent(void)
    {
      this->textBoxLogin = (gcnew System::Windows::Forms::TextBox());
      this->LabelLogin = (gcnew System::Windows::Forms::Label());
      this->Label_Registration = (gcnew System::Windows::Forms::Label());
      this->LabelCreatePassword = (gcnew System::Windows::Forms::Label());
      this->TextBoxCreatePassword = (gcnew System::Windows::Forms::TextBox());
      this->LabelConfirmPassword = (gcnew System::Windows::Forms::Label());
      this->TextBoxConfirmPassword = (gcnew System::Windows::Forms::TextBox());
      this->RegisterButton = (gcnew System::Windows::Forms::Button());
      this->SuspendLayout();
      // 
      // textBoxLogin
      // 
      this->textBoxLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
      this->textBoxLogin->Location = System::Drawing::Point(18, 73);
      this->textBoxLogin->Name = L"textBoxLogin";
      this->textBoxLogin->Size = System::Drawing::Size(452, 38);
      this->textBoxLogin->TabIndex = 0;
      // 
      // LabelLogin
      // 
      this->LabelLogin->AutoSize = true;
      this->LabelLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
      this->LabelLogin->Location = System::Drawing::Point(12, 38);
      this->LabelLogin->Name = L"LabelLogin";
      this->LabelLogin->Size = System::Drawing::Size(85, 32);
      this->LabelLogin->TabIndex = 1;
      this->LabelLogin->Text = L"Login";
      // 
      // Label_Registration
      // 
      this->Label_Registration->Anchor = System::Windows::Forms::AnchorStyles::Top;
      this->Label_Registration->AutoSize = true;
      this->Label_Registration->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
      this->Label_Registration->Location = System::Drawing::Point(148, 9);
      this->Label_Registration->Name = L"Label_Registration";
      this->Label_Registration->Size = System::Drawing::Size(179, 32);
      this->Label_Registration->TabIndex = 2;
      this->Label_Registration->Text = L"Registration";
      this->Label_Registration->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
      // 
      // LabelCreatePassword
      // 
      this->LabelCreatePassword->AutoSize = true;
      this->LabelCreatePassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
      this->LabelCreatePassword->Location = System::Drawing::Point(12, 138);
      this->LabelCreatePassword->Name = L"LabelCreatePassword";
      this->LabelCreatePassword->Size = System::Drawing::Size(227, 32);
      this->LabelCreatePassword->TabIndex = 4;
      this->LabelCreatePassword->Text = L"Create password";
      // 
      // TextBoxCreatePassword
      // 
      this->TextBoxCreatePassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
      this->TextBoxCreatePassword->Location = System::Drawing::Point(18, 173);
      this->TextBoxCreatePassword->Name = L"TextBoxCreatePassword";
      this->TextBoxCreatePassword->Size = System::Drawing::Size(452, 38);
      this->TextBoxCreatePassword->TabIndex = 3;
      this->TextBoxCreatePassword->UseSystemPasswordChar = true;
      // 
      // LabelConfirmPassword
      // 
      this->LabelConfirmPassword->AutoSize = true;
      this->LabelConfirmPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
      this->LabelConfirmPassword->Location = System::Drawing::Point(12, 240);
      this->LabelConfirmPassword->Name = L"LabelConfirmPassword";
      this->LabelConfirmPassword->Size = System::Drawing::Size(303, 32);
      this->LabelConfirmPassword->TabIndex = 6;
      this->LabelConfirmPassword->Text = L"Confirm your password";
      // 
      // TextBoxConfirmPassword
      // 
      this->TextBoxConfirmPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
      this->TextBoxConfirmPassword->Location = System::Drawing::Point(18, 275);
      this->TextBoxConfirmPassword->Name = L"TextBoxConfirmPassword";
      this->TextBoxConfirmPassword->Size = System::Drawing::Size(452, 38);
      this->TextBoxConfirmPassword->TabIndex = 5;
      this->TextBoxConfirmPassword->UseSystemPasswordChar = true;
      // 
      // RegisterButton
      // 
      this->RegisterButton->AutoSize = true;
      this->RegisterButton->BackColor = System::Drawing::SystemColors::Highlight;
      this->RegisterButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
      this->RegisterButton->ForeColor = System::Drawing::SystemColors::Control;
      this->RegisterButton->Location = System::Drawing::Point(18, 331);
      this->RegisterButton->Name = L"RegisterButton";
      this->RegisterButton->Size = System::Drawing::Size(452, 62);
      this->RegisterButton->TabIndex = 7;
      this->RegisterButton->Text = L"Sign Up";
      this->RegisterButton->UseVisualStyleBackColor = false;
      this->RegisterButton->Click += gcnew System::EventHandler(this, &RegistrationForm::RegisterButton_Click);
      // 
      // RegistrationForm
      // 
      this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->ClientSize = System::Drawing::Size(486, 410);
      this->Controls->Add(this->RegisterButton);
      this->Controls->Add(this->LabelConfirmPassword);
      this->Controls->Add(this->TextBoxConfirmPassword);
      this->Controls->Add(this->LabelCreatePassword);
      this->Controls->Add(this->TextBoxCreatePassword);
      this->Controls->Add(this->Label_Registration);
      this->Controls->Add(this->LabelLogin);
      this->Controls->Add(this->textBoxLogin);
      this->MaximizeBox = false;
      this->Name = L"RegistrationForm";
      this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
      this->Text = L"RegistrationForm";
      this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &RegistrationForm::RegistrationForm_FormClosed);
      this->Load += gcnew System::EventHandler(this, &RegistrationForm::RegistrationForm_Load);
      this->ResumeLayout(false);
      this->PerformLayout();

    }
#pragma endregion
  private: System::Void RegistrationForm_Load(System::Object^ sender, System::EventArgs^ e) {
  }
  private: System::Void RegistrationForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
    this->Owner->Show();
  }
  private: System::Void RegisterButton_Click(System::Object^ sender, System::EventArgs^ e) {
    std::string login = marshal_as<std::string>(textBoxLogin->Text);
    std::string password = marshal_as<std::string>(TextBoxCreatePassword->Text);
    std::string repeat_password = marshal_as<std::string>(TextBoxConfirmPassword->Text);

    try {
      User new_user;

      new_user.set_login(login);

      if (password != repeat_password) {
        throw std::logic_error("The passwords you entered don't match");
      }

      new_user.set_password(password);

      const auto& users = (*MyGameStoreCopy).get_all_users_ref();

      size_t candidate_id = (*MyGameStoreCopy).find_available_user_id();

      new_user.set_user_id(candidate_id);

      if (!(*MyGameStoreCopy).add_client(new_user)) {
        throw std::logic_error("This Login is busy!");
      }

      this->Close();
    }
    catch (const std::exception& ex) {
      MessageBox::Show(gcnew String(ex.what()), "ќшибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
  }
  };
}
