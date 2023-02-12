#pragma once
#include <stdio.h>
#include <stdlib.h>

class User
{
private:

	int id;
	const char* name;
	const char* userClass;

	char nameStr[64];

public:

	User();
	~User();

	void Initaize(int id, const char* userClass);
	void Name();
};

