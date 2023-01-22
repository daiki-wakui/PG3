#include "Enemy.h"

void (Enemy::* Enemy::StateTable[])() = {
	&Enemy::Punch,
	&Enemy::Shot,
	&Enemy::Move
};

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
	changeStateTimer++;

	//100�t���[�����ɏ�Ԃ�؂�ւ���
	if (changeStateTimer > 100) {
		stateNum++;
		changeStateTimer = 0;
	}

	//�ߐځA�ˌ��A�ړ��̏�Ԃ����[�v������
	if (stateNum >= NULL_STATE) {
		stateNum = PUNCH;
	}

	//���݂̏�Ԃ̊֐����Ăяo��
	(this->*StateTable[stateNum])();

	//�G�̒e�̍X�V����
	for (int i = 0; i < 100; i++) {
		if (bullets[i].GetIsAlive() == true) {
			bullets[i].Update();
		}
	}
}

void Enemy::Draw()
{
	DrawFormatString(0, 40, GetColor(255, 255, 255), "%d timer", changeStateTimer);
	DrawFormatString(0, 20, GetColor(255, 255, 255), "%d num",stateNum);

	if (isAlive == true) {
		DrawBox(pos.x, pos.y, pos.x + 32, pos.y + 32, GetColor(255, 0, 0), true);

		if (stateNum == PUNCH) {
			DrawBox(punchPos.x, punchPos.y, punchPos.x + 32, punchPos.y + 32, GetColor(255, 0, 0), false);
		}
		
	}

	for (int i = 0; i < 100; i++) {

		if (bullets[i].GetIsAlive() == true) {
			bullets[i].Draw();
		}
	}
	
}

void Enemy::Punch() {
	punchPos.x = pos.x;
	punchPos.y = pos.y + 32;
}

void Enemy::Shot() {

	if (isAlive == true) {
		coolTime--;

		for (int i = 0; i < 100; i++) {
			if (bullets[i].GetIsAlive() == false && coolTime < 0) {
				bullets[i].Initailze(pos.x + 16, pos.y);
				coolTime = 10;
				break;
			}
		}
	}
	
}

void Enemy::Move() {
	pos.x++;
}