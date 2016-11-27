//
//  cursor.cpp
//  Untitled_Zombie
//
//  Created by Matthew Broton on 11/26/16.
//  Copyright © 2016 Matthew Broton. All rights reserved.
//

#include "cursor.hpp"

Cursor::Cursor(SDL_Renderer * renderer){
    cursorTexture = IMG_LoadTexture(renderer, "images/player/cursor.png");
    cursorRect.x = 0;
    cursorRect.y = 0;
    cursorRect.w = 20;
    cursorRect.h = 20;
}

Cursor::~Cursor(){
}

void Cursor::draw(SDL_Renderer * renderer){
    int mX,mY;
    SDL_GetMouseState(&mX, &mY);
    cursorRect.x = mX - cursorRect.w/2+1;
    cursorRect.y = mY - cursorRect.h/2+1;
    SDL_RenderCopy(renderer, cursorTexture, NULL, &cursorRect);
}
