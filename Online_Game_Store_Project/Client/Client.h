// Copyright 2025 Smirnov Nikita

#ifndef ONLINE_GAME_STORE_PROJECT_CLIENT_CLIENT_H_
#define ONLINE_GAME_STORE_PROJECT_CLIENT_CLIENT_H_

#include "my_vector.h"  // NOLINT(build/include_subdir)
#include "User.h"

class Game;

class Client : public User {
    int _balance;
    TVector<Game*> _my_purchases;
    TVector<Game*> _desired;
    TVector<Game*> _basket;
 public:
   Client();
   Client(const User& user);
   Client(const User& user, int balance, const TVector<Game*>& my_purchases,
     const TVector<Game*>& desired, const TVector<Game*>& basket);
   Client(const Client& other);
   ~Client();

   int get_balance() const;
   const TVector<Game*>& get_purchases() const;
   const TVector<Game*>& get_desired() const;
   const TVector<Game*>& get_basket() const;

   void set_balance(int balance);
   void set_purchases(const TVector<Game*>& purchases);
   void set_desired(const TVector<Game*>& purchases);
   void set_basket(const TVector<Game*>& purchases);

   void add_purchase(Game* game);
   void add_desired(Game* game);
   void add_basket(Game* game);
};

#endif  // ONLINE_GAME_STORE_PROJECT_CLIENT_CLIENT_H_
