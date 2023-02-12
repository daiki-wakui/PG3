#include "User.h"

User::User()
{
	printf("名前を入れて下さい\n");
	scanf_s("%s", nameStr, 64);
}

User::~User()
{
}

void User::Initaize(int id, const char* userClass)
{


	//this->name = name;

	this->name = nameStr;
	this->id = id;
	this->userClass = userClass;
}

void User::Name()
{
	printf("ID : %d クラス : %s  名前 : %s\n", id, userClass, name);
}
