#include "User.h"

User::User()
{
	printf("���O�����ĉ�����\n");
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
	printf("ID : %d �N���X : %s  ���O : %s\n", id, userClass, name);
}
