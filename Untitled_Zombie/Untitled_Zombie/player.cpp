//
//  player.cpp
//  Untitled_Zombie
//
//  Created by Matthew Broton on 11/23/16.
//  Copyright © 2016 Matthew Broton. All rights reserved.
//

#include "player.hpp"

Player::Player(SDL_Renderer * renderer, int x,int y, int cHealth, int mHealth) : sprite(renderer, (char*)"images/player/stickguy.png", x, y, 16*3, 32*3) {
    xpos = x;
    ypos = y;
    
    xvel = 0;
    yvel = 0;
    
    currentHealth = cHealth;
    maxHealth = mHealth;
}

void Player::startMovingLeft(){
    xvel = -walkingVelocity;
}

void Player::startMovingRight(){
    xvel = walkingVelocity;
}

void Player::stopMoving(){
    xvel = 0;
}

void Player::jump(){
    if( yvel == 0 ){
        yvel = -10;
    }
}


void Player::update(){
    xpos += xvel;
    ypos += yvel;
    sprite.update(xpos, ypos);
}

void Player::draw(SDL_Renderer * renderer){
    sprite.draw(renderer);
}

void Player::updateHealth(int change){
    currentHealth += change;
}

bool Player::checkHealth(){
    if( currentHealth <= 0 ){
        return true;
    }
    return false;
}