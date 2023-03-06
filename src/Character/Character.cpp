#include "Character.h"
Character::Character()
{
    // default rectangle for frames properties
    m_rect = new SDL_Rect;
    m_rect->x = 400;
    m_rect->y = 500;
    m_rect->w = FRAME_SIZE;
    m_rect->h = FRAME_SIZE;

    // default hit box properties
    m_hitbox = new SDL_Rect;
    m_hitbox->x = 400;
    m_hitbox->y = 500;
    m_hitbox->w = PLAYER_WIDTH;
    m_hitbox->h = PLAYER_HEIGHT;

    // default position, velocity, acceleration
    player_pos.x = 500.f;
    player_pos.y = 500.f;

    player_vel.x = 0.f;
    player_vel.y = 0.f;

    player_acc.x = 5.f;
    player_acc.y = -15.f;

    // default state
    character_state = IDLE;
    id = "idle";
    current_frame = 0;
    max_frame = IDLE_FRAMES;

    is_jumpping = false;
}

SDL_Rect* Character::Get_Rect()
{
    return m_rect;
}

SDL_Rect* Character::Get_Hitbox()
{
    return m_hitbox;
}

// position and event
void Character::Character_Handle(SDL_Event& event)
{
    // get keystate from keyboard
    const Uint8* keystate = SDL_GetKeyboardState(NULL);

    // if no input from keyboard;
    player_vel.x = 0.f;
    if (is_jumpping) id = "jump";
    else id = "idle";

    // left move
    if (keystate[SDL_SCANCODE_D])
    {
        player_vel.x += player_acc.x;
        id = "run";
        flip_flag = SDL_FLIP_NONE;
        max_frame = RUN_FRAMES;
    }

    // right move
    if (keystate[SDL_SCANCODE_A])
    {
        player_vel.x -= player_acc.x;
        id = "run";
        flip_flag = SDL_FLIP_HORIZONTAL;
        max_frame = RUN_FRAMES;
    }

    // jumping
    if (keystate[SDL_SCANCODE_W] && !is_jumpping)
    {
        player_vel.y = player_acc.y;
        is_jumpping = true;
        max_frame = JUMP_FRAMES;
    }

    // update frame
    current_frame = (SDL_GetTicks() / 50) % max_frame;

}

void Character::Update_Position(float dt)
{
    // gravity
    player_vel.y += (float)GRAVITY * dt;


    // update position by time
    player_pos.x += player_vel.x * dt;
    player_pos.y += player_vel.y * dt;


    // no falling out of background
    if (player_pos.y + m_hitbox->h >= 640.f)
    {
        player_pos.y = 640.f - m_hitbox->h;
        player_vel.y = 0.f;
        is_jumpping = false;
    }

    // update hitbox and rectangle frame
    m_hitbox->x = (int)player_pos.x;
    m_hitbox->y = (int)player_pos.y;

    m_rect->x = m_hitbox->x - (FRAME_SIZE - PLAYER_WIDTH) / 2;
    m_rect->y = m_hitbox->y - (FRAME_SIZE - PLAYER_HEIGHT) / 2;
}

void Character::set_y_vel(float replace_y_vel)
{
    player_vel.y = replace_y_vel;
}

void Character::set_y_pos(float replace_y_pos)
{
    player_pos.y = replace_y_pos;
}

float Character::get_y_vel()
{
    return player_vel.y;
}

// in case character die
void Character::reset_pos()
{
    m_hitbox -> x = 100;
    m_hitbox -> y = 640;
}



