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
	printf("�N���X�����ĉ�����\n");
	scanf_s("%s", classStr, 32);

	printf("���O�����ĉ�����\n");
	scanf_s("%s", nameStr, 64);

	userInfo = true;

	//�S���҂̏���ݒ�
	this->name = nameStr;
	this->id = id;
	this->className = classStr;
}

void User::Name()
{
	//���O�\��
	printf("ID:%d �N���X:%s ���O:%s\n", id, className, name);
}

void User::AddTask()
{
	task->AddTask();	//�Ăяo��
}

void User::TaskView()
{
	task->DrawTask();	//�Ăяo��
}
