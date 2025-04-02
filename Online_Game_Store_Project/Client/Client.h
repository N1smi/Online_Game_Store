// Copyright 2025 Smirnov Nikita

#ifndef ONLINE_GAME_STORE_PROJECT_CLIENT_CLIENT_H_ 
#define ONLINE_GAME_STORE_PROJECT_CLIENT_CLIENT_H_ 

#include "User.h"

class Game;  

class Client :public User {
    int _balance;
    Game** _my_purchases;
    Game** _desired;
    Game** _basket;
};


#endif  // ONLINE_GAME_STORE_PROJECT_CLIENT_CLIENT_H_ 
