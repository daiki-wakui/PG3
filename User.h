#pragma once
#include <stdio.h>
#include <stdlib.h>

class User
{
private:

	int id;
	const char* name;
	const char* userClass;

public:

	User();
	~User();

	void Initaize(int id, const char* userClass , const char* name);
	void Name();
};

