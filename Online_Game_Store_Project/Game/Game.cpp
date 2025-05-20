// Copyright 2025 Smirnov Nikita

#include "Game.h"

Game::Game()
  : _title("Unknown Title"),
    _genre(TGenre),
    _release_date(),
    _developer("Unknown Developer"),
    _description("No description"),
    _price(0),
    _rating(0.0f),
    _feedbacks()
  {}

Game::Game(const std::string& title,
  GenreType genre,
  const Date& release_date,
  const std::string& developer,
  const std::string& description,
  int price, float rating,
  const TVector<Feedback>& feedbacks)
  : _title(title),
  _genre(genre),
  _release_date(release_date),
  _developer(developer),
  _description(description),
  _price(price),
  _rating(rating),
  _feedbacks(feedbacks)
{
}
Game::~Game() {

}

float Game::calculateAverageRating() const {
  if (_feedbacks.is_empty()) {
    return 0.0f;
  }

  float sum = 0.0f;
  for (size_t i = 0; i < _feedbacks.size(); i++) {
    sum += _feedbacks[i].get_assessment();
  }
  return sum / _feedbacks.size();
}