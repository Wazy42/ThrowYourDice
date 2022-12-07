#pragma once

// Assets path
#define ASSETS_PATH "assets/"

// FPS
#define FPS 60

// Fonts path
#define FONT_PATH ASSETS_PATH ## "fonts/"
#define FONT_SPINWERARD FONT_PATH ## "spinwerad.ttf"
#define FONT_SPINWERARD_CAPITALIZE FONT_PATH ## "spinweradC.ttf"

// Textures path
#define TEXTURE_PATH ASSETS_PATH ## "textures/"

// Sounds path
#define SOUND_PATH ASSETS_PATH ## "sounds/"

// Sizes
#define SIZE_TILE 32

// Animation
#define ANIMATION_DOWN 0
#define ANIMATION_UP 1
#define ANIMATION_RIGHT 2
#define ANIMATION_LEFT 3

// Draw
#define LAYER_UP 10 // Drawn on top of everything
#define LAYER_DECORATION 8
#define LAYER_ANIMATIONS_UP 7 // Animated
#define LAYER_OBSTACLES 6
#define LAYER_BEINGS 5 // Animated
#define LAYER_UNDER_BEINGS 4
#define LAYER_ANIMATIONS_DOWN 3 // Animated
#define LAYER_FURNITURE 2
#define LAYER_GROUND 1
#define LAYER_DOWN 0 // Drawn under everything
