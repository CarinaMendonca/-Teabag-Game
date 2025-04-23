#pragma once
#include"raylib.h"
#include "TeabagUpdate.h"
#include "Enemies.h"
#include <string_view>



class gameLogic
{
  public:
	gameLogic();
	bool run;
	void checkTeabagCollision(TeabagUpdate& teabag, Enemies& enemy);
	void checkCherryCollision(TeabagUpdate& cherry, Enemies& enemy);
	void gameOverMessage(std::string_view);
	void gameOver(TeabagUpdate& teabag, Enemies& enemy);
	bool isRunning();
	

};

