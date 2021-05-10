
#include <stdio.h>

#ifdef definded(_WIN32)
#include <GL/glut.h>
#elif (__linux__)
#include <GL/glut.h>
#elif (__APPLE__)
#include <GLUT/glut.h>
#endif

#include "util/Line.hpp"
#include "util/drawCardinalCoordinate.hpp"

//Global Variables: ------------------------------------
extern Color background;
extern Color primaryColor;
extern Color acceptedColor;
extern Color clippedColor;

extern float winWidth;
extern float winHeight;

extern float boundWidth;
extern float boundHeight;;

//Functions:
void showMsg()
{
    glColor3f(1.0, 0.0, 0.0);
    cout << "showing msg";
    generateBitmapString("Check Your Command Line for inputs", (-winWidth/2) + 10 , winHeight/2 - 20);
    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2f(-150,280);
    glVertex2f(400,-100);
    glEnd();
    glFlush();


}


void addLineCoordinates()
{
    float x1, y1, x2, y2;
    cout << "\n -1st Point X: ";
    cin >> x1;

    cout << "\n -1st Point Y: ";
    cin >> y1;

    cout << "\n -2nd Point X: ";
    cin >> x2;

    cout << "\n -2nd Point Y: ";
    cin >> y2;

    cout << "\n New Line @ ( " << x1 << " , " << y1 << " ) --> "
         << "( " << x2 << " , " << y2 << " )\n\n\n";

    cout << "\n";
    glutPostRedisplay();
}

//
//
//
//
//
//
//
//
//
//

//
//
//
//Menus:-------

//      //Main createMenu function:----

void actionsAction(int ID)
{
    showMsg();
    switch (ID)
    {
    case 1:
        addLineCoordinates();
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        
        break;
    default:
        break;
    }
    
}

void clippingColorAction(int ID)
{

    switch (ID)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    default:
        break;
    }
    glutPostRedisplay();
}
void lineColorAction(int ID)
{
    switch (ID)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    default:
        break;
    }
    glutPostRedisplay();
}
void mainmenuAction(int ID){

}
//
//
//
//Create menu:
//
//
//
//
void createMenu()
{
    int actions;
    int clipColor;
    int lineColor;
    int clippingColor;

    int mainmenu;

    glutAddMenuEntry("Add Coordinates via Command Line", 1);

    actions = glutCreateMenu(actionsAction);
    glutAddMenuEntry("Edit Clipping Region", 1);
    glutAddMenuEntry("Clip!", 2);
    glutAddMenuEntry("Add Line", 3);
    glutAddMenuEntry("Select Line", 4);

    lineColor = glutCreateMenu(lineColorAction);
    glutAddMenuEntry("Cyan (default)", 1);
    glutAddMenuEntry("White", 2);
    glutAddMenuEntry("Lime", 3);
    glutAddMenuEntry("Lavendar", 4);

    clippingColor = glutCreateMenu(clippingColorAction);
    glutAddMenuEntry("Red (default)", 1);
    glutAddMenuEntry("Black", 2);
    glutAddMenuEntry("Yellow", 3);
    glutAddMenuEntry("Orange", 4);

    mainmenu = glutCreateMenu(mainmenuAction);
    glutAddSubMenu("Actions", actions);
    glutAddSubMenu("Line Color", lineColor);
    glutAddSubMenu("Clipped Line Color", clippingColor);
    




    glutAttachMenu(GLUT_RIGHT_BUTTON);
}