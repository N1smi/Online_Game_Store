// Copyright 2025 Smirnov Nikita

#ifndef FEEDBACK_FEEDBACK_H_
#define FEEDBACK_FEEDBACK_H_

class Client;

class Feedback {
	Client* _client;
	char* _text;
	int _assessment;
};

#endif  // FEEDBACK_FEEDBACK_H_