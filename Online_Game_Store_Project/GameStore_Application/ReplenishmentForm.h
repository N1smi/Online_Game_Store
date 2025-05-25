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
	/// —водка дл€ ReplenishmentForm
	/// </summary>
	public ref class ReplenishmentForm : public System::Windows::Forms::Form
	{
	public:
		Client* MyClient;
	private: System::Windows::Forms::TextBox^ textBoxAmount;
	private: System::Windows::Forms::Label^ LabelReplenishment;
	public:


	private: System::Windows::Forms::Label^ LabelAmount;
	private: System::Windows::Forms::TextBox^ textBoxcardNumber;
	private: System::Windows::Forms::Label^ LabelCardNumber;
	private: System::Windows::Forms::TextBox^ textBoxValidityPeriod;
	private: System::Windows::Forms::Label^ labelValidatyPeriod;
	private: System::Windows::Forms::TextBox^ textBoxCode;
	private: System::Windows::Forms::Label^ labelCode;
	private: System::Windows::Forms::Button^ buttonReplenishMain;






	public:
		int* Amount;
		ReplenishmentForm(Client* MyClientCopy,int* AmountCopy)
		{
			MyClient = MyClientCopy;
			Amount = AmountCopy;
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~ReplenishmentForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBoxAmount = (gcnew System::Windows::Forms::TextBox());
			this->LabelReplenishment = (gcnew System::Windows::Forms::Label());
			this->LabelAmount = (gcnew System::Windows::Forms::Label());
			this->textBoxcardNumber = (gcnew System::Windows::Forms::TextBox());
			this->LabelCardNumber = (gcnew System::Windows::Forms::Label());
			this->textBoxValidityPeriod = (gcnew System::Windows::Forms::TextBox());
			this->labelValidatyPeriod = (gcnew System::Windows::Forms::Label());
			this->textBoxCode = (gcnew System::Windows::Forms::TextBox());
			this->labelCode = (gcnew System::Windows::Forms::Label());
			this->buttonReplenishMain = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBoxAmount
			// 
			this->textBoxAmount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxAmount->Location = System::Drawing::Point(12, 82);
			this->textBoxAmount->Name = L"textBoxAmount";
			this->textBoxAmount->Size = System::Drawing::Size(239, 34);
			this->textBoxAmount->TabIndex = 1;
			// 
			// LabelReplenishment
			// 
			this->LabelReplenishment->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->LabelReplenishment->AutoSize = true;
			this->LabelReplenishment->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelReplenishment->Location = System::Drawing::Point(136, 9);
			this->LabelReplenishment->Name = L"LabelReplenishment";
			this->LabelReplenishment->Size = System::Drawing::Size(218, 32);
			this->LabelReplenishment->TabIndex = 3;
			this->LabelReplenishment->Text = L"Replenishment";
			this->LabelReplenishment->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// LabelAmount
			// 
			this->LabelAmount->AutoSize = true;
			this->LabelAmount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelAmount->ForeColor = System::Drawing::SystemColors::AppWorkspace;
			this->LabelAmount->Location = System::Drawing::Point(12, 54);
			this->LabelAmount->Name = L"LabelAmount";
			this->LabelAmount->Size = System::Drawing::Size(80, 25);
			this->LabelAmount->TabIndex = 4;
			this->LabelAmount->Text = L"Amount";
			this->LabelAmount->Click += gcnew System::EventHandler(this, &ReplenishmentForm::LabelAmount_Click);
			// 
			// textBoxcardNumber
			// 
			this->textBoxcardNumber->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBoxcardNumber->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->textBoxcardNumber->Location = System::Drawing::Point(12, 158);
			this->textBoxcardNumber->Name = L"textBoxcardNumber";
			this->textBoxcardNumber->Size = System::Drawing::Size(239, 34);
			this->textBoxcardNumber->TabIndex = 5;
			this->textBoxcardNumber->Text = L"0000 0000 0000 0000";
			// 
			// LabelCardNumber
			// 
			this->LabelCardNumber->AutoSize = true;
			this->LabelCardNumber->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelCardNumber->ForeColor = System::Drawing::SystemColors::AppWorkspace;
			this->LabelCardNumber->Location = System::Drawing::Point(7, 130);
			this->LabelCardNumber->Name = L"LabelCardNumber";
			this->LabelCardNumber->Size = System::Drawing::Size(171, 25);
			this->LabelCardNumber->TabIndex = 6;
			this->LabelCardNumber->Text = L"Bank card number";
			this->LabelCardNumber->Click += gcnew System::EventHandler(this, &ReplenishmentForm::LabelCardNumber_Click);
			// 
			// textBoxValidityPeriod
			// 
			this->textBoxValidityPeriod->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBoxValidityPeriod->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->textBoxValidityPeriod->Location = System::Drawing::Point(257, 158);
			this->textBoxValidityPeriod->Name = L"textBoxValidityPeriod";
			this->textBoxValidityPeriod->Size = System::Drawing::Size(88, 34);
			this->textBoxValidityPeriod->TabIndex = 7;
			this->textBoxValidityPeriod->Text = L"MM/YY";
			// 
			// labelValidatyPeriod
			// 
			this->labelValidatyPeriod->AutoSize = true;
			this->labelValidatyPeriod->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->labelValidatyPeriod->ForeColor = System::Drawing::SystemColors::AppWorkspace;
			this->labelValidatyPeriod->Location = System::Drawing::Point(252, 130);
			this->labelValidatyPeriod->Name = L"labelValidatyPeriod";
			this->labelValidatyPeriod->Size = System::Drawing::Size(82, 25);
			this->labelValidatyPeriod->TabIndex = 8;
			this->labelValidatyPeriod->Text = L"Validaty";
			this->labelValidatyPeriod->Click += gcnew System::EventHandler(this, &ReplenishmentForm::label1_Click);
			// 
			// textBoxCode
			// 
			this->textBoxCode->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxCode->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->textBoxCode->Location = System::Drawing::Point(351, 158);
			this->textBoxCode->Name = L"textBoxCode";
			this->textBoxCode->Size = System::Drawing::Size(143, 34);
			this->textBoxCode->TabIndex = 9;
			this->textBoxCode->Tag = L"";
			this->textBoxCode->Text = L"CVV2/CVC2";
			// 
			// labelCode
			// 
			this->labelCode->AutoSize = true;
			this->labelCode->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelCode->ForeColor = System::Drawing::SystemColors::AppWorkspace;
			this->labelCode->Location = System::Drawing::Point(351, 130);
			this->labelCode->Name = L"labelCode";
			this->labelCode->Size = System::Drawing::Size(60, 25);
			this->labelCode->TabIndex = 10;
			this->labelCode->Text = L"Code";
			// 
			// buttonReplenishMain
			// 
			this->buttonReplenishMain->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->buttonReplenishMain->Location = System::Drawing::Point(12, 208);
			this->buttonReplenishMain->Name = L"buttonReplenishMain";
			this->buttonReplenishMain->Size = System::Drawing::Size(131, 40);
			this->buttonReplenishMain->TabIndex = 11;
			this->buttonReplenishMain->Text = L"Replenish";
			this->buttonReplenishMain->UseVisualStyleBackColor = true;
			this->buttonReplenishMain->Click += gcnew System::EventHandler(this, &ReplenishmentForm::buttonAddMain_Click);
			// 
			// ReplenishmentForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(501, 268);
			this->Controls->Add(this->buttonReplenishMain);
			this->Controls->Add(this->labelCode);
			this->Controls->Add(this->textBoxCode);
			this->Controls->Add(this->labelValidatyPeriod);
			this->Controls->Add(this->textBoxValidityPeriod);
			this->Controls->Add(this->LabelCardNumber);
			this->Controls->Add(this->textBoxcardNumber);
			this->Controls->Add(this->LabelAmount);
			this->Controls->Add(this->LabelReplenishment);
			this->Controls->Add(this->textBoxAmount);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ReplenishmentForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ReplenishmentForm";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &ReplenishmentForm::ReplenishmentForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &ReplenishmentForm::ReplenishmentForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ReplenishmentForm_Load(System::Object^ sender, System::EventArgs^ e) {
		int amount = *Amount;
		this->textBoxAmount->Text = amount.ToString();
	}

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}

