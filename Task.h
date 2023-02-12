#pragma once
#include <vector>
#include <iostream>
#include <list>
#include <string>
using namespace std;

class Task
{
private:

	//�^�X�N�薼
	list<const char*> title;
	char titleStr[128];		//�ǉ����镶���������ϐ�
	string tmpTitleStr[64];	//�ǉ����镶����̃R�s�[�ϐ�
	const char* titleList[64] = {};

	//�^�X�N���e
	list<const char*> content;
	char contentStr[128];	//�ǉ����镶���������ϐ�
	string tmpContentStr[64];	//�ǉ����镶����̃R�s�[�ϐ�
	const char* contentList[64] = {};

	//�^�X�N�D��x
	list<const char*> priority;
	char prioritystr[32];	//�ǉ����镶���������ϐ�
	string tmpPriorityStr[64];	//�ǉ����镶����̃R�s�[�ϐ�
	const char* priorityList[64] = {};

	//����
	list<const char*> limit;
	char limitstr[64];	//�ǉ����镶���������ϐ�
	string tmpLimitStr[64];	//�ǉ����镶����̃R�s�[�ϐ�
	const char* limitList[64] = {};

	//�����ς݂�
	list<const char*> finish;
	char finishstr[32];	//�ǉ����镶���������ϐ�
	string tmpFinishStr[64];	//�ǉ����镶����̃R�s�[�ϐ�
	const char* finishList[64] = {};

	//�^�X�N�̗v�f���𐔂���
	int itr;

public:
	Task();
	~Task();

	void AddTask();
	void DrawTask();
};

