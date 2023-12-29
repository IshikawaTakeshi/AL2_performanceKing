#pragma once
#include "Novice.h"
#include "Vector2.h"
#include "GetColor.h"

class Player {
public:
	Player(Vector2 pos,Vector2 size, Color color,bool isAlive);
	void VertexUpdate();

	int GetColor(Color color);
	
	Vector2 GetPos() { return pos_; };

	bool GetIsAlive() { return isAlive_; };
	void Spawn();
	void Update(char *keys);
	void Draw();

private:
	Vector2 pos_;
	Vector2 size_;
	//Vector2 vertex_[4];
	Vector2 velocity_;
	Color color_;
	//BlendMode blendMode_ = kBlendModeNone;
	float gravity_;
	bool isAlive_;
	int gh_;
};

