// Copyright 2025 Smirnov Nikita

#include <stdexcept>
#include "User.h"

User::User(const std::string& login, const std::string& password, bool is_blocked) {
  set_login(login);
  set_password(password);
  _is_blocked = is_blocked;
}

const std::string& User::get_login() const { return _login; }
const std::string& User::get_password() const { return _password; }
const bool User::get_block() const { return _is_blocked;  }

void User::set_login(const std::string& login) {
  if (login.length() < 3 || login.length() > 32) {
    throw std::invalid_argument("Login must be between 3 and 32 characters");
  }
  if (login.find(' ') != std::string::npos) {
    throw std::invalid_argument("Input error: The input contains spaces!");
  }
  for (char ch : login) {
    if (!isAlphaNum(ch)) {
      throw std::invalid_argument("Login must contain only letters and digits");
    }
  }
  _login = login;
}

void User::set_password(const std::string& password) {
  if (password.length() < 8 || password.length() > 32) {
    throw std::invalid_argument("Password must be between 8 and 32 characters");
  }
  if (password.find(' ') != std::string::npos) {
    throw std::invalid_argument("Input error: The input contains spaces!");
  }
  _password = password;
}

bool User::check_password(const std::string& input_password) const {
  return _password == input_password;
}

User& User::operator=(const User& other) {
  if (this != &other) {
    _login = other._login;
    _password = other._password;
    _is_blocked = other._is_blocked;
  }
  return *this;
}

bool User::isAlphaNum(char ch) {
  if (ch >= '0' && ch <= '9') {
    return true;
  }
  if (ch >= 'a' && ch <= 'z') {
    return true;
  }
  if (ch >= 'A' && ch <= 'Z') {
    return true;
  }
  return false;
}

