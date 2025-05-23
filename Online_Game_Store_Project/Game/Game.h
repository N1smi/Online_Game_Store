// Copyright 2025 Smirnov Nikita

#ifndef ONLINE_GAME_STORE_PROJECT_GAME_GAME_H_
#define ONLINE_GAME_STORE_PROJECT_GAME_GAME_H_

#include <string>
#include "Feedback.h"
#include "my_vector.h"  // NOLINT(build/include_subdir)
#include "Date.h"

enum GenreType { Shooter, Battle_Royale, Role_Play, Strategy,
  Simulator, Horror, Races, Casual, Adventure, Survival,
  Sandbox, Action, RPG, Open_World, MMORPG, TGenre,
  Sports, Platform};

class Game {
  size_t _game_id;
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
  Game(size_t game_id ,const std::string& title,
    GenreType genre,
    const Date& release_date,
    const std::string& developer,
    const std::string& description,
    int price, float rating,
    const TVector<Feedback>& feedbacks);

  Game(const Game& other);

  ~Game();

  const size_t get_game_id() const;
  const std::string& get_title() const;
  GenreType get_genre() const;
  const Date& get_release_date() const;
  const std::string& get_developer() const;
  const std::string& get_description() const;
  int get_price() const;
  float get_rating() const;
  const TVector<Feedback>& get_feedbacks() const;

  void set_game_id(size_t game_id);
  void set_title(const std::string& title);
  void set_genre(GenreType genre);
  void set_release_date(const Date& date);
  void set_developer(const std::string& developer);
  void set_description(const std::string& description);
  void set_price(int price);

  void addFeedback(const Feedback& feedback);
 private:
  float calculateAverageRating() const;
};

#endif  // ONLINE_GAME_STORE_PROJECT_GAME_GAME_H_
