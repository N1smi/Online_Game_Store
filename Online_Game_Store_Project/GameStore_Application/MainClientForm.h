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
  private: System::Windows::Forms::ComboBox^ FilterGenre;



  private: System::Windows::Forms::Button^ SearchGames;

  private: System::Windows::Forms::FlowLayoutPanel^ gamesPanel;



  private: Panel^ gameInfoPanel = nullptr;

  public:
    Client* MyClient;
    MainClientForm(GameStore* MyGameStore, Client* client)
    {
      MyGameStoreCopy = MyGameStore;
      MyClient = client;

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
      this->FilterGenre = (gcnew System::Windows::Forms::ComboBox());
      this->SearchGames = (gcnew System::Windows::Forms::Button());
      this->gamesPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
      this->menuStrip1->SuspendLayout();
      this->SuspendLayout();
      // 
      // menuStrip1
      // 
      this->menuStrip1->Dock = System::Windows::Forms::DockStyle::Right;
      this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
      this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->nameBalanceToolStripMenuItem });
      this->menuStrip1->Location = System::Drawing::Point(1026, 0);
      this->menuStrip1->Name = L"menuStrip1";
      this->menuStrip1->Size = System::Drawing::Size(156, 653);
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
      this->nameBalanceToolStripMenuItem->Size = System::Drawing::Size(143, 24);
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
      // FilterGenre
      // 
      this->FilterGenre->Anchor = System::Windows::Forms::AnchorStyles::Top;
      this->FilterGenre->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
      this->FilterGenre->FormattingEnabled = true;
      this->FilterGenre->Location = System::Drawing::Point(859, 109);
      this->FilterGenre->Name = L"FilterGenre";
      this->FilterGenre->Size = System::Drawing::Size(187, 28);
      this->FilterGenre->TabIndex = 2;
      this->FilterGenre->SelectedIndexChanged += gcnew System::EventHandler(this, &MainClientForm::comboBox1_SelectedIndexChanged);
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
      this->Controls->Add(this->FilterGenre);
      this->Controls->Add(this->searchBox);
      this->Controls->Add(this->menuStrip1);
      this->MainMenuStrip = this->menuStrip1;
      this->MaximizeBox = false;
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

    this->gamesPanel->Size = System::Drawing::Size(this->Width - 35, this->Height - 165);

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

  private: Panel^ CreateGameCard(const Game* game) {
    Panel^ card = gcnew Panel();
    card->Size = Drawing::Size(200, 250);
    card->BorderStyle = BorderStyle::FixedSingle;
    Game* gameptr = const_cast<Game*>(game);
    IntPtr ptr(gameptr);
    card->Tag = ptr;
    card->Margin = System::Windows::Forms::Padding(7);

    card->BackColor = Color::WhiteSmoke;
    card->Cursor = Cursors::Hand;
    card->Click += gcnew EventHandler(this, &MainClientForm::GameCard_Click);
    card->MouseEnter += gcnew EventHandler(this, &MainClientForm::Card_MouseEnter);
    card->MouseLeave += gcnew EventHandler(this, &MainClientForm::Card_MouseLeave);

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
    gamesPanel->Controls->Clear();

    String^ searchText = searchBox->Text->ToLower();
    //String^ selectedGenre = genreFilter->Text;


    // Фильтрация игр
    for (size_t i = 0; i < (*MyGameStoreCopy).get_all_games_ref().size(); i++) {
      const Game* game = &((*MyGameStoreCopy).get_all_games_ref()[i]);
      String^ titleString = gcnew String(game->get_title().c_str());
      bool matchesSearch = titleString->ToLower()->Contains(searchText);
      //bool matchesGenre = (selectedGenre == "Все жанры" || game->Genre == selectedGenre);

      if (matchesSearch/* && matchesGenre*/) {
        Panel^ gameCard = CreateGameCard(game);
        gamesPanel->Controls->Add(gameCard);
      }
    }
  }
  private: Void GameCard_Click(Object^ sender, EventArgs^ e)
  {
    this->searchBox->Visible = false;
    this->SearchGames->Visible = false;
    this->gamesPanel->Visible = false;
    this->FilterGenre->Visible = false;
    gameInfoPanel = gcnew Panel();
    gameInfoPanel->Size = System::Drawing::Size(this->Width - 50, this->Height - 75);
    gameInfoPanel->Margin = System::Windows::Forms::Padding(10);
    gameInfoPanel->Location = Point(12, 25);
    gameInfoPanel->AutoScroll = true;
    this->Controls->Add(gameInfoPanel);

    Button^ backButton = gcnew Button();
    backButton->Text = L"Back";
    backButton->Size = System::Drawing::Size(80, 30);
    backButton->Location = Point(10, 10);
    backButton->Click += gcnew EventHandler(this, &MainClientForm::BackButton_Click);
    gameInfoPanel->Controls->Add(backButton);

    Panel^ prev_panel = safe_cast<Panel^>(sender);
    IntPtr ptr = (IntPtr)prev_panel->Tag;
    gameInfoPanel->Tag = ptr;
    Game* game = (Game*)ptr.ToPointer();

    Label^ titleLabel = gcnew Label();
    titleLabel->Text = msclr::interop::marshal_as<System::String^>(game->get_title());
    titleLabel->Font = gcnew System::Drawing::Font("Arial", 24, FontStyle::Bold);
    titleLabel->AutoSize = false;
    titleLabel->Size = System::Drawing::Size(gameInfoPanel->ClientSize.Width, 50);
    titleLabel->TextAlign = ContentAlignment::MiddleCenter;
    titleLabel->Location = Point(0, 20);
    gameInfoPanel->Controls->Add(titleLabel);

    int currentY = 80;
    int currentXforleft = 500;

    PictureBox^ pb = gcnew PictureBox();

    pb->AutoSize = true;

    pb->Location = Point(20, currentY);

    System::String^ gameTitle = msclr::interop::marshal_as<System::String^>(game->get_title());

    System::String^ imagesFolder = "E:\\GitHub\\Online_Game_Store\\Online_Game_Store_Project\\Images";

    System::String^ imagePath = System::IO::Path::Combine(imagesFolder, gameTitle + ".jpg");

    if (System::IO::File::Exists(imagePath)) {
      pb->Image = Image::FromFile(imagePath);
      gameInfoPanel->Controls->Add(pb);
      currentY += pb->Height + 10;
      currentXforleft = pb->Width + 20;
    }
    else {
      currentY += 200;
    }

    RichTextBox^ descriptionBox = gcnew RichTextBox();
    descriptionBox->Text = msclr::interop::marshal_as<System::String^>(game->get_description());
    descriptionBox->ReadOnly = true;
    descriptionBox->BorderStyle = BorderStyle::None;
    descriptionBox->Font = gcnew System::Drawing::Font("Arial", 16);
    descriptionBox->Location = Point(20, currentY);
    descriptionBox->Size = System::Drawing::Size(gameInfoPanel->ClientSize.Width - 100, 70);
    descriptionBox->WordWrap = true;
    gameInfoPanel->Controls->Add(descriptionBox);

    currentY += descriptionBox->Height + 10;
    int currentYforleft = 90;

    Label^ releaseLabel = gcnew Label();
    releaseLabel->Text = "Release Date: " + msclr::interop::marshal_as<System::String^>(game->get_release_date().toString());
    releaseLabel->AutoSize = true;
    releaseLabel->Font = gcnew System::Drawing::Font("Arial", 16, FontStyle::Regular);
    releaseLabel->Location = Point(currentXforleft, currentYforleft);
    gameInfoPanel->Controls->Add(releaseLabel);

    currentYforleft += releaseLabel->Height + 10;

    Label^ ratingLabel = gcnew Label();
    ratingLabel->Text = "Rating: " + String::Format("{0}", game->get_rating());
    ratingLabel->Font = gcnew System::Drawing::Font("Arial", 16, FontStyle::Regular);
    ratingLabel->AutoSize = true;
    ratingLabel->Location = Point(currentXforleft, currentYforleft);
    gameInfoPanel->Controls->Add(ratingLabel);

    currentYforleft += ratingLabel->Height + 10;

    Label^ developerLabel = gcnew Label();
    developerLabel->Text = "Developer: " + msclr::interop::marshal_as<System::String^>(game->get_developer());
    developerLabel->AutoSize = true;
    developerLabel->Font = gcnew System::Drawing::Font("Arial", 16, FontStyle::Regular);
    developerLabel->Location = Point(currentXforleft, currentYforleft);
    gameInfoPanel->Controls->Add(developerLabel);

    currentYforleft += developerLabel->Height + 10;

    Label^ genreLabel = gcnew Label();
    genreLabel->Text = "Genre: " + GenreTypeToString(game->get_genre());
    genreLabel->AutoSize = true;
    genreLabel->Font = gcnew System::Drawing::Font("Arial", 16, FontStyle::Regular);
    genreLabel->Location = Point(currentXforleft, currentYforleft);
    gameInfoPanel->Controls->Add(genreLabel);

    currentYforleft += genreLabel->Height + 20;


    Label^ feedbackLabel = gcnew Label();
    feedbackLabel->Text = "Write your feedback for " + msclr::interop::marshal_as<System::String^>(game->get_title()) + ":";
    feedbackLabel->AutoSize = true;
    feedbackLabel->Font = gcnew System::Drawing::Font("Arial", 16, FontStyle::Regular);
    feedbackLabel->Location = Point(20, currentY);
    gameInfoPanel->Controls->Add(feedbackLabel);

    currentY += feedbackLabel->Height + 10;

    Label^ feedbackLabelPlus = gcnew Label();
    feedbackLabelPlus->Text = "Please describe what you liked or disliked about this game and whether you recommend it to others.";
    feedbackLabelPlus->AutoSize = true;
    feedbackLabelPlus->Font = gcnew System::Drawing::Font("Arial", 14, FontStyle::Regular);
    feedbackLabelPlus->Location = Point(20, currentY);
    gameInfoPanel->Controls->Add(feedbackLabelPlus);

    currentY += feedbackLabelPlus->Height + 10;

    RichTextBox^ feedbackBox = gcnew RichTextBox();
    feedbackBox->Name = "feedbackBox";
    feedbackBox->BorderStyle = BorderStyle::FixedSingle;
    feedbackBox->Font = gcnew System::Drawing::Font("Arial", 12);
    feedbackBox->Location = Point(20, currentY);
    feedbackBox->Size = System::Drawing::Size(gameInfoPanel->ClientSize.Width - 100, 200);
    feedbackBox->WordWrap = true;
    feedbackBox->BackColor = System::Drawing::Color::LightGray;
    gameInfoPanel->Controls->Add(feedbackBox);

    currentY += feedbackBox->Height + 10;

    Button^ btnAddReview = gcnew Button();
    btnAddReview->Text = L"Add Feedback";
    btnAddReview->Size = System::Drawing::Size(120, 30);
    btnAddReview->Location = Point(ClientSize.Width - 230, currentY);
    btnAddReview->Click += gcnew EventHandler(this, &MainClientForm::AddFeedback_Click);
    gameInfoPanel->Controls->Add(btnAddReview);

    Label^ feedbackLabel2 = gcnew Label();
    feedbackLabel2->Text = "What grade would you give? ";
    feedbackLabel2->AutoSize = true;
    feedbackLabel2->Font = gcnew System::Drawing::Font("Arial", 14, FontStyle::Regular);
    feedbackLabel2->Location = Point(20, currentY + 5);
    gameInfoPanel->Controls->Add(feedbackLabel2);

    RadioButton^ rb1 = gcnew RadioButton();
    rb1->Name = "rb1";
    rb1->Text = L"1";
    rb1->Location = Point(20, 20);
    rb1->AutoSize = true;

    RadioButton^ rb2 = gcnew RadioButton();
    rb2->Name = "rb2";
    rb2->Text = L"2";
    rb2->Location = Point(60, 20);
    rb2->AutoSize = true;

    RadioButton^ rb3 = gcnew RadioButton();
    rb3->Name = "rb3";
    rb3->Text = L"3";
    rb3->Location = Point(100, 20);
    rb3->AutoSize = true;

    RadioButton^ rb4 = gcnew RadioButton();
    rb4->Name = "rb4";
    rb4->Text = L"4";
    rb4->Location = Point(140, 20);
    rb4->AutoSize = true;

    RadioButton^ rb5 = gcnew RadioButton();
    rb5->Name = "rb5";
    rb5->Text = L"5";
    rb5->Location = Point(180, 20);
    rb5->AutoSize = true;

    GroupBox^ ratingGroup = gcnew GroupBox();
    ratingGroup->Name = "ratingGroup";
    ratingGroup->Controls->AddRange(gcnew array<Control^> { rb1, rb2, rb3, rb4, rb5 });
    ratingGroup->Location = Point(feedbackLabel2->Width + 20, currentY - 10);
    ratingGroup->Size = System::Drawing::Size(230, 50);
    gameInfoPanel->Controls->Add(ratingGroup);
  }

  private: Void Card_MouseEnter(Object^ sender, EventArgs^ e) {
    safe_cast<Panel^>(sender)->BackColor = Color::LightGray;
  }
  private: Void Card_MouseLeave(Object^ sender, EventArgs^ e) {
    safe_cast<Panel^>(sender)->BackColor = Color::WhiteSmoke;
  }

         System::String^ GenreTypeToString(GenreType genre) {
           switch (genre) {
           case GenreType::Shooter: return "Shooter";
           case GenreType::Battle_Royale: return "Battle Royale";
           case GenreType::Role_Play: return "Role Play";
           case GenreType::Strategy: return "Strategy";
           case GenreType::Simulator: return "Simulator";
           case GenreType::Horror: return "Horror";
           case GenreType::Races: return "Races";
           case GenreType::Casual: return "Casual";
           case GenreType::Adventure: return "Adventure";
           case GenreType::Survival: return "Survival";
           case GenreType::Sandbox: return "Sandbox";
           case GenreType::Action: return "Action";
           case GenreType::RPG: return "RPG";
           case GenreType::Open_World: return "Open World";
           case GenreType::MMORPG: return "MMORPG";
           case GenreType::TGenre: return "TGenre";
           case GenreType::Sports: return "Sports";
           case GenreType::Platform: return "Platform";
           default: return "Unknown";
           }
         }
  private: Void BackButton_Click(System::Object^ sender, System::EventArgs^ e) {
    this->searchBox->Visible = true;
    this->SearchGames->Visible = true;
    this->gamesPanel->Visible = true;
    this->FilterGenre->Visible = true;

    if (gameInfoPanel->Parent != nullptr) {
      this->Controls->Remove(gameInfoPanel);
      delete gameInfoPanel;
    }
  }
  private: Void AddFeedback_Click(System::Object^ sender, EventArgs^ e) {
    RichTextBox^ rtb = nullptr;
    for each (Control ^ ctrl in gameInfoPanel->Controls) {
      if (ctrl->Name == L"feedbackBox") {
        rtb = dynamic_cast<RichTextBox^>(ctrl);
        break;
      }
    }

    if (rtb == nullptr) {
      MessageBox::Show("Поле для отзыва не найдено");
      return;
    }

    String^ reviewText = rtb->Text;

    GroupBox^ group = nullptr;
    for each (Control ^ ctrl in gameInfoPanel->Controls) {
      if (ctrl->Name == L"ratingGroup") {
        group = dynamic_cast<GroupBox^>(ctrl);
        break;
      }
    }

    int rating = 0;
    for each (Control ^ ctrl in group->Controls) {
      RadioButton^ rb = dynamic_cast<RadioButton^>(ctrl);
      if (rb != nullptr && rb->Checked) {
        if (rb->Name == L"rb1") rating = 1;
        else if (rb->Name == L"rb2") rating = 2;
        else if (rb->Name == L"rb3") rating = 3;
        else if (rb->Name == L"rb4") rating = 4;
        else if (rb->Name == L"rb5") rating = 5;
        break;
      }
    }
    if (rating == 0) {
      MessageBox::Show("Please, choose a rating");
      return;
    }

    std::string Text = marshal_as<std::string>(rtb->Text);
    Feedback* user_feedback = new Feedback(MyClient->get_user_id(), MyClient, Text, rating);

    IntPtr ptr = (IntPtr)gameInfoPanel->Tag;
    Game* game = (Game*)ptr.ToPointer();
    game->addFeedback(user_feedback);
    MessageBox::Show("Отзыв успешно добавлен");
  }

};
}
