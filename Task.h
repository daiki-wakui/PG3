#pragma once
#include <vector>
#include <iostream>
#include <list>
#include <string>
using namespace std;

class Task
{
private:

	list<const char*> title;	//タスク内容
	list<const char*> content;	//内容
	list<const char*> priority;	//優先度
	list<const char*> limit;	//期限
	list<const char*> finish;	//完了か

	char titleStr[128];
	char contentStr[128];
	char prioritystr[32];
	char limitstr[64];
	char finishstr[32];

	string tmpTitleStr[64];
	string tmpContentStr[64];
	string tmpPriorityStr[64];
	string tmpLimitStr[64];
	string tmpFinishStr[64];

	const char* titleList[64] = {};
	const char* contentList[64] = {};
	const char* priorityList[64] = {};
	const char* limitList[64] = {};
	const char* finishList[64] = {};

	int itr;

public:
	Task();
	~Task();

	void addTask();
	void Initaize();
	void ToDo();
};

