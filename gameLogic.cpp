#include "gameLogic.h"
#include <iostream>



gameLogic::gameLogic() : run{ true } {};

bool gameLogic::isRunning() {
	return run;
}


  void gameLogic::checkTeabagCollision(TeabagUpdate& teabag, Enemies& enemy) {
	for (int i = 0; i < MAX_TEABAGS; ++i) {


		if (teabag.teabagObjects[i].active) {
			Rectangle teabagHitBox = teabag.teabagObjects[i].getHitBox();
			if (CheckCollisionRecs(teabagHitBox, enemy.GetRect())) {
				
				//deactivate teabags from array
				enemy.takeDamage(20);
				std::cout << "collision dedected" << enemy.getHealth() <<std::endl;
				teabag.teabagObjects[i].active = false;
				
			}
		}
	}
}

  void gameLogic::checkCherryCollision(TeabagUpdate& cherry, Enemies& enemy) {
	for (int i = 0; i < MAX_CHERRY; ++i) {
		if (cherry.cherryObjects[i].active) {
			Rectangle cherryHitbox = cherry.cherryObjects[i].CherryHitbox();
			if (CheckCollisionRecs(cherryHitbox, enemy.GetRect())){
				//deactivate cherries from array
				enemy.gainHealth(20);
				std::cout << "cherry collision" << enemy.getHealth()<< std::endl;
				cherry.cherryObjects[i].active = false;
			}

		
		}
	}
}

 void gameLogic::gameOverMessage(std::string_view message) {
	 BeginDrawing();
	 ClearBackground(BLACK);
	 DrawText(message.data(), 35, 300, 20, BLUE);
	 EndDrawing();
 }

 void gameLogic::gameOver(TeabagUpdate& teabag, Enemies& enemy) {
	 if (teabag.CheckRemainingTeabags() == 0) {
		 float timer = 0.0f;
		 while (timer < 4.0f) {
			 gameOverMessage("There are no more teabags left!Sorry you have lost!!");
			 timer += GetFrameTime();
		 }
		 run = false;

	 }
	 else if (enemy.getHealth() == 0) {
		 float timer = 0.0f;
		 while (timer < 4.0f) {
			 gameOverMessage("There are no more teabags left! Sorry you have lost!!");
			 timer += GetFrameTime();
		 }
		 run = false;
	 }
 }
	
