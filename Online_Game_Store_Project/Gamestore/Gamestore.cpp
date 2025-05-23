// Copyright 2025 Smirnov Nikita

#include <fstream>
#include <sstream>
#include <iostream>
#include "Gamestore.h"

GameStore::GameStore() : _users(), _games(){}

GameStore::~GameStore() {

}

bool GameStore::load_data(const std::string& filename_users,
  const std::string& filename_games) {

  bool check_1 = load_users(filename_users);

  bool check_2 = load_games(filename_games);

  bool check_3 = create_clients(filename_users);

  return check_1 && check_2 && check_3;
}

bool GameStore::update_data(const std::string& filename_users,
  const std::string& filename_games) {

  bool check_1 = save_users(filename_users);

  bool check_2 = save_games(filename_games);

  return check_1 && check_2;
}

bool GameStore::load_users(const std::string& filename) {
  std::ifstream file(filename);

  if (!file.is_open()) {
    throw std::logic_error("Error opening the file for reading!");
    return false;
  }

  std::string line;
  size_t line_num = 0;

  while (std::getline(file, line)) {
    line_num++;

    if (line.empty() || line[0] == '#') continue;

    std::stringstream ss(line);
    std::string str_user_id;
    std::string login, password;
    std::string str_is_admin;
    std::string str_is_blocked;

    size_t user_id;
    int is_admin;
    int is_blocked;

    std::getline(ss, str_user_id, ';');
    std::getline(ss, login, ';');
    std::getline(ss, password, ';');
    std::getline(ss, str_is_admin, ';');
    std::getline(ss, str_is_blocked, ';');

    user_id = static_cast<size_t>(std::stoull(str_user_id));
    is_admin = std::stoi(str_is_admin);
    is_blocked = std::stoi(str_is_blocked);

    User user(user_id, login, password, is_admin, is_blocked);

    if (user.get_is_admin() == false) {
      _users.push_back(new Client(user));
    } else {
      _users.push_back(new Administrator(user));
    }
  }

  file.close();
  return true;
}

bool GameStore::load_games(const std::string& filename) {
  std::ifstream file(filename);

  if (!file.is_open()) {
    throw std::logic_error("Error opening the file for reading!");
    return false;
  }

  std::string line;
  size_t line_num = 0;

  while (std::getline(file, line)) {
    line_num++;

    if (line.empty() || line[0] == '#') continue;

    std::stringstream ss(line);
    std::string str_game_id, title, genre, release_date, developer, description, price, rating;

    std::getline(ss, str_game_id, ';');
    std::getline(ss, title, ';');
    std::getline(ss, genre, ';');
    std::getline(ss, release_date, ';');
    std::getline(ss, developer, ';');
    std::getline(ss, description, ';');
    std::getline(ss, price, ';');
    std::getline(ss, rating, ';');

    TVector<Feedback> feedbacks;
    std::string token;
    while (std::getline(ss, token, ';')) {
      if (token.empty()) continue;

      std::stringstream feedback_ss(token);
      std::string str_client_id, text, assessment_str;


      std::getline(feedback_ss, str_client_id, ',');

      std::getline(feedback_ss, text, ',');

      if (!text.empty() && text.front() == '\"') text.erase(0, 1);
      if (!text.empty() && text.back() == '\"') text.pop_back();

      std::getline(feedback_ss, assessment_str);

      int assessment = std::stoi(assessment_str);

      size_t client_id = static_cast<size_t>(std::stoull(str_client_id));

      for (size_t i = 0; i < _users.size(); i++) {
        if (_users[i]->get_user_id() == client_id) {
          Client* client = dynamic_cast<Client*>(_users[i]);
          if (client) {
            Feedback feedback(client_id, client, text, assessment);
            feedbacks.push_back(feedback);
          }
          break;
        }
      }
    }
    
    size_t game_id = static_cast<size_t>(std::stoull(str_game_id));
    GenreType genreT = (GenreType)(std::stoi(genre));
    int priceT = std::stoi(price);
    float ratingT = std::stof(rating);
    Date release_dateT(release_date);
    Game game(game_id, title, genreT, release_dateT, developer, description, priceT, ratingT, feedbacks);

    _games.push_back(game);
  }

  file.close();
  return true;

}

