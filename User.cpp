#include "User.h"

User::User()
{
	userInfo = false;
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

	userInfo = true;

	//担当者の情報を設定
	this->name = nameStr;
	this->id = id;
	this->className = classStr;
}

void User::Name()
{
	//名前表示
	printf("ID:%d クラス:%s 名前:%s\n", id, className, name);
}

void User::AddTask()
{
	task->AddTask();	//呼び出し
}

void User::TaskView()
{
	task->DrawTask();	//呼び出し
}
