#include "Player.h"



class Forwards:public Player
{
private:
public:
    Forwards();
    Forwards(int i);//c'tor
    Forwards(int sy,Point& pla,Point& spee);//c'tor
    Forwards(Forwards& temp);//c'tor
    void UpdateSpeed(Point& GlobalRecord);
};

