#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <iostream>


#include "LoadTexture.h"
#include "GameEvent.h"
#include "Character.h"
#include "Timer.h"
#include "Ghost.h"
#include "MouseCursor.h"

const int SCREEN_WIDTH = 1260;
const int SCREEN_HEIGHT = 720;

const int BACKGROUND_LAYER = 5;


const char* WINDOW_TITLE = "FIORA GRAND CHALLENGE";


SDL_Window* g_window = NULL;
SDL_Renderer* g_renderer = NULL;
GameEvent game_update;
bool is_running = true;
LoadTexture g_background;
Timer time_manage;
Character player;
MouseCursor mouse;
float current_time = 0.f;
float prev_time = 0.f;
float delta_time = 0.f;
