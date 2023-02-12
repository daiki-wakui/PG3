#pragma once
#include <vector>
#include <iostream>
#include <list>
#include <string>
using namespace std;

class Task
{
private:

	list<const char*> title;	//�^�X�N���e
	list<const char*> content;	//���e
	list<const char*> priority;	//�D��x
	list<const char*> limit;	//����
	list<const char*> finish;	//������

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

