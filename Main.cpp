#include "raylib.h"
#include "gameLogic.h"


int main() {
	const int windowHeight = 700;
	const int windowWidth = 750;


	InitWindow(windowHeight, windowWidth, "The Teabag Game");

	SetTargetFPS(60);

	Enemies enemy_1{ 300, 5, 0 };

	TeabagUpdate teabagUpdate{ "C:/New folder/The Teabag Game/Teabag_assets/teabag.png.png","C:/New folder/The Teabag Game/Teabag_assets/cherry.png" };
	gameLogic logic;


	while (!WindowShouldClose() && logic.isRunning()) {
		
		teabagUpdate.TUpdate();
		teabagUpdate.CherryUpdate();
		logic.checkTeabagCollision(teabagUpdate, enemy_1);
		logic.checkCherryCollision(teabagUpdate, enemy_1);
		logic.gameOver(teabagUpdate, enemy_1);
		int remainingTeabags = teabagUpdate.CheckRemainingTeabags();
		int totalTeabgs = MAX_TEABAGS;
		int enemyHealth = enemy_1.getHealth();
		int totalHealth = 100;

		BeginDrawing();
		ClearBackground(BLACK);

		DrawText(TextFormat(" remaining teabags: %d ", remainingTeabags), 8, 15, 20, BLUE);
		DrawText(TextFormat("enemy health: %d", enemyHealth), 8, 35, 20, BLUE);
		enemy_1.Draw();
		enemy_1.Move();

		teabagUpdate.TeabagDraw();
		teabagUpdate.DropTeabag();
		teabagUpdate.CherryDraw();

		EndDrawing();
	}
	CloseWindow();
}

	

