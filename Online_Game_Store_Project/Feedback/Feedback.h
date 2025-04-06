// Copyright 2025 Smirnov Nikita

#ifndef ONLINE_GAME_STORE_PROJECT_FEEDBACK_FEEDBACK_H_
#define ONLINE_GAME_STORE_PROJECT_FEEDBACK_FEEDBACK_H_

class Client;

class Feedback {
    Client* _client;
    char* _text;
    int _assessment;
};

#endif  // ONLINE_GAME_STORE_PROJECT_FEEDBACK_FEEDBACK_H_
