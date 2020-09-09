#include "Forwards.h"
/****************************************/
Forwards::Forwards():Player(){
    this->SetType('F');
 }
/****************************************/
Forwards::Forwards(int i):Player(i){
    this->SetType('F');
 }
/****************************************/
Forwards::Forwards(int sy,Point& pla,Point& spee):Player(sy,pla,spee){
    this->SetType('F');
 }
/****************************************/
Forwards::Forwards(Forwards& temp):Player(temp){}
/****************************************/
void Forwards::UpdateSpeed(Point& GlobalRecord){
    Point temp1,temp2,temp3;
    double a=0.25,b=1.0,c=1.0;
    temp1=(*speed)*a;
    temp2=((*PersonalRecord-(*place))*GetRandomNum())*b;
    temp3=((GlobalRecord-(*place))*GetRandomNum())*c;
    *speed=temp1+temp2+temp3;
 }
/****************************************/
