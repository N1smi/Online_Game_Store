// Copyright 2025 Smirnov Nikita

#ifndef CLIENT_CLIENT_H_
#define CLIENT_CLIENT_H_

#include "User.h"

class Game;

class Client :public User {
	int _balance;
	Game** _my_purchases;
	Game** _desired;
	Game** _basket;
};


#endif  // CLIENT_CLIENT_H_
