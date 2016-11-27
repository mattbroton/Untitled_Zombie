//
//  inventory.cpp
//  Untitled_Zombie
//
//  Created by Matthew Broton on 11/23/16.
//  Copyright © 2016 Matthew Broton. All rights reserved.
//

#include "inventory.hpp"


double getAngle(int caseAngle){
    double r = 0;
    switch(caseAngle){
        case 0:
            r = 90;
            break;
        case 1:
            r = 0;
            break;
        case 2:
            r = 270;
            break;
        case 3:
            r = 180;
            break;
    }
    return r;
}

inventoryObject::~inventoryObject(){
}

void inventoryObject::draw(SDL_Renderer * renderer){
    // draw grid
    // draw weapons
    // draw inventory amount
    // draw held item
    // draw stats on the side
    SDL_Point point; // TODO: make sure this point is correct
    point.x = xloc;
    point.y = yloc;
    double angle = getAngle(rotation);
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    SDL_RenderCopyEx(renderer,itemTexture,src,dest,angle,&point,flip);
}

void Inventory::drawSelector(SDL_Renderer * renderer, SDL_Rect temp, int x, int y){
    temp.x = 20 + x*iunitSize;
    temp.y = 20 + y*iunitSize;
    temp.w = iunitSize;
    temp.h = iunitSize;
    SDL_RenderCopy(renderer, inventorySelector, NULL, &temp);
}

void Inventory::draw(SDL_Renderer * renderer){
    SDL_Rect temp;
    temp.x = 0;
    temp.y = 0;
    temp.w = 800;
    temp.h = 450;
    SDL_RenderCopy(renderer, inventoryBackground, NULL, &temp);
    
    temp.w = iunitSize;
    temp.h = iunitSize;
    
    for( int i = 0; i < xunits; i++ ){
        for( int j = 0; j < yunits ; j++){
            temp.x = 20 + iunitSize*i;
            temp.y = 20 + iunitSize*j;
            SDL_RenderCopy(renderer, iunitTexture, NULL, &temp);
        }
    }
    
    //TODO: can make this more effecient instead of redrawing all the weapons multiple times
    // draw all inventory objects here
    for( int i = 0; i < xunits; i++ ){
        for( int j = 0; j < yunits ; j++){
            if( objects[i][j] != NULL ){
                objects[i][j]->draw(renderer);
            }
        }
    }
    
    if( holding == 0 ){
        drawSelector(renderer, temp, px, py);
    }
    else{
        // draw the held weapon here
        objects[px][py]->draw(renderer);
        
        inventoryObject * c = objects[px][py];
        for(int i = 0; i < c->itemWidth; i++ ){
            for( int j = 0 ; j < c->itemHeight; j++){
                drawSelector(renderer, temp, px + i, py + j);
            }
        }
    }
}

inventoryObject * Inventory::findNextObject(int cx, int cy, int dir){
    switch(dir){
        case 0:
            cy += 1;
            cy = cy % yunits;
            if( objects[cx][cy] == NULL ){
                return NULL;
            }
            else{
                return objects[cx][cy];
            }
            break;
        case 1:
            cx += 1;
            cx = cx % xunits;
            if( objects[cx][cy] == NULL ){
                return NULL;
            }
            else{
                return objects[cx][cy];
            }
            break;
        case 2:
            cy -= 1;
            cy = cy % yunits;
            if( objects[cx][cy] == NULL ){
                return NULL;
            }
            else{
                return objects[cx][cy];
            }
            break;
        case 3:
            cx -= 1;
            cx = cx % xunits;
            if( objects[cx][cy] == NULL ){
                return NULL;
            }
            else{
                return objects[cx][cy];
            }
            break;
        default:
            break;
    }
    return NULL;
}

void Inventory::moveUp(){
    if(holding == 1 || objects[px][py] == NULL ){
        py -= 1;
        py = (py%yunits+yunits)%yunits;
    }
    else{
        inventoryObject * newObj = findNextObject(px, py, 0);
        if( newObj != NULL ){
            printf("(%d,%d),holding = %d\n",px,py,holding);
            px = newObj->xloc;
            py = newObj->yloc;
        }
        else{
            py -= 1;
            py = (py%yunits+yunits)%yunits;
        }
    }
    //printf("up:(%d,%d),holding = %d\n",px,py,holding);
}

void Inventory::moveRight(){
    if(holding == 1 || objects[px][py] == NULL ){ // if you are holding something or current space is empty
        px += 1;
        px = (px%xunits+xunits)%xunits;
    }
    else{ // if
        inventoryObject * newObj = findNextObject(px, py, 1);
        if( newObj != NULL ){
            px = newObj->xloc;
            py = newObj->yloc;
        }
        else{
            px += 1;
            px = (px%xunits+xunits)%xunits;
        }
    }
    //printf("right:(%d,%d),holding = %d\n",px,py,holding);
}

