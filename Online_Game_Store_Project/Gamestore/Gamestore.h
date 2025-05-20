// Copyright 2025 Smirnov Nikita

#ifndef ONLINE_GAME_STORE_PROJECT_GAMESTORE_GAMESTORE_H_
#define ONLINE_GAME_STORE_PROJECT_GAMESTORE_GAMESTORE_H_

#include "User.h"
#include "my_vector.h"  // NOLINT(build/include_subdir)
#include "Game.h"

class GameStore {
  TVector<User> _users;
  TVector<Game> _games;

public:
  GameStore();
  ~GameStore();

  const Game* find_game(const std::string& title) const;

  const User* find_user(const std::string& login) const;

  bool game_exists(const std::string& title) const;

  bool user_exists(const std::string& login) const;

  bool add_user(const User& new_user);

  bool add_game(const Game& new_game);

  const TVector<User>& get_all_users_ref() const;

  const TVector<Game>& get_all_games_ref() const;

  bool load_games(const std::string& filename);

  bool load_users(const std::string& filename);

  bool save_games(const std::string& filename) const;

  bool save_users(const std::string& filename) const;

  bool save_game(const std::string& filename, const Game& new_game) const;

  bool save_user(const std::string& filename, const User& new_user) const;

  void print_users();
};

#endif  // ONLINE_GAME_STORE_PROJECT_GAMESTORE_GAMESTORE_H_
