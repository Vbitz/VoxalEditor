//
//  stdheader.h
//  VoxalEditor
//
//  Created by Vbitz on 9/02/12.
//  Copyright (c) 2012 Vbitz. All rights reserved.
//

#ifndef VoxalEditor_stdheader_h
#define VoxalEditor_stdheader_h

struct vector3f{
    float X;
    float Y;
    float Z;
};

inline vector3f CreateVector3f(float x, float y, float z)
{
    vector3f vec;
    
    vec.X = x;
    vec.Y = y;
    vec.Z = z;
    
    return vec;
}

struct drawCommand
{
    vector3f data;
    int type;
};

inline drawCommand CreateDrawCommand(vector3f data, int type)
{
    drawCommand cmd;
    
    cmd.data = data;
    cmd.type = type;
    
    return cmd;
}

#include <sys/types.h>
#include <sys/cdefs.h>
#include <stddef.h>
#include <_types.h>

namespace openGL
{
#include <GLUT/GLUT.h>
}

#include <iostream>
#include <string>
#include <vector>

namespace cHelpers
{
    extern "C"
    {
        #include <time.h>
        #include <stdlib.h>
    }
}

#endif
