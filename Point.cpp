#include "Point.h"

using namespace std;
/********************************************/
Point::Point(double xp,double yp):x(xp),y(yp){}
/********************************************/
Point::Point():x(0),y(0){}
/********************************************/
Point::Point(Point& temp):x(temp.x),y(temp.y){}
/********************************************/
Point::~Point(){}
/********************************************/
double Point::getX() const{return x;}
/********************************************/
int Point::getXint() const{return x;}
/********************************************/
double Point::getY() const{return y;}
/********************************************/
int Point::getYint() const{return y;}
/********************************************/
void Point::setY(double temp){y=temp;}
/********************************************/
void Point::setX(double temp){x=temp;}
/********************************************/
Point Point::operator+(const Point& p) const{
    Point temp((x+p.x),(y+p.y));
    return temp;
 }
/********************************************/
Point Point::operator-(const Point& p) const{
    Point temp((x-p.x),(y-p.y));
    return temp;
 }
/********************************************/
Point& Point::operator=(const Point& rhs){
    if(this==&rhs) // copying from the same object
    return *this;
    else{
        x=rhs.x;
        y=rhs.y;
    }
    return *this;
 }
/********************************************/
Point& Point::operator*(double rhs){
    x*=rhs;
    y*=rhs;
    return *this;
 }
/********************************************/






