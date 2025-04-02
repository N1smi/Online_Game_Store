#pragma once

// Copyright 2025 Smirnov Nikita

#ifndef GAMESTORECORE_GAMESTORECORE_H_
#define GAMESTORECORE_GAMESTORECORE_H_

#include "../User/user.h"

class Client;

class Feedback {
	Client* _client;
	char* _text;
	int _assessment;
};

class Game {
	char* _title;
	char* _genre;
	char* _release_date;
	char* _developer;
	char* _description;
	int _price;
	float _rating;
	Feedback** _feedbacks;
};

class Client:public User {
	int _balance;
	Game** _my_purchases;
	Game** _desired;
	Game** _basket;
};


#endif  // GAMESTORECORE_GAMESTORECORE_H_
