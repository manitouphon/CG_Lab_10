#include <stdio.h>

#ifdef definded(_WIN32)
#include <GL/glut.h>
#elif (__linux__)
#include <GL/glut.h>
#elif (__APPLE__)
#include <GLUT/glut.h>
#endif


#include "createMenu.hpp"

//Global Variables: ------------------------------------
extern Color background;
extern Color primaryColor;
extern Color acceptedColor;
extern Color clippedColor;

extern float winWidth;
extern float winHeight;

extern float boundWidth;
extern float boundHeight;

//
//
//
//Functions:-----------------------------------------

void drawClippingBorder()
{
    glBegin(GL_LINE_STRIP);

    glVertex2d(-boundWidth / 2, boundHeight / 2);
    glVertex2d(boundWidth / 2, boundHeight / 2);
    glVertex2d(boundWidth / 2, -boundHeight / 2);
    glVertex2d(-boundWidth / 2, -boundHeight / 2);
    glVertex2d(-boundWidth / 2, boundHeight / 2);

    glEnd();
}
//      //Main display function:----
void display()
{
    drawCoordinate();
    glColor3f(1.0,1.0,1.0);
    drawClippingBorder();
    
    glFlush();
}

