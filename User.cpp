#include "User.h"

User::User()
{

	
}

User::~User()
{
}

void User::Initaize(const char* name, int id)
{
	this->name = name;
	this->id = id;
}

void User::Name()
{
	printf("ID : %d  ���O : %s\n", id, name);
}
