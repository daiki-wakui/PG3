#include "Player.h"

void Player::Update(char* keys, char* oldkeys)
{
	if (keys[KEY_INPUT_RIGHT] == 1) {
		pos.x += 7;
	}
	if (keys[KEY_INPUT_LEFT] == 1) {
		pos.x -= 7;
	}
	if (keys[KEY_INPUT_UP] == 1) {
		pos.y -= 7;
	}
	if (keys[KEY_INPUT_DOWN] == 1) {
		pos.y += 7;
	}

	if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
		isAttack = true;
	}
}

void Player::Draw()
{
	DrawBox(pos.x, pos.y, pos.x + 16, pos.y + 16, GetColor(255, 255, 255), true);
}
