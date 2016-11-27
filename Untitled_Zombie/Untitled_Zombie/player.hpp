//
//  player.hpp
//  Untitled_Zombie
//
//  Created by Matthew Broton on 11/23/16.
//  Copyright © 2016 Matthew Broton. All rights reserved.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>

#include "sprite.hpp"
#include <cmath>

static float walkingVelocity = 1;
static float gravity = 1;

struct Player{
    
    Player(SDL_Renderer * renderer, int x,int y, int cHealth, int mHealth);
    
    void update();
    void draw(SDL_Renderer * renderer);
    
    void startMovingLeft();
    void startMovingRight();
    void stopMoving();
    
    void jump();
    
    // updates the players health by change amount
    void updateHealth(int change);
    
    // returns true if dead. false if otherwise
    bool checkHealth();
    
    void checkCollision();
    
    private:
        int xpos,ypos;
        float xvel,yvel;
        int currentHealth, maxHealth;
        Sprite sprite;
};

#endif /* player_hpp */
