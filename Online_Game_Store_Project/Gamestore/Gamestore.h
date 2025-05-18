// Copyright 2025 Smirnov Nikita

#ifndef ONLINE_GAME_STORE_PROJECT_GAMESTORE_GAMESTORE_H_
#define ONLINE_GAME_STORE_PROJECT_GAMESTORE_GAMESTORE_H_

#include "User.h"
#include "my_vector.h"  // NOLINT(build/include_subdir)
#include "Game.h"

class GameStore {
  TVector<User> _users;
  //TVector<Game> _games;

public:
  GameStore();
  ~GameStore();
  const User* find_user(const std::string& login) const;

  bool user_exists(const std::string& login) const;

  bool add_user(const User& new_user);

  const TVector<User>& get_all_users_ref() const;

  bool load_users(const std::string& filename);

  bool save_users(const std::string& filename) const;

  bool save_user(const std::string& filename, const User& new_user) const;

  void print_users();
};

#endif  // ONLINE_GAME_STORE_PROJECT_GAMESTORE_GAMESTORE_H_
