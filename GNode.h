#include <iostream>
//this class are for node in the tree
//for this class work need in T class to have:copy c'tor,enmtey c'tor. and Override operator: '==','<','>','<<'

template<class T>
class GNode
{
    private:
        GNode<T> *left, *right,*parent;
        T* pData;
        int item_id;
        GNode(const GNode<T>& temp);
        GNode<T>& operator=(const GNode<T>&temp) ;
    public:
        GNode():left(0),right(0),parent(0),pData(new T),item_id(0){}
        GNode(T* pd, int id):left(0),right(0),parent(0),item_id(id){pData = new T; *pData = *pd;}
        ~GNode(){delete left; delete right; delete pData;}
        GNode<T>* getLeft(){return left;}
        GNode<T>* getRight(){return right;}
        GNode<T>* getParent(){return parent;}
        GNode<T>* getMax();
        GNode<T>* getMin();
        T* getData(){return pData;}
        int getID(){return item_id;}
        void setID(int id){item_id=id;}
        void setLeft(GNode<T>* l){left=l;}
        void setRight(GNode<T>* r){right=r;}
        void setData(const T& d){*pData = d;}
        void Insert(GNode<T>* newNode);
        GNode<T>* Search(const T& d);
        GNode<T>* Remove(const T& d,GNode<T>* root);
        void PrintInorder(GNode<T>* root);
        void Swap(GNode<T>* a,GNode<T>* b);
        int size( GNode<T> *leaf);
};
/****************************************/
template<class T>
GNode<T>::GNode(const GNode<T>& temp):left(temp.left),right(temp.right),pData(new T(*temp.pData)),item_id(temp.item_id){}
/****************************************/
template<class T>
GNode<T>& GNode<T>::operator=(const GNode<T>& temp){
    if(this==&temp) return *this;
    else{
        left=temp.left;
        right=temp.right;
        parent=temp.parent;
        *pData=*temp.pData;
        item_id=temp.item_id;
    }
    return *this;
 }
/****************************************/
template<class T>
void GNode<T>::Insert(GNode<T>* newNode){
    if(*newNode->pData == *pData){
        item_id=newNode->item_id;
        *pData=*newNode->pData;
    }
    if(*pData<*newNode->pData){
        if(right==0){
            right=new GNode<T>;
            right=newNode;
            right->parent=this;
        }
        else
        right->Insert(newNode);
    }
    if(*pData>*newNode->pData){
        if(left==0){
            left=new GNode<T>;
            left=newNode;
            left->parent=this;
        }
        else
        left->Insert(newNode);
    }
    return;
 }
/****************************************/
template <class T>
GNode<T>* GNode<T>::Search(const T& d){
    if(d > *pData){
        if(right==0){
          return 0;  
        }
        else{
            return right->Search(d);
        } 
    }
    if(d < *pData){
        if(left==0){
            return 0;
            }
        else{
          return left->Search(d);  
        } 
    }
    return this;
 }
/****************************************/
template <class T>
GNode<T>* GNode<T>::getMax(){
    return right?right->getMax() :this;
 }
/****************************************/
template <class T>
GNode<T>* GNode<T>::getMin(){
     return left?left->getMin() : this;
 }
/****************************************/
template <class T>
GNode<T>* GNode<T>::Remove(const T& d,GNode<T>* root){
    GNode<T> *node, *node2;
    T *temp;
    node =root->Search(d);
    if (node == 0) return root;
    if (node->left==NULL && node->right==0){
        if (node->parent!=0) {
            if (node->parent->left== node) node->parent->left=0;
            else node->parent->right=0;
            delete node;
            return root;
        } else {
            delete node;
            return NULL;
        }
     } 
    if (node->left!= 0) {
        node2 =node->left->getMax();
        GNode<T> temp1;
        Swap(node,node2);
        node->left=Remove(d,node2);
    } else {
        node2 =node->getRight()->getMin();
        Swap(node,node2);
        node->right=Remove(d,node2);
    }
    return root;
 }
/****************************************/
template <class T>
void GNode<T>::PrintInorder(GNode<T>* root){
    if(root==NULL) return;
    PrintInorder(root->left);
    std::cout <<*root->getData();
    if(root->left!=NULL || root->right!=NULL ) std::cout << '\n';
    PrintInorder(root->right);
 }
/****************************************/
template <class T>
int GNode<T>::size( GNode<T> *leaf){
     if(leaf == NULL) { //This node doesn't exist. Therefore there are no nodes in this 'subtree'
        return 0;
    } else { //Add the size of the left and right trees, then add 1 (which is the current node)
        return size(leaf->getRight()) + size(leaf->getLeft()) + 1;
    }
 }
/****************************************/
template <class T>
void GNode<T>::Swap( GNode<T> *a, GNode<T> *b){
    int temp1;
    T temp2;
    temp2=*a->pData;
    *a->pData=*b->pData;
    *b->pData=temp2;
    temp1=a->item_id;
    a->item_id=b->item_id;
    b->item_id=temp1;
 }
/****************************************/