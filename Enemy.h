#pragma once
#include "DxLib.h"
#include <stdlib.h>
#include "EnemyBullet.h"

enum State
{
	PUNCH,
	SHOT,
	MOVE,
	NULL_STATE
};

class Enemy
{
protected:
public:

	static bool isAlive;
	EnemyBullet* bullets = new EnemyBullet[100];

private:

	VECTOR pos;
	VECTOR punchPos;

	int changeStateTimer = 0;
	int stateNum = 0;

	int coolTime = 20;

public:

	Enemy() { isAlive = true; }
	~Enemy() { isAlive = false; };

	void Dead();

	void Initalize(float posX,float posY);
	void Update();
	void Draw();

	void Punch();
	void Shot();
	void Move();

	static void (Enemy::* StateTable[])();
};

