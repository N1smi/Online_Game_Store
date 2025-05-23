// Copyright 2025 Smirnov Nikita

#ifndef ONLINE_GAME_STORE_PROJECT_FEEDBACK_FEEDBACK_H_
#define ONLINE_GAME_STORE_PROJECT_FEEDBACK_FEEDBACK_H_

#include <string>

class Client;

class Feedback {
  size_t _client_id;
  Client* _client_login;
  std::string _text;
  int _assessment;
public:
  Feedback(size_t client_id = 0, Client* client_login = nullptr,
    const std::string& text = "No Text", int assessment = 1);
  Feedback(const Feedback& other);

  const size_t get_client_id() const;
  Client* get_client_login() const;
  const std::string& get_text() const;
  const int get_assessment() const;

  void set_client_id(size_t client_id);
  void set_client_login(Client* client);
  void set_text(const std::string& text);
  void set_assesment(int assesment);
};

#endif  // ONLINE_GAME_STORE_PROJECT_FEEDBACK_FEEDBACK_H_
