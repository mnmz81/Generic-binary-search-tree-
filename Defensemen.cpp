#include "Defensemen.h"

/****************************************/
Defensemen::Defensemen():Player(){
    this->SetType('D');
 }
/****************************************/
Defensemen::Defensemen(int i):Player(i){
    this->SetType('D');
 }
/****************************************/
Defensemen::Defensemen(int sy,Point& pla,Point& spee):Player(sy,pla,spee){
    this->SetType('D');
 }
/****************************************/
Defensemen::Defensemen(Defensemen& temp):Player(temp){}
/****************************************/
void Defensemen::UpdateSpeed(Point& GlobalRecord){
    Point temp1,temp2,temp3;
    double a=0.05,b=1.0,c=0.0;
    temp1=(*speed)*a;
    temp2=((*PersonalRecord-(*place))*GetRandomNum())*b;
    temp3=((GlobalRecord-(*place))*GetRandomNum())*c;
    *speed=temp1+temp2+temp3;
 }
/****************************************/
