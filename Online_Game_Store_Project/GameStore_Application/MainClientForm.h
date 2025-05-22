#pragma once

namespace GameStore_Application {

  using namespace System;
  using namespace System::ComponentModel;
  using namespace System::Collections;
  using namespace System::Windows::Forms;
  using namespace System::Data;
  using namespace System::Drawing;

  /// <summary>
  /// Сводка для MainClientForm
  /// </summary>
  public ref class MainClientForm : public System::Windows::Forms::Form
  {
  public:
    GameStore* MyGameStoreCopy;
  private: System::Windows::Forms::MenuStrip^ menuStrip1;
  public:
  private: System::Windows::Forms::ToolStripMenuItem^ nameBalanceToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^ myProfileToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^ myWalletToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^ signOutOfAccountToolStripMenuItem;
  private: System::Windows::Forms::TextBox^ searchBox;


  private: System::Windows::Forms::ComboBox^ comboBox1;
  private: System::Windows::Forms::Button^ SearchGames;

  private: System::Windows::Forms::FlowLayoutPanel^ gamesPanel;





  public:
    Client* MyClient;
    MainClientForm(GameStore* MyGameStore, const User MyUser)
    {
      MyGameStoreCopy = MyGameStore;
      TVector<std::string> my_purchases, desired, basket;
      MyClient = new Client(MyUser, 0, my_purchases, desired, basket);
      /* Тут нужна подгрузка данных пользователя и взаимодействие с csv*/
      InitializeComponent();
      //
      //TODO: добавьте код конструктора
      //
    }

  protected:
    /// <summary>
    /// Освободить все используемые ресурсы.
    /// </summary>
    ~MainClientForm()
    {
      if (components)
      {
        delete components;
      }
    }
  private: System::ComponentModel::IContainer^ components;
  protected:

  private:
    /// <summary>
    /// Обязательная переменная конструктора.
    /// </summary>


#pragma region Windows Form Designer generated code
    /// <summary>
    /// Требуемый метод для поддержки конструктора — не изменяйте 
    /// содержимое этого метода с помощью редактора кода.
    /// </summary>
    void InitializeComponent(void)
    {
      this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
      this->nameBalanceToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->myProfileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->myWalletToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->signOutOfAccountToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->searchBox = (gcnew System::Windows::Forms::TextBox());
      this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
      this->SearchGames = (gcnew System::Windows::Forms::Button());
      this->gamesPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
      this->menuStrip1->SuspendLayout();
      this->SuspendLayout();
      // 
      // menuStrip1
      // 
      this->menuStrip1->AutoSize = false;
      this->menuStrip1->Dock = System::Windows::Forms::DockStyle::Right;
      this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
      this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->nameBalanceToolStripMenuItem });
      this->menuStrip1->Location = System::Drawing::Point(1057, 0);
      this->menuStrip1->Name = L"menuStrip1";
      this->menuStrip1->Size = System::Drawing::Size(125, 653);
      this->menuStrip1->TabIndex = 0;
      this->menuStrip1->Text = L"menuStrip1";
      // 
      // nameBalanceToolStripMenuItem
      // 
      this->nameBalanceToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
        this->myProfileToolStripMenuItem,
          this->myWalletToolStripMenuItem, this->signOutOfAccountToolStripMenuItem
      });
      this->nameBalanceToolStripMenuItem->Name = L"nameBalanceToolStripMenuItem";
      this->nameBalanceToolStripMenuItem->Size = System::Drawing::Size(118, 24);
      this->nameBalanceToolStripMenuItem->Text = L"Name balance";
      // 
      // myProfileToolStripMenuItem
      // 
      this->myProfileToolStripMenuItem->Name = L"myProfileToolStripMenuItem";
      this->myProfileToolStripMenuItem->Size = System::Drawing::Size(221, 26);
      this->myProfileToolStripMenuItem->Text = L"My profile";
      this->myProfileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainClientForm::myProfileToolStripMenuItem_Click);
      // 
      // myWalletToolStripMenuItem
      // 
      this->myWalletToolStripMenuItem->Name = L"myWalletToolStripMenuItem";
      this->myWalletToolStripMenuItem->Size = System::Drawing::Size(221, 26);
      this->myWalletToolStripMenuItem->Text = L"My wallet";
      // 
      // signOutOfAccountToolStripMenuItem
      // 
      this->signOutOfAccountToolStripMenuItem->Name = L"signOutOfAccountToolStripMenuItem";
      this->signOutOfAccountToolStripMenuItem->Size = System::Drawing::Size(221, 26);
      this->signOutOfAccountToolStripMenuItem->Text = L"Sign out of account";
      // 
      // searchBox
      // 
      this->searchBox->Anchor = System::Windows::Forms::AnchorStyles::Top;
      this->searchBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
      this->searchBox->Location = System::Drawing::Point(65, 63);
      this->searchBox->Name = L"searchBox";
      this->searchBox->Size = System::Drawing::Size(896, 30);
      this->searchBox->TabIndex = 1;
      // 
      // comboBox1
      // 
      this->comboBox1->Anchor = System::Windows::Forms::AnchorStyles::Top;
      this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
      this->comboBox1->FormattingEnabled = true;
      this->comboBox1->Location = System::Drawing::Point(859, 109);
      this->comboBox1->Name = L"comboBox1";
      this->comboBox1->Size = System::Drawing::Size(187, 28);
      this->comboBox1->TabIndex = 2;
      this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MainClientForm::comboBox1_SelectedIndexChanged);
      // 
      // SearchGames
      // 
      this->SearchGames->Anchor = System::Windows::Forms::AnchorStyles::Top;
      this->SearchGames->AutoSize = true;
      this->SearchGames->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
      this->SearchGames->Location = System::Drawing::Point(967, 63);
      this->SearchGames->Name = L"SearchGames";
      this->SearchGames->Size = System::Drawing::Size(87, 30);
      this->SearchGames->TabIndex = 3;
      this->SearchGames->Text = L"Search";
      this->SearchGames->UseVisualStyleBackColor = true;
      this->SearchGames->Click += gcnew System::EventHandler(this, &MainClientForm::SearchGames_Click);
      // 
      // gamesPanel
      // 
      this->gamesPanel->AutoScroll = true;
      this->gamesPanel->BackColor = System::Drawing::SystemColors::Control;
      this->gamesPanel->Location = System::Drawing::Point(12, 143);
      this->gamesPanel->Margin = System::Windows::Forms::Padding(10);
      this->gamesPanel->Name = L"gamesPanel";
      this->gamesPanel->Size = System::Drawing::Size(1158, 498);
      this->gamesPanel->TabIndex = 4;
      // 
      // MainClientForm
      // 
      this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->ClientSize = System::Drawing::Size(1182, 653);
      this->Controls->Add(this->gamesPanel);
      this->Controls->Add(this->SearchGames);
      this->Controls->Add(this->comboBox1);
      this->Controls->Add(this->searchBox);
      this->Controls->Add(this->menuStrip1);
      this->MainMenuStrip = this->menuStrip1;
      this->MinimizeBox = false;
      this->Name = L"MainClientForm";
      this->Text = L"MainClientForm";
      this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
      this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainClientForm::MainClientForm_FormClosed);
      this->Load += gcnew System::EventHandler(this, &MainClientForm::MainClientForm_Load);
      this->menuStrip1->ResumeLayout(false);
      this->menuStrip1->PerformLayout();
      this->ResumeLayout(false);
      this->PerformLayout();

    }
