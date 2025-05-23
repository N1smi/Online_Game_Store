#pragma once
#include "RegistrationForm.h"
#include "MainClientForm.h"

namespace CppCLRWinFormsProject {

  using namespace System;
  using namespace System::ComponentModel;
  using namespace System::Collections;
  using namespace System::Windows::Forms;
  using namespace System::Data;
  using namespace System::Drawing;
  using namespace msclr::interop;

  /// <summary>
  /// Summary for Form1
  /// </summary>

  public ref class LoginForm : public System::Windows::Forms::Form
  {
  private:
    GameStore* MyGameStore;
  public:
    LoginForm(void)
    {
      MyGameStore = new GameStore();
      (*MyGameStore).load_data("E:\\GitHub\\Online_Game_Store\\Online_Game_Store_Project\\Users.csv",
        "E:\\GitHub\\Online_Game_Store\\Online_Game_Store_Project\\Games.csv");
      InitializeComponent();
    }

  protected:
    ~LoginForm()
    {
      if (components)
      {
        delete components;
      }
    }

  private: System::Windows::Forms::Label^ SingInLabel;
  private: System::Windows::Forms::Label^ LabelLogin;
  private: System::Windows::Forms::TextBox^ TextBoxLogin;
  private: System::Windows::Forms::Label^ LabelPassword;
  private: System::Windows::Forms::TextBox^ TextBoxPassword;
  private: System::Windows::Forms::Button^ SignInButton;
  private: System::Windows::Forms::LinkLabel^ LinkLabelSignUp;
  private: System::Windows::Forms::Label^ label1;




  protected:

  protected:

  private:
    /// <summary>
    /// Required designer variable.
    /// </summary>
    System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    void InitializeComponent(void)
    {
      this->SingInLabel = (gcnew System::Windows::Forms::Label());
      this->LabelLogin = (gcnew System::Windows::Forms::Label());
      this->TextBoxLogin = (gcnew System::Windows::Forms::TextBox());
      this->LabelPassword = (gcnew System::Windows::Forms::Label());
      this->TextBoxPassword = (gcnew System::Windows::Forms::TextBox());
      this->SignInButton = (gcnew System::Windows::Forms::Button());
      this->LinkLabelSignUp = (gcnew System::Windows::Forms::LinkLabel());
      this->label1 = (gcnew System::Windows::Forms::Label());
      this->SuspendLayout();
      // 
      // SingInLabel
      // 
      this->SingInLabel->AutoSize = true;
      this->SingInLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
      this->SingInLabel->Location = System::Drawing::Point(179, 9);
      this->SingInLabel->Name = L"SingInLabel";
      this->SingInLabel->Size = System::Drawing::Size(95, 36);
      this->SingInLabel->TabIndex = 1;
      this->SingInLabel->Text = L"Login";
      this->SingInLabel->Click += gcnew System::EventHandler(this, &LoginForm::label1_Click);
      // 
      // LabelLogin
      // 
      this->LabelLogin->AutoSize = true;
      this->LabelLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
      this->LabelLogin->Location = System::Drawing::Point(6, 42);
      this->LabelLogin->Name = L"LabelLogin";
      this->LabelLogin->Size = System::Drawing::Size(85, 32);
      this->LabelLogin->TabIndex = 3;
      this->LabelLogin->Text = L"Login";
      // 
      // TextBoxLogin
      // 
      this->TextBoxLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
      this->TextBoxLogin->Location = System::Drawing::Point(12, 77);
      this->TextBoxLogin->Name = L"TextBoxLogin";
      this->TextBoxLogin->Size = System::Drawing::Size(452, 38);
      this->TextBoxLogin->TabIndex = 2;
      // 
      // LabelPassword
      // 
      this->LabelPassword->AutoSize = true;
      this->LabelPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
      this->LabelPassword->Location = System::Drawing::Point(6, 134);
      this->LabelPassword->Name = L"LabelPassword";
      this->LabelPassword->Size = System::Drawing::Size(138, 32);
      this->LabelPassword->TabIndex = 6;
      this->LabelPassword->Text = L"Password";
      // 
      // TextBoxPassword
      // 
      this->TextBoxPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
      this->TextBoxPassword->Location = System::Drawing::Point(12, 169);
      this->TextBoxPassword->Name = L"TextBoxPassword";
      this->TextBoxPassword->Size = System::Drawing::Size(452, 38);
      this->TextBoxPassword->TabIndex = 5;
      this->TextBoxPassword->UseSystemPasswordChar = true;
      // 
      // SignInButton
      // 
      this->SignInButton->AutoSize = true;
      this->SignInButton->BackColor = System::Drawing::SystemColors::Highlight;
      this->SignInButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
      this->SignInButton->ForeColor = System::Drawing::SystemColors::Control;
      this->SignInButton->Location = System::Drawing::Point(12, 232);
      this->SignInButton->Name = L"SignInButton";
      this->SignInButton->Size = System::Drawing::Size(148, 49);
      this->SignInButton->TabIndex = 8;
      this->SignInButton->Text = L"Sign In";
      this->SignInButton->UseVisualStyleBackColor = false;
      this->SignInButton->Click += gcnew System::EventHandler(this, &LoginForm::SignInButton_Click);
      // 
      // LinkLabelSignUp
      // 
      this->LinkLabelSignUp->AutoSize = true;
      this->LinkLabelSignUp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
      this->LinkLabelSignUp->Location = System::Drawing::Point(381, 247);
      this->LinkLabelSignUp->Name = L"LinkLabelSignUp";
      this->LinkLabelSignUp->Size = System::Drawing::Size(74, 22);
      this->LinkLabelSignUp->TabIndex = 9;
      this->LinkLabelSignUp->TabStop = true;
      this->LinkLabelSignUp->Text = L"Sign Up";
      this->LinkLabelSignUp->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &LoginForm::LinkLabelSignUp_LinkClicked);
      // 
      // label1
      // 
      this->label1->AutoSize = true;
      this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
      this->label1->Location = System::Drawing::Point(166, 247);
      this->label1->Name = L"label1";
      this->label1->Size = System::Drawing::Size(199, 22);
      this->label1->TabIndex = 10;
      this->label1->Text = L"Don\'t have an account\?";
      this->label1->Click += gcnew System::EventHandler(this, &LoginForm::label1_Click_1);
      // 
      // LoginForm
      // 
      this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->ClientSize = System::Drawing::Size(482, 294);
      this->Controls->Add(this->label1);
      this->Controls->Add(this->LinkLabelSignUp);
      this->Controls->Add(this->SignInButton);
      this->Controls->Add(this->LabelPassword);
      this->Controls->Add(this->TextBoxPassword);
      this->Controls->Add(this->LabelLogin);
      this->Controls->Add(this->TextBoxLogin);
      this->Controls->Add(this->SingInLabel);
      this->MaximizeBox = false;
      this->Name = L"LoginForm";
      this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
      this->Text = L"LoginForm";
      this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &LoginForm::LoginForm_FormClosed);
      this->Load += gcnew System::EventHandler(this, &LoginForm::LoginForm_Load);
      this->ResumeLayout(false);
      this->PerformLayout();

    }
