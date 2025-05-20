// Copyright 2025 Smirnov Nikita

#include <fstream>
#include <sstream>
#include <iostream>
#include "Gamestore.h"

GameStore::GameStore() : _users(), _games(){}

GameStore::~GameStore() {

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
    if (_users[i].get_login() == login) {
      return &_users[i];
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

bool GameStore::add_user(const User& new_user) {
  if (user_exists(new_user.get_login())) {
    return false;
  }

  _users.push_back(new_user);
  return true;
}

bool GameStore::add_game(const Game& new_game) {
  if (game_exists(new_game.get_title())) {
    return false;
  }

  _games.push_back(new_game);
  return true;
}

const TVector<User>& GameStore::get_all_users_ref() const {
  return _users;
}

const TVector<Game>& GameStore::get_all_games_ref() const {
  return _games;
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
    std::string title, genre, release_date, developer, description, price, rating;

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
      std::string client_login, text, assessment_str;

      std::getline(feedback_ss, client_login, ',');

      std::getline(feedback_ss, text, ',');

      if (!text.empty() && text.front() == '\"') text.erase(0, 1);
      if (!text.empty() && text.back() == '\"') text.pop_back();

      std::getline(feedback_ss, assessment_str);

      int assessment = std::stoi(assessment_str);

      Feedback feedback(client_login, text, assessment);
      feedbacks.push_back(feedback);
    }


    GenreType genreT = (GenreType)(std::stoi(genre));
    int priceT = std::stoi(price);
    float ratingT = std::stof(rating);
    Date release_dateT(release_date);
    Game game(title, genreT, release_dateT, developer, description, priceT, ratingT, feedbacks);

    _games.push_back(game);
  }

  file.close();
  return true;

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
    std::string login, password;
    std::string str_is_blocked;
    int is_blocked;

    std::getline(ss, login, ';');
    std::getline(ss, password, ';');
    std::getline(ss, str_is_blocked);
    is_blocked = std::stoi(str_is_blocked);

    User user(login, password, is_blocked);

    _users.push_back(user);
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

  file << "# Название;Жанр;Дата релиза;Разработчик;Описание;Цена;Рейтинг;Отзывы\n";

  for (size_t i = 0; i < _games.size(); i++) {
    file << _games[i].get_title() << ";" << _games[i].get_genre() << ";"
      << _games[i].get_release_date() << ";" << _games[i].get_developer() << ";"
      << _games[i].get_description() << ";" << _games[i].get_price() << ";"
      << _games[i].get_rating() << ";";

    const auto& feedbacks = _games[i].get_feedbacks();
    for (size_t j = 0; j < _games[i].get_feedbacks().size(); j++) {
      const auto& feedback = feedbacks[j];
      file << feedback.get_client_login() << ","
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

  file << "# Логин;Пароль;Блокировка\n";

  for (size_t i = 0; i < _users.size(); i++) {
    file << _users[i].get_login() << ";" << _users[i].get_password() << ";" << _users[i].get_block() << "\n";
  }

  file.close();
 
  return true;
}

bool GameStore::save_game(const std::string& filename, const Game& new_game) const {
  std::ofstream file(filename, std::ios::app);

  if (!file.is_open()) {
    throw std::logic_error("Error opening the file for saving!");
    return false;
  }

  file << new_game.get_title() << ";" << new_game.get_genre() << ";"
    << new_game.get_release_date() << ";" << new_game.get_developer() << ";"
    << new_game.get_description() << ";" << new_game.get_price() << ";"
    << new_game.get_rating() << ";";

  const auto& feedbacks = new_game.get_feedbacks();
  for (size_t j = 0; j < feedbacks.size(); j++) {
    const auto& feedback = feedbacks[j];
    file << feedback.get_client_login() << ","
      << "\"" << feedback.get_text() << "\"" << ","
      << feedback.get_assessment() << ";";
  }
  file << "\n";
  file.close();

  return true;
}

bool GameStore::save_user(const std::string& filename, const User& new_user) const {
  std::ofstream file(filename, std::ios::app);

  if (!file.is_open()) {
    throw std::logic_error("Error opening the file for saving!");
    return false;
  }
  
  file << new_user.get_login() << ";"
    << new_user.get_password() << ";"
  << new_user.get_block() << "\n";

  file.close();

  return true;
}

void GameStore::print_users() {
  for (size_t i = 0; i < _users.size(); i++) {
    std::cout << _users[i].get_login() << ' ' << _users[i].get_password() << std::endl;
  }
}