void Inventory::moveDown(){
    if(holding == 1 || objects[px][py] == NULL ){
        py += 1;
        py = (py%yunits+yunits)%yunits;
    }
    else{
        inventoryObject * newObj = findNextObject(px, py, 2);
        if( newObj != NULL ){
            px = newObj->xloc;
            py = newObj->yloc;
        }
        else{
            py += 1;
            py = (py%yunits+yunits)%yunits;
        }
    }
    //printf("down:(%d,%d),holding = %d\n",px,py,holding);
}

void Inventory::moveLeft(){ // (i % n + n) % n;
    if(holding == 1 || objects[px][py] == NULL ){
        px -= 1;
        px = (px%xunits+xunits)%xunits;
    }
    else{
        inventoryObject * newObj = findNextObject(px, py, 0);
        if( newObj != NULL ){
            px = newObj->xloc;
            py = newObj->yloc;
        }
        else{
            px -= 1;
            px = (px%xunits+xunits)%xunits;
        }
    }
    //printf("left:d(%d,%d),holding = %d\n",px,py,holding);
}

bool Inventory::closeInventory(){
    if( holding == 0 ){
        return false;
    }
    return true;
}


void Inventory::clearInventory(){
    for(int i = 0; i < xunits; i++){
        for(int j = 0; j < yunits; j++){
            objects[i][j] = NULL;
        }
    }
}

Inventory::Inventory(SDL_Renderer * renderer,int width, int height){
    px = 0;
    py = 0;
    
    holding = 0;
    
    xunits = width;
    yunits = height;
    
    iunitSize = 40;
    
    heldObject = NULL;
    
    inventoryBackground = IMG_LoadTexture(renderer, "images/inventory/inventoryBackground.png");
    iunitTexture = IMG_LoadTexture(renderer, "images/inventory/iunit.png");
    inventorySelector = IMG_LoadTexture(renderer, "images/inventory/inventorySelector.png");

    objects = new inventoryObject**[width];
    for(int i = 0; i < width; i++){
        objects[i] = new inventoryObject*[height];
    }
    clearInventory();
}

void Inventory::interactItem(){
    if( holding == 0 ){
        pickUpItem();
    }
    else{
        placeItem(heldObject);
    }
}

void Inventory::pickUpItem(){
    if( holding == 1 || objects[px][py] == NULL ){
        return;
    }
    holding = 1;
    heldObject = objects[px][py];
}

bool Inventory::isValidSpot(int x, int y ){
    if( x < 0 || x >= xunits || y < 0 || y >= yunits ){
        return false;
    }
    return true;
}

bool Inventory::isSpotFree(int x, int y ){
    if( isValidSpot(x, y) ){
        if( objects[x][y] == NULL ){
            return true;
        }
    }
    return false;
}

bool Inventory::isFree(int x, int y, int width, int height){
    for( int i = x; i < x + width; i++ ){
        for( int j = y; j < y + height; j++ ){
            if( !isSpotFree(i, j) ){
                return false;
            }
        }
    }
    return true;
}

bool Inventory::addItem(inventoryObject * newItem){
    // find the first availible spot
    return false;
}

void Inventory::placeItemHelper(inventoryObject * item){
    for( int i = px; i < px + item->itemWidth; i++ ){
        for( int j = py; j < py + item->itemHeight; j++ ){
            objects[px][py] = item;
        }
    }
    item->xloc = px;
    item->yloc = py;
    holding = 0;
    heldObject = NULL;
}

bool Inventory::placeItem(inventoryObject * item){
    if(isFree(px, py, item->itemWidth, item->itemHeight)){
        placeItemHelper(item);
        return true;
    }
    return false;
}

/*
Given top left unit of the item. Remove it from the array
*/
void Inventory::removeItem(int x, int y){
    // should also remove all references to it here.
}

/*
 Given top left unit of the item. Remove and delete it from the array
*/
void Inventory::deleteItem(int x, int y){
    inventoryObject * c = objects[x][y];
    removeItem(x, y);
    delete c;
}

void Inventory::resize(int newwidth, int newheight){
    if( newwidth < xunits || newheight < yunits ){
        return;
    }
    
    inventoryObject *** newobjects = new inventoryObject**[newwidth];
    for(int i = 0; i < newwidth; i++){
        newobjects[i] = new inventoryObject*[newheight];
    }
    
    for(int i = 0; i < xunits; i++){
        for(int j = 0; j < yunits; j++ ){
            newobjects[i][j] = objects[i][j];
        }
    }
    
    freeInventory(objects);
    
    objects = newobjects;
    xunits = newwidth;
    yunits = newheight;
}

void Inventory::freeInventory(inventoryObject *** inv){
    for(int i = 0; i < xunits; i++){
        for(int j = 0; j < yunits; j++ ){
            if(inv[i][j] != NULL ){
                delete inv[i][j] ;
                inv[i][j] = NULL;
            }
        }
        delete[] inv[i];
    }
    delete[] inv;
}

Inventory::~Inventory(){
    freeInventory(objects);
}
