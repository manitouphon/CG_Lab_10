#ifdef definded(_WIN32)
#include <GL/glut.h>
#elif  (__linux__)
#include <GL/glut.h>
#elif  (__APPLE__)
#include <GLUT/glut.h>
#endif

#include <iostream>

using namespace std;

void generateBitmapString(string text, float x, float y)
{
    if(x == 0){
        x = x - (text.size() * 10);
    }//draw on Y Axis
    else if(y ==0 ){
        y = y + (text.size() * 2);
        x = x - (text.size() * 10);
    }//draw on X Axis


    bool switcher = true;
    
  
    glBegin(GL_BITMAP);
    for (int i = 0; i != text.size(); i++)
    {

        glRasterPos2f(x + (i * 10), y );
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text.at(i));

    }

    glEnd();
   
}

