// Copyright 2025 Smirnov Nikita

#ifndef ONLINE_GAME_STORE_PROJECT_GAME_GAME_H_
#define ONLINE_GAME_STORE_PROJECT_GAME_GAME_H_

#include <string>
#include "my_vector.h"  // NOLINT(build/include_subdir)
#include "Date.h"

class Feedback;

enum GenreType { Shooter, Battle_Royale, Role_Play, Strategy,
  Simulator, Horror, Races, Casual, Adventures, Survival,
  Sandbox, Action, RPG, Open_World};

class Game {
  std::string _title;
  GenreType _genre;
  Date _release_date;
  std::string _developer;
  std::string _description;
  int _price;
  float _rating;
  TVector<Feedback> _feedbacks;
};

#endif  // ONLINE_GAME_STORE_PROJECT_GAME_GAME_H_
