#ifdef definded(_WIN32)
#include <GL/glut.h>
#elif (__linux__)
#include <GL/glut.h>
#elif (__APPLE__)
#include <GLUT/glut.h>
#endif

#include "Color.hpp"
#include "glBitmapStringGenerator.hpp"


extern Color background;
extern Color primaryColor;

extern float winWidth ;
extern float winHeight ;

extern float boundWidth ;
extern float boundHeight ;



void drawCoordinate()
{
    //Prime Color with 30% alpha
    glColor3f(primaryColor.getR(), primaryColor.getG(), primaryColor.getB());
    

    glClear(GL_COLOR_BUFFER_BIT);

    //Draw X line

    glBegin(GL_LINE_STRIP);

    glVertex2f(-winHeight, 0.0);
    glVertex2f(winHeight, 0.0);

    glEnd();
      

  

    //Draw Y line
    glBegin(GL_LINE_STRIP);

    glVertex2f(0.0, -winWidth);
    glVertex2f(0.0, winWidth);

    glEnd();
      

   
    //Draw 0 unit label:
    generateBitmapString("0", 10, 20);

    float x = -100.0;
    float y = 0;
    float lineOffset = 2.5;
    //X unit div
    for (x = -winWidth; x < winWidth; x = x +100.0)
    {

        glBegin(GL_LINE_STRIP);

        y = 0;
        y = y + lineOffset;
        glVertex2f(x, y);

        y = 0;
        y = y - lineOffset;
        glVertex2f(x, y);

        y = 0;
        glEnd();
          
        if (x == 0)
            continue;
        //Generate the unit dividers labels
        generateBitmapString(to_string((int)x), x , y );
    }

    //Y unit div

    x = 0;
    y = -100.0;
    for (y = -winHeight; y < winHeight; y = y + 100.0)
    {

        glBegin(GL_LINE_STRIP);

        x = 0;
        x = x + lineOffset;
        glVertex2f(x, y);
        x = 0;
        x = x - lineOffset;
        glVertex2f(x, y);

        glEnd();
        x = 0;
        //Generate the unit dividers labels
        if (y == 0)
            continue;
        generateBitmapString(to_string((int)y), x , y );
    }

    //Fill in bitmap chars

    // glBegin(GL_BITMAP);

    // glRasterPos2f(10.0, 100.0);
    // glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'y');

    // glRasterPos2f(100.0, 10.0);
    // glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'x');

    // glEnd();
      
}