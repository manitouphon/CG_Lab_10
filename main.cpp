#include <stdio.h>

#ifdef definded(_WIN32)
#include <GL/glut.h>
#elif (__linux__)
#include <GL/glut.h>
#elif (__APPLE__)
#include <GLUT/glut.h>
#endif


#include "createMenu.hpp"

//Global variables section: ------------------------------
DrawDriver dd;




//Functions Section: ---------------------------------------------------
void init(void)
{

    glClearColor(dd.getBackgroundColor().getR(), dd.getBackgroundColor().getG(), dd.getBackgroundColor().getB(), 0.0);
    //change projection mode
    glMatrixMode(GL_PROJECTION);
    glShadeModel(GL_SMOOTH);
    // set current matrix to identiy matrix
    glLoadIdentity();
    gluOrtho2D(-(dd.getWinWidth()/2) ,(dd.getWinWidth()/2) , -(dd.getWinHeight()/2) ,   (dd.getWinHeight()/2));
} //Init::void

void display()
{
    dd.startDrawing();
}



int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(dd.getWinWidth(), dd.getWinHeight());
    
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Lab 10: Line Clipping");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(pressKey);
    createMenu();

    glutMainLoop();
    return 0;


} //Main::int
