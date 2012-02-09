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
