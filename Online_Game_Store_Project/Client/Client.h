// Copyright 2025 Smirnov Nikita

#ifndef ONLINE_GAME_STORE_PROJECT_CLIENT_CLIENT_H_
#define ONLINE_GAME_STORE_PROJECT_CLIENT_CLIENT_H_

#include "my_vector.h"  // NOLINT(build/include_subdir)
#include "User.h"

// class Game;

class Client : public User {
    int _balance;
    TVector<std::string> _my_purchases;
    TVector<std::string> _desired;
    TVector<std::string> _basket;
 public:
   Client();
   Client(const User& user, int balance, TVector<std::string>& my_purchases,
     TVector<std::string>& desired, TVector<std::string>& basket);
   Client(const Client& other);
   ~Client();
};

#endif  // ONLINE_GAME_STORE_PROJECT_CLIENT_CLIENT_H_
