#include "EuclideanSpace.h"

EuclideanSpace::EuclideanSpace():MaxDim(new Point(61,30)),MinDim(new Point()),Area(new Cell*[30]){
    int y=MaxDim->getYint();
    int x=MaxDim->getXint();
    for(int i=0;i<y;i++){
        Area[i]=new Cell[x];
    }
 }
/**************************************************/
EuclideanSpace::EuclideanSpace(Point& max):MaxDim(new Point(max)),MinDim(new Point()),Area(new Cell*[max.getYint()]){
    int y=MaxDim->getYint();
    int x=MaxDim->getXint();
    for(int i=0;i<y;i++){
        Area[i]=new Cell[x];
    }
 }
/**************************************************/
EuclideanSpace::~EuclideanSpace(){
    int y=MaxDim->getYint();
    for(int i=0;i<y;i++){
        delete [] Area[i];
    }
    delete []Area;
    delete MinDim;
    delete MaxDim;
 }
/**************************************************/
void EuclideanSpace::CheckPointDim(Point* check){
     if(check->getX()>MaxDim->getX()) check->setX(MaxDim->getX());
     if(check->getY()>MaxDim->getY()) check->setY(MaxDim->getY());
     if(check->getX()<MinDim->getX()) check->setX(MinDim->getX());
     if(check->getY()<MinDim->getY()) check->setY(MinDim->getX());
 }
/**************************************************/
Point EuclideanSpace::GetMaxDim() const{
    Point copy(MaxDim->getX(),MaxDim->getY());
    return copy;
 }
/**************************************************/
double EuclideanSpace::GetDis(Point& a,Point& b){
    return sqrt(pow((a.getXint()-b.getXint()),2)-pow((a.getYint()-b.getYint()),2));
 }
/**************************************************/
void EuclideanSpace::AddToCell(Point& temp){

    Area[temp.getYint()][temp.getXint()]++;
 }
/**************************************************/
void EuclideanSpace::SubToCell(Point& temp){
     Area[temp.getYint()][temp.getXint()]--;
 }
/**************************************************/
EuclideanSpace& EuclideanSpace::operator=(const EuclideanSpace& rhs){
    if(this==&rhs) // copying from the same object
    return *this;
    else{
        MaxDim->setX(rhs.GetMaxDim().getX());
        MaxDim->setY(rhs.GetMaxDim().getY());
    }
    return *this;
 }
/**************************************************/
int EuclideanSpace::operator() (int i,int j){
    return Area[i][j].GetCounter();
 }
/**************************************************/
