#pragma once

#ifndef RASTERIZER_PIXEL_HPP
#define RASTERIZER_PIXEL_HPP

#include <GL/glut.h>

class pixel
{
private:
public:
    int color[3];
    pixel(int r, int g, int b)
    {
        this->color[0] = r;
        this->color[1] = g;
        this->color[2] = b;
    }
    void setGLcolor()
    {
        glColor3f(this->color[0] / 255.0, this->color[1] / 255.0, this->color[2] / 255.0);
    }
    void init()
    {
        this->color[0] = 0;
        this->color[1] = 0;
        this->color[2] = 0;
    }
    void set(int r, int g, int b)
    {
        this->color[0] = r;
        this->color[1] = g;
        this->color[2] = b;
    }
};

#endif // RASTERIZER_PIXEL_HPP