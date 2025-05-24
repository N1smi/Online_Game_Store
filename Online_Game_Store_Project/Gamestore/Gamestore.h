// Copyright 2025 Smirnov Nikita

#ifndef ONLINE_GAME_STORE_PROJECT_GAMESTORE_GAMESTORE_H_
#define ONLINE_GAME_STORE_PROJECT_GAMESTORE_GAMESTORE_H_

#include "Client.h"
#include "Administrator.h"
#include "Game.h"

class GameStore {
  TVector<User*> _users;
  TVector<Game> _games;

public:
  GameStore();
  ~GameStore();

  bool load_data(const std::string& filename_users,
    const std::string& filename_games);

  bool update_data(const std::string& filename_users,
    const std::string& filename_games);

  bool load_users(const std::string& filename);

  bool load_games(const std::string& filename);

  bool create_clients(const std::string& filename);

  const Game* find_game(const std::string& title) const;

  User* find_user(const std::string& login) const;

  bool game_exists(const std::string& title) const;

  bool user_exists(const std::string& login) const;

  bool add_client(const User& new_user);

  bool add_game(const Game& new_game);

  const TVector<User*>& get_all_users_ref() const;

  const TVector<Game>& get_all_games_ref() const;

  bool save_games(const std::string& filename) const;

  bool save_users(const std::string& filename) const;

  void print_users() const;

  void print_games() const;
};

#endif  // ONLINE_GAME_STORE_PROJECT_GAMESTORE_GAMESTORE_H_
