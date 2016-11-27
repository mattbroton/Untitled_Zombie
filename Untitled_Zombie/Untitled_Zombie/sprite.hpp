//
//  sprite.hpp
//  Untitled_Zombie
//
//  Created by Matthew Broton on 11/22/16.
//  Copyright © 2016 Matthew Broton. All rights reserved.
//

#ifndef sprite_hpp
#define sprite_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include "SDL2_image/SDL_image.h"

struct Sprite{
    Sprite(SDL_Renderer * renderer, char * file_path,int x, int y, int width, int height);
    
    void update(int newx, int newy);
    
    void draw(SDL_Renderer * renderer);
    
    ~Sprite();
    
    private:
    SDL_Texture * sprite_sheet;
    SDL_Rect source_rect;
};


#endif /* sprite_hpp */
