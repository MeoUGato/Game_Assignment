#include "MouseCursor.h"

MouseCursor::MouseCursor()
{
    Mouse_Rect.x = 0;
    Mouse_Rect.y = 0;
    Mouse_Rect.w = 64;
    Mouse_Rect.h = 64;

    Sword_Rect.x = 0;
    Sword_Rect.y = 0;
    Sword_Rect.w = 44;
    Sword_Rect.h = 128;

    is_call = false;
}


void MouseCursor::Update()
{
    int x, y;
    SDL_GetMouseState(&x, &y);

    Mouse_Rect.x = x;
    Mouse_Rect.y = y;

}

void MouseCursor::Call_CyberSword(SDL_Event& events)
{
    if (events.button.button == SDL_BUTTON_LEFT)
    {
        is_call = true;
        Sword_Rect.x = Mouse_Rect.x;
        Sword_Rect.y = Mouse_Rect.y;
    }
}

void MouseCursor::Sword_Falling()
{
    Sword_Rect.y += 20;
    if (Sword_Rect.y + Sword_Rect.h >= 640) is_call = false;
}
