#pragma once
#include "raylib.h"

class Teabag

{private:
	Texture2D teabag;
    Vector2 positions;
	int speed;
public:
	
	bool active;
	Teabag();
	void Initialize(Vector2 startPos, Texture2D tex);
	//void unload();
     void DrawTeabag();
	 void UpdateTeabag();
	 Rectangle getHitBox();
};

