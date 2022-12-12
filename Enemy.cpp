#include "Enemy.h"

void Enemy::Dead()
{
	isAlive = false;
}

void Enemy::Initalize(float posX, float posY)
{
	pos.x = posX;
	pos.y = posY;
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
	if (isAlive == true) {
		DrawBox(pos.x, pos.y, pos.x + 16, pos.y + 16, GetColor(255, 0, 0), true);
	}
}
