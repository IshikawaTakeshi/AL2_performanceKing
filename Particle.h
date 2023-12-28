#pragma once
#include "GetColor.h"
#include "Vector2.h"

class Particle {
public:
	int GetColor(Color color);
	bool GetIsAlive_() { return isAlive_; };
	virtual void Spawn();
	virtual void Update(char *keys);
	virtual void Draw();
protected:
	Vector2 pos_;
	//Vector2 beforePos_[20];
	Vector2 size_;
	Vector2 velocity_;
	Color color_;
	//BlendMode blendMode_ = kBlendModeNone;
	bool isAlive_;
};

