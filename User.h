#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Task.h"

class User
{
private:

	//���[�U�[��񂪂��邩
	bool userInfo = false;

	//ID
	int id;
	//�S���Җ�
	const char* name;
	//�N���X��
	const char* className;

	//���͒l�����镶����
	char nameStr[64];
	char classStr[32];

	Task* task = new Task();

public:

	User();
	~User();

	//�V��������
	static User* Create(int id);
	//�S���Ґݒ�
	void Initaize(int id);
	//���O�`��
	void Name();
	//getter
	bool GetInfo() { return userInfo; }
	int GetId() { return id; }

	//Task�N���X�ɒǉ��A�`�悷��֐�
	void AddTask();
	void TaskView();
};

