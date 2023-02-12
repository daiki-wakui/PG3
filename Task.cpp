#include "Task.h"

Task::Task()
{
}

Task::~Task()
{
}

void Task::AddTask()
{

	printf("�薼�����ĉ�����\n");
	cin >> tmpTitleStr[itr];
	titleList[itr] = tmpTitleStr[itr].c_str();
	title.push_back(titleList[itr]);

	printf("���e�����ĉ�����\n");
	cin >> tmpContentStr[itr];
	contentList[itr] = tmpContentStr[itr].c_str();
	content.push_back(contentList[itr]);

	printf("�D��x�����ĉ�����\n");
	cin >> tmpPriorityStr[itr];
	priorityList[itr] = tmpPriorityStr[itr].c_str();
	priority.push_back(priorityList[itr]);

	printf("���������ĉ�����\n");
	cin >> tmpLimitStr[itr];
	limitList[itr] = tmpLimitStr[itr].c_str();
	limit.push_back(limitList[itr]);

	printf("�������Ă邩����Ă�������\n");
	cin >> tmpFinishStr[itr];
	finishList[itr] = tmpFinishStr[itr].c_str();
	finish.push_back(finishList[itr]);

	itr++;
}

void Task::DrawTask()
{

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