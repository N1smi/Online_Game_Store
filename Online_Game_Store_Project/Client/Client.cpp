// Copyright 2025 Smirnov Nikita

#include "Client.h"

Client::Client() : User(), _balance(0), _my_purchases(),
_desired(),
_basket() {
}

Client::Client(const User& user) : User(user), _balance(0), _my_purchases(),
_desired(),
_basket() {
}

Client::Client(const User& user, int balance, const TVector<Game*>& my_purchases,
  const TVector<Game*>& desired, const TVector<Game*>& basket) : User(user),
  _balance(balance),
  _my_purchases(my_purchases),
  _desired(desired),
  _basket(basket) { }

Client::Client(const Client& other)
  : User(other),
  _balance(other._balance),
  _my_purchases(other._my_purchases),
  _desired(other._desired),
  _basket(other._basket)
{ }

Client::~Client() {
}

int Client::get_balance() const { return _balance; }

const TVector<Game*>& Client::get_purchases() const { return _my_purchases; }

const TVector<Game*>& Client::get_desired() const { return _desired; }

const TVector<Game*>& Client::get_basket() const { return _basket; }

void Client::set_balance(int balance) {
  _balance = balance;
}

void Client::set_purchases(const TVector<Game*>& purchases) { _my_purchases = purchases; }

void Client::set_desired(const TVector<Game*>& desired) { _desired = desired; }

void Client::set_basket(const TVector<Game*>& basket) { _basket = basket; }


void Client::add_purchase(Game* game) {
  _my_purchases.push_back(game);
}

void Client::add_desired(Game* game) {
  _desired.push_back(game);
}

void Client::add_basket(Game* game) {
  _basket.push_back(game);
}