bool GameStore::create_clients(const std::string& filename) {
  std::ifstream file(filename);

  if (!file.is_open()) {
    throw std::logic_error("Error opening the file for reading!");
    return false;
  }

  std::string line;
  size_t line_num = 0;


  while (std::getline(file, line)) {
    line_num++;

    if (line.empty() || line[0] == '#') continue;

    std::stringstream ss(line);
    std::string cell;
    int cellIndex = 0;

    std::string str_user_id;

    getline(ss, str_user_id, ';');

    size_t user_id = static_cast<size_t>(std::stoull(str_user_id));

    while (cellIndex < 2 && std::getline(ss, cell, ';')) {
      cellIndex++;
    }

    std::string str_is_admin;
    int is_admin;
    std::getline(ss, str_is_admin, ';');

    std::getline(ss, cell, ';');

    is_admin = std::stoi(str_is_admin);

    if (is_admin == 0) {
      std::string str_balance;

      int balance;

      std::getline(ss, str_balance, ';');

      balance = std::stoi(str_balance);

      TVector<Game*> purchases;
      std::string str_purchases;

      std::getline(ss, str_purchases, ';');

      std::stringstream purchases_ss(str_purchases);
      std::string str_game_id_p;
      while (std::getline(purchases_ss, str_game_id_p, ',')) {
        size_t game_id = static_cast<size_t>(std::stoull(str_game_id_p));

        for (size_t i = 0; i < _games.size(); i++) {
          if (_games[i].get_game_id() == game_id) {
            purchases.push_back(&_games[i]);
            break;
          }
        }
      }

      TVector<Game*> desired;
      std::string str_desired;

      std::getline(ss, str_desired, ';');

      std::stringstream desired_ss(str_desired);
      std::string str_game_id_d;
      while (std::getline(desired_ss, str_game_id_d, ',')) {
        size_t game_id = static_cast<size_t>(std::stoull(str_game_id_d));

        for (size_t i = 0; i < _games.size(); i++) {
          if (_games[i].get_game_id() == game_id) {
            desired.push_back(&_games[i]);
            break;
          }
        }
      }

      TVector<Game*> basket;
      std::string str_basket;

      std::getline(ss, str_basket, ';');

      std::stringstream basket_ss(str_basket);
      std::string str_game_id_b;
      while (std::getline(basket_ss, str_game_id_b, ',')) {
        size_t game_id = static_cast<size_t>(std::stoull(str_game_id_b));

        for (size_t i = 0; i < _games.size(); i++) {
          if (_games[i].get_game_id() == game_id) {
            basket.push_back(&_games[i]);
            break;
          }
        }
      }

      for (size_t i = 0; i < _users.size(); i++) {
        if (user_id == _users[i]->get_user_id()) {
          Client* client = dynamic_cast<Client*>(_users[i]);
          if (client != nullptr) {
            client->set_balance(balance);
            client->set_purchases(purchases);
            client->set_desired(desired);
            client->set_basket(basket);
          }
          break;
        }
      }

    }
  }
  file.close();
  return true;
}

bool GameStore::save_games(const std::string& filename) const {
  std::ofstream file(filename);
  if (!file.is_open()) {
    throw std::logic_error("Error opening the file for saving!");
    return false;
  }

  file << "#ID;Title;Genre;Released;Developer;Description;Price;Rating;Feedbacks\n";

  for (size_t i = 0; i < _games.size(); i++) {
    file << _games[i].get_game_id() << ";" << _games[i].get_title() << ";" << _games[i].get_genre() << ";"
      << _games[i].get_release_date() << ";" << _games[i].get_developer() << ";"
      << _games[i].get_description() << ";" << _games[i].get_price() << ";"
      << _games[i].get_rating() << ";";

    const auto& feedbacks = _games[i].get_feedbacks();
    for (size_t j = 0; j < _games[i].get_feedbacks().size(); j++) {
      const auto& feedback = feedbacks[j];
      file << feedback.get_client_id() << ","
        << "\"" << feedback.get_text() << "\"" << ","
        << feedback.get_assessment() << ";";
    }
    file << "\n";

  }

  file.close();

  return true;
}

