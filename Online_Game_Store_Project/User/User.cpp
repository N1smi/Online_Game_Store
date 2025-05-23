// Copyright 2025 Smirnov Nikita

#include <stdexcept>
#include "User.h"

User::User(size_t user_id, const std::string& login, const std::string& password, bool is_admin, bool is_blocked) {
  _user_id = user_id;
  set_login(login);
  set_password(password);
  _is_admin = is_admin;
  _is_blocked = is_blocked;
}

User::User(const User& other)
  : _user_id(other._user_id),
  _login(other._login),
  _password(other._password),
  _is_admin(other._is_admin),
  _is_blocked(other._is_blocked) {
}

const size_t User::get_user_id() const { return _user_id;  }
const std::string& User::get_login() const { return _login; }
const std::string& User::get_password() const { return _password; }
const bool User::get_is_blocked() const { return _is_blocked;  }
const bool User::get_is_admin() const { return _is_admin; }

void User::set_user_id(size_t user_id) {
  _user_id = user_id;
}

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

void User::set_is_admin(bool is_admin) {
  _is_admin = is_admin;
}

void User::set_is_blocked(bool is_blocked) {
  _is_blocked = is_blocked;
}

bool User::check_password(const std::string& input_password) const {
  return _password == input_password;
}

User& User::operator=(const User& other) {
  if (this != &other) {
    _user_id = other._user_id;
    _login = other._login;
    _password = other._password;
    _is_admin = other._is_admin;
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

