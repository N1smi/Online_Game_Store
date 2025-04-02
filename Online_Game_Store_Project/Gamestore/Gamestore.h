#pragma once

// Copyright 2025 Smirnov Nikita

#ifndef GAMESTORE_GAMESTORE_H_
#define GAMESTORE_GAMESTORE_H_

#include "../Administrator/administrator.h"
#include "../Gamestorecore/gamestorecore.h"

class GameStore {
	Client* _clients;
	Administrator* _administrators;
	Game* _games;
};

#endif  // GAMESTORE_GAMESTORE_H_