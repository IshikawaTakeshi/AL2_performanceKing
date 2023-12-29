#include "ShockWave.h"
#include "Player.h"
#include "Novice.h"



ShockWave::ShockWave(Player *player,Vector2 acceleration) {
	player_ = player;
	pos_ = { -50,-50 };
	size_ = { 25, 25 };
	velocity_ = { 0,0 };
	acceleration_ = acceleration;
	color_ = { 255,255,255,255 };
	isAlive_ = false;
	VertexUpdate();
}

void ShockWave::VertexUpdate() {
	vertex_[LT].x = pos_.x - size_.x / 2;
	vertex_[LT].y = pos_.y - size_.y / 2;
	vertex_[RT].x = pos_.x + size_.x / 2;
	vertex_[RT].y = pos_.y - size_.y / 2;
	vertex_[LB].x = pos_.x - size_.x / 2;
	vertex_[LB].y = pos_.y + size_.y / 2;
	vertex_[RB].x = pos_.x + size_.x / 2;
	vertex_[RB].y = pos_.y + size_.y / 2;
}

void ShockWave::Spawn(char *keys) {
	if (isAlive_ == false) {
		pos_.x = player_->GetPos().x + 35;
		pos_.y = player_->GetPos().y + 50;
		velocity_ = { 0,0 };
		VertexUpdate();
		if (keys[DIK_S] && player_->GetPos().y >= 400) {
			isAlive_ = true;
		}
		
	}
}

void ShockWave::Update() {
	if (isAlive_ == true) {
		VertexUpdate();
		velocity_.x += acceleration_.x;
		pos_.x += velocity_.x;
		color_.alpha -= 5;
		if (color_.alpha <= 0) {
			color_.alpha = 255;
			isAlive_ = false;
		}
	}
}

void ShockWave::Draw() {
	if (acceleration_.x <= 0.0f) {
		if (isAlive_ == true) {
			Novice::DrawTriangle(
				static_cast<int>(vertex_[LT].x),
				static_cast<int>(vertex_[LT].y),
				static_cast<int>(vertex_[LB].x),
				static_cast<int>(vertex_[LB].y),
				static_cast<int>(vertex_[RB].x),
				static_cast<int>(vertex_[RB].y),
				GetColor(color_),
				kFillModeSolid
			);
		}
		
	} else {
		if (isAlive_ == true) {
			Novice::DrawTriangle(
				static_cast<int>(vertex_[RT].x),
				static_cast<int>(vertex_[RT].y),
				static_cast<int>(vertex_[LB].x),
				static_cast<int>(vertex_[LB].y),
				static_cast<int>(vertex_[RB].x),
				static_cast<int>(vertex_[RB].y),
				GetColor(color_),
				kFillModeSolid
			);
		}
	}
	
}
