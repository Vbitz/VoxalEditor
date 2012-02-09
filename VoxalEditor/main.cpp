//
//  main.cpp
//  VoxalEditor
//
//  Created by Vbitz on 9/02/12.
//  Copyright (c) 2012 Vbitz. All rights reserved.
//

#include "stdheader.h"
#include "main.h"

Cube testingCube(0,0,0);

Cube Cubes[8][8][8];

int width = 800, height = 600;

void ChangeSize(int w, int h)
{
    openGL::glViewport(0, 0, w, h);
    width = w;
    height = h;
    
    SetMatrix();
}

void RenderScene()
{
    openGL::glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    
    for (int z = 0; z < 8; z++) {
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                Cubes[x][y][z].Draw();
            }
        }
    }
    
    openGL::glutSwapBuffers();
}

void SetMatrix()
{
    openGL::glMatrixMode(GL_PROJECTION);
    openGL::glLoadIdentity();
    openGL::gluPerspective(35, width / height, .1f, 50);
    
    // modelview matrix
    openGL::glMatrixMode(GL_MODELVIEW);
    openGL::glLoadIdentity();
    openGL::gluLookAt(
                      -10, -10, -8,
                      0, 0, 0,
                      0, 0, -1);
}

void SetupRC()
{
    openGL::glClearColor(0.01, 0.01, 0.01, 1.0);
    
    openGL::glEnable(GL_DEPTH_TEST);
    
    for (int z = 0; z < 8; z++) {
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                Cubes[x][y][z] = Cube(x - 4, y - 4, z - 4);
            }
        }
    }
    
    SetMatrix();
}

int main (int argc, char * argv[])
{
    openGL::glutInit(&argc, argv);
    openGL::glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
    
    openGL::glutInitWindowSize(800, 600);
    openGL::glutCreateWindow("Voxal Editor");
    
    openGL::glutReshapeFunc(ChangeSize);
    openGL::glutDisplayFunc(RenderScene);
    
    SetupRC();
    
    openGL::glutMainLoop();
    
    return 0;
}

