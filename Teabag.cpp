#include "Teabag.h"


Teabag::Teabag()
	:teabag{0}, positions {0, 0}, speed{ 5 }, active{ false } {}

void Teabag::Initialize(Vector2 startPos, Texture2D tex) {
	positions = startPos;
	teabag = tex;
	active = true;
}
	

void Teabag::DrawTeabag() 
{
	if (active) 
	{
		DrawTextureV(teabag,positions, WHITE);
		
	}

}
void Teabag::UpdateTeabag()
{
	if (active) {
		positions.y += speed;
		
		// set the object inactive when if falls out of the screen
		if (positions.y > GetScreenHeight()) {
			active = false;
		}
	}
}
Rectangle Teabag::getHitBox() {
	return{ positions.x, positions.y, (float)teabag.width, (float)teabag.height };
}

