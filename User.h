#pragma once
#include <stdio.h>
#include <stdlib.h>

class User
{
private:

	int id;
	const char* name;

public:

	User();
	~User();

	void Initaize(const char* name, int id);
	void Name();
};

