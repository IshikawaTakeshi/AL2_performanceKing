#pragma once
#include "Particle.h"
class Player;
class PlayerParticle :public Particle {
public:
	PlayerParticle(Player *player);
	bool GetIsAlive() { return isAlive_; };

	void Spawn() override;
	void Update();
	void Draw() override;
private:
	Player *player_;
	const int spawnMax_ = 10;
	int timer_;
};

