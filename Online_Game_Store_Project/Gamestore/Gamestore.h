// Copyright 2025 Smirnov Nikita

#ifndef GAMESTORE_GAMESTORE_H_
#define GAMESTORE_GAMESTORE_H_

class Client;
class Administrator;
class Game;

class GameStore {
	Client* _clients;
	Administrator* _administrators;
	Game* _games;
};

#endif  // GAMESTORE_GAMESTORE_H_