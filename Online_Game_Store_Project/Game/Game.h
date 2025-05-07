// Copyright 2025 Smirnov Nikita

#ifndef ONLINE_GAME_STORE_PROJECT_GAME_GAME_H_
#define ONLINE_GAME_STORE_PROJECT_GAME_GAME_H_

#include <string>
#include "my_vector.h"  // NOLINT(build/include_subdir)

class Feedback;

class Game {
  std::string _title;
  std::string _genre;
  std::string _release_date;
  std::string _developer;
  std::string _description;
  int _price;
  float _rating;
  TVector<Feedback> _feedbacks;
};

#endif  // ONLINE_GAME_STORE_PROJECT_GAME_GAME_H_
