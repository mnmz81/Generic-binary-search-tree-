#include "Player.h"


class Goalie :public Player
{
private:
    /* data */
public:
    Goalie();
    Goalie(int i);//c'tor
    Goalie(int sy,Point& pla,Point& spee);//c'tor
    Goalie(Goalie& temp);//c'tor
    void UpdateSpeed(Point& GlobalRecord);
};

