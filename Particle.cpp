#include "Particle.h"
#include "Novice.h"

int Particle::GetColor(Color color) {
	unsigned int result;
	color.red <<= 24;
	color.green <<= 16;
	color.blue <<= 8;
	result = (color.red | color.green | color.blue | color.alpha);

	return result;
}

void Particle::Spawn() {
}

void Particle::Update(char *keys) {
	if (keys[DIK_0]) {

	}
}

void Particle::Draw() {
}
