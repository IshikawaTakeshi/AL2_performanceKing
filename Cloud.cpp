#include "Cloud.h"
#include "Novice.h"

Cloud::Cloud(Vector2 pos, Vector2 size, Color color) {
	pos_ = pos;
	size_ = size;
	velosity_ = { 5,5 };
	color_ = color;
}

int Cloud::GetColor(Color color) {
	unsigned int result;
	color.red <<= 24;
	color.green <<= 16;
	color.blue <<= 8;
	result = (color.red | color.green | color.blue | color.alpha);

	return result;
}

void Cloud::Update() {
	pos_.x -= velosity_.x;
	if (pos_.x <= -100) {
		pos_.x = 1300;
	}
}

void Cloud::Draw() {
	Novice::DrawBox(
		static_cast<int>(pos_.x),
		static_cast<int>(pos_.y),
		static_cast<int>(size_.x),
		static_cast<int>(size_.y),
		0.0f,
		GetColor(color_),
		kFillModeSolid
	);
	Novice::DrawBox(
		static_cast<int>(pos_.x),
		static_cast<int>(pos_.y),
		static_cast<int>(size_.x),
		static_cast<int>(size_.y),
		0.0f,
		GetColor({0,0,0,255}),
		kFillModeWireFrame
	);
}
