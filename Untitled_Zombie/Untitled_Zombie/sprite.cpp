//
//  sprite.cpp
//  Untitled_Zombie
//
//  Created by Matthew Broton on 11/22/16.
//  Copyright © 2016 Matthew Broton. All rights reserved.
//

#include "sprite.hpp"


Sprite::Sprite(SDL_Renderer * renderer,char * file_path,int x, int y, int width, int height){
    sprite_sheet = IMG_LoadTexture(renderer, file_path);
    source_rect.x = x;
    source_rect.y = y;
    source_rect.w = width;
    source_rect.h = height;
}

void Sprite::update(int newx, int newy){
    source_rect.x = newx;
    source_rect.y = newy;
}

void Sprite::draw(SDL_Renderer * renderer){
    SDL_RenderCopy(renderer, sprite_sheet, NULL, &source_rect);
}

Sprite::~Sprite(){
    SDL_DestroyTexture(sprite_sheet);
}