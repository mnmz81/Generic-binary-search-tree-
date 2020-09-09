#ifndef _CELL_H_
#define _CELL_H_
//this class presenter one cell in the euclideasn spaces

class Cell
{
private:
    int counter;
public:
    Cell();//c'tor
    Cell(int i);//c'tor
    Cell(Cell& p);//c'tor
    ~Cell();//d'tor
    int GetCounter() const;
    //Override operator
    Cell& operator=(const Cell& rhs);
    Cell& operator++();
    const Cell operator++(int);
    Cell& operator--();
    const Cell operator--(int);
};
#endif