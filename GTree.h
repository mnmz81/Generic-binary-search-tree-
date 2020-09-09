#include "GNode.h"
//this class are the tree

template<class T>
class GTree
{
    private:
        GNode<T>* head;
        int counter; // counts the nodes in the GTree
        int id_counter; // counts nodes, including those deleted
        GTree(const GTree<T>& t);
    public:
        GTree():head(0),counter(0),id_counter(0){}
        ~GTree(){delete head;}
        int GetID_counter(){return id_counter;}
        int GetCounter(){return counter;}
        GNode<T>* GetHead(){return head;}
        void Insert(T* pData);
        bool Remove(const T& d); //delete a node
        void Clear(); //delete the entire GTree
        GNode<T>* Search(const T& d);
        GNode<T>* Min();
        GNode<T>* Max();
        void PrintTree();
        GTree<T>& operator=(const GTree<T>& t);
};
/****************************************/
template<class T>
GTree<T>::GTree(const GTree<T>& t):head(new GNode<T>(*t.head)),counter(t.counter),id_counter(t.id_counter){}
/****************************************/
template<class T>
GTree<T>& GTree<T>::operator=(const GTree<T>& t){
    if (this != &t)
    {
       head=t.head;
       counter=t.counter;
       id_counter=t.counter;
    }
    return *this;
 }
/****************************************/
template<class T>
void GTree<T>::Insert(T* pData){
    counter++;
    id_counter++;
    GNode<T> *newNode = new GNode<T>(pData, id_counter);
    if(head!=NULL)
        head->Insert(newNode);
    else
        head = newNode;
 }
/****************************************/
template<class T>
bool GTree<T>::Remove(const T& d){ //delete a node
    if(counter==0) return false;
    head=head->Remove(d,head);
    int i=head->size(head);
    if(i!=counter){
        counter--;
        return true;
    }
    return false;
 }
/****************************************/
// deletes the entire tree
template<class T>
void GTree<T>::Clear(){
    delete head; // initiates recursion
    head = 0;
    counter = id_counter = 0;
 }
/****************************************/
template<class T>
GNode<T>* GTree<T>::Search(const T& d){
    if(counter==0) return 0;
    return head->Search(d);
 }
/****************************************/
template<class T>
GNode<T>* GTree<T>::Min(){
     if(counter==0) return 0;
     return head->getMin();
 }
/****************************************/
template<class T>
GNode<T>* GTree<T>::Max(){
    if(counter==0) return 0;
     return head->getMax();
 }
/****************************************/
template<class T>
void GTree<T>::PrintTree(){
    head->PrintInorder(head);
 }
/****************************************/
