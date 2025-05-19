// Copyright 2025 Smirnov Nikita

#ifndef ONLINE_GAME_STORE_PROJECT_USER_USER_H_
#define ONLINE_GAME_STORE_PROJECT_USER_USER_H_

#include <string>

class User {
 protected:
  std::string _login;
  std::string _password;
  bool _is_blocked;
 public:
   User(const std::string& login = "LoginExample",
     const std::string& password = "PasswordExample",bool is_blocked = false);

   const std::string& get_login() const;
   const std::string& get_password() const;
   const bool get_block() const;


   void set_login(const std::string& login);

   void set_password(const std::string& password);

   bool check_password(const std::string& input_password) const;

   User& operator=(const User& other);
protected:
   bool isAlphaNum(char ch);
};

#endif  // ONLINE_GAME_STORE_PROJECT_USER_USER_H_
