#include "GameEvent.h"

void GameEvent::AddEnemy()
{
    SDL_Rect *tmp_rect = new SDL_Rect;
    tmp_rect->w = 50;
    tmp_rect->h = 32;
    int last_y_pos = 30;
    for (int i = 1; i <= 10; i++)
    {
        tmp_rect->x = rand() % 1260;
        tmp_rect->y = last_y_pos;
        last_y_pos += 50;

        // adding enemy

        enemies.push_back(Enemy(*tmp_rect));
    }
}


bool GameEvent::CheckCollision(const SDL_Rect& rect1, const SDL_Rect& rect2)
{
    int left1 = rect1.x;
    int right1 = rect1.x + rect1.w;
    int top1 = rect1.y;
    int bot1 = rect1.y + rect1.h;

    int left2 = rect2.x;
    int right2 = rect2.x + rect2.w;
    int top2 = rect2.y;
    int bot2 = rect2.y + rect2.h;

    if (left1 > right2 || left2 > right1 || top1 > bot2 || top2 > bot1) return false;
    return true;
}

void GameEvent::Check_Player_And_Ghostball(Character& player, Enemy& ghostball)
{
    if (CheckCollision(*player.Get_Hitbox(), *ghostball.Get_Rect()))
    {
        hp_player--;
        if (hp_player == 0) player.reset_pos();
        return;
    }
}

void GameEvent::AddGhost()
{
    for (int i = 1; i <= 2; i++)
    {
        ghosts.push_back(Ghost());
    }
}

bool GameEvent::Check_PLayer_And_Ghost(Character& player, Ghost& ghost)
{


}

bool GameEvent::Check_Player_And_Block(Character& player)
{
    int x_pos = player.Get_Hitbox()->x;
    int r_width = player.Get_Hitbox()->w;

    int y_pos = player.Get_Hitbox()->y;
    int r_height = player.Get_Hitbox()->h;


    for (SDL_Rect& block : blocks)
    {
        if ((x_pos >= block.x - r_width) && (x_pos <= block.x + block.w)
            && (y_pos <= block.y - r_height)
            && (player.get_y_vel() >= 0.f))
        {
            player.is_jumpping = false;
            player.set_y_vel(2.f);
            if (y_pos + r_height >= block.y && y_pos + r_height <= block.y + block.h)
              player.set_y_pos((float)block.y - (float)player.Get_Hitbox()->h),
              player.set_y_vel(0.f);

        }
    }
    return false;
}










