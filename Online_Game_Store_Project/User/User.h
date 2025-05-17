// Copyright 2025 Smirnov Nikita

#ifndef ONLINE_GAME_STORE_PROJECT_USER_USER_H_
#define ONLINE_GAME_STORE_PROJECT_USER_USER_H_

#include <string>

class User {
 protected:
  std::string _login;
  std::string _password;
 public:
   User(const std::string& login = "LoginExample",
     const std::string& password = "PasswordExample");

   const std::string& get_login() const;
   const std::string& get_password() const;

   void set_login(const std::string& login);

   void set_password(const std::string& password);

   bool check_password(const std::string& input_password) const;
};

#endif  // ONLINE_GAME_STORE_PROJECT_USER_USER_H_
