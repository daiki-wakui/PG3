#pragma once
#include <stdio.h>
#include <stdlib.h>

class User
{
private:

	bool info = false;
	int id;
	const char* name;
	const char* userClass;

	char nameStr[64];
	char classStr[32];

public:

	User();
	~User();

	static User* Create(int id);
	void Initaize(int id);
	void Name();
	bool GetInfo() { return info; }
};

