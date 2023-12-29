#pragma once
#include "Particle.h"
#include "Vector2.h"
#include "GetColor.h"
class Player;

class ShockWave :public Particle {

	enum vertex {
		LT,
		RT,
		LB,
		RB
	};

	ShockWave(Vector2 acceleration);
	void VertexUpdate();
	void Spawn() override;
	void Update();
	void Draw();
private:
	Player *player_;
	Vector2 vertex_[4];
	Vector2 acceleration_;
};

