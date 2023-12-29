#include "Player.h"
#include <stdlib.h>

Player::Player(Vector2 pos, Vector2 size, Color color, bool isAlive) {
	pos_ = pos;
	velocity_ = { 10,10 };
	size_ = size;
	color_ = color;
	gravity_ = 4.0f;
	isAlive_ = isAlive;
	gh_ = Novice::LoadTexture("white1x1.png");
}



int Player::GetColor(Color color) {
	unsigned int result;
	color.red <<= 24;
	color.green <<= 16;
	color.blue <<= 8;
	result = (color.red | color.green | color.blue | color.alpha);

	return result;
}

/*-------------------更新処理---------------------*/
void Player::Update(char *keys) {

	//左右の移動
	if (keys[DIK_A] || keys[DIK_LEFT]) {
		pos_.x -= velocity_.x;
	}
	if (keys[DIK_D] || keys[DIK_RIGHT]) {
		pos_.x += velocity_.x;
	}
	if (keys[DIK_W]&& pos_.y == 400) {
		velocity_.y = -50.0f;
	}
	velocity_.y += gravity_;
	pos_.y += velocity_.y;

	//y座標400の位置に着地
	if (pos_.y >= 400) {
		pos_.y = 400;
	}

}

void Player::Draw() {
	Novice::DrawBox(
		static_cast<int>(pos_.x),
		static_cast<int>(pos_.y),
		static_cast<int>(size_.x),
		static_cast<int>(size_.y),
		0.0f,
		GetColor(color_),
		kFillModeSolid
	);
}

