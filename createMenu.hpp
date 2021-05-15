
#include <stdio.h>

#ifdef definded(_WIN32)
#include <GL/glut.h>
#elif (__linux__)
#include <GL/glut.h>
#elif (__APPLE__)
#include <GLUT/glut.h>
#endif

#include "DrawDriver.hpp"

//Global Variables: ------------------------------------
extern DrawDriver dd;

int linesNumbers = -1;
float lineMoveSteps = 10;

//Functions:
void refresh();


void showMsg()
{
    glColor3f(1.0, 0.0, 0.0);
    cout << "showing msg";
    generateBitmapString("Check Your Command Line for inputs", (-dd.getWinWidth() / 2) + 10, dd.getWinHeight() / 2 - 20);
    glFlush();
}

void moveLine(float xShift, float yShift)
{
    dd.moveSelectedLine(xShift, yShift);
}

void clearAllLines()
{
    dd.clearAll();
    linesNumbers = -1;
}

void selectLine(int sl)
{
    
    if (sl > linesNumbers || sl < 0)
    {
        cout << "\n line does not exist. Please reslect again \n(The line ID is the red label next to the line on the graph)";
        return;
    }
    else
    {
        cout << "\nLine \"" << to_string(sl) << "\" selected.";
        cout << "\n";
        dd.setSelectedLine(sl);
    }
}

void setBoundaryRegion()
{
    float w, h;
    cout << "\n Boundary width: ";
    cin >> w;
    cout << "\n Boundary height: ";
    cin >> h;

    cout << "\n Boundary Dimension: Width = " << w << "/ Height = " << h;

    dd.setBoundaryrDimension(w, h);
}

void addLineCoordinates()
{
    Line newLine;

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

    linesNumbers++;
    string lineName = to_string(linesNumbers);

    newLine.setPoints(x1, y1, x2, y2);
    newLine.setLabel(lineName);
    dd.addLine(newLine);
    dd.setSelectedLine(linesNumbers);

    refresh();
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

    switch (ID)
    {
    case 1:
        showMsg();
        setBoundaryRegion();
        break;
    case 2:
        dd.clip();
        break;
    case 3:
        showMsg();
        addLineCoordinates();
        break;
    case 4:
        clearAllLines();
        break;
    case 5:
        linesNumbers++;
        dd.generateRandomLine(linesNumbers);
        break;
    default:
        break;
    }
    refresh();
    
}

void lineColorAction(int ID)
{

    switch (ID)
    {
    case 1:
        dd.setAcceptedColor(0.5, 0.82, 1.0);
        break;
    case 2:
        dd.setAcceptedColor(1.0, 1.0, 1.0);
        break;
    case 3:
        dd.setAcceptedColor(0, 1.0, 0.1);
        break;
    case 4:
        dd.setAcceptedColor(0.75, 0.58, 0.89);

        break;
    default:
        break;
    }
    refresh();
}
void clippingColorAction(int ID)
{
    switch (ID)
    {
    case 1:
        dd.setDeclinedColor(1, 0, 0);
        break;
    case 2:
        dd.setDeclinedColor(1, 1, 0);
        break;
    case 3:
        dd.setDeclinedColor(0, 0, 0);
        break;
    case 4:
        dd.setDeclinedColor(1, 0.4, 0);
        break;
    default:
        break;
    }
    refresh();
    
}

void selectLineAction(int ID){
    selectLine(ID);
    glutPostRedisplay();
}
void mainmenuAction(int ID)
{
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
    int selectLine;

    int mainmenu;

    glutAddMenuEntry("Add Coordinates via Command Line", 1);

    actions = glutCreateMenu(actionsAction);
    glutAddMenuEntry("Set Clipping Region Dimension", 1);
    glutAddMenuEntry("Clip Lines", 2);
    glutAddMenuEntry("Add Line", 3);
    glutAddMenuEntry("Clear Lines!", 4);
    glutAddMenuEntry("Generate a random Line", 5);

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

    selectLine = glutCreateMenu(selectLineAction);
    string label;
    for(int i = 0; i <= linesNumbers; i++){
        label = "Line #" + to_string(i) ;
        glutAddMenuEntry(label.c_str(), i);
    }

    mainmenu = glutCreateMenu(mainmenuAction);
    glutAddSubMenu("Actions", actions);
    glutAddSubMenu("Line Color", lineColor);
    glutAddSubMenu("Clipped Line Color", clippingColor);
    glutAddSubMenu("Select Line", selectLine);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

//
//
//
// Keyboard functions:
//
//
//
void pressKey(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
        moveLine(0, +lineMoveSteps);
        break;
    case 'a':
        moveLine(-lineMoveSteps, 0);
        break;
    case 's':
        moveLine(0, -lineMoveSteps);
        break;
    case 'd':
        moveLine(+lineMoveSteps, 0);
        break;

    default:
        break;
    }
    refresh();
}

void refresh(){
    
    glutPostRedisplay();
    createMenu();
   
}