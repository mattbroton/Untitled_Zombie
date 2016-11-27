//
//  tile.cpp
//  Untitled_Zombie
//
//  Created by Matthew Broton on 11/23/16.
//  Copyright © 2016 Matthew Broton. All rights reserved.
//

#include "tile.hpp"

Tile::Tile(SDL_Renderer * renderer, char * file_path, int x,int y){
    printf("this got called\n");
    texture = IMG_LoadTexture(renderer, file_path);
    texture_rect.x = x;
    texture_rect.y = y;
    texture_rect.w = 16*3;
    texture_rect.h = 16*3;
}

void Tile::update(){
}

void Tile::draw(SDL_Renderer * renderer){
    SDL_RenderCopy(renderer, texture, NULL, &texture_rect);
}

Tile::~Tile(){
}
