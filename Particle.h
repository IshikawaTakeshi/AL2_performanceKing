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
	Vector2 pos_ = { 0,0 };

	Vector2 size_ = { 0,0 };
	Vector2 velocity_ = { 0,0 };
	Color color_ = { 0,0,0,0 };
	//BlendMode blendMode_ = kBlendModeNone;
	bool isAlive_ = false;
};

