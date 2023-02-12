#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Task.h"

class User
{
private:

	//ユーザー情報があるか
	bool userInfo = false;

	//ID
	int id;
	//担当者名
	const char* name;
	//クラス名
	const char* className;

	//入力値を入れる文字列
	char nameStr[64];
	char classStr[32];

	Task* task = new Task();

public:

	User();
	~User();

	//新しく生成
	static User* Create(int id);
	//担当者設定
	void Initaize(int id);
	//名前描画
	void Name();
	//getter
	bool GetInfo() { return userInfo; }
	int GetId() { return id; }

	//Taskクラスに追加、描画する関数
	void AddTask();
	void TaskView();
};

