//
//  tile.hpp
//  Untitled_Zombie
//
//  Created by Matthew Broton on 11/23/16.
//  Copyright © 2016 Matthew Broton. All rights reserved.
//

#ifndef tile_hpp
#define tile_hpp

#include <stdio.h>
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"

struct Tile{
    
    Tile(SDL_Renderer * renderer, char * file_path, int x, int y);
    
    void update();
    void draw(SDL_Renderer * renderer);
    
    ~Tile();
    
    private:
        SDL_Texture * texture;
        SDL_Rect texture_rect;
};

#endif /* tile_hpp */