bool GameStore::save_users(const std::string& filename) const {
  std::ofstream file(filename);

  if (!file.is_open()) {
    throw std::logic_error("Error opening the file for saving!");
    return false;
  }

  file << "#ID;Login;Password;is Admin;Block;Balance;Purchases;Desired;Basket\n";

  for (size_t i = 0; i < _users.size(); i++) {
    file << _users[i]->get_user_id() << ";" << _users[i]->get_login() << ";" << _users[i]->get_password() << ";" << _users[i]->get_is_admin() << ";"
      << _users[i]->get_is_blocked() << ";";

    if (!_users[i]->get_is_admin()) {
      Client* client = dynamic_cast<Client*>(_users[i]);
      file << client->get_balance() << ";";

      const auto& purchase = client->get_purchases();
      for (size_t j = 0; j < purchase.size(); j++) {
        file << purchase[j]->get_game_id() << ",";
      }
      file << ";";

      const auto& desired = client->get_desired();
      for (size_t j = 0; j < desired.size(); j++) {
        file << desired[j]->get_game_id() << ",";
      }
      file << ";";

      const auto& basket = client->get_basket();
      for (size_t j = 0; j < basket.size(); j++) {
        file << basket[j]->get_game_id() << ",";
      }

    }
    file << "\n";
  }

  file.close();

  return true;
}

const Game* GameStore::find_game(const std::string& title) const {
  for (size_t i = 0; i < _games.size(); i++) {
    if (_games[i].get_title() == title) {
      return &_games[i];
    }
  }
  return nullptr;
}

const User* GameStore::find_user(const std::string& login) const {
  for (size_t i = 0; i < _users.size(); i++) {

    if (_users[i] != nullptr && _users[i]->get_login() == login) {
      return _users[i];
    }
  }
  return nullptr;
}

bool GameStore::game_exists(const std::string& title) const {
  return find_game(title) != nullptr;
}

bool GameStore::user_exists(const std::string& login) const {
  return find_user(login) != nullptr;
}

bool GameStore::add_client(const User& new_user) {
  if (user_exists(new_user.get_login())) {
    return false;
  }

  Client* client = new Client(new_user);

  _users.push_back(client);
}

bool GameStore::add_game(const Game& new_game) {
  if (game_exists(new_game.get_title())) {
    return false;
  }

  _games.push_back(new_game);
  return true;
}

const TVector<User*>& GameStore::get_all_users_ref() const {
  return _users;
}

const TVector<Game>& GameStore::get_all_games_ref() const {
  return _games;
}

void GameStore::print_users() const {
  std::cout << "All users:\n";
  for (size_t i = 0; i < _users.size();i++) {
    std::cout << "ID: " << _users[i]->get_user_id()
      << ", Login: " << _users[i]->get_login()
      << ", Password: " << _users[i]->get_password()
      << ", isAdmin: " << _users[i]->get_is_admin()
      << ", Blocked: " << _users[i]->get_is_blocked()
      << "\n" << &_users[i] <<"\n";
    if (_users[i]->get_is_admin() == false) {
      Client* client = dynamic_cast<Client*>(_users[i]);
      std::cout << "Balance: " << client->get_balance() << "\n";

      std::cout << "Purchases:\n";
      for (size_t i = 0; i < client->get_purchases().size(); i++) {
        std::cout << client->get_purchases()[i];
      }

      std::cout << "Desired:\n";
      for (size_t i = 0; i < client->get_desired().size(); i++) {
        std::cout << client->get_desired()[i];
      }

      std::cout << "Basket:\n";
      for (size_t i = 0; i < client->get_basket().size(); i++) {
        std::cout << client->get_basket()[i];
      }
    }
  }
}

void GameStore::print_games() const {
  std::cout << "All Games:\n";
  for (size_t i = 0; i < _games.size(); i++) {
    std::cout << "ID: " << _games[i].get_game_id()
      << ", Title: " << _games[i].get_title()
      << ", Genre: " << _games[i].get_genre()
      << ", Release Date: " << _games[i].get_release_date()
      << ", Developer: " << _games[i].get_developer()
      << ", Description: " << _games[i].get_description()
      << ", Price: " << _games[i].get_price()
      << ", Rating: " << _games[i].get_rating()
      << "\nFeedbacks:\n";

    const auto& feedbacks = _games[i].get_feedbacks();
    for (size_t i = 0; i < feedbacks.size(); i++) {
      std::cout << "  Client ID: " << feedbacks[i].get_client_id()
        << "ID ADDRESSS:" << feedbacks[i].get_client_login() << " ";
      if (feedbacks[i].get_client_login() != nullptr) {
        std::cout << feedbacks[i].get_client_login()->get_user_id();
      }
        std::cout << ", Text: " << feedbacks[i].get_text()
        << ", Assessment: " << feedbacks[i].get_assessment()
        << "\n";
    }
    std::cout << "----------------------------\n";
  }
}

