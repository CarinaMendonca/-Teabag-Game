#include "TeabagUpdate.h"

TeabagUpdate::TeabagUpdate(const char* teabagImage, const char* cherryImage)
    :teabags{ LoadTexture(teabagImage) }, cherries{ LoadTexture(cherryImage) }, teabagObjects{}, cherryObjects{}, cherryTimer{ 0.0f },remainingTeabags{MAX_TEABAGS}, remainingCherries{MAX_CHERRY}
{
   
    for (int i = 0; i < MAX_TEABAGS; i++) {
        teabagObjects[i] = Teabag();
    }
    for (int i = 0; i < MAX_CHERRY; i++) {
        cherryObjects[i] = Cherry();
    }
}
//default constructor for gameLogic class
TeabagUpdate::TeabagUpdate() {
    for (int i = 0; i < MAX_TEABAGS; i++) {
        teabagObjects[i] = Teabag();
    }
    for (int i = 0; i < MAX_CHERRY; ++i) {
        cherryObjects[i] = Cherry();
    }
}

TeabagUpdate::~TeabagUpdate() {
    UnloadTexture(teabags);
    UnloadTexture(cherries);
}
int TeabagUpdate::GetRemainingObjects(int& attribute) {
    if (attribute > 0) {
         return attribute--;
     }
    return 0;
}
TeabagUpdate teabagUpdate;
int remainingTeabags = teabagUpdate.GetRemainingObjects(remainingTeabags);
int remainingCherries = teabagUpdate.GetRemainingObjects(remainingCherries);
  
int TeabagUpdate::CheckRemainingTeabags()const {
    return remainingTeabags;
}
    


void TeabagUpdate::SpawnTeabag(Vector2 startPos){
    for (int i = 0; i < MAX_TEABAGS; ++i) {
        if (!teabagObjects[i].active) {
            teabagObjects[i].Initialize(startPos,teabags);
           
            break;
        }
    }
}

void TeabagUpdate::SpawnCherry(Vector2 startP) {
    for (int i = 0; i < MAX_CHERRY; i++) {
        if (!cherryObjects[i].active) {
            cherryObjects[i].InitCherry(startP, cherries);

            break;
        }
    }
}
void TeabagUpdate::TUpdate() {
    for (int i = 0; i < MAX_TEABAGS; i++) {
        if (teabagObjects[i].active) {
            teabagObjects[i].UpdateTeabag();
            //break;
        }
    }
}
void TeabagUpdate::UpdateCherries() {
    for (int i = 0; i < MAX_CHERRY; i++) {
        if(cherryObjects[i].active) {
            cherryObjects[i].UpdateCherry();
            
        }
    }
}

void TeabagUpdate::CherryUpdate() {
    cherryTimer += GetFrameTime();
    if (cherryTimer >= 5.0f) {
        // Reset the timer
        cherryTimer = 0.0f;

        //cherries will fall randomly without any input from user
        float randomX = GetRandomValue(0.0f, GetScreenWidth() - cherries.width);// get a random x position to spawn cherries
        Vector2 startP = { randomX , 0.0f };
        SpawnCherry(startP);
        GetRemainingObjects(remainingCherries);
    }
    UpdateCherries();
    
}



  


void TeabagUpdate::TeabagDraw(){ 
    for (int i = 0; i < MAX_TEABAGS; ++i) 
    { 
        if (teabagObjects[i].active) 
        { 
            teabagObjects[i].DrawTeabag(); 
        } 
    } 
}

void TeabagUpdate::CherryDraw() {
    for (int i = 0; i < MAX_CHERRY; i++) {
        if (cherryObjects[i].active) {
            cherryObjects[i].DrawCherry();
            
        }
    }
}
void TeabagUpdate::DropTeabag() {
     if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
       float mouseX= GetMousePosition().x;
       Vector2 startPos = { mouseX,0.0f };
       SpawnTeabag(startPos);
       int remaining = teabagUpdate.GetRemainingObjects(remainingTeabags);

     }
 }

