// Copyright 2025 Smirnov Nikita

#ifndef ONLINE_GAME_STORE_PROJECT_FEEDBACK_FEEDBACK_H_
#define ONLINE_GAME_STORE_PROJECT_FEEDBACK_FEEDBACK_H_

#include <string>

// class Client;

class Feedback {
    std::string _client_login;
    std::string _text;
    int _assessment;
public:
  Feedback(const std::string& client_login = "",
    const std::string& text = "No Text", int assessment = 1);
  Feedback(const Feedback& other);

  const std::string& get_client_login() const;
  const std::string& get_text() const;
  const int get_assessment() const;

  void set_client_login(const std::string& login);
  void set_text(const std::string& text);
  void set_assesment(int assesment);
};

#endif  // ONLINE_GAME_STORE_PROJECT_FEEDBACK_FEEDBACK_H_
