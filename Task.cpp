#include "Task.h"

Task::Task()
{
}

Task::~Task()
{
}

void Task::AddTask()
{
	//���ꂼ�������͂��Ă���
	printf("�薼�����ĉ�����\n");
	cin >> tmpTitleStr[size];
	titleList[size] = tmpTitleStr[size].c_str();
	title.push_back(titleList[size]);

	printf("���e�����ĉ�����\n");
	cin >> tmpContentStr[size];
	contentList[size] = tmpContentStr[size].c_str();
	content.push_back(contentList[size]);

	printf("�D��x�����ĉ�����\n");
	cin >> tmpPriorityStr[size];
	priorityList[size] = tmpPriorityStr[size].c_str();
	priority.push_back(priorityList[size]);

	printf("���������ĉ�����\n");
	cin >> tmpLimitStr[size];
	limitList[size] = tmpLimitStr[size].c_str();
	limit.push_back(limitList[size]);

	printf("�������Ă邩����Ă�������\n");
	cin >> tmpFinishStr[size];
	finishList[size] = tmpFinishStr[size].c_str();
	finish.push_back(finishList[size]);

	//���X�g�̗v�f���ǉ�
	size++;
}

void Task::DrawTask()
{
	//���ꂼ��̃��X�g��`��
	for (auto itr = title.begin(); itr != title.end(); ++itr) {
		cout << *itr << "\n";
	}

	printf("\n-------------------------------\n");

	for (auto itr = content.begin(); itr != content.end(); ++itr) {
		cout << *itr << "\n";
	}
	printf("\n-------------------------------\n");

	for (auto itr = priority.begin(); itr != priority.end(); ++itr) {
		cout << *itr << "\n";
	}
	printf("\n-------------------------------\n");

	for (auto itr = limit.begin(); itr != limit.end(); ++itr) {
		cout << *itr << "\n";
	}
	printf("\n-------------------------------\n");

	for (auto itr = finish.begin(); itr != finish.end(); ++itr) {
		cout << *itr << "\n";
	}
}
