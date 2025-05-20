// Copyright 2025 Smirnov Nikita

#ifndef ONLINE_GAME_STORE_PROJECT_GAME_GAME_H_
#define ONLINE_GAME_STORE_PROJECT_GAME_GAME_H_

#include <string>
#include "Feedback.h"
#include "my_vector.h"  // NOLINT(build/include_subdir)
#include "Date.h"

// class Feedback;

enum GenreType { Shooter, Battle_Royale, Role_Play, Strategy,
  Simulator, Horror, Races, Casual, Adventure, Survival,
  Sandbox, Action, RPG, Open_World, MMORPG, TGenre,
  Sports, Platform};

class Game {
  std::string _title;
  GenreType _genre;
  Date _release_date;
  std::string _developer;
  std::string _description;
  int _price;
  float _rating;
  TVector<Feedback> _feedbacks;
public:
  Game();
  Game(const std::string& title,
    GenreType genre,
    const Date& release_date,
    const std::string& developer,
    const std::string& description,
    int price, float rating,
    const TVector<Feedback>& feedbacks);
  ~Game();

  const std::string& get_title() const { return _title; }
  GenreType get_genre() const { return _genre; }
  const Date& get_release_date() const { return _release_date; }
  const std::string& get_developer() const { return _developer; }
  const std::string& get_description() const { return _description; }
  int get_price() const { return _price; }
  float get_rating() const { return _rating; }
  const TVector<Feedback>& get_feedbacks() const { return _feedbacks; }

  void set_title(const std::string& title) { _title = title; }
  void set_genre(GenreType genre) { _genre = genre; }
  void set_release_date(const Date& date) { _release_date = date; }
  void set_developer(const std::string& developer) { _developer = developer; }
  void set_description(const std::string& description) { _description = description; }
  void set_price(int price) { _price = price; }

  void addFeedback(const Feedback& feedback) { _feedbacks.push_back(feedback);
  _rating = calculateAverageRating();
  }

 private:
  float calculateAverageRating() const;
};

#endif  // ONLINE_GAME_STORE_PROJECT_GAME_GAME_H_
