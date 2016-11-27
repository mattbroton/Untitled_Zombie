//
//  main.cpp
//  Untitled_Zombie
//
//  Created by Matthew Broton on 11/21/16.
//  Copyright © 2016 Matthew Broton. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "input.hpp"
#include "sprite.hpp"
#include "player.hpp"
#include "inventory.hpp"
#include "level.hpp"
#include "cursor.hpp"

#include "mathStuff.hpp"

#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
//#include "SDL2_ttf/SDL_ttf.h"

// g++ "filename"
// ./"filename"

// special thanks to Christopher Hebert for creating the reconstruction of cave story videos
// https://www.youtube.com/watch?v=IufkC1IRY2Q&list=PL006xsVEsbKjSKBmLu1clo85yLrwjY67X

/*
 //SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
 //SDL_Surface * image = SDL_LoadBMP("image.bmp");
 // SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);
*/


int fps = 60;
SDL_Window * window;
SDL_Renderer * renderer;


// 16:9
int scale = 50;
int width = 16 * scale;
int height = 9 * scale;


int currentStage = 0;

char * gameTitle = (char *)"Untitled Zombie";

bool running;

Player * mainCharacter;
Inventory * myInv;
Level * currentLevel;
Cursor * myCursor;

int mouseX;
int mouseY;

// 4 stages. 0 = main menu. 1 = pause menu. 2 = gameplay. 3 = inventory

void update(Input &input){
    SDL_GetMouseState(&mouseX, &mouseY);
    if(input.wasKeyPressed(SDLK_ESCAPE)){
        running = false;
    }
    
    if(input.wasKeyPressed(SDLK_i)){
        printf("pressed i\n");
        if(currentStage == 3){
            currentStage = 2;
        }
        else if(currentStage == 2){
            currentStage = 3;
        }
        else{
            // do nothing?
        }
    }
    
    switch( currentStage ){
        case 0:
            break;
        case 1:
            break;
        case 2:
            mainCharacter->update();
            if( input.isKeyHeld(SDLK_a) && input.isKeyHeld(SDLK_d)){
                mainCharacter->stopMoving();
            }
            else if(input.isKeyHeld(SDLK_a)){
                mainCharacter->startMovingLeft();
            }
            else if(input.isKeyHeld(SDLK_d)){
                mainCharacter->startMovingRight();
            }
            else{
                mainCharacter->stopMoving();
            }
            break;
            
            
        case 3:
            if( input.wasKeyPressed(SDLK_a) && input.wasKeyPressed(SDLK_d)){
            }
            else if(input.wasKeyPressed(SDLK_a)){
                myInv->moveLeft();
            }
            else if(input.wasKeyPressed(SDLK_d)){
                myInv->moveRight();
            }
            else{
            }
            
            if( input.wasKeyPressed(SDLK_w) && input.wasKeyPressed(SDLK_s)){
            }
            else if(input.wasKeyPressed(SDLK_w)){
                myInv->moveUp();
            }
            else if(input.wasKeyPressed(SDLK_s)){
                myInv->moveDown();
            }
            else{
            }
            
            if(input.wasKeyPressed(SDLK_RETURN)){
                printf("enter was pressed\n");
                myInv->pickUpItem();
            }
            
            break;
        default:
            break;
    }
}

void draw(){
    SDL_RenderClear(renderer);
    // call for everything on the screen
    switch( currentStage ){
        case 0:
            break;
        case 1:
            break;
        case 2:
            currentLevel->draw(renderer);
            mainCharacter->draw(renderer);
            break;
        case 3:
            myInv->draw(renderer);
            break;
        default:
            break;
    }
    myCursor->draw(renderer);
    SDL_RenderPresent(renderer);
}


int invX = 10;
int invY = 4;

void init(){
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_JPG);
    window = SDL_CreateWindow(gameTitle, SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, width, height,SDL_WINDOW_OPENGL);
    renderer = SDL_CreateRenderer(window, -1, 0);
    
    mainCharacter = new Player(renderer,0,0,10,10);
    myInv = new Inventory(renderer, invX,invY);
    
    
    // need to make a menu at some point
    currentLevel = new Level(0,renderer);
    myCursor = new Cursor(renderer);
    
    SDL_ShowCursor(SDL_DISABLE);
}

void uninit(){
    delete mainCharacter;
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

void gameloop(){
    
    currentStage = 2;
    
    SDL_Event event;
    Input input;
    running = true;
    while(running){
        int start_time_ms = SDL_GetTicks();
        input.beginNewFrame();
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_KEYDOWN:
                    input.keyDownEvent(event);
                    break;
                case SDL_KEYUP:
                    input.KeyUpEvent(event);
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    break;
                case SDL_MOUSEBUTTONUP:
                    break;
                default:
                    break;
            }
        }
        
        update(input);
        draw();
        int elapsed_time_ms = SDL_GetTicks() - start_time_ms;
        int delayed_time_ms = 1000/fps - elapsed_time_ms;
        if( delayed_time_ms <= 0 ){
            delayed_time_ms = 0;
        }
        SDL_Delay( delayed_time_ms );
    }
}


int main(){
    
    init();
    gameloop();
    uninit();
    
    return 0;
}