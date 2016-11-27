//
//  mathStuff.cpp
//  Untitled_Zombie
//
//  Created by Matthew Broton on 11/23/16.
//  Copyright © 2016 Matthew Broton. All rights reserved.
//

#include "mathStuff.hpp"

int slopesolver(int x1, int y1, int x2, int y2){
    return (y2-y1)/(x2-x1);
}

int interceptSolver(int x1, int y1, int m){
    return y1 - (m*x1);
}