#pragma endregion
  private: System::Void MainClientForm_Load(System::Object^ sender, System::EventArgs^ e) {

    std::string login = MyClient->get_login();
    int balance = MyClient->get_balance();

    System::String^ loginStr = gcnew System::String(login.c_str());

    System::String^ displayText = System::String::Format("{0} ({1} rub)", loginStr, balance);

    System::String^ displayText2 = System::String::Format(" ({0} rub)", balance);

    this->gamesPanel->Size = System::Drawing::Size(this->Width - 35, this->Height-165);

    this->nameBalanceToolStripMenuItem->Text = displayText;
    this->myWalletToolStripMenuItem->Text += displayText2;
  }
  private: System::Void MainClientForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
    this->Owner->BeginInvoke(gcnew GameStore_Application::Action(this->Owner, &Form::Close));
  }
  private: System::Void myProfileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
  }
  private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
  }

  private: Panel^ CreateGameCard(Game* game) {
    Panel^ card = gcnew Panel();
    card->Size = Drawing::Size(200, 250);
    card->BorderStyle = BorderStyle::FixedSingle;
    card->Margin = System::Windows::Forms::Padding(7);

    // Название игры
    Label^ title = gcnew Label();
    title->AutoSize = true;
    title->Text = msclr::interop::marshal_as<System::String^>(game->get_title());
    if (title->Text->Length > 30) {
      title->Text = title->Text->Substring(0, 23) + "...";
    }
    title->Location = Point(10, 10);
    title->Font = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);

    // Дата
    Label^ data = gcnew Label();
    data->AutoSize = true;
    data->Text = "Released: ";
    data->Text += msclr::interop::marshal_as<System::String^>(game->get_release_date().toString());
    data->Location = Point(10, 40);

    // Рейтинг 
    Label^ rating = gcnew Label();
    rating->AutoSize = true;
    rating->Text = "Rating: ";
    rating->Text += String::Format("{0}", game->get_rating());
    rating->Location = Point(10, 70);

    // Цена
    Label^ price = gcnew Label();
    price->AutoSize = true;
    price->Text = String::Format("{0} rub", game->get_price());
    price->Location = Point(10, 180);

    // Кнопка "Купить"
    Button^ buyButton = gcnew Button();
    buyButton->Text = "Buy";
    buyButton->Location = Point(10, 210);
    buyButton->Click += gcnew EventHandler(this, &MainClientForm::BuyGame);
    IntPtr ptr(game);
    buyButton->Tag = ptr;

    card->Controls->Add(title);
    card->Controls->Add(data);
    card->Controls->Add(rating);
    card->Controls->Add(price);
    card->Controls->Add(buyButton);

    return card;
  }

  private: Void BuyGame(Object^ sender, EventArgs^ e) {
    Button^ button = safe_cast<Button^>(sender);
    IntPtr ptr = (IntPtr)button->Tag;
    Game* game = (Game*)ptr.ToPointer();

    if (MyClient->get_balance() >= game->get_price()) {
      // MyClient->PurchaseGame(game);
      MessageBox::Show("Игра куплена!", "Успех");
      //UpdateBalanceDisplay();
    }
    else {
      MessageBox::Show("Недостаточно средств!", "Ошибка");
    }
  }

private: System::Void SearchGames_Click(System::Object^ sender, System::EventArgs^ e) {
  gamesPanel->Controls->Clear(); // Очищаем предыдущие результаты

  String^ searchText = searchBox->Text->ToLower();
  //String^ selectedGenre = genreFilter->Text;

  // Фильтрация игр
  for (size_t i = 0; i < (*MyGameStoreCopy).get_all_games_ref().size(); i++) {
    Game* game = new Game((*MyGameStoreCopy).get_all_games_ref()[i]);
    String^ titleString = gcnew String(game->get_title().c_str());
    bool matchesSearch = titleString->ToLower()->Contains(searchText);
    //bool matchesGenre = (selectedGenre == "Все жанры" || game->Genre == selectedGenre);

    if (matchesSearch/* && matchesGenre*/) {
      // Создаем "карточку игры" (как в Steam)
      Panel^ gameCard = CreateGameCard(game);
      gamesPanel->Controls->Add(gameCard);
    }
  }
}

};
}
