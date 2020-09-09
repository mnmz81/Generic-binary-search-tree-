#include "Goalie.h"


/****************************************/
Goalie::Goalie():Player(){
    this->SetType('G');
 }
/****************************************/
Goalie::Goalie(int i):Player(i){
    this->SetType('G');
 }
/****************************************/
Goalie::Goalie(int sy,Point& pla,Point& spee):Player(sy,pla,spee){
    this->SetType('G');
 }
/****************************************/
Goalie::Goalie(Goalie& temp):Player(temp){}
/****************************************/
void Goalie::UpdateSpeed(Point& GlobalRecord){
    Point temp1,temp2,temp3;
    double a=0.01,b=-0.1,c=-0.25;
    temp1=(*speed)*a;
    temp2=((*PersonalRecord-(*place))*GetRandomNum())*b;
    temp3=((GlobalRecord-(*place))*GetRandomNum())*c;
    *speed=temp1+temp2+temp3;
 }
/****************************************/

