//
//  cursor.hpp
//  Untitled_Zombie
//
//  Created by Matthew Broton on 11/26/16.
//  Copyright © 2016 Matthew Broton. All rights reserved.
//

#ifndef cursor_hpp
#define cursor_hpp

#include <stdio.h>


#include <stdio.h>
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"


struct Cursor{
    Cursor(SDL_Renderer * renderer);
    ~Cursor();
    
    void draw(SDL_Renderer * renderer);
    
private:
    SDL_Texture * cursorTexture;
    SDL_Rect cursorRect;
};


#endif /* cursor_hpp */
