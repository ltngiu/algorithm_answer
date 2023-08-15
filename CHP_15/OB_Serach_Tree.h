#ifndef OBST
#define OBST
template<class T> class Binary_Tree{
    pubilc:
        Binary_Tree_Node<T>* Root_Node;

};

template<class T> class Binary_Tree_Node{
    pubilc:
        T data;
        Binary_Tree_Node<T>* Left_Child;
        Binary_Tree_Node<T>* Right_Child;
        Binary_Tree_Node<T>(T data_in):data(data_in), Left_Child(NULL), Right_Child(NULL){}
        
};
#endif