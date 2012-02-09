//
//  Cube.h
//  VoxalEditor
//
//  Created by Joshua Scarsbrook on 9/02/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef VoxalEditor_Cube_h
#define VoxalEditor_Cube_h

#include "Drawable.h"
#include "stdheader.h"

class CubeSide : Drawable {
    bool Enabled;
    
    int R, G, B;
    
    vector3f Point1;
    vector3f Point2;
    
public:
    
    CubeSide();
    CubeSide(int x1, int y1, int z1, int x2, int y2, int z2, int r, int g, int b);
    
    void Draw();
    
    bool GetEnabled();
    void SetEnabled(bool s);
};

class Cube : Drawable {
    CubeSide topSide;
    CubeSide bottomSide;
    CubeSide frontSide;
    CubeSide backSide;
    CubeSide leftSide;
    CubeSide rightSide;
    
public:
    Cube(int x, int y, int z);
    
    void Draw();
};

#endif
