#include <stdio.h>

#ifdef definded(_WIN32)
#include <GL/glut.h>
#elif (__linux__)
#include <GL/glut.h>
#elif (__APPLE__)
#include <GLUT/glut.h>
#endif


#include "display.hpp"

//Global variables section: ------------------------------
Color background;
Color primaryColor;
Color acceptedColor;
Color clippedColor;

float winWidth = 1000;
float winHeight = 750;

float boundWidth = 600;
float boundHeight = 450;




//Functions Section: ---------------------------------------------------
void init(void)
{
    background.setColor(0.3, 0.3, 0.3);
    primaryColor.setColor(0.5,0.5,0.5);
    glClearColor(background.getR(), background.getG(), background.getB(), 0.0);
    //change projection mode
    glMatrixMode(GL_PROJECTION);
    glShadeModel(GL_SMOOTH);
    // set current matrix to identiy matrix
    glLoadIdentity();
    gluOrtho2D(-(winWidth/2) ,(winWidth/2) , -(winHeight/2) ,   (winHeight/2));
} //Init::void

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(winWidth, winHeight);
    
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Lab 10: Line Clipping");
    init();
    glutDisplayFunc(display);
    createMenu();

    glutMainLoop();
    return 0;


} //Main::int
