//
//  level.cpp
//  Untitled_Zombie
//
//  Created by Matthew Broton on 11/22/16.
//  Copyright © 2016 Matthew Broton. All rights reserved.
//

#include "level.hpp"

Level::Level(int level,SDL_Renderer * renderer){
    currentLevel = level;
    loadLevel( level , renderer);
}

void Level::update(){
}

void Level::draw(SDL_Renderer * renderer){
    SDL_RenderCopy(renderer, background_1, &background_1_Rect, NULL );
    
    for(int i = 0; i < xtiles; i++){
        for(int j = 0; j < ytiles; j++){
            if( tilemap[i][j] != NULL ){
                tilemap[i][j]->draw(renderer);
            }
        }
    }
}

void Level::clearTiles(){
    for(int i = 0; i < xtiles; i++ ){
        for(int j = 0; j < ytiles; j++ ){
            tilemap[i][j] = NULL;
        }
    }
}

void Level::createTileMap(int width, int height){
    tilemap = new Tile **[width];
    for(int i = 0; i < width; i++){
        tilemap[i] = new Tile*[height];
    }
    xtiles = width;
    ytiles = height;
    clearTiles();
}

void Level::loadLevel(int level, SDL_Renderer * renderer){
    switch(level){
        case 0:
            createTileMap(50, 20);
            
            tilemap[0][0] = new Tile(renderer, (char*)"images/objects/tiles/tinTile.png",0,0);
            tilemap[3][3] = new Tile(renderer, (char*)"images/objects/tiles/tinTile.png",3*sTiles,3*sTiles);
            tilemap[6][7] = new Tile(renderer, (char*)"images/objects/tiles/tinTile.png",6*sTiles,7*sTiles);

            tilemap[0][1] = new Tile(renderer, (char*)"images/objects/tiles/tinTile.png",6*sTiles,7*sTiles);
           
            background_1 = IMG_LoadTexture(renderer, "images/levels/level0/whiteBackground.png");
            background_1_Rect.x = 0;
            background_1_Rect.y = 0;
            background_1_Rect.w = 800;
            background_1_Rect.h = 480;
            
            break;
        case 1:
            break;
        case 2:
            break;
        default:
            break;
    }
}

void Level::destroyLevel(){
    SDL_DestroyTexture(background_1);
    for(int i = 0; i < xtiles ;i++){
        delete[] tilemap[i];
    }
    delete[] tilemap;
}

Level::~Level(){
}