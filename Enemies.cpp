#include "Enemies.h"
#include<iostream>



Enemies::Enemies(float x_pos, float velX, float velY)
	: rect{ x_pos, 700.f, 40.f,50.f , }, velocity{ velX, velY }, health{ 100 }{
}
Rectangle Enemies::GetRect() {
	return rect;
}

//Enemies::Enemies() : rect{ 300, 645, 30,40 }, velocity{ 2,0 }, health{ 100 } {}

 Enemies::~Enemies() {

}
  int Enemies::getHealth() {
	  return health;

 }

 
  
 void Enemies::Draw() {
	  DrawRectangle(static_cast<int>(rect.x),static_cast<int>(rect.y) , static_cast<int>(rect.width), static_cast<int>(rect.height), BLUE);
	 
 }

 void Enemies::Move() {
	 float frameTime = GetFrameTime();
	 
	 rect.x += velocity.x * frameTime * 50.0f;
		
	  // change direction based on position
	 if (rect.x >= 689 || rect.x <= 0) {
		 velocity.x = -velocity.x;
		 std::cout << "Rectangle changed direction at x:" << rect.x << std::endl;
	 }
 }
 void Enemies::takeDamage(int damage)
 {
	health -= damage;
	 if (health < 0)health = 0;

 }
 void Enemies::gainHealth(int energy) {
	 health += energy;
	 if (health > 100) health = 100;


 }
