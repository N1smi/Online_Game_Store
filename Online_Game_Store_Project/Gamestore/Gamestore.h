// Copyright 2025 Smirnov Nikita

#ifndef ONLINE_GAME_STORE_PROJECT_GAMESTORE_GAMESTORE_H_
#define ONLINE_GAME_STORE_PROJECT_GAMESTORE_GAMESTORE_H_

#include "my_vector.h"  // NOLINT(build/include_subdir)
#include "User.h"
#include "Game.h"

class GameStore {
  TVector<User> _users;
  TVector<Game> _games;

public:
  const User* find_user(const std::string& login) const;

  bool user_exists(const std::string& login) const;

  bool add_user(const User& new_user);
};

#endif  // ONLINE_GAME_STORE_PROJECT_GAMESTORE_GAMESTORE_H_
