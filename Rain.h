#pragma once
#include "Particle.h"
#include "Cloud.h"

class Rain :public Particle {
public:
	Rain();
	bool GetIsAlive() { return isAlive_; };
	void Spawn(Cloud cloud);
	void Update() override;
	void Draw() override;

private:
	Vector2 endPos_;
	float gravity_;

};

