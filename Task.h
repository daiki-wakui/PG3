#pragma once
#include <vector>
#include <iostream>
#include <list>
#include <string>
using namespace std;

class Task
{
private:

	//タスク題名
	list<const char*> title;
	char titleStr[128];		//追加する文字列を入れる変数
	string tmpTitleStr[64];	//追加する文字列のコピー変数
	const char* titleList[64] = {};

	//タスク内容
	list<const char*> content;
	char contentStr[128];	//追加する文字列を入れる変数
	string tmpContentStr[64];	//追加する文字列のコピー変数
	const char* contentList[64] = {};

	//タスク優先度
	list<const char*> priority;
	char prioritystr[32];	//追加する文字列を入れる変数
	string tmpPriorityStr[64];	//追加する文字列のコピー変数
	const char* priorityList[64] = {};

	//期限
	list<const char*> limit;
	char limitstr[64];	//追加する文字列を入れる変数
	string tmpLimitStr[64];	//追加する文字列のコピー変数
	const char* limitList[64] = {};

	//完了済みか
	list<const char*> finish;
	char finishstr[32];	//追加する文字列を入れる変数
	string tmpFinishStr[64];	//追加する文字列のコピー変数
	const char* finishList[64] = {};

	//タスクの要素数を数える
	int itr;

public:
	Task();
	~Task();

	void AddTask();
	void DrawTask();
};

