#pragma once
#include "raylib.h"
#include "Teabag.h"
#include "cherry.h"

constexpr int MAX_TEABAGS = 20;
constexpr int MAX_CHERRY = 10;

class TeabagUpdate
{private:
	Texture2D teabags;
	Texture2D cherries;
	float cherryTimer;
public:
	int remainingTeabags;
	int remainingCherries;
	int CheckRemainingTeabags()const;
	Teabag teabagObjects[MAX_TEABAGS];
	Cherry cherryObjects[MAX_CHERRY];
	TeabagUpdate(const char* teabagImage, const char* cherryImage);
	TeabagUpdate();
	~TeabagUpdate();
	int GetRemainingObjects(int& attribute);
	void TUpdate();
	void UpdateCherries();
	void CherryUpdate();
	void SpawnTeabag(Vector2 startPos);
	void SpawnCherry(Vector2 startP);
	void TeabagDraw();
	void CherryDraw();
	void DropTeabag();
	
	
};

