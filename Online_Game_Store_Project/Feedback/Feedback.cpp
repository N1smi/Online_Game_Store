// Copyright 2025 Smirnov Nikita

#include "Feedback.h"

Feedback::Feedback(size_t client_id, Client* client_login,
  const std::string& text, int assessment) {
  _client_id = client_id;
  _client_login = client_login;
  _text = text;
  _assessment = assessment;
}

Feedback::Feedback(const Feedback& other) {
  _client_id = other._client_id;
  _client_login = other._client_login;
  _text = other._text;
  _assessment = other._assessment;
}

const size_t Feedback::get_client_id() const { return _client_id; }
Client* Feedback::get_client_login() const { return _client_login; }
const std::string& Feedback::get_text() const { return _text; }
const int Feedback::get_assessment() const { return _assessment; }

void Feedback::set_client_id(size_t client_id) {
  _client_id = client_id;
}
void Feedback::set_client_login(Client* login) {
  _client_login = login;
}
void Feedback::set_text(const std::string& text) {
  _text = text;
}
void Feedback::set_assesment(int assessment) {
  _assessment = assessment;
}
