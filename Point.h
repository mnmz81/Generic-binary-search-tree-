#ifndef _POINT_h
#define _POINT_h
#include <iostream>
//this class Represents Space cell
class Point
{
private:
    double x;
    double y;
public:
    Point();//c'tor
    Point(double x,double y);//c'tor
    Point(Point& temp);//c'tor
    ~Point();//d'tor
    double getX() const;
    int getXint() const;
    double getY() const;
    int getYint() const;
    void setX(double temp);
    void setY(double temp);
    void setPoint(Point& temp);
    //Override operator
    Point operator+(const Point& p) const;//Override operator
    Point operator-(const Point& p) const;//Override operator
    Point& operator=(const Point& rhs);//Override operator
    Point& operator*(double rhs);//Override operator



};
#endif //_POINT_h
