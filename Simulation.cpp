#include "Simulation.h"

using namespace std;

Simulation::Simulation():t(new Team()),time1(10000),NumOfPlayer(10),finishPoint(new Point(10,10)){}
/**************************************************/
Simulation::Simulation(int ctime1,Point& finalp,int NumOfPlay):t(new Team(NumOfPlay)),time1(ctime1),NumOfPlayer(NumOfPlay),finishPoint(new Point(finalp)){}
/**************************************************/
Simulation::Simulation(Simulation& temp):
t(new Team(*temp.t)),time1(temp.time1),NumOfPlayer(temp.NumOfPlayer),finishPoint(new Point(*temp.finishPoint)){
 }
/**************************************************/
Simulation::Simulation(char* a,char* b){
   double x,y;
   Point start,speed;
   char type;
   Player* temp;
   std::ifstream input_file1(a);
   std::ifstream input_file2(b);
   if (!input_file1) Error();
   if (!input_file2) Error();
   if(!(input_file1>>x>>y)) Error();
   if(!(input_file1>>time1))Error();
   if(!(input_file2>>NumOfPlayer))Error();
   finishPoint=new Point(x,y);
   t=new Team(NumOfPlayer);
   t->SetFinishPoint(*finishPoint);
   for(int i=0;i<NumOfPlayer;i++){
      if(!(input_file2>>type)) Error();
      if(!(input_file2>>x>>y)) Error();
      start.setX(x);
      start.setY(y);
      if(!(input_file2>>x>>y)) Error();
      speed.setX(x);
      speed.setY(y);
      if(type=='F'){temp=new Forwards(i,start,speed);}
      else{
          if(type=='G'){temp=new Goalie(i,start,speed);}
          else{
            if(type=='D'){temp=new Defensemen(i,start,speed);}
            else Error();
         }
   }
   t->AddPlayer(temp);  
 }
 if((input_file2>>x))Error();
}
/**************************************************/
Simulation::~Simulation(){
    delete t;
    delete finishPoint;
 }
/**************************************************/
Simulation& Simulation::operator=(const Simulation& rhs){
    if(this==&rhs) // copying from the same object
    return *this;
    else{
       t=rhs.t;
       time1=rhs.time1;
       NumOfPlayer=rhs.NumOfPlayer;
    }
    return *this;
 }
/**************************************************/
void Simulation::PrintPoint() const{
   std::cout << NumOfPlayer << '\n';
   std::cout << finishPoint->getX() << '\n';
   std::cout << finishPoint->getY() << '\n';
 }
/**************************************************/
void Simulation::Run(){
   int i=0;
   t->SetGloblBast();
   while(i<time1){
      t->UpDateGloblBast();;
      t->BefordMove();
      t->UpDatePlace();
      t->AfterMove();
      t->UpDateSpeed();
      if(t->IfFinish()==true) break;
      i++;
   }
   cout<<i<<endl;
   t->PrintTeam();
   return;
 }
/**************************************************/
void Simulation::Error() {
    cerr << "ERROR: Invalid input."<<endl;
    exit(1);
 }
/**************************************************/