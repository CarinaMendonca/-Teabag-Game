# include "cherry.h"


Cherry::Cherry()
    :cherry{ 0 }, positions{0 , 0 }, speed{ 6 }, active{ false } {}


void Cherry::InitCherry(Vector2 startP, Texture2D image) {
	positions = startP;
	cherry = image ;
	active = true;
}

void Cherry::DrawCherry()
{
	if (active)
	{
		DrawTextureV(cherry, positions, WHITE);

	}

}

void Cherry::UpdateCherry() {
	if (active) {
		positions.y += speed;

		// set the object inactive when if falls out of the screen
		if (positions.y > GetScreenHeight()) {
			active = false;
		}
	}
}

Rectangle Cherry::CherryHitbox() {
	return{ positions.x, positions.y, (float)cherry.width, (float)cherry.height };
}


