#include"binary_tree.h"
template<typename T> Binary_Search_Tree<T>* Binary_Search_Tree<T>::Find_Min(Binary_Search_Tree<T>* BST){
    Binary_Search_Tree<T>* cur = BST;
    if(cur == NULL){
        return NULL;
    }
    while(cur){
        if(cur->lchild == NULL){
            return cur;
        }
        else   cur = cur->lchild;
    }
}
template<typename T> Binary_Search_Tree<T>* Binary_Search_Tree<T>::Find_Max(Binary_Search_Tree<T>* BST){
    Binary_Search_Tree<T>* cur = BST;
    if(cur == NULL){
        return NULL;
    }
    while(cur){
        if(cur->rchild == NULL){
            return cur;
        }
        else   {cur = cur->rchild;}
    }
}
template<typename T> Binary_Search_Tree<T>* Binary_Search_Tree<T>::
        Find(Binary_Search_Tree<T>* BST, T data){
    Binary_Search_Tree<T>* cur = BST;
    if(cur == NULL){
        return NULL;
    }while(cur){
        if(cur->data == data){
            return cur;
        }else if(cur-data < data){
            cur = cur->lchild;
        }else{
            cur = cur->rchild;
        }
    }
    return cur;
}
template<typename T> Binary_Search_Tree<T>* Binary_Search_Tree<T>::
        Insert(Binary_Search_Tree<T>* BST, T data){
            if(!BST){
                BST = new Binary_Search_Tree;
                BST->data = data;
                BST->lchild = BST->rchild = NULL;
            }else{
                if(data < BST->data){
                    BST->lchild = BST->Insert(BST->lchild, data);
                }
                else if(data > BST->data){
                    BST->rchild = BST->Insert(BST->child, data);
                }
            }
        return BST;
}

template<typename T> Binary_Search_Tree<T>* Binary_Search_Tree<T>::Create(std::vector<T>& data, int size){
    Binary_Search_Tree<T> * BST = NULL;
    for(int i = 0; i < size; ++i){
        BST = this->Insert(BST, data[i]);
    }
    return BST;
}