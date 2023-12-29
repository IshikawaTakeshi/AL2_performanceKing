#pragma once
#define _USE_MATH_DEFINES
#include "math.h"


float Liner(float startPos,float endPos, float easedT) {
	return (1.0f - easedT) * startPos + easedT * endPos;
}

float EaseOutSine(float x) {
	return sinf((x * float(M_PI)) / 2.0f);
}

float EaseInSine(float x) {
	return 1.0f - cosf((x * float(M_PI)) / 2.0f);
}
