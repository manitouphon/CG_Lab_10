#include <iostream>


#ifdef definded(_WIN32)
#include <GL/glut.h>
#elif (__linux__)
#include <GL/glut.h>
#elif (__APPLE__)
#include <GLUT/glut.h>
#endif


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
            labelY = y1 - 5;
        }else{
            labelX = x1;
            labelY = y1 - 5;
        }
    }

public:
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




};
