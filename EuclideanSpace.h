#ifndef _EUCLIDEANSPACE_h
#define _EUCLIDEANSPACE_h
#include "Point.h"
#include "Cell.h"
#include <cmath>
//this class is the arae

class EuclideanSpace
{
private:
    Point* MaxDim;
    Point* MinDim;
    Cell** Area;
public:
    EuclideanSpace();//c'tor
    EuclideanSpace(Point& Max);//c'tor
    ~EuclideanSpace();//d'tor
    void CheckPointDim(Point* chack);//check if the point are in the filed
    Point GetMaxDim() const;//get max point
    double GetDis(Point& a,Point& b);//dis bitwin 2 point
    void AddToCell(Point& temp);//add player to cell
    void SubToCell(Point& temp);//sub player to cell
    EuclideanSpace& operator=(const EuclideanSpace& rhs);//Override operator
    int operator() (int i,int j);//Override operator
/********************************************/
};
#endif
