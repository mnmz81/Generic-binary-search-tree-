#ifndef _PLAYER_h
#define _PLAYER_h
#include "Point.h"
#include <stdlib.h>
#include <ostream>
//this class present player in the game
 

using namespace std;

class Player
{
protected:
    char type;
    int symbol; 
    Point* place;
    Point* speed;
    Point* PersonalRecord;
public:
    Player();
    Player(int i);//c'tor
    Player(int sy,Point& pla,Point& spee);//c'tor
    Player(Player& temp);//c'tor
    ~Player();//d'tor
    int GetSymbol() const;//getter
    void SetSymbol(int i);//setter
    Point* GetPlace() const;//getter
    void SetPlace(Point& t);//setter
    void UpdatePlace();//updata place
    void SetSpeed(Point& t);//setter
    void UpdateSpeed(Point& GlobalRecord);//updata speed
    char GetType() const;
    void SetType(char t);
    Point* GetPersonalRecord() const;//getter
    double GetRandomNum();//getter
    void SetPersonalRecord(Point& temp);//setter
    void PrintPlace() const;//print place
    Player& operator=(const Player& rhs);//Override operator
    friend bool operator==(const Player& lhs, const Player& rhs);
    friend bool operator<(const Player& lhs, const Player& rhs);
    friend bool operator>(const Player& lhs, const Player& rhs);
    friend ostream& operator<<(ostream&, const Player&);
};
#endif
/******************************/