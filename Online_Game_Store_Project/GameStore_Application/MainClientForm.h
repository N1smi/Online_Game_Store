#pragma once

#include "ReplenishmentForm.h"
#include "PasswordСhangeForm.h"

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


  private: Panel^ cartinfoPanel = nullptr;
  private: Panel^ wishlistinfoPanel = nullptr;
  private: Panel^ gameInfoPanel = nullptr;
  private: Panel^ myWalletInfoPanel = nullptr;
  private: Panel^ myProfileInfoPanel = nullptr;
  private: bool closeOwner = true;
  private: bool isMyWalletOpen = false;
  private: bool isMyProfileOpen = false;
  private: System::Windows::Forms::Button^ WishlistButton;
  private: System::Windows::Forms::Button^ CartButton;
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
      this->WishlistButton = (gcnew System::Windows::Forms::Button());
      this->CartButton = (gcnew System::Windows::Forms::Button());
      this->menuStrip1->SuspendLayout();
      this->SuspendLayout();
      // 
      // menuStrip1
      // 
      this->menuStrip1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
      this->menuStrip1->BackColor = System::Drawing::SystemColors::Control;
      this->menuStrip1->Dock = System::Windows::Forms::DockStyle::None;
      this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
      this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->nameBalanceToolStripMenuItem });
      this->menuStrip1->Location = System::Drawing::Point(1055, 0);
      this->menuStrip1->Name = L"menuStrip1";
      this->menuStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
      this->menuStrip1->Size = System::Drawing::Size(127, 28);
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
      this->nameBalanceToolStripMenuItem->Size = System::Drawing::Size(119, 24);
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
      this->myWalletToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainClientForm::myWalletToolStripMenuItem_Click);
      // 
      // signOutOfAccountToolStripMenuItem
      // 
      this->signOutOfAccountToolStripMenuItem->Name = L"signOutOfAccountToolStripMenuItem";
      this->signOutOfAccountToolStripMenuItem->Size = System::Drawing::Size(221, 26);
      this->signOutOfAccountToolStripMenuItem->Text = L"Sign out of account";
      this->signOutOfAccountToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainClientForm::signOutOfAccountToolStripMenuItem_Click);
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
      this->FilterGenre->Items->AddRange(gcnew cli::array< System::Object^  >(18) {
        L"All Genre", L"Shooter", L"Battle Royale", L"Role Play",
          L"Strategy", L"Simulator", L"Horror", L"Races", L"Casual", L"Adventure", L"Survival", L"Sandbox", L"Action", L"RPG", L"Open World",
          L"MMORPG", L"Sports", L"Platform"
      });
      this->FilterGenre->Location = System::Drawing::Point(905, 107);
      this->FilterGenre->Name = L"FilterGenre";
      this->FilterGenre->Size = System::Drawing::Size(149, 28);
      this->FilterGenre->TabIndex = 2;
      this->FilterGenre->Text = L"All Genre";
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
      // WishlistButton
      // 
      this->WishlistButton->Anchor = System::Windows::Forms::AnchorStyles::Top;
      this->WishlistButton->AutoSize = true;
      this->WishlistButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
      this->WishlistButton->Location = System::Drawing::Point(719, 105);
      this->WishlistButton->Name = L"WishlistButton";
      this->WishlistButton->Size = System::Drawing::Size(87, 30);
      this->WishlistButton->TabIndex = 5;
      this->WishlistButton->Text = L"Wishlist";
      this->WishlistButton->UseVisualStyleBackColor = true;
      this->WishlistButton->Click += gcnew System::EventHandler(this, &MainClientForm::WishlistButton_Click);
      // 
      // CartButton
      // 
      this->CartButton->Anchor = System::Windows::Forms::AnchorStyles::Top;
      this->CartButton->AutoSize = true;
      this->CartButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
      this->CartButton->Location = System::Drawing::Point(812, 105);
      this->CartButton->Name = L"CartButton";
      this->CartButton->Size = System::Drawing::Size(87, 30);
      this->CartButton->TabIndex = 6;
      this->CartButton->Text = L"Cart";
      this->CartButton->UseVisualStyleBackColor = true;
      this->CartButton->Click += gcnew System::EventHandler(this, &MainClientForm::CartButton_Click);
      // 
      // MainClientForm
      // 
      this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->ClientSize = System::Drawing::Size(1182, 653);
      this->Controls->Add(this->CartButton);
      this->Controls->Add(this->WishlistButton);
      this->Controls->Add(this->gamesPanel);
      this->Controls->Add(this->SearchGames);
      this->Controls->Add(this->FilterGenre);
      this->Controls->Add(this->searchBox);
      this->Controls->Add(this->menuStrip1);
      this->MainMenuStrip = this->menuStrip1;
      this->MaximizeBox = false;
      this->Name = L"MainClientForm";
      this->Text = L"MainClientForm";
      this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
      this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainClientForm::MainClientForm_FormClosing);
      this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainClientForm::MainClientForm_FormClosed);
      this->Load += gcnew System::EventHandler(this, &MainClientForm::MainClientForm_Load);
      this->menuStrip1->ResumeLayout(false);
      this->menuStrip1->PerformLayout();
      this->ResumeLayout(false);
      this->PerformLayout();

    }
