#include "Ghost.h"

Ghost::Ghost()
{
    m_rect = new SDL_Rect;
    m_rect->x = rand() % 1200;
    m_rect->y = rand() % 760;
    m_rect->w = 64;
    m_rect->h = 44;
    current_frame = 0;
    id = "ghost";
    ghost_state = GHOST_FLY;
}
SDL_Rect* Ghost::Get_Rect()
{
    return m_rect;
}

void Ghost::update_pos(Character* player)
{
    if (player->Get_Hitbox()->x > m_rect->x)
    {
        m_rect->x ++;
        flip_flag = SDL_FLIP_NONE;
    }
    else
    {
        m_rect->x --;
        flip_flag = SDL_FLIP_HORIZONTAL;
    }

    if (player->Get_Hitbox()->y > m_rect->y) m_rect->y ++;
    else m_rect->y --;

    if (ghost_state == GHOST_FLY)
    {
        current_frame = (SDL_GetTicks() / 50) % GHOST_FLY_FRAME;
    }

    else if (ghost_state ==  GHOST_DEATH)
    {
        current_frame++;
        if(current_frame >= GHOST_DEATH_FRAME) current_frame = GHOST_DEATH_FRAME;
        id = "ghost_death";
    }

}

