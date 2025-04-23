#pragma once
#include "raylib.h"


class Enemies
{private:
	Rectangle rect;
	int health;
	Vector2 velocity;
	
	
	
public:
	//Enemies();
	Rectangle GetRect();
	Enemies(float x_pos, float vel_x, float vel_y);
	~Enemies();
	int getHealth();
    void Draw();
	void Move();
	void takeDamage(int damage);
	void gainHealth(int energy);

};

