//
//  inventory.hpp
//  Untitled_Zombie
//
//  Created by Matthew Broton on 11/23/16.
//  Copyright © 2016 Matthew Broton. All rights reserved.
//

#ifndef inventory_hpp
#define inventory_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include "SDL2_image/SDL_image.h"

struct inventoryObject{
    
    inventoryObject(SDL_Renderer * renderer, char * file_path);
    ~inventoryObject();
    
    // add some kind of object identifier
    
    int xloc;
    int yloc;
    int itemWidth;
    int itemHeight;
    
    int rotation; // 0 up, 1 right, 2 down, 3 left
    
    int stackable; // 0 for no. only 1 ever, 1 for yes. multiple weapons allowed, 2 for weapon. show ammount in clip
    int amount;
    
    SDL_Texture * itemTexture;
    SDL_Rect * src;
    SDL_Rect * dest;
    
    void rotate();
    
    void draw(SDL_Renderer * renderer);
};

struct Inventory{
    
    Inventory(SDL_Renderer * renderer, int width, int height);
    
    void removeItem(int x, int y);
    void deleteItem(int x, int y);
    
    void resize(int newwidth, int newheight);
    void freeInventory(inventoryObject *** inv);
    
    void moveUp();
    void moveRight();
    void moveDown();
    void moveLeft();

    bool addItem(inventoryObject * newItem);
    
    void interactItem();
    
    bool isFree(int x, int y, int width, int height);
        
    bool placeItem();
    
    // returns true if can close inventory
    bool closeInventory();
    
    inventoryObject * findNextObject(int cx, int cy, int dir);
    
    void pickUpItem();

    void clearInventory();
    
    void draw(SDL_Renderer * renderer);
    
    void drawSelector(SDL_Renderer * renderer, SDL_Rect temp, int x, int y);
    
    bool isValidSpot(int x, int y );
    bool isSpotFree(int x, int y );
    
    
    void placeItemHelper(inventoryObject * item);
    
    // returns true if item was placed
    bool placeItem(inventoryObject * item);

    
    ~Inventory();
    
    private:
        int px;
        int py;
    
        int holding; // if you are currently holding an item. can't close until you do something with it
        inventoryObject * heldObject;
    
        int xunits;
        int yunits;
        inventoryObject *** objects;
    
        SDL_Texture * inventoryBackground;
        SDL_Texture * iunitTexture;
        SDL_Texture * inventorySelector;
    
        int iunitSize;
};


#endif /* inventory_hpp */
