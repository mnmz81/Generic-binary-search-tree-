#include "Team.h"

using namespace std;
/**************************************************/
Team::Team():
team(new GTree<Player>()),NumOfPlayer(10),eucli(new EuclideanSpace()),GloblBast(new Point()),
 FinishPoint(new Point()),cournntPlayer(0),BestOne(-1)
 {
     
 }
/**************************************************/
Team::Team(int n):
 team(new GTree<Player>()),NumOfPlayer(n),eucli(new EuclideanSpace()),
 GloblBast(new Point()),FinishPoint(new Point()),cournntPlayer(0),BestOne(-1)
 {
 }
/**************************************************/
Team::Team(Team& temp):
 team(new GTree<Player>()),NumOfPlayer(temp.GetNumOfPl()),eucli(new EuclideanSpace(temp.GetSpace())),
 GloblBast(new Point()),FinishPoint(new Point()),cournntPlayer(temp.GetCournntPlayer()),BestOne(temp.GetBestOne())
 {
    *GloblBast=temp.GetGloblBast();
    *FinishPoint=temp.GetFinishPoint();
    *team=*temp.team;
 }
/**************************************************/
Team::~Team()
 {
     delete team;
     delete eucli;
     delete GloblBast;
     delete FinishPoint;
 }
/**************************************************/
Team& Team::operator=(const Team& rhs){
    if(this==&rhs) // copying from the same object
    return *this;
    else{
        NumOfPlayer=rhs.GetNumOfPl();
        *eucli=rhs.GetSpace();
        *GloblBast=rhs.GetGloblBast();
        *FinishPoint=rhs.GetFinishPoint();
        cournntPlayer=rhs.GetCournntPlayer();
        BestOne=rhs.GetBestOne();
        *team=*rhs.team;
    }
    return *this;
 }
/**************************************************/
EuclideanSpace Team::GetSpace() const{
    EuclideanSpace temp(*eucli);
    return temp;
 }
/**************************************************/
int Team::GetBestOne() const{
    return BestOne;
 }
/**************************************************/
int Team::GetNumOfPl() const{
    return NumOfPlayer;
 }
/**************************************************/
Point Team::GetGloblBast() const{
    Point temp(*GloblBast);
    return temp;
 }
/**************************************************/
Point Team::GetFinishPoint() const{
    Point temp(*FinishPoint);
    return temp;
 }
/**************************************************/
int Team::GetCournntPlayer() const{
    return cournntPlayer;
 }
/**************************************************/
void Team::AddPlayer(Player* temp){
   if(cournntPlayer+1==NumOfPlayer) NumOfPlayer*=2;
   team->Insert(temp);
   cournntPlayer++;
 }
/**************************************************/ 
void Team::UpDatePlace(){
    Player temp;
    for(int i=0;i<cournntPlayer;i++){
        temp.SetSymbol(i);
        team->Search(temp)->getData()->UpdatePlace();
        eucli->CheckPointDim(team->Search(temp)->getData()->GetPlace());
    }
 }
/**************************************************/ 
void Team::UpDateSpeed(){
    Player temp;
    for(int i=0;i<cournntPlayer;i++){
        temp.SetSymbol(i);
        team->Search(temp)->getData()->UpdateSpeed(*GloblBast);
    }
 }
/**************************************************/
void Team::UpDatePerBast(){
    double min,temp;
    Player temp1;
    Player* temp3;
    for(int i=0;i<cournntPlayer;i++){
        temp1.SetSymbol(i);
        temp3=team->Search(temp1)->getData();
        min=eucli->GetDis(*temp3->GetPlace(),*FinishPoint);
        temp=eucli->GetDis(*temp3->GetPersonalRecord(),*FinishPoint);
        if(temp<min)
            temp3->SetPersonalRecord(*temp3->GetPlace());
    }
 }
/**************************************************/
void Team::UpDateGloblBast(){
    double min,temp;
    Player temp1;
    Player* temp3;
    for(int i=0;i<cournntPlayer;i++){
        temp1.SetSymbol(i);
        temp3=team->Search(temp1)->getData();
        min=eucli->GetDis(*GloblBast,*FinishPoint);
        temp=eucli->GetDis(*temp3->GetPersonalRecord(),*FinishPoint);
        if(temp<min){
            *GloblBast=*temp3->GetPersonalRecord();
            BestOne=temp3->GetSymbol();
        }
    }
 }
/**************************************************/
bool Team::IfFinish(){
    double temp;
    temp=eucli->GetDis(*FinishPoint,*GloblBast);
    if(temp==0) return true;
    return false;
 }
/**************************************************/
void Team::PrintTeam(){
        team->PrintTree();
 }
/**************************************************/
void Team::BefordMove(){
    Player temp1;
    Player* temp3;
    for(int i=0;i<cournntPlayer;i++){
        temp1.SetSymbol(i);
        temp3=team->Search(temp1)->getData();
        eucli->SubToCell(*temp3->GetPlace());
    }
 }
/**************************************************/
void Team::AfterMove(){
    Player temp1;
    for(int i=0;i<cournntPlayer;i++){
        temp1.SetSymbol(i);
        eucli->AddToCell(*team->Search(temp1)->getData()->GetPlace());
    }
 }
/**************************************************/
void Team::SetGloblBast(){
    Player temp1;
    temp1.SetSymbol(0);
    *GloblBast=*team->Search(temp1)->getData()->GetPersonalRecord();
 }
/**************************************************/
void Team::SetFinishPoint(Point& p){
    *FinishPoint=p;
}
/**************************************************/