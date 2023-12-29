#include "PlayerParticle.h"
#include "Player.h"
#include "Easing.h"

PlayerParticle::PlayerParticle(Player *player) {
	player_ = player;
	pos_ = { -150,-150 };
	size_ = { 70,70 };
	color_ = { 0,0,0,255 };
	isAlive_ = false;
	timer_ = 0;
}

void PlayerParticle::Spawn() {
	if (isAlive_ == false) {
		pos_ = player_->GetPos();
		isAlive_ = true;
	}
}

void PlayerParticle::Update() {
	if (isAlive_ == true) {
		timer_++;

		//残像の色を変える
		color_.green += 10;
		if (color_.green >= 255) {
			color_.green = 0;
		}
	}

	if (timer_ >= 10) {
		timer_ = 0;
		isAlive_ = false;
	}

}

void PlayerParticle::Draw() {
		if (isAlive_ == true) {
			Novice::DrawBox(
				static_cast<int>(pos_.x),
				static_cast<int>(pos_.y),
				static_cast<int>(size_.x),
				static_cast<int>(size_.y),
				0.0f,
				GetColor({ color_.red,color_.green,color_.blue,color_.alpha }),
				kFillModeSolid
			);
		}
}



