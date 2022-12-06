#pragma once

// Assets path
#define ASSETS_PATH "assets/"

// Fonts path
#define FONT_PATH ASSETS_PATH ## "fonts/"
#define FONT_SPINWERARD FONT_PATH ## "spinwerad.ttf"
#define FONT_SPINWERARD_CAPITALIZE FONT_PATH ## "spinweradC.ttf"

// Textures path
#define TEXTURE_PATH ASSETS_PATH ## "textures/"
#define TEXTURE_CAT TEXTURE_PATH ## "cat.jpg"
#define TEXTURE_KNIGHT TEXTURE_PATH ## "knight.png"
#define TEXTURE_FLOOR1 TEXTURE_PATH ## "floor1.png"

// Sounds path
#define SOUND_PATH ASSETS_PATH ## "sounds/"

// Sizes
#define SIZE_TILE 32

// Draw
#define LAYER_UP 10 // Drawn on top of everything
#define LAYER_DECORATION_UP 9
#define LAYER_DECORATION_DOWN 8
#define LAYER_OBSTACLES 7
#define LAYER_ANIMATIONS 6
#define LAYER_BEINGS 5
#define LAYER_FURNITURE_UP 4
#define LAYER_FURNITURE_DOWN 3
#define LAYER_GROUND_UP 2
#define LAYER_GROUND_DOWN 1
#define LAYER_DOWN 0 // Drawn under everything