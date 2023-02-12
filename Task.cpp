#include "Task.h"

Task::Task()
{
}

Task::~Task()
{
}

void Task::AddTask()
{
	//それぞれ情報を入力していく
	printf("題名を入れて下さい\n");
	cin >> tmpTitleStr[size];
	titleList[size] = tmpTitleStr[size].c_str();
	title.push_back(titleList[size]);

	printf("内容を入れて下さい\n");
	cin >> tmpContentStr[size];
	contentList[size] = tmpContentStr[size].c_str();
	content.push_back(contentList[size]);

	printf("優先度を入れて下さい\n");
	cin >> tmpPriorityStr[size];
	priorityList[size] = tmpPriorityStr[size].c_str();
	priority.push_back(priorityList[size]);

	printf("期限を入れて下さい\n");
	cin >> tmpLimitStr[size];
	limitList[size] = tmpLimitStr[size].c_str();
	limit.push_back(limitList[size]);

	printf("完了してるか入れてください\n");
	cin >> tmpFinishStr[size];
	finishList[size] = tmpFinishStr[size].c_str();
	finish.push_back(finishList[size]);

	//リストの要素数追加
	size++;
}

void Task::DrawTask()
{
	//それぞれのリストを描画
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
