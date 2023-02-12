#include "User.h"

User::User()
{

	
}

User::~User()
{
}

void User::Initaize(int id, const char* userClass, const char* name)
{
	this->name = name;
	this->id = id;
	this->userClass = userClass;
}

void User::Name()
{
	printf("ID : %d ƒNƒ‰ƒX : %s  –¼‘O : %s\n", id, userClass, name);
}
