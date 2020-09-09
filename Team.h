#ifndef _TEAM_h
#define _TEAM_h
#include "Player.h"
#include "EuclideanSpace.h"
#include "GTree.h"
#include "Defensemen.h"
#include "Forwards.h"
#include "Goalie.h"
class Team
{
private:
    GTree<Player>* team;
    int NumOfPlayer;
    EuclideanSpace* eucli;
    Point* GloblBast;
    Point* FinishPoint;
    int cournntPlayer;
    int BestOne;
public:
    Team();//c'tor
    Team(int i);//c'tor
    Team(Team& temp);//c'tor
    ~Team();//d'tor
    Team& operator=(const Team& rhs);//Override operator
    Player* GetPlayerAt(int i) const;//geter
    EuclideanSpace GetSpace() const;//geter
    int GetNumOfPl() const;//geter
    Point GetGloblBast() const;//geter
    Point GetFinishPoint() const;//geter
    int GetCournntPlayer() const;//geter
    void AddPlayer(Player* temp);//add player to the team
    void UpDatePlace();//update all place
    void UpDateSpeed();//update all speedd
    void UpDatePerBast();//update all perBast
    int GetBestOne() const;//getter
    void UpDateGloblBast();//update globl bast
    bool IfFinish();//check if player get to the point;
    void PrintTeam();//print the team
    void BefordMove();//update cell
    void AfterMove();//update cell
    void SetGloblBast();//seter
    void SetFinishPoint(Point& p);//seter
};
#endif