#pragma endregion
  private: System::Void LoginForm_Load(System::Object^ sender, System::EventArgs^ e) {
  }
  private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
  }
  private: System::Void LinkLabelSignUp_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
    GameStore_Application::RegistrationForm^ regForm = gcnew GameStore_Application::RegistrationForm(MyGameStore);
    regForm->Owner = this;
    regForm->Show();
    this->Hide();
  }
  private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
  }
  private: System::Void SignInButton_Click(System::Object^ sender, System::EventArgs^ e) {
    std::string login = marshal_as<std::string>(TextBoxLogin->Text);
    std::string password = marshal_as<std::string>(TextBoxPassword->Text);

    try {
      User checkUser;
      checkUser.set_login(login);
      checkUser.set_password(password);

      if ((*MyGameStore).user_exists(login)) {
        const User* Searchuser = (*MyGameStore).find_user(login);
        auto* client = dynamic_cast<const Client*>(Searchuser); //сломана как и передача в форму 

        if (!(*Searchuser).check_password(password)) {
          throw std::logic_error("The password is incorrect");
        }

        if ((*Searchuser).get_is_blocked()) {
          throw std::logic_error("The user is blocked in our online store!");
        }


        if ((*Searchuser).get_is_admin()) {

        }
        else {
          GameStore_Application::MainClientForm^ clientForm = gcnew GameStore_Application::MainClientForm(MyGameStore, client);
          clientForm->Owner = this;
          clientForm->Show();
          this->Hide();
        }

      }
      else {
        throw std::logic_error("User with this login no exist!");
      }
    }
    catch (const std::exception& ex) {
      MessageBox::Show(gcnew String(ex.what()), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
  }
  private: System::Void LoginForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
    (*MyGameStore).update_data("E:\\GitHub\\Online_Game_Store\\Online_Game_Store_Project\\Users.csv",
      "E:\\GitHub\\Online_Game_Store\\Online_Game_Store_Project\\Games.csv");
  }
};
}
