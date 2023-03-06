#ifndef GAMEEVENT_H
#define GAMEEVENT_H

#include "Enemy.h"
#include "Character.h"
#include <vector>
#include "SDL.h"
#include "SDL_image.h"
#include "Ghost.h"

class GameEvent
{
    public:
        GameEvent(){};

        void AddEnemy();
        void AddGhost();

        bool CheckCollision(const SDL_Rect& a, const SDL_Rect& b);

        void Check_Player_And_Ghostball(Character& player, Enemy& ghostball);

        bool Check_PLayer_And_Ghost(Character& player, Ghost& ghost);

        bool Check_Player_And_Block(Character& player);

        std::vector<Enemy> enemies;
        std::vector<Ghost> ghosts;
        std::vector<SDL_Rect> blocks {{75,178,130,30},{25,358,75,30},{75,460,150,30},{226,255,175,30},
        {275,410,125,30}, {480,330,75,30}, {455,510,100,30}, {680,180,150,30}, {605,255,75,30},
        {605,410,175,30}, {605,590,50,50}, {655,590,50,10}, {805,512,75,30}, {855,332,155,30},
        {1032,255,100,30}, {905,127, 130,30}, {1110, 75, 125, 30}};

        int hp_player = 10;
};

#endif // GAMEEVENT_H
