#include "User.h"

User::User()
{
	info = false;
}

User::~User()
{
}

User* User::Create(int id) {
	User* user = new User();

	return user;
}

void User::Initaize(int id)
{
	printf("クラスを入れて下さい\n");
	scanf_s("%s", classStr, 32);

	printf("名前を入れて下さい\n");
	scanf_s("%s", nameStr, 64);

	info = true;

	this->name = nameStr;
	this->id = id;
	this->userClass = classStr;
}

void User::Name()
{
	printf("ID:%d クラス:%s 名前:%s\n", id, userClass, name);
}

void User::addTask()
{
	task->addTask();
}

void User::TaskView()
{
	task->ToDo();
}
