#pragma once
#include "DxLib.h"
#include <stdlib.h>

class Enemy
{
protected:
public:

	static bool isAlive;

private:

	VECTOR pos;

public:

	Enemy() { isAlive = true; }
	~Enemy() { isAlive = false; };

	void Dead();

	void Initalize(float posX,float posY);
	void Update();
	void Draw();
};

