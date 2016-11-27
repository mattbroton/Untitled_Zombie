//
//  input.hpp
//  Untitled_Zombie
//
//  Created by Matthew Broton on 11/23/16.
//  Copyright © 2016 Matthew Broton. All rights reserved.
//

#ifndef input_hpp
#define input_hpp

#include <stdio.h>
#include <map>
#include <SDL2/SDL.h>

using namespace std;

struct Input{
    
    void beginNewFrame();
    
    void keyDownEvent(SDL_Event &event);
    void KeyUpEvent(SDL_Event &event);
    
    bool wasKeyPressed(SDL_Keycode key);
    bool wasKeyReleased(SDL_Keycode key);
    bool isKeyHeld(SDL_Keycode key);
    
    private:
    map<SDL_Keycode,bool> held_keys;
    map<SDL_Keycode,bool> pressed_keys;
    map<SDL_Keycode,bool> released_keys;
};


#endif /* input_hpp */
