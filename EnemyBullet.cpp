#include "EnemyBullet.h"

void EnemyBullet::Initailze(float posX, float posY)
{
	pos.x = posX;
	pos.y = posY;
	isAlive = true;
}

void EnemyBullet::Update()
{
	pos.y+=3;

	if (pos.y >= 720) {
		isAlive = false;
	}
}

void EnemyBullet::Draw()
{
	DrawCircle(pos.x, pos.y, 8, GetColor(255, 255, 255), true);
}
