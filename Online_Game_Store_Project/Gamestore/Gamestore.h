// Copyright 2025 Smirnov Nikita

#ifndef ONLINE_GAME_STORE_PROJECT_GAMESTORE_GAMESTORE_H_ 
#define ONLINE_GAME_STORE_PROJECT_GAMESTORE_GAMESTORE_H_ 

class Client;    
class Administrator;    
class Game;    

class GameStore {
	Client* _clients;    
	Administrator* _administrators;    
	Game* _games;    
};

#endif  // ONLINE_GAME_STORE_PROJECT_GAMESTORE_GAMESTORE_H_ 