private: System::Void LabelAmount_Click(System::Object^ sender, System::EventArgs^ e) {
	}

private: System::Void LabelCardNumber_Click(System::Object^ sender, System::EventArgs^ e) {
	}

private: System::Void buttonAddMain_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string amount = marshal_as<std::string>(textBoxAmount->Text);
	std::string card = marshal_as<std::string>(textBoxcardNumber->Text);
	std::string validaty = marshal_as<std::string>(textBoxValidityPeriod->Text);
	std::string code = marshal_as<std::string>(textBoxCode->Text);

	int amountInt = 0;
	try {
		amountInt = Int32::Parse(gcnew String(amount.c_str()));
	}
	catch (...) {
		MessageBox::Show("Incorrect amount","Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	if (card.length() != 16 || !IsDigitsOnly(gcnew String(card.c_str())) || card[0] == '0') {
		MessageBox::Show("Incorrect card number", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	String^ val = gcnew String(validaty.c_str());
	if (!(val->Length == 5 && val->Contains("/"))) {
		MessageBox::Show("Incorrect validaty date", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	array<String^>^ parts = val->Split('/');
	if (parts->Length != 2) {
		MessageBox::Show("Invalid string format", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	int month, year;
	if (!Int32::TryParse(parts[0], month) || !Int32::TryParse(parts[1], year)) {
		MessageBox::Show("Incorrect term data", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	if (month < 1 || month > 12) {
		MessageBox::Show("Incorrect month", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	if (year < 25) {
		MessageBox::Show("Incorrect year", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	if (code.length() != 3 || !IsDigitsOnly(gcnew String(code.c_str()))) {
		MessageBox::Show("Incorrect CVV code", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	int clientBalance = MyClient->get_balance() + amountInt;
	MyClient->set_balance(clientBalance);
	MessageBox::Show("Funds have been added successfully!", "Succes", MessageBoxButtons::OK, MessageBoxIcon::Information);
	this->Close();
}

bool IsDigitsOnly(String^ str) {
  for each (Char c in str) {
    if (!Char::IsDigit(c))
      return false;
  }
  return true;
}

private: System::Void ReplenishmentForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
}
};
}
