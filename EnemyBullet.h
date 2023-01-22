#pragma once
#include "DxLib.h"

class EnemyBullet
{
private:

	bool isAlive = false;

	VECTOR pos;

public:

	bool GetIsAlive(){ return isAlive; };
	void Initailze(float posX, float posY);
	void Update();
	void Draw();
};

