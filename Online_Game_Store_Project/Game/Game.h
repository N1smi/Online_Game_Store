// Copyright 2025 Smirnov Nikita

#ifndef ONLINE_GAME_STORE_PROJECT_GAME_GAME_H_
#define ONLINE_GAME_STORE_PROJECT_GAME_GAME_H_

class Feedback;

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


#endif  // ONLINE_GAME_STORE_PROJECT_GAME_GAME_H_
