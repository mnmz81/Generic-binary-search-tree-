#include "Player.h"

 
class Defensemen:public Player
{
private:
    /* data */
public:
    Defensemen();
    Defensemen(int i);//c'tor
    Defensemen(int sy,Point& pla,Point& spee);//c'tor
    Defensemen(Defensemen& temp);//c'tor
    void UpdateSpeed(Point& GlobalRecord);
};
