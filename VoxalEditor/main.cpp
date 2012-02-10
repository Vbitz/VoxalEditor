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

const int worldSize = 16;

Cube Cubes[worldSize][worldSize][worldSize];

int width = 800, height = 600;

bool needsRebuild = true;

std::vector<drawCommand> vertexs = std::vector<drawCommand>();

void ChangeSize(int w, int h)
{
    openGL::glViewport(0, 0, w, h);
    width = w;
    height = h;
    
    SetMatrix();
}

void RebuildScene()
{
    needsRebuild = false;
    
    for (int z = 0; z < worldSize; z++) {
        for (int x = 0; x < worldSize; x++) {
            for (int y = 0; y < worldSize; y++) {
                Cube cbe = Cubes[x][y][z];
                cbe.DrawVector(&vertexs);
            }
        }
    }
}

void RenderScene()
{
    openGL::glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    
    if (needsRebuild)
    {
        RebuildScene();
    }
    
    openGL::glBegin(GL_TRIANGLES);
    
    for(std::vector<drawCommand>::iterator it = vertexs.begin(); it != vertexs.end(); ++it)
    {
        if (it->type == 1)
        {
            openGL::glColor3f(it->data.X, it->data.Y, it->data.Z);
        }
        else
        {
            openGL::glVertex3f(it->data.X, it->data.Y, it->data.Z);
        }
    }
    
    openGL::glEnd();
    
    openGL::glutSwapBuffers();
}

void SetMatrix()
{
    openGL::glMatrixMode(GL_PROJECTION);
    openGL::glLoadIdentity();
    openGL::gluPerspective(35, 1.3, .1f, 600);
    
    // modelview matrix
    openGL::glMatrixMode(GL_MODELVIEW);
    openGL::glLoadIdentity();
    openGL::gluLookAt(
                      -30, -40, -20,
                      0, 0, 0,
                      0, 0, -1);
}

void SetupRC()
{
    openGL::glClearColor(0.01, 0.01, 0.01, 1.0);
    
    openGL::glEnable(GL_DEPTH_TEST);
    
    for (int z = 0; z < worldSize; z++) {
        for (int x = 0; x < worldSize; x++) {
            for (int y = 0; y < worldSize; y++) {
                Cubes[x][y][z] = Cube(x - worldSize / 2, y - worldSize / 2, z - worldSize / 2);
                if ((rand() % 2) > 0) {
                    Cubes[x][y][z].SetDrawing(false);
                }
            }
        }
    }
    
    SetMatrix();
}

int main (int argc, char * argv[])
{
    srand(time(0));
    
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

