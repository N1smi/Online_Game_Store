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

Game::Game(const Game& other)
  : _title(other._title),
  _genre(other._genre),
  _release_date(other._release_date),
  _developer(other._developer),
  _description(other._description),
  _price(other._price),
  _rating(other._rating),
  _feedbacks(other._feedbacks)
{}

Game::~Game() {

}

const std::string& Game::get_title() const { return _title; }
GenreType Game::get_genre() const { return _genre; }
const Date& Game::get_release_date() const { return _release_date; }
const std::string& Game::get_developer() const { return _developer; }
const std::string& Game::get_description() const { return _description; }
int Game::get_price() const { return _price; }
float Game::get_rating() const { return _rating; }
const TVector<Feedback>& Game::get_feedbacks() const { return _feedbacks; }

void Game::set_title(const std::string& title) { _title = title; }
void Game::set_genre(GenreType genre) { _genre = genre; }
void Game::set_release_date(const Date& date) { _release_date = date; }
void Game::set_developer(const std::string& developer) { _developer = developer; }
void Game::set_description(const std::string& description) { _description = description; }
void Game::set_price(int price) { _price = price; }

void Game::addFeedback(const Feedback& feedback) {
  _feedbacks.push_back(feedback);
  _rating = calculateAverageRating();
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