#pragma once
#include "DxLib.h"
#include "Enemy.h"

class Player
{
private: 

	VECTOR pos = { 1280/2,720/2,0 };
	bool isAttack = false;

public:

	void Update(char* keys, char* oldkeys);
	void Draw();

	bool GetIsAttack() { return isAttack; };
};