#pragma endregion
  private: System::Void MainClientForm_Load(System::Object^ sender, System::EventArgs^ e) {

    UpdateBalance();
    this->gamesPanel->Size = System::Drawing::Size(this->Width - 35, this->Height - 165);

  }

  private: System::Void MainClientForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
  }

  private: System::Void myProfileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    if (isMyProfileOpen == true) return;
    isMyWalletOpen = false;
    isMyProfileOpen = true;
    int width = searchBox->Width;
    width += SearchGames->Width;
    Point pos = searchBox->Location;
    this->searchBox->Visible = false;
    this->SearchGames->Visible = false;
    this->gamesPanel->Visible = false;
    this->FilterGenre->Visible = false;
    this->CartButton->Visible = false;
    this->WishlistButton->Visible = false;

    if (wishlistinfoPanel != nullptr) {
      this->Controls->Remove(wishlistinfoPanel);
      delete wishlistinfoPanel;
    }

    if (cartinfoPanel != nullptr) {
      this->Controls->Remove(cartinfoPanel);
      delete cartinfoPanel;
    }

    if (gameInfoPanel != nullptr && gameInfoPanel->Parent != nullptr) {
      this->Controls->Remove(gameInfoPanel);
      delete gameInfoPanel;
    }

    if (myWalletInfoPanel != nullptr) {
      this->Controls->Remove(myWalletInfoPanel);
      delete myWalletInfoPanel;
    }

    myProfileInfoPanel = gcnew Panel();
    myProfileInfoPanel->Size = System::Drawing::Size(width, this->Height - 100);
    myProfileInfoPanel->Margin = System::Windows::Forms::Padding(10);
    myProfileInfoPanel->Location = pos;
    myProfileInfoPanel->AutoScroll = true;
    this->Controls->Add(myProfileInfoPanel);

    Button^ backButton = gcnew Button();
    backButton->Text = L"Back";
    backButton->Size = System::Drawing::Size(80, 30);
    backButton->Location = Point(10, 10);
    backButton->Click += gcnew EventHandler(this, &MainClientForm::BackButtonMyProfile_Click);
    myProfileInfoPanel->Controls->Add(backButton);

    Label^ lableprofile = gcnew Label();
    lableprofile->AutoSize = false;
    lableprofile->Text = "Your Profile";
    lableprofile->Font = gcnew System::Drawing::Font("Arial", 16, FontStyle::Bold);
    lableprofile->Location = Point((myProfileInfoPanel->Width) / 2 - 60, 10);
    lableprofile->TextAlign = ContentAlignment::MiddleCenter;
    lableprofile->AutoSize = true;
    myProfileInfoPanel->Controls->Add(lableprofile);

    int currentY = 70;

    Label^ lablelogin = gcnew Label();
    lablelogin->AutoSize = false;
    lablelogin->Text = "Login: " + msclr::interop::marshal_as<System::String^>(MyClient->get_login());
    lablelogin->Font = gcnew System::Drawing::Font("Arial", 12, FontStyle::Regular);
    lablelogin->Location = Point(10, currentY);
    lablelogin->AutoSize = true;
    myProfileInfoPanel->Controls->Add(lablelogin);

    Button^ changePasswordButton = gcnew Button();
    changePasswordButton->Text = L"Change Password";
    changePasswordButton->Size = System::Drawing::Size(120, 30);
    changePasswordButton->Location = Point(lablelogin->Width + 20, currentY - 5);
    changePasswordButton->Click += gcnew EventHandler(this, &MainClientForm::ChangePasswordButton_Click);
    myProfileInfoPanel->Controls->Add(changePasswordButton);

    currentY += lablelogin->Height + 15;

    Label^ lablebalance = gcnew Label();
    lablebalance->AutoSize = false;
    int balance = MyClient->get_balance();
    System::String^ displayText = System::String::Format("{0} rub", balance);
    lablebalance->Text = "Balance: " + displayText;
    lablebalance->Font = gcnew System::Drawing::Font("Arial", 12, FontStyle::Regular);
    lablebalance->Location = Point(10, currentY);
    lablebalance->AutoSize = true;
    myProfileInfoPanel->Controls->Add(lablebalance);

    currentY += lablebalance->Height + 35;

    Label^ lablebPurchases = gcnew Label();
    lablebPurchases->AutoSize = false;
    lablebPurchases->Text = "Purchases: ";
    lablebPurchases->Font = gcnew System::Drawing::Font("Arial", 14, FontStyle::Bold);
    lablebPurchases->Location = Point(10, currentY);
    lablebPurchases->AutoSize = true;
    myProfileInfoPanel->Controls->Add(lablebPurchases);

    currentY += lablebPurchases->Height + 15;

    for (size_t i = 0; i < MyClient->get_purchases().size(); i++) {
      const Game* game = MyClient->get_purchases()[i];

      Panel^ gameCardinPurchases = CreateGameCardinPurchases(game);
      gameCardinPurchases->Location = Point(10, currentY);
      myProfileInfoPanel->Controls->Add(gameCardinPurchases);
      currentY += gameCardinPurchases->Height + 10;
    }

  }

  private: Void ChangePasswordButton_Click(Object^ sender, EventArgs^ e) {
    GameStore_Application::PasswordСhangeForm^ PasswordСhangeForm = gcnew GameStore_Application::PasswordСhangeForm(MyClient);
    PasswordСhangeForm->Owner = this;

    PasswordСhangeForm->Show();
  }
  
  private: Panel^ CreateGameCardinPurchases(const Game* game) {
    Panel^ card = gcnew Panel();
    card->Size = System::Drawing::Size(myProfileInfoPanel->Width - 30, 160);
    card->BorderStyle = BorderStyle::FixedSingle;

    Game* gameptr = const_cast<Game*>(game);
    IntPtr ptr(gameptr);
    card->Tag = ptr;
    card->Margin = System::Windows::Forms::Padding(7);

    card->BackColor = Color::WhiteSmoke;
    card->Cursor = Cursors::Hand;

    int currentX = 300;

    PictureBox^ pb = gcnew PictureBox();

    pb->AutoSize = true;

    pb->Location = Point(10, 10);

    System::String^ gameTitle = msclr::interop::marshal_as<System::String^>(game->get_title());

    System::String^ imagesFolder = "E:\\GitHub\\Online_Game_Store\\Online_Game_Store_Project\\Images";

    System::String^ imagePath = System::IO::Path::Combine(imagesFolder, gameTitle + " mid.jpg");

    if (System::IO::File::Exists(imagePath)) {
      pb->Image = Image::FromFile(imagePath);
      card->Controls->Add(pb);
    }

    Label^ title = gcnew Label();
    title->AutoSize = true;
    title->Text = msclr::interop::marshal_as<System::String^>(game->get_title());
    title->Location = Point(currentX + 10, 20);
    title->Font = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);

    card->Controls->Add(title);

    return card;
  }

  private: Void BackButtonMyProfile_Click(System::Object^ sender, System::EventArgs^ e) {
    isMyProfileOpen = false;
    this->searchBox->Visible = true;
    this->SearchGames->Visible = true;
    this->gamesPanel->Visible = true;
    this->FilterGenre->Visible = true;
    this->CartButton->Visible = true;
    this->WishlistButton->Visible = true;

    if (myProfileInfoPanel != nullptr) {
      this->Controls->Remove(myProfileInfoPanel);
      delete myProfileInfoPanel;
    }
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

    int currentY = 116;

    PictureBox^ pb = gcnew PictureBox();

    pb->AutoSize = true;

    pb->Location = Point(10, 10);

    System::String^ gameTitle = msclr::interop::marshal_as<System::String^>(game->get_title());

    System::String^ imagesFolder = "E:\\GitHub\\Online_Game_Store\\Online_Game_Store_Project\\Images";

    System::String^ imagePath = System::IO::Path::Combine(imagesFolder, gameTitle + " logo.ico");

    if (System::IO::File::Exists(imagePath)) {
      pb->Image = Image::FromFile(imagePath);
      card->Controls->Add(pb);
    }

    // Название игры
    Label^ title = gcnew Label();
    title->AutoSize = true;
    title->Text = msclr::interop::marshal_as<System::String^>(game->get_title());
    if (title->Text->Length > 30) {
      title->Text = title->Text->Substring(0, 23) + "...";
    }
    title->Location = Point(10, currentY);
    title->Font = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);

    currentY += title->Height;

    // Дата
    Label^ data = gcnew Label();
    data->AutoSize = true;
    data->Text = "Released: ";
    data->Text += msclr::interop::marshal_as<System::String^>(game->get_release_date().toString());
    data->Location = Point(10, currentY);

    currentY += data->Height;

    // Рейтинг 
    Label^ rating = gcnew Label();
    rating->AutoSize = true;
    rating->Text = "Rating: ";
    rating->Text += String::Format("{0}", game->get_rating());
    rating->Location = Point(10, currentY);

    currentY += rating->Height + 10;

    // Цена
    Label^ price = gcnew Label();
    price->AutoSize = true;
    price->Text = String::Format("{0} rub", game->get_price());
    price->Location = Point(10, currentY);

    currentY += price->Height + 10;

    // Кнопка "Купить"
    Button^ buyButton = gcnew Button();
    buyButton->Text = "Buy";
    buyButton->Location = Point(10, currentY-20);
    buyButton->Click += gcnew EventHandler(this, &MainClientForm::BuyGame);
    buyButton->Tag = ptr;

    Button^ AddtoCart = gcnew Button();
    AddtoCart->Text = "Add to Cart";
    AddtoCart->Location = Point(110, currentY-20);
    AddtoCart->Click += gcnew EventHandler(this, &MainClientForm::Add_to_Cart);
    AddtoCart->Tag = ptr;

    card->Controls->Add(title);
    card->Controls->Add(data);
    card->Controls->Add(rating);
    card->Controls->Add(price);
    card->Controls->Add(buyButton);
    card->Controls->Add(AddtoCart);
    return card;
  }

  private: Void BuyGame(Object^ sender, EventArgs^ e) {
    Button^ button = safe_cast<Button^>(sender);
    IntPtr ptr = (IntPtr)button->Tag;
    Game* game = (Game*)ptr.ToPointer();

    if (MyClient->get_balance() >= game->get_price()) {
      MyClient->add_purchase(game);
      int balance = MyClient->get_balance() - game->get_price();
      MyClient->set_balance(balance);
      MessageBox::Show("Thanks for the purchase!", "Succes", MessageBoxButtons::OK, MessageBoxIcon::Information);
      UpdateBalance();
    }
    else {
      MessageBox::Show("Not enough funds!", "Operation Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
  }

  private: System::Void SearchGames_Click(System::Object^ sender, System::EventArgs^ e) {
    gamesPanel->Controls->Clear();

    String^ searchText = searchBox->Text->ToLower();
    String^ selectedGenre = FilterGenre->Text;


    for (size_t i = 0; i < (*MyGameStoreCopy).get_all_games_ref().size(); i++) {
      const Game* game = &((*MyGameStoreCopy).get_all_games_ref()[i]);
      String^ titleString = gcnew String(game->get_title().c_str());

      bool matchesSearch = titleString->ToLower()->Contains(searchText);
      bool matchesGenre = (selectedGenre == "All Genre" || GenreTypeToString((game->get_genre())) == selectedGenre);

      if (matchesSearch && matchesGenre) {
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
    this->CartButton->Visible = false;
    this->WishlistButton->Visible = false;

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
    btnAddReview->AutoSize = true;
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

    currentY += feedbackLabel2->Height + 15;

    Button^ btnAddWishlist = gcnew Button();
    btnAddWishlist->Text = L"Add to your wishlist";
    btnAddWishlist->AutoSize = true;
    btnAddWishlist->Font = gcnew System::Drawing::Font("Arial", 12, FontStyle::Regular);
    btnAddWishlist->Size = System::Drawing::Size(120, 30);
    btnAddWishlist->Location = Point(20, currentY + 5);
    btnAddWishlist->Tag = ptr;
    btnAddWishlist->Click += gcnew EventHandler(this, &MainClientForm::AddinWislist_Click);
    gameInfoPanel->Controls->Add(btnAddWishlist);

    currentY += btnAddWishlist->Height + 30;

    Label^ Allfeedbacks = gcnew Label();
    Allfeedbacks->Text = "All Feedbacks ";
    Allfeedbacks->AutoSize = true;
    Allfeedbacks->Font = gcnew System::Drawing::Font("Arial", 14, FontStyle::Bold);
    Allfeedbacks->Location = Point(20, currentY);
    gameInfoPanel->Controls->Add(Allfeedbacks);

    currentY += Allfeedbacks->Height + 10;

    const auto& feedbacks = game->get_feedbacks();

    if (feedbacks.is_empty()) {
      Label^ noFeedbacksLabel = gcnew Label();
      noFeedbacksLabel->Text = "No feedbacks yet.";
      noFeedbacksLabel->AutoSize = true;
      noFeedbacksLabel->Font = gcnew System::Drawing::Font("Arial", 12, FontStyle::Regular);
      noFeedbacksLabel->Location = Point(20, currentY);
      gameInfoPanel->Controls->Add(noFeedbacksLabel);
      currentY += noFeedbacksLabel->Height + 10;
    }
    else {
      Panel^ feedbacksPanel = gcnew Panel();
      feedbacksPanel->Location = Point(20, currentY);
      feedbacksPanel->Size = System::Drawing::Size(gameInfoPanel->ClientSize.Width - 100, 300);
      feedbacksPanel->AutoScroll = true;
      //feedbacksPanel->BorderStyle = BorderStyle::FixedSingle;
      gameInfoPanel->Controls->Add(feedbacksPanel);

      int feedbackY = 10;
      for (size_t i = 0; i < feedbacks.size(); i++) {
        const auto& feedback = feedbacks[i];
        Label^ userLabel = gcnew Label();
        userLabel->Text = msclr::interop::marshal_as<System::String^>(feedback->get_client_login()->get_login());
        userLabel->AutoSize = true;
        userLabel->Font = gcnew System::Drawing::Font("Arial", 12, FontStyle::Bold);
        userLabel->Location = Point(10, feedbackY);
        feedbacksPanel->Controls->Add(userLabel);
        feedbackY += userLabel->Height + 5;

        Label^ ratingLabel = gcnew Label();
        ratingLabel->Text = "Rating: " + gcnew String(L'★', feedback->get_assessment());
        ratingLabel->AutoSize = true;
        ratingLabel->Font = gcnew System::Drawing::Font("Arial", 10);
        ratingLabel->Location = Point(10, feedbackY);
        feedbacksPanel->Controls->Add(ratingLabel);
        feedbackY += ratingLabel->Height + 5;

        RichTextBox^ feedbackText = gcnew RichTextBox();
        feedbackText->Text = msclr::interop::marshal_as<System::String^>(feedback->get_text());
        feedbackText->ReadOnly = true;
        feedbackText->BorderStyle = BorderStyle::None;
        //feedbackText->BackColor = System::Drawing::Color::LightGray;
        feedbackText->Font = gcnew System::Drawing::Font("Arial", 10);
        feedbackText->Location = Point(10, feedbackY);
        feedbackText->Size = System::Drawing::Size(feedbacksPanel->ClientSize.Width - 30, 60);
        feedbackText->WordWrap = true;
        feedbacksPanel->Controls->Add(feedbackText);
        feedbackY += feedbackText->Height + 15;

        Label^ separator = gcnew Label();
        separator->BorderStyle = BorderStyle::Fixed3D;
        separator->Height = 2;
        separator->Width = feedbacksPanel->ClientSize.Width - 20;
        separator->Location = Point(10, feedbackY);
        feedbacksPanel->Controls->Add(separator);
        feedbackY += separator->Height + 10;
      }
      currentY += feedbacksPanel->Height + 10;
    }

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
    this->CartButton->Visible = true;
    this->WishlistButton->Visible = true;

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

    reviewText = reviewText->Replace(L"\"", L"");

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
      MessageBox::Show("Please, choose a rating", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
      return;
    }

    std::string Text = marshal_as<std::string>(reviewText);
    Feedback* user_feedback = new Feedback(MyClient->get_user_id(), MyClient, Text, rating);

    IntPtr ptr = (IntPtr)gameInfoPanel->Tag;
    Game* game = (Game*)ptr.ToPointer();
    game->addFeedback(user_feedback);
    MessageBox::Show("Feedback successfully added", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
  }

  private: System::Void signOutOfAccountToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    closeOwner = false;
    this->Close();
  }

  private: System::Void MainClientForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
    if (closeOwner && this->Owner != nullptr) {
      Application::Exit();
    }
    else {
      this->Owner->Show();
    }
  }

  private: System::Void myWalletToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    if (isMyWalletOpen == true) return;
    isMyWalletOpen = true;
    isMyProfileOpen = false;
    this->searchBox->Visible = false;
    this->SearchGames->Visible = false;
    this->gamesPanel->Visible = false;
    this->FilterGenre->Visible = false;
    this->CartButton->Visible = false;
    this->WishlistButton->Visible = false;

    if (wishlistinfoPanel != nullptr) {
      this->Controls->Remove(wishlistinfoPanel);
      delete wishlistinfoPanel;
    }

    if (cartinfoPanel != nullptr) {
      this->Controls->Remove(cartinfoPanel);
      delete cartinfoPanel;
    }

    if (gameInfoPanel != nullptr && gameInfoPanel->Parent != nullptr) {
      this->Controls->Remove(gameInfoPanel);
      delete gameInfoPanel;
    }

    if (myProfileInfoPanel != nullptr) {
      this->Controls->Remove(myProfileInfoPanel);
      delete myProfileInfoPanel;
    }

    myWalletInfoPanel = gcnew Panel();
    myWalletInfoPanel->Size = System::Drawing::Size(this->Width - 50, this->Height - 75);
    myWalletInfoPanel->Margin = System::Windows::Forms::Padding(10);
    myWalletInfoPanel->Location = Point(12, 25);
    myWalletInfoPanel->AutoScroll = true;
    this->Controls->Add(myWalletInfoPanel);

    Button^ backButton = gcnew Button();
    backButton->Text = L"Back";
    backButton->Size = System::Drawing::Size(80, 30);
    backButton->Location = Point(10, 10);
    backButton->Click += gcnew EventHandler(this, &MainClientForm::BackButtonMyWallet_Click);
    myWalletInfoPanel->Controls->Add(backButton);

    Label^ mainLabel = gcnew Label();
    mainLabel->Text = "ADD FUNDS TO YOUR WALLET";
    mainLabel->Font = gcnew System::Drawing::Font("Arial", 24, FontStyle::Bold);
    mainLabel->AutoSize = false;
    mainLabel->Size = System::Drawing::Size(myWalletInfoPanel->ClientSize.Width, 50);
    mainLabel->TextAlign = ContentAlignment::MiddleLeft;
    mainLabel->Location = Point(100, 20);
    myWalletInfoPanel->Controls->Add(mainLabel);

    array<int>^ amounts = gcnew array<int> {150, 300, 750, 1500, 3000};
    int startY = 100;
    int spacingY = 50;

    for (int i = 0; i < amounts->Length; i++) {
      int amount = amounts[i];

      Panel^ box = gcnew Panel();
      box->Text = "";
      box->Size = System::Drawing::Size(280, 50);
      box->Location = Point(20, startY + i * (spacingY + 10));
      box->BorderStyle = BorderStyle::FixedSingle;
      box->BackColor = Color::LightGray;
      myWalletInfoPanel->Controls->Add(box);


      Label^ lbl = gcnew Label();
      lbl->Text = String::Format(L"{0} rub.", amount);
      lbl->Font = gcnew System::Drawing::Font("Arial", 14, FontStyle::Regular);
      lbl->Location = Point(10, 15);
      lbl->AutoSize = true;
      box->Controls->Add(lbl);

      Button^ btnAdd = gcnew Button();
      btnAdd->Text = L"Add funds";
      btnAdd->Location = Point(150, 10);
      btnAdd->BackColor = Color::LightGreen;
      btnAdd->Size = System::Drawing::Size(120, 30);

      btnAdd->Tag = amount;
      btnAdd->Click += gcnew EventHandler(this, &MainClientForm::AddFunds_Click);
      box->Controls->Add(btnAdd);
    }
  }

  private: Void BackButtonMyWallet_Click(System::Object^ sender, System::EventArgs^ e) {
    isMyWalletOpen = false;
    this->searchBox->Visible = true;
    this->SearchGames->Visible = true;
    this->gamesPanel->Visible = true;
    this->FilterGenre->Visible = true;
    this->CartButton->Visible = true;
    this->WishlistButton->Visible = true;

    if (myWalletInfoPanel != nullptr) {
      this->Controls->Remove(myWalletInfoPanel);
      delete myWalletInfoPanel;
    }
  }

  private: System::Void AddFunds_Click(System::Object^ sender, EventArgs^ e) {
    Button^ btn = safe_cast<Button^>(sender);
    int amount = safe_cast<int>(btn->Tag);

    GameStore_Application::ReplenishmentForm^ ReplenishmentForm = gcnew GameStore_Application::ReplenishmentForm(MyClient, &amount);
    ReplenishmentForm->Owner = this;

    ReplenishmentForm->FormClosed += gcnew FormClosedEventHandler(this, &MainClientForm::ReplenishmentForm_Closed);

    ReplenishmentForm->Show();

  }

  private: System::Void ReplenishmentForm_Closed(System::Object^ sender, FormClosedEventArgs^ e) {
    UpdateBalance();
  }

  void UpdateBalance() {

    std::string login = MyClient->get_login();
    int balance = MyClient->get_balance();

    System::String^ loginStr = gcnew System::String(login.c_str());

    System::String^ displayText = System::String::Format("{0} ({1} rub)", loginStr, balance);
    System::String^ displayText2 = System::String::Format("My wallet ({0} rub)", balance);

    this->nameBalanceToolStripMenuItem->Text = displayText;
    this->myWalletToolStripMenuItem->Text = displayText2;
  }

  private: System::Void WishlistButton_Click(System::Object^ sender, System::EventArgs^ e) {
    int width = searchBox->Width;
    width += SearchGames->Width;
    Point pos = searchBox->Location;
    this->searchBox->Visible = false;
    this->SearchGames->Visible = false;
    this->gamesPanel->Visible = false;
    this->FilterGenre->Visible = false;
    this->CartButton->Visible = false;
    this->WishlistButton->Visible = false;

    wishlistinfoPanel = gcnew Panel();
    wishlistinfoPanel->Size = System::Drawing::Size(width, this->Height - 100);
    wishlistinfoPanel->Margin = System::Windows::Forms::Padding(10);
    wishlistinfoPanel->Location = pos;
    wishlistinfoPanel->AutoScroll = true;
    this->Controls->Add(wishlistinfoPanel);

    Button^ backButton = gcnew Button();
    backButton->Text = L"Back";
    backButton->Size = System::Drawing::Size(80, 30);
    backButton->Location = Point(10, 10);
    backButton->Click += gcnew EventHandler(this, &MainClientForm::BackButtonWishlist_Click);
    wishlistinfoPanel->Controls->Add(backButton);

    Label^ lablewihlist = gcnew Label();
    lablewihlist->AutoSize = false;
    lablewihlist->Text = msclr::interop::marshal_as<System::String^>(MyClient->get_login()) + "'s Wishlist";
    lablewihlist->Font = gcnew System::Drawing::Font("Arial", 16, FontStyle::Bold);
    lablewihlist->Location = Point((wishlistinfoPanel->Width) / 2 - 110, 10);
    lablewihlist->TextAlign = ContentAlignment::MiddleCenter;
    lablewihlist->AutoSize = true;
    wishlistinfoPanel->Controls->Add(lablewihlist);

    int currentY = 50;
    for (size_t i = 0; i < MyClient->get_desired().size(); i++) {
      const Game* game = MyClient->get_desired()[i];

      Panel^ gameCardinWish = CreateGameCardinWish(game);
      gameCardinWish->Location = Point(10, currentY);
      wishlistinfoPanel->Controls->Add(gameCardinWish);
      currentY += gameCardinWish->Height + 10;
    }
  }

  private: Panel^ CreateGameCardinWish(const Game* game) {
    Panel^ card = gcnew Panel();
    card->Size = System::Drawing::Size(wishlistinfoPanel->Width - 30, 160);
    card->BorderStyle = BorderStyle::FixedSingle;

    Game* gameptr = const_cast<Game*>(game);
    IntPtr ptr(gameptr);
    card->Tag = ptr;
    card->Margin = System::Windows::Forms::Padding(7);

    card->BackColor = Color::WhiteSmoke;
    card->Cursor = Cursors::Hand;

    int currentX = 300;

    PictureBox^ pb = gcnew PictureBox();

    pb->AutoSize = true;

    pb->Location = Point(10, 10);

    System::String^ gameTitle = msclr::interop::marshal_as<System::String^>(game->get_title());

    System::String^ imagesFolder = "E:\\GitHub\\Online_Game_Store\\Online_Game_Store_Project\\Images";

    System::String^ imagePath = System::IO::Path::Combine(imagesFolder, gameTitle + " mid.jpg");

    if (System::IO::File::Exists(imagePath)) {
      pb->Image = Image::FromFile(imagePath);
      card->Controls->Add(pb);
    }

    Label^ title = gcnew Label();
    title->AutoSize = true;
    title->Text = msclr::interop::marshal_as<System::String^>(game->get_title());
    title->Location = Point(currentX + 10, 20);
    title->Font = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);

    Label^ price = gcnew Label();
    price->AutoSize = true;
    price->Text = String::Format("{0} rub", game->get_price());
    price->Location = Point(card->Width - 130, card->Height/ 2 - 5);

    Label^ data = gcnew Label();
    data->AutoSize = true;
    data->Text = "Released: ";
    data->Text += msclr::interop::marshal_as<System::String^>(game->get_release_date().toString());
    data->Location = Point(currentX + 10, 75);

    Label^ rating = gcnew Label();
    rating->AutoSize = true;
    rating->Text = "Rating: ";
    rating->Text += String::Format("{0}", game->get_rating());
    rating->Location = Point(currentX + 10, 55);

    Button^ RemoveButton = gcnew Button();
    RemoveButton->Text = "Remove";
    RemoveButton->Location = Point(card->Width - 80, card->Height - 30);
    RemoveButton->Click += gcnew EventHandler(this, &MainClientForm::RemoveGameinWish);
    RemoveButton->Tag = ptr;

    Button^ addToCartButton = gcnew Button();
    addToCartButton->Text = "Add to Cart";
    addToCartButton->Location = Point(card->Width - 80, (card->Height / 2) - 10);
    addToCartButton->Click += gcnew EventHandler(this, &MainClientForm::Add_to_Cart);
    addToCartButton->Tag = ptr;

    card->Controls->Add(rating);
    card->Controls->Add(data);
    card->Controls->Add(title);
    card->Controls->Add(price);
    card->Controls->Add(RemoveButton);
    card->Controls->Add(addToCartButton);

    return card;
  }

  private: Void BackButtonWishlist_Click(System::Object^ sender, System::EventArgs^ e) {
    this->searchBox->Visible = true;
    this->SearchGames->Visible = true;
    this->gamesPanel->Visible = true;
    this->FilterGenre->Visible = true;
    this->CartButton->Visible = true;
    this->WishlistButton->Visible = true;

    if (wishlistinfoPanel != nullptr) {
      this->Controls->Remove(wishlistinfoPanel);
      delete wishlistinfoPanel;
    }
  }

  private: System::Void CartButton_Click(System::Object^ sender, System::EventArgs^ e) {
    int width = searchBox->Width;
    width += SearchGames->Width;
    Point pos = searchBox->Location;
    this->searchBox->Visible = false;
    this->SearchGames->Visible = false;
    this->gamesPanel->Visible = false;
    this->FilterGenre->Visible = false;
    this->CartButton->Visible = false;
    this->WishlistButton->Visible = false;

    cartinfoPanel = gcnew Panel();
    cartinfoPanel->Size = System::Drawing::Size(width, this->Height - 100);
    cartinfoPanel->Margin = System::Windows::Forms::Padding(10);
    cartinfoPanel->Location = pos;
    cartinfoPanel->AutoScroll = true;
    this->Controls->Add(cartinfoPanel);

    Button^ backButton = gcnew Button();
    backButton->Text = L"Back";
    backButton->Size = System::Drawing::Size(80, 30);
    backButton->Location = Point(10, 10);
    backButton->Click += gcnew EventHandler(this, &MainClientForm::BackButtonCart_Click);
    cartinfoPanel->Controls->Add(backButton);

    Label^ lablebasket = gcnew Label();
    lablebasket->AutoSize = false;
    lablebasket->Text = "Your Shopping Cart";
    lablebasket->Font = gcnew System::Drawing::Font("Arial", 16, FontStyle::Bold);
    lablebasket->Location = Point((cartinfoPanel->Width)/2 - 110, 10);
    lablebasket->TextAlign = ContentAlignment::MiddleCenter;
    lablebasket->AutoSize = true;
    cartinfoPanel->Controls->Add(lablebasket);


    int currentY = 50;
    int be = 0;
    for (size_t i = 0; i < MyClient->get_basket().size(); i++) {
      const Game* game = MyClient->get_basket()[i];

      Panel^ gameCardinCart = CreateGameCardinCart(game);
      gameCardinCart->Location = Point(10, currentY);
      cartinfoPanel->Controls->Add(gameCardinCart);
      currentY += gameCardinCart->Height + 10;
      be += 1;
    }

    if (be > 1) {
      Button^ buyAllButton = gcnew Button();
      buyAllButton->Name = "buyAllButton";
      buyAllButton->Text = "Buy All";
      buyAllButton->Location = Point(10, currentY);
      buyAllButton->AutoSize = true;
      buyAllButton->Click += gcnew EventHandler(this, &MainClientForm::BuyAllGame);
      cartinfoPanel->Controls->Add(buyAllButton);

      Button^ RemoveAllButton = gcnew Button();
      RemoveAllButton->Name = "RemoveAllButton";
      RemoveAllButton->Text = "Remove All";
      RemoveAllButton->Location = Point(cartinfoPanel->Width - 93, currentY);
      RemoveAllButton->Click += gcnew EventHandler(this, &MainClientForm::RemoveAllGame);
      cartinfoPanel->Controls->Add(RemoveAllButton);
    }
  }

  private: Void RemoveAllGame(Object^ sender, EventArgs^ e) {
    while (!MyClient->get_basket().is_empty()) {
      MyClient->remove_basket(MyClient->get_basket().front());
    }

    System::Collections::Generic::List<Control^>^ controlsToRemove = gcnew System::Collections::Generic::List<Control^>();
    for each (Control ^ ctrl in cartinfoPanel->Controls) {
      if (ctrl->Tag != nullptr || ctrl->Name == "buyAllButton" || ctrl->Name == "RemoveAllButton") {
        controlsToRemove->Add(ctrl);
      }
    }

    for each (Control ^ ctrl in controlsToRemove) {
      cartinfoPanel->Controls->Remove(ctrl);
      delete ctrl;
    }

  }

  private: Void BuyAllGame(Object^ sender, EventArgs^ e) {
     int amount = 0;
     for (size_t i = 0; i < MyClient->get_basket().size(); i++) {
       amount += (MyClient->get_basket())[i]->get_price();
     }

     if (MyClient->get_balance() >= amount) {
       auto basket = MyClient->get_basket();

       for (size_t i = 0; i < basket.size(); i++) {
         MyClient->add_purchase(basket[i]);
       }

       for (size_t i = 0; i < basket.size(); i++) {
         MyClient->remove_basket(basket[i]);
       }

       int balance = MyClient->get_balance() - amount;
       MyClient->set_balance(balance);
       MessageBox::Show("Thanks for the purchases!", "Succes", MessageBoxButtons::OK, MessageBoxIcon::Information);
       UpdateBalance();

       System::Collections::Generic::List<Control^>^ controlsToRemove = gcnew System::Collections::Generic::List<Control^>();
       for each (Control ^ ctrl in cartinfoPanel->Controls) {
         if (ctrl->Tag != nullptr || ctrl->Name == "buyAllButton" || ctrl->Name == "RemoveAllButton") {
           controlsToRemove->Add(ctrl);
         }
       }

       for each (Control ^ ctrl in controlsToRemove) {
         cartinfoPanel->Controls->Remove(ctrl);
         delete ctrl;
       }

     }
     else {
       MessageBox::Show("Not enough funds!", "Operation Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
     }
   }

  private: Void BuyGameinCart(Object^ sender, EventArgs^ e) {
    Button^ button = safe_cast<Button^>(sender);
    IntPtr ptr = (IntPtr)button->Tag;
    Game* game = (Game*)ptr.ToPointer();

    if (MyClient->get_balance() >= game->get_price()) {
      MyClient->add_purchase(game);
      int balance = MyClient->get_balance() - game->get_price();
      MyClient->set_balance(balance);

      MyClient->remove_basket(game);

      Panel^ panelToRemove = nullptr;
      for each (Control ^ ctrl in cartinfoPanel->Controls) {
        if (ctrl->Tag != nullptr && (IntPtr)ctrl->Tag == ptr) {
          panelToRemove = safe_cast<Panel^>(ctrl);
          break;
        }
      }

      if (panelToRemove != nullptr) {
        cartinfoPanel->Controls->Remove(panelToRemove);
        delete panelToRemove;

        int currentY = 50;
        int fixedY = 0;
        System::Collections::Generic::List<Control^>^ controlsToRemove = gcnew System::Collections::Generic::List<Control^>();
        for each (Control ^ ctrl in cartinfoPanel->Controls) {
          if (ctrl->Tag != nullptr || ctrl->Name == "buyAllButton" || ctrl->Name == "RemoveAllButton") {
            if ((ctrl->Name == "buyAllButton" || ctrl->Name == "RemoveAllButton") && MyClient->get_basket().size() < 2) {
              controlsToRemove->Add(ctrl);
            }
            else {
              ctrl->Location = Point(10, currentY);
              if (ctrl->Name == "buyAllButton") {
                if (fixedY != 0) {
                  ctrl->Location = Point(10, fixedY);
                }
                else {
                  ctrl->Location = Point(10, currentY);
                  fixedY = currentY;
                }
                
              }
              if (ctrl->Name == "RemoveAllButton") {
                if (fixedY != 0) {
                  ctrl->Location = Point(cartinfoPanel->Width - ctrl->Width - 10, fixedY);
                }
                else {
                  ctrl->Location = Point(cartinfoPanel->Width - ctrl->Width - 10, currentY);
                  fixedY = currentY;
                }
              }
              currentY += ctrl->Height + 10;
            }
          }
        }

        for each (Control ^ ctrl in controlsToRemove) {
          cartinfoPanel->Controls->Remove(ctrl);
          delete ctrl;
        }
      }
      MessageBox::Show("Thanks for the purchase!", "Succes", MessageBoxButtons::OK, MessageBoxIcon::Information);
      UpdateBalance();
    }
    else {
      MessageBox::Show("Not enough funds!", "Operation Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
  }

  private: Void BackButtonCart_Click(System::Object^ sender, System::EventArgs^ e) {
    this->searchBox->Visible = true;
    this->SearchGames->Visible = true;
    this->gamesPanel->Visible = true;
    this->FilterGenre->Visible = true;
    this->CartButton->Visible = true;
    this->WishlistButton->Visible = true;

    if (cartinfoPanel != nullptr) {
      this->Controls->Remove(cartinfoPanel);
      delete cartinfoPanel;
    }
  }

  private: Panel^ CreateGameCardinCart(const Game* game) {
    Panel^ card = gcnew Panel();
    card->Size = System::Drawing::Size(cartinfoPanel->Width - 30, 160);
    card->BorderStyle = BorderStyle::FixedSingle;

    Game* gameptr = const_cast<Game*>(game);
    IntPtr ptr(gameptr);
    card->Tag = ptr;
    card->Margin = System::Windows::Forms::Padding(7);

    card->BackColor = Color::WhiteSmoke;
    card->Cursor = Cursors::Hand;

    int currentX = 300;

    PictureBox^ pb = gcnew PictureBox();

    pb->AutoSize = true;

    pb->Location = Point(10, 10);

    System::String^ gameTitle = msclr::interop::marshal_as<System::String^>(game->get_title());

    System::String^ imagesFolder = "E:\\GitHub\\Online_Game_Store\\Online_Game_Store_Project\\Images";

    System::String^ imagePath = System::IO::Path::Combine(imagesFolder, gameTitle + " mid.jpg");

    if (System::IO::File::Exists(imagePath)) {
      pb->Image = Image::FromFile(imagePath);
      card->Controls->Add(pb);
    }

    Label^ title = gcnew Label();
    title->AutoSize = true;
    title->Text = msclr::interop::marshal_as<System::String^>(game->get_title());
    title->Location = Point(currentX + 10,20);
    title->Font = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);

    Label^ price = gcnew Label();
    price->AutoSize = true;
    price->Text = String::Format("{0} rub", game->get_price());
    price->Location = Point(card->Width - 160, card->Height-50);

    Button^ buyButton = gcnew Button();
    buyButton->Text = "Buy";
    buyButton->Location = Point(card->Width - 160, card->Height - 30);
    buyButton->Click += gcnew EventHandler(this, &MainClientForm::BuyGameinCart);
    buyButton->Tag = ptr;

    Button^ RemoveButton = gcnew Button();
    RemoveButton->Text = "Remove";
    RemoveButton->Location = Point(card->Width - 80, card->Height - 30);
    RemoveButton->Click += gcnew EventHandler(this, &MainClientForm::RemoveGameinCart);
    RemoveButton->Tag = ptr;

    card->Controls->Add(title);
    card->Controls->Add(price);
    card->Controls->Add(buyButton);
    card->Controls->Add(RemoveButton);

    return card;
  }

  private: System::Void Add_to_Cart(System::Object^ sender, System::EventArgs^ e) {
    Button^ btn = safe_cast<Button^>(sender);

    IntPtr ptr = (IntPtr)btn->Tag;
    Game* game = (Game*)ptr.ToPointer();

    MyClient->add_basket(game);
    MessageBox::Show(String::Format(L"Added to cart: {0}", gcnew String(game->get_title().c_str())));
  }

  private: System::Void AddinWislist_Click(System::Object^ sender, System::EventArgs^ e) {
    Button^ btn = safe_cast<Button^>(sender);

    IntPtr ptr = (IntPtr)btn->Tag;
    Game* game = (Game*)ptr.ToPointer();

    MyClient->add_desired(game);
    MessageBox::Show(String::Format(L"Added to wishlist: {0}", gcnew String(game->get_title().c_str())));
  }

  private: System::Void RemoveGameinWish(System::Object^ sender, System::EventArgs^ e) {
    Button^ btn = safe_cast<Button^>(sender);
    IntPtr ptr = (IntPtr)btn->Tag;
    Game* game = (Game*)ptr.ToPointer();

    MyClient->remove_desired(game);

    Panel^ panelToRemove = nullptr;
    for each (Control ^ ctrl in wishlistinfoPanel->Controls) {
      if (ctrl->Tag != nullptr && (IntPtr)ctrl->Tag == ptr) {
        panelToRemove = safe_cast<Panel^>(ctrl);
        break;
      }
    }

    if (panelToRemove != nullptr) {
      wishlistinfoPanel->Controls->Remove(panelToRemove);
      delete panelToRemove;
    }

    int currentY = 50;
    System::Collections::Generic::List<Control^>^ controlsToRemove = gcnew System::Collections::Generic::List<Control^>();
    for each (Control ^ ctrl in wishlistinfoPanel->Controls) {
      if (ctrl->Tag != nullptr) {
        ctrl->Location = Point(10, currentY);
        currentY += ctrl->Height + 10;
      }
    }

    MessageBox::Show(String::Format(L"Deleted from the wishlist: {0}", gcnew String(game->get_title().c_str())));
  }

  private: System::Void RemoveGameinCart(System::Object^ sender, System::EventArgs^ e) {
    Button^ btn = safe_cast<Button^>(sender);
    IntPtr ptr = (IntPtr)btn->Tag;
    Game* game = (Game*)ptr.ToPointer();

    MyClient->remove_basket(game);

    Panel^ panelToRemove = nullptr;
    for each (Control ^ ctrl in cartinfoPanel->Controls) {
      if (ctrl->Tag != nullptr && (IntPtr)ctrl->Tag == ptr) {
        panelToRemove = safe_cast<Panel^>(ctrl);
        break;
      }
    }

    if (panelToRemove != nullptr) {
      cartinfoPanel->Controls->Remove(panelToRemove);
      delete panelToRemove;

      int currentY = 50;
      int fixedY = 0;
      System::Collections::Generic::List<Control^>^ controlsToRemove = gcnew System::Collections::Generic::List<Control^>();
      for each (Control ^ ctrl in cartinfoPanel->Controls) {
        if (ctrl->Tag != nullptr || ctrl->Name == "buyAllButton" || ctrl->Name == "RemoveAllButton") {
          if ((ctrl->Name == "buyAllButton" || ctrl->Name == "RemoveAllButton") && MyClient->get_basket().size() < 2) {
            controlsToRemove->Add(ctrl);
          }
          else {
            ctrl->Location = Point(10, currentY);
            if (ctrl->Name == "buyAllButton") {
              if (fixedY != 0) {
                ctrl->Location = Point(10, fixedY);
              }
              else {
                ctrl->Location = Point(10, currentY);
                fixedY = currentY;
              }

            }
            if (ctrl->Name == "RemoveAllButton") {
              if (fixedY != 0) {
                ctrl->Location = Point(cartinfoPanel->Width - ctrl->Width - 10, fixedY);
              }
              else {
                ctrl->Location = Point(cartinfoPanel->Width - ctrl->Width - 10, currentY);
                fixedY = currentY;
              }
            }
            currentY += ctrl->Height + 10;
          }
        }
      }

      for each (Control ^ ctrl in controlsToRemove) {
        cartinfoPanel->Controls->Remove(ctrl);
        delete ctrl;
      }
    }

    MessageBox::Show(String::Format(L"Deleted from the cart: {0}", gcnew String(game->get_title().c_str())));
  }
};
}
