//
//  level.hpp
//  Untitled_Zombie
//
//  Created by Matthew Broton on 11/22/16.
//  Copyright © 2016 Matthew Broton. All rights reserved.
//

#ifndef level_hpp
#define level_hpp

#include <stdio.h>

#include <stdio.h>
#include <SDL2/SDL.h>
#include "SDL2_image/SDL_image.h"
#include "tile.hpp"

static int sTiles = 16;

struct Level{
    Level(int level,SDL_Renderer * renderer);
    
    void update();
    void draw(SDL_Renderer * renderer);
    void loadLevel(int level, SDL_Renderer * renderer );
    void destroyLevel();
    void clearTiles();
    void createTileMap(int width, int height);
    
    ~Level();
    
private:
    int currentLevel;
    SDL_Texture * background_1;
    SDL_Rect background_1_Rect;
    
    SDL_Texture * background_2;
    SDL_Rect background_2_Rect;
    
    SDL_Texture * background_3;
    SDL_Rect background_3_Rect;
    
    int xtiles,ytiles;
    
    Tile *** tilemap;
};

#endif /* level_hpp */
