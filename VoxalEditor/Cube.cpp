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
    if (!Enabled) return;
    
    int cubeSize = 16;
    
    //openGL::glColor3i(125, 0, 0);
    
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

Cube::Cube(int x, int y, int z)
{
    topSide = CubeSide(x, y, z, x + 1, y + 1, z, 125, 0, 0); // red
    bottomSide = CubeSide(x + 1, y + 1, z + 1, x, y, z + 1, 0, 125, 0); // green
    frontSide = CubeSide(x, y, z, x, y + 1, z + 1, 0, 0, 125); // blue
    backSide = CubeSide(x + 1, y, z, x + 1, y + 1, z + 1 , 125, 125, 0); // yellow
    leftSide = CubeSide(x, y, z, x + 1, y, z + 1, 125, 0, 125); // purple
    rightSide = CubeSide(x, y + 1, z, x + 1, y + 1, z + 1, 0, 125, 125); // cyan
}

void Cube::Draw()
{
    openGL::glBegin(GL_TRIANGLES);
        topSide.Draw();
        bottomSide.Draw();
        frontSide.Draw();
        backSide.Draw();
        leftSide.Draw();
        rightSide.Draw();
    openGL::glEnd();
}