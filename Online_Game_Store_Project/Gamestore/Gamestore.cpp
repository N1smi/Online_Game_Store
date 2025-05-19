// Copyright 2025 Smirnov Nikita

#include <fstream>
#include <sstream>
#include <iostream>
#include "Gamestore.h"

GameStore::GameStore() : _users() {}

GameStore::~GameStore() {

}

const User* GameStore::find_user(const std::string& login) const {
  for (size_t i = 0; i < _users.size(); i++) {
    if (_users[i].get_login() == login) {
      return &_users[i];
    }
  }
  return nullptr;
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

const TVector<User>& GameStore::get_all_users_ref() const {
  return _users;
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

