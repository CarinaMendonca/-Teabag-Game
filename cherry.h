#pragma once
#include "raylib.h"

class Cherry
{
private:
	Texture2D cherry;
	Vector2 positions;
	int speed;
	
public:
	bool active;
	Cherry();
	void InitCherry(Vector2 startP, Texture2D image);
	void DrawCherry();
	void UpdateCherry();
	Rectangle CherryHitbox();
};