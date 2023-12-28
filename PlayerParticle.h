#pragma once
#include "Particle.h"
class Player;
class PlayerParticle :public Particle {
public:
	PlayerParticle(Player *player);
	bool GetIsAlive() { return isAlive_; };
	void Spawn() override;
	void Update(char *keys) override;
	void Draw() override;
private:
	Player *player_;
	const int spawnMax_ = 19;
	Vector2 beforePos_[20];
	bool isHitSpaceKey_;
};

