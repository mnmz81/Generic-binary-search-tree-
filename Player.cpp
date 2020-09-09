#include "Player.h"

using namespace std;
/********************************************/
Player::Player():type('O'),symbol(0),place(new Point()),speed(new Point(1,1)),PersonalRecord(new Point()){}
/********************************************/
Player::Player(int sy,Point& pla,Point& spee):type('O'),symbol(sy),place(new Point(pla)),speed(new Point(spee)),PersonalRecord(new Point(pla)){}
/********************************************/
Player::Player(int n):type('O'),symbol(n),place(new Point()),speed(new Point(1,1)),PersonalRecord(new Point())
 {

 }
/********************************************/
Player::~Player(){
    delete place;
    delete speed;
    delete PersonalRecord;
 }
/********************************************/
Player& Player::operator=(const Player& rhs){
    if(this==&rhs) // copying from the same object
    return *this;
    else{
        type=rhs.type;
        symbol=rhs.symbol;
        *place=*rhs.place;
        *speed=*rhs.speed;
        *PersonalRecord=*rhs.PersonalRecord;
    }
    return *this;
 }
/********************************************/
Player::Player(Player& temp):type(temp.type),symbol(temp.GetSymbol()),place(new Point()),speed(new Point()),PersonalRecord(){
    *place=*temp.place;
    *speed=*temp.speed;
    *PersonalRecord=*temp.PersonalRecord;
 }
/********************************************/
int Player::GetSymbol() const{return symbol;}
/********************************************/
void Player::SetSymbol(int i){symbol=i;}
/********************************************/
Point* Player::GetPlace() const{return place;}
/********************************************/
Point* Player::GetPersonalRecord() const{return PersonalRecord;}
/********************************************/
double Player::GetRandomNum(){return ((double)(rand())/RAND_MAX);}
/********************************************/
void Player::UpdatePlace(){*place=*place+*speed;}
/********************************************/
void Player::UpdateSpeed(Point& GlobalRecord){
    Point temp1,temp2,temp3;
    temp1=(*speed)*0.25;
    temp2=(*PersonalRecord-(*place))*GetRandomNum();
    temp3=(GlobalRecord-(*place))*GetRandomNum();
    *speed=temp1+temp2+temp3;
 }
/********************************************/
void Player::PrintPlace() const{
    double x,y;
    x=(int)(place->getX()*100);
    y=(int)(place->getY()*100);
    cout<<type << x/100<<" "<< y/100; 
 }
/********************************************/
void Player::SetPersonalRecord(Point& temp){
    *PersonalRecord=temp;
 }
/********************************************/
void Player::SetPlace(Point& t){
    *place=t;
 }
/********************************************/
void Player::SetSpeed(Point& t){
    *speed=t;
 }
/********************************************/
bool operator==(const Player& lhs, const Player& rhs){
    return (lhs.GetSymbol() == rhs.GetSymbol());
}
/******************************/
bool operator<(const Player& lhs, const Player& rhs)
{
    return (lhs.GetSymbol() < rhs.GetSymbol());
}
/******************************/
bool operator>(const Player& lhs, const Player& rhs){
    return (lhs.GetSymbol() > rhs.GetSymbol());
}
/******************************/
ostream& operator<<(ostream& out, const Player& temp){
    double x,y;
    x=(int)(temp.GetPlace()->getX()*100);
    y=(int)(temp.GetPlace()->getY()*100);
    out<<temp.GetType()<<" "<< x/100<< " "<<y/100;
    return out;
 }
/******************************/
char Player::GetType()const {return type;}
/******************************/
void Player::SetType(char t){type=t;}
/******************************/