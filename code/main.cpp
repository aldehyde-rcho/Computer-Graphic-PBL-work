#include <iostream>
#include <GL/glut.h>

#include "rasterizer.hpp"
#include "Triangle.hpp"
#include "Shader.hpp"
#include "Texture.hpp"
#include "OBJ_Loader.h"
#include "Pixel.hpp"

pixel Pixels[800][600];

void display();

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("PBL_PROJECT");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

void display()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POINTS);
    for (int i = 0; i < 800; i++)
    {
        for (int j = 0; j < 600; j++)
        {
            Pixels[i][j].setGLcolor();
            glVertex2i(i, j);
        }
    }
    glEnd();
    glFlush();
}