//
//  input.cpp
//  Untitled_Zombie
//
//  Created by Matthew Broton on 11/23/16.
//  Copyright © 2016 Matthew Broton. All rights reserved.
//

#include "input.hpp"


void Input::beginNewFrame(){
    pressed_keys.clear();
    released_keys.clear();
}


void Input::keyDownEvent(SDL_Event &event){
    pressed_keys[event.key.keysym.sym] = true;
    held_keys[event.key.keysym.sym] = true;
}

void Input::KeyUpEvent(SDL_Event &event){
    released_keys[event.key.keysym.sym] = true;
    held_keys[event.key.keysym.sym] = false;
}


bool Input::wasKeyPressed(SDL_Keycode key){
    return pressed_keys[key];
}

bool Input::wasKeyReleased(SDL_Keycode key){
    return released_keys[key];
}

bool Input::isKeyHeld(SDL_Keycode key){
    return held_keys[key];
}