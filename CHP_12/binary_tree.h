#ifndef binary_tree
#define binary_tree
#include<stack>
#include<vector>
#include<iostream>
template<typename T> class Binary_Search_Tree{
    private:
        T data;
        Binary_Search_Tree *lchild;
        Binary_Search_Tree *rchild;
    public:
        Binary_Search_Tree<T>* Find_Min(Binary_Search_Tree<T>* BST);
        //寻找二叉树中最小值
        Binary_Search_Tree<T>* Find_Max(Binary_Search_Tree<T>* BST);
        //寻找二叉树中最大值
        Binary_Search_Tree<T>* Find(Binary_Search_Tree<T>* BST, T data);
        //按值查找节点
        Binary_Search_Tree<T>* Insert(Binary_Search_Tree<T>* BST, T data);
        //插入函数
        Binary_Search_Tree<T>* Create(std::vector<T>& data, int size);
        //二叉搜索树的构造
        void Preorder_Traversal(Binary_Search_Tree<T> *Tree);
        //递归前序遍历
        void Inorder_Traversal(Binary_Search_Tree<T> *Tree);0u
        //递归中序遍历
        void Postor_Traversal(Binary_Search_Tree<T> *Tree);
        //递归后序遍历
        Binary_Search_Tree* Delete(Binary_Search_Tree<T>* BST, T data);
        //删除操作
        Binary_Search_Tree* DeleteMin(Binary_Search_Tree<T>* BST);
        //删除最小值
        Binary_Search_Tree* DeleteMax(Binary_Search_Tree<T>* BST);
         //删除最大值
        bool Judge(Binary_Search_Tree<T>* root, int& MAX);
         //判断是否为二叉排序树
};

#endif