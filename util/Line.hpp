#include <iostream>


#ifdef definded(_WIN32)
#include <GL/glut.h>
#elif (__linux__)
#include <GL/glut.h>
#elif (__APPLE__)
#include <GLUT/glut.h>
#endif

#include "Color.hpp"
#include "glBitmapStringGenerator.hpp"


using namespace std;
class Line
{ 
private:
    float x1, y1, x2, y2;
    float x1P, y1P, x2P, y2P; //x1 & y1 Prime
    string label;
    float labelX, labelY;

    void adjustLabelCoor(){
        if(y1 <= y2){
            labelX = x1;
            labelY = y1 - 10;
        }else{
            labelX = x1;
            labelY = y1 - 10;
        }
    }

public:

    Line(){
        x1 = 0;
        x2 = 0;
        y1 = 0;
        y2= 0;
        x1P = 0;
        x2P = 0;
        y1P = 0 ;
        y2P = 0;

        label = "";
    }



    void setPoints(float x1, float y1, float x2, float y2)
    {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;    
        adjustLabelCoor();
    }

    void setLabel(string newLabel){
        this->label = newLabel;
    }


    void setPoint1(float x1, float y1){
        this->x1 = x1;
        this->y1 = y1;
        adjustLabelCoor();
    }
    void setPoint2(float x2, float y2){
        this->x2 = x2;
        this->y2 = y2; 
        adjustLabelCoor();  
    }
    
    void setPrime1(float x1p, float y1p){
        this->x1P = x1p;
         this->y1P = y1p;   
    }
    void setPrime2(float x2p, float y2p){
        this->x2P = x2p;
        this->y2P = y2p;  
    }

    float getX1(){return x1;}
    float getY1(){return y1;}

    float getX2(){return x2;}
    float getY2(){return y2;}

    float getX1P(){return x1P;}
    float getY1P(){return y1P;}
    
    float getX2P(){return x2P;}
    float getY2P(){return y2P;}

    void move(float xShift, float yShift){
        setPoint1(x1 + xShift, y1 + yShift);
        setPoint2(x2 + xShift, y2 + yShift);
    }
    

    void draw(Color c1, Color c2){

        glColor3f(1,1,1);
        //Draw Line Label:
        generateBitmapString(label,labelX, labelY);

        glColor3f(c1.getR(),c1.getG(), c1.getB());
        //Draw Accepted Line
        glBegin(GL_LINES);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
        glEnd();

        //Draw Declined Line
        glColor3f(c2.getR(),c2.getG(), c2.getB());
        glBegin(GL_LINES);
        glVertex2f(x1P,y1P);
        glVertex2f(x2P,y2P);

        glEnd();


        


    }
    void doClipping(){

    }
    void markClipping(){

    }



};
