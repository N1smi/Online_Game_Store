// Copyright 2025 Smirnov Nikita

#ifndef ONLINE_GAME_STORE_PROJECT_CLIENT_CLIENT_H_
#define ONLINE_GAME_STORE_PROJECT_CLIENT_CLIENT_H_

#include "my_vector.h"  // NOLINT(build/include_subdir)
#include "User.h"

class Game;

class Client : public User {
    int _balance;
    TVector<Game*> _my_purchases;
    TVector<Game*> _desired;
    TVector<Game*> _basket;
};

#endif  // ONLINE_GAME_STORE_PROJECT_CLIENT_CLIENT_H_
