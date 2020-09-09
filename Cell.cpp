#include "Cell.h"
/********************************************/
Cell::Cell():counter(0){} //c'tor
/********************************************/
Cell::Cell(int i):counter(i){}//c'tor
/********************************************/
Cell::Cell(Cell& p):counter(p.counter){}//c'tor
/********************************************/
Cell::~Cell(){}//d'tor
/********************************************/
Cell& Cell::operator=(const Cell& rhs){ //Override operator
    if(this==&rhs) return *this;
    else counter=rhs.counter;
    return *this;
 }
/********************************************/
Cell& Cell::operator++() { //Override operator
    counter++;
    return *this;
 }
/********************************************/
const Cell Cell::operator++(int){ //Override operator
    Cell temp = *this;
    counter++;
    return temp; // the result before addition
 }
/********************************************/
Cell& Cell::operator--() { //Override operator
    counter--;
    return *this;
 }
/********************************************/
const Cell Cell::operator--(int){ //Override operator
    Cell temp = *this;
    counter--;
    return temp; // the result before addition
 }
/********************************************/
int Cell::GetCounter() const{
    return counter;
 }
/********************************************/
