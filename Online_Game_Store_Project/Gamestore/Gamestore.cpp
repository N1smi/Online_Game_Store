// Copyright 2025 Smirnov Nikita

#include "Gamestore.h"

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