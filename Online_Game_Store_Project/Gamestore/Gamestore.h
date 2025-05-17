// Copyright 2025 Smirnov Nikita

#ifndef ONLINE_GAME_STORE_PROJECT_GAMESTORE_GAMESTORE_H_
#define ONLINE_GAME_STORE_PROJECT_GAMESTORE_GAMESTORE_H_

#include "my_vector.h"  // NOLINT(build/include_subdir)

class User;
class Game;

class GameStore {
  TVector<User> _users;
  TVector<Game> _games;
};

#endif  // ONLINE_GAME_STORE_PROJECT_GAMESTORE_GAMESTORE_H_
