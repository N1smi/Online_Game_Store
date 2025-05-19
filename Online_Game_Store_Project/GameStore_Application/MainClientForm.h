#pragma once

namespace GameStore_Application {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MainClientForm
	/// </summary>
	public ref class MainClientForm : public System::Windows::Forms::Form
	{
	public:
		MainClientForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MainClientForm()
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
			this->SuspendLayout();
			// 
			// MainClientForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1200, 700);
			this->Name = L"MainClientForm";
			this->Text = L"MainClientForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainClientForm::MainClientForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &MainClientForm::MainClientForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MainClientForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MainClientForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		this->Owner->BeginInvoke(gcnew GameStore_Application::Action(this->Owner, &Form::Close));
	}
	};
}
