//
//  Cube.cpp
//  VoxalEditor
//
//  Created by Vbitz on 9/02/12.
//  Copyright (c) 2012 Vbitz. All rights reserved.
//

#include "Cube.h"

CubeSide::CubeSide()
{
    Enabled = false;
    R = 255;
    G = 255;
    B = 255;
}

CubeSide::CubeSide(int x1, int y1, int z1, int x2, int y2, int z2, int r, int g, int b)
{
    Enabled = true;
    Point1.X = x1;
    Point1.Y = y1;
    Point1.Z = z1;
    Point2.X = x2;
    Point2.Y = y2;
    Point2.Z = z2;
    
    R = r;
    G = g;
    B = b;
}

bool CubeSide::GetEnabled()
{
    return Enabled;
}

void CubeSide::SetEnabled(bool s)
{
    Enabled = s;
}

void CubeSide::Draw()
{
    
    openGL::glColor4f(R, G, B, 255);
    
    openGL::glVertex3f(Point1.X, Point1.Y, Point1.Z);
    
    if (Point1.X == Point2.X)
    {
        openGL::glVertex3f(Point1.X, Point2.Y, Point1.Z);
        openGL::glVertex3f(Point1.X, Point2.Y, Point2.Z);
        openGL::glVertex3f(Point1.X, Point1.Y, Point1.Z);
        openGL::glVertex3f(Point1.X, Point1.Y, Point2.Z);
        openGL::glVertex3f(Point1.X, Point2.Y, Point2.Z);
    }
    else if (Point1.Y == Point2.Y)
    {
        openGL::glVertex3f(Point2.X, Point1.Y, Point1.Z);
        openGL::glVertex3f(Point2.X, Point1.Y, Point2.Z);
        openGL::glVertex3f(Point1.X, Point1.Y, Point1.Z);
        openGL::glVertex3f(Point1.X, Point1.Y, Point2.Z);
        openGL::glVertex3f(Point2.X, Point1.Y, Point2.Z);
    }
    else if (Point1.Z == Point2.Z)
    {
        openGL::glVertex3f(Point1.X, Point2.Y, Point1.Z);
        openGL::glVertex3f(Point2.X, Point2.Y, Point1.Z);
        openGL::glVertex3f(Point1.X, Point1.Y, Point1.Z);
        openGL::glVertex3f(Point2.X, Point1.Y, Point1.Z);
        openGL::glVertex3f(Point2.X, Point2.Y, Point1.Z);
    }
}

void CubeSide::DrawVector(std::vector<drawCommand> *vec)
{
    vec->push_back(CreateDrawCommand(CreateVector3f(R, B, G),1));
    
    vec->push_back(CreateDrawCommand(CreateVector3f(Point1.X, Point1.Y, Point1.Z),0));
    
    if (Point1.X == Point2.X)
    {
        vec->push_back(CreateDrawCommand(CreateVector3f(Point1.X, Point2.Y, Point1.Z),0));
        vec->push_back(CreateDrawCommand(CreateVector3f(Point1.X, Point2.Y, Point2.Z),0));
        vec->push_back(CreateDrawCommand(CreateVector3f(Point1.X, Point1.Y, Point1.Z),0));
        vec->push_back(CreateDrawCommand(CreateVector3f(Point1.X, Point1.Y, Point2.Z),0));
        vec->push_back(CreateDrawCommand(CreateVector3f(Point1.X, Point2.Y, Point2.Z),0));
    }
    else if (Point1.Y == Point2.Y)
    {
        vec->push_back(CreateDrawCommand(CreateVector3f(Point2.X, Point1.Y, Point1.Z),0));
        vec->push_back(CreateDrawCommand(CreateVector3f(Point2.X, Point1.Y, Point2.Z),0));
        vec->push_back(CreateDrawCommand(CreateVector3f(Point1.X, Point1.Y, Point1.Z),0));
        vec->push_back(CreateDrawCommand(CreateVector3f(Point1.X, Point1.Y, Point2.Z),0));
        vec->push_back(CreateDrawCommand(CreateVector3f(Point2.X, Point1.Y, Point2.Z),0));
    }
    else if (Point1.Z == Point2.Z)
    {
        vec->push_back(CreateDrawCommand(CreateVector3f(Point1.X, Point2.Y, Point1.Z),0));
        vec->push_back(CreateDrawCommand(CreateVector3f(Point2.X, Point2.Y, Point1.Z),0));
        vec->push_back(CreateDrawCommand(CreateVector3f(Point1.X, Point1.Y, Point1.Z),0));
        vec->push_back(CreateDrawCommand(CreateVector3f(Point2.X, Point1.Y, Point1.Z),0));
        vec->push_back(CreateDrawCommand(CreateVector3f(Point2.X, Point2.Y, Point1.Z),0));
    }
}

Cube::Cube()
{
    Drawing = false;
}

void Cube::SetDrawing(bool s)
{
    Drawing = s;
}

Cube::Cube(int x, int y, int z)
{
    Drawing = true;
    topSide = CubeSide(x, y, z, x + 1, y + 1, z, 125, 1, 1); // red
    bottomSide = CubeSide(x + 1, y + 1, z + 1, x, y, z + 1, 1, 125, 1); // green
    frontSide = CubeSide(x, y, z, x, y + 1, z + 1, 1, 1, 125); // blue
    backSide = CubeSide(x + 1, y, z, x + 1, y + 1, z + 1 , 125, 125, 1); // yellow
    leftSide = CubeSide(x, y, z, x + 1, y, z + 1, 125, 1, 125); // purple
    rightSide = CubeSide(x, y + 1, z, x + 1, y + 1, z + 1, 1, 125, 125); // cyan
}

void Cube::Draw()
{
    if (!Drawing) return;
    
    openGL::glBegin(GL_TRIANGLES);
        topSide.Draw();
        bottomSide.Draw();
        frontSide.Draw();
        backSide.Draw();
        leftSide.Draw();
        rightSide.Draw();
    openGL::glEnd();
}

void Cube::DrawVector(std::vector<drawCommand> *vec)
{
    if (!Drawing) return;
    
    topSide.DrawVector(vec);
    bottomSide.DrawVector(vec);
    frontSide.DrawVector(vec);
    backSide.DrawVector(vec);
    leftSide.DrawVector(vec);
    rightSide.DrawVector(vec);
}