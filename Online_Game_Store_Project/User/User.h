// Copyright 2025 Smirnov Nikita

#ifndef ONLINE_GAME_STORE_PROJECT_USER_USER_H_
#define ONLINE_GAME_STORE_PROJECT_USER_USER_H_

#include <string>

class User {
 protected:
  size_t _user_id;
  std::string _login;
  std::string _password;
  bool _is_admin;
  bool _is_blocked;
 public:
   User(size_t user_id = 0, const std::string& login = "LoginExample",
     const std::string& password = "PasswordExample", bool is_admin = false, bool is_blocked = false);
   User(const User& other);
   virtual ~User() {}
   const size_t get_user_id() const;
   const std::string& get_login() const;
   const std::string& get_password() const;
   const bool get_is_blocked() const;
   const bool get_is_admin() const;

   void set_user_id(size_t user_id);

   void set_login(const std::string& login);

   void set_password(const std::string& password);

   void set_is_admin(bool is_admin);

   void set_is_blocked(bool is_blocked);

   bool check_password(const std::string& input_password) const;

   virtual User& operator=(const User& other);
protected:
   bool isAlphaNum(char ch);
};

#endif  // ONLINE_GAME_STORE_PROJECT_USER_USER_H_
