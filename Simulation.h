#ifndef _SIMULATION_h
#define _SIMULATION_h
#include "Team.h"
#include <fstream>
#include <cstdlib>
#include <string>
//this class is the game

class Simulation
{
private:
    Team* t;
    int time1;
    int NumOfPlayer;
    Point* finishPoint;
public:
    Simulation& operator=(const Simulation& rhs);//Override operator
    Simulation();//c'tor
    Simulation(int ctime1,Point& fins,int NumOfPlay);//c'tor
    Simulation(Simulation& temp);//c'tor
    Simulation(char* a,char* b);//c'tor
    ~Simulation();//d'tor
    void AddPlayerToTeam(Player ta);//add player to the team
    void PrintPoint() const;//print all point
    void Run();//run the game
    void Error();//error
};
#endif