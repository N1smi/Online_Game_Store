// Copyright 2025 Smirnov Nikita

#include "Client.h"

Client::Client() : User(), _balance(0), _my_purchases(),
_desired(),
_basket() {
}

Client::Client(const User& user, int balance, TVector<std::string>& my_purchases,
  TVector<std::string>& desired, TVector<std::string>& basket) : User(user),
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