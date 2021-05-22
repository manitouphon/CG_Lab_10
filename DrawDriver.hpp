
#include <stdio.h>

#ifdef definded(_WIN32)
#include <GL/glut.h>
#elif (__linux__)
#include <GL/glut.h>
#elif (__APPLE__)
#include <GLUT/glut.h>
#endif

#include "util/Line.hpp"
#include <vector>

class DrawDriver
{
private:
    vector<Line> linesVector;
    Color background;
    Color primaryColor;
    Color acceptedColor;
    Color declinedColor;
    float winWidth;
    float winHeight;
    float boundWidth;
    float boundHeight;
    int selectedLine = -1;

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
    void showMsg()
    {
        glColor3f(primaryColor.getR(), primaryColor.getG(), primaryColor.getG());
        string slTmp = std::to_string(selectedLine);
        string selectedLineMsg = "Selected Line: \"" + slTmp + "\"";
   
        generateBitmapString("W: Move Up", (-getWinWidth() / 2) + 10, getWinHeight() / 2 - 40);
        generateBitmapString("A: Move Left", (-getWinWidth() / 2) + 10, getWinHeight() / 2 - 60);
        generateBitmapString("S: Move Down", (-getWinWidth() / 2) + 10, getWinHeight() / 2 - 80);
        generateBitmapString("D: Move Right", (-getWinWidth() / 2) + 10, getWinHeight() / 2 - 100);

        glColor3f(1,1,1);
        generateBitmapString(selectedLineMsg, (-getWinWidth() / 2) + 10, - getWinHeight() / 2 + 10);
    }

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
        for (x = -winWidth; x < winWidth; x = x + 100.0)
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
            generateBitmapString(to_string((int)x), x, y);
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
            generateBitmapString(to_string((int)y), x, y);
        }

        //Fill in bitmap chars

        // glBegin(GL_BITMAP);

        // glRasterPos2f(10.0, 100.0);
        // glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'y');

        // glRasterPos2f(100.0, 10.0);
        // glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'x');

        // glEnd();
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
    //
    //
    //
    //

public:




//TODO: Fix
void mouse(int button , int state , int mouseX, int mouseY){
    
    glutPostRedisplay();
}

    void generateRandomLine(int lineID){
        string label = to_string(lineID);
        //int randNum = rand()%(max-min + 1) + min;
        int w,h;
        w = winWidth/2 - 20;
        h = winHeight/2 - 20;
        

        int x1 = rand()%(w-(-w) + 1) + (-w);
        int y1 = rand()%(h-(-h) + 1) + (-h);
        int x2 = rand()%(w-(-w) + 1) + (-w);
        int y2 = rand()%(h-(-h) + 1) + (-h);

        cout << "\n New Line @ ( " << x1 << " , " << y1 << " ) --> "
         << "( " << x2 << " , " << y2 << " )\n\n\n";
        cout << "\n";

        Line newLine;
        newLine.setPoints(x1,y1,x2,y2);
        newLine.setLabel(label);
        addLine(newLine);
        selectedLine = linesVector.size() - 1;
    }
    DrawDriver()
    {
        winWidth = 1000;
        winHeight = 750;
        boundWidth = 600;
        boundHeight = 450;
        background.setColor(0.3, 0.3, 0.3);
        primaryColor.setColor(0.5, 0.5, 0.5);
        acceptedColor.setColor(0.5, 0.82, 1.0);
        declinedColor.setColor(1, 0, 0);
    }

    void setAcceptedColor(float r, float g, float b)
    {
        this->acceptedColor.setColor(r, g, b);
    }
    void setDeclinedColor(float r, float g, float b)
    {
        this->declinedColor.setColor(r, g, b);
    }
    void setBackgroundColor(float r, float g, float b)
    {
        this->background.setColor(r, g, b);
    }
    void setPrimaryColor(float r, float g, float b)
    {
        this->primaryColor.setColor(r, g, b);
    }

    void setWinDimension(float w, float h)
    {
        winWidth = w;
        winHeight = h;
    }
    void setBoundaryrDimension(float w, float h)
    {
        boundHeight = h;
        boundWidth = w;
    }

    Color getBackgroundColor()
    {
        return background;
    }
    Color getPrimaryColor()
    {
        return primaryColor;
    }
    Color getAcceptedColor()
    {
        return acceptedColor;
    }
    Color getDeclinedColor()
    {
        return declinedColor;
    }
    float getBoundWidth()
    {
        return boundWidth;
    }
    float getBoundHeight()
    {
        return boundHeight;
    }
    float getWinWidth()
    {
        return winWidth;
    }
    float getWinHeight()
    {
        return winHeight;
    }

    ///

    //
    //

    //
    //
    //

    Line getSelectedLine()
    {
        return linesVector.at(selectedLine);
    }
    void moveSelectedLine(float xShift, float yShift){
        if(selectedLine == -1) return; 
        Line newLine = linesVector.at(selectedLine);
        newLine.move(xShift,yShift);
        linesVector.at(selectedLine) = newLine;
        
    }

    void addLine(Line newLine)
    {
        linesVector.push_back(newLine);
    }
    void clearAll()
    {
        linesVector.clear();
        selectedLine = -1;
    }
    void setSelectedLine(int index)
    {
        selectedLine = index;
    }

    //
    //
    //
    //
    //
    //

    void startDrawing()
    {
        drawCoordinate();
        drawClippingBorder();
        showMsg();
        //Draw Lines:
        for (int i = 0; i < linesVector.size(); i++)
        {
            linesVector.at(i).markClipping();
            linesVector.at(i).draw(acceptedColor, declinedColor);
        }

        glFlush();
    }

    void clip()
    {
        drawCoordinate();
        drawClippingBorder();
        showMsg();

        //Draw Lines:
        for (int i = 0; i < linesVector.size(); i++)
        {
            linesVector.at(i).doClipping();
            linesVector.at(i).draw(acceptedColor, declinedColor);
        }

        glFlush();
    }
};