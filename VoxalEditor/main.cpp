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

int width, height;

void ChangeSize(int w, int h)
{
    openGL::glViewport(0, 0, w, h);
    width = w;
    height = h;
}

void RenderScene()
{
    openGL::glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    
    openGL::glMatrixMode(GL_PROJECTION_MATRIX);
    openGL::glLoadIdentity();
    openGL::gluPerspective(35, width / (float) height, .1f, 50);
    
    // modelview matrix
    openGL::glMatrixMode(GL_MODELVIEW);
    openGL::glLoadIdentity();
    openGL::gluLookAt(
                      -1, -1, -1,
                      0, 0, 0,
                      0, 1, 0);
    
    testingCube.Draw();
    
    openGL::glutSwapBuffers();
}

void SetupRC()
{
    
    openGL::glClearColor(0.01, 0.01, 0.01, 1.0);
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

