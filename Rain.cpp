#include "Rain.h"
#include <stdlib.h>
#include "Novice.h"

Rain::Rain() {
	pos_ = { -30,-30 };
	endPos_ = { pos_.x + 20,pos_.y+20 };
	size_ = { 0,0 };
	gravity_ = 4.0f;
	color_ = {0,0,0,255 };
	isAlive_ = false;
}

void Rain::Spawn(Cloud cloud) {
	if (isAlive_ == false) {
		//座標の初期化
		pos_.x = (cloud.GetPos().x)
			+ (rand() % (int)cloud.GetSize().x - (int)cloud.GetSize().x / 2);
		pos_.y = (cloud.GetPos().y)
			+ (rand() % (int)cloud.GetSize().y - (int)cloud.GetSize().y / 2);
		endPos_ = { pos_.x + 20,pos_.y + 20 };
		velocity_.y = 0;
		//フラグをtrueに
		isAlive_ = true;
	}
}

void Rain::Update() {
	if (isAlive_ == true) {
		//落下の計算
		velocity_.y += gravity_;
		pos_.y += velocity_.y;
		endPos_ = { pos_.x + 20,pos_.y + 20 };

		if (pos_.x >= 1280 || pos_.x <= 0 || pos_.y >= 740.0f) {
			//画面外に出たときフラグをfalseに
			isAlive_ = false;
		}
	}
}

void Rain::Draw() {
	Novice::DrawLine(
		static_cast<int>(pos_.x),
		static_cast<int>(pos_.y),
		static_cast<int>(endPos_.x),
		static_cast<int>(endPos_.y),
		GetColor(color_)
	);
}
