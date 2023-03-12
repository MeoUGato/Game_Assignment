#include "MouseCursor.h"

MouseCursor::MouseCursor()
{
    Mouse_Rect.x = 0;
    Mouse_Rect.y = 0;
    Mouse_Rect.w = 64;
    Mouse_Rect.h = 64;


}


void MouseCursor::Update()
{
    int x, y;
    SDL_GetMouseState(&x, &y);

    Mouse_Rect.x = x;
    Mouse_Rect.y = y;

}


