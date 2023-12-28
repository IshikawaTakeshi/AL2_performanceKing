#include "PlayerParticle.h"
#include "Player.h"

PlayerParticle::PlayerParticle(Player *player) {
	player_ = player;
	pos_ = { -150,-150 };
	size_ = { 100,100 };
	color_ = { 255,255,255,255 };
	isAlive_ = false;
}

void PlayerParticle::Spawn() {
	if (isAlive_ == false) {
		for (int i = 0; i < spawnMax_; i++) {
			beforePos_[i] = beforePos_[i + 1];
		}
		beforePos_[0] = player_->GetPos();
		//フラグをtrueに
		isAlive_ = true;
	}
}

void PlayerParticle::Update(char *keys) {
	if (isAlive_ == true) {
		if (keys[DIK_SPACE]) {
			isHitSpaceKey_ = true;
		}else {
			isHitSpaceKey_ = false;
		}
	}
}

void PlayerParticle::Draw() {
	if (isHitSpaceKey_) {
		if (isAlive_ == true) {
			//残像を出す
			for (int i = 0; i < spawnMax_; i++) {
				Novice::DrawBox(
					static_cast<int>(beforePos_[i].x),
					static_cast<int>(beforePos_[i].y),
					static_cast<int>(size_.x),
					static_cast<int>(size_.y),
					0.0f,
					GetColor({ 255 - i * 10,255 - i * 10,255 - i * 10,255 }),
					kFillModeWireFrame
				);
			}
		}
	}
}



