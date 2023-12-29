#pragma once
#include "Vector2.h"
#include "GetColor.h"
class Cloud {
public:
	Cloud(Vector2 pos,Vector2 size,Color color);
	Vector2 GetPos() { return pos_; };
	Vector2 GetSize() { return size_; };
	int GetColor(Color color);
	void Update();
	void Draw();
private:
	Vector2 pos_;
	Vector2 size_;
	Vector2 velosity_;
	Color color_;
};

