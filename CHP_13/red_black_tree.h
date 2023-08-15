#ifndef RB_TREE_H
#define RB_TREE_H
//#pragma once
#include<cstdio>
#include<iostream>
#include"red_black_tree.h"
template <class T>
class RB_Tree
{
public:
	RB_Tree(T Root_Data);
	~RB_Tree();	
	void Left_Rotate(RB_Tree_Node<T>* current_Node);
	//左旋
	void Right_Rotate(RB_Tree_Node<T>* current_Node);
	//右旋
	void Insert_Node(T insert_data);
	//插入节点
	int Delete_Node(T delete_data);
	//删除节点
    void RB_Transplant(RB_Tree_Node<T>* current_Node, RB_Tree_Node<T>* next_Node);
	//移植
	void Fix_Tree(RB_Tree_Node<T>* current_Node);
	//插入节点后修复红黑树的性质
	void erase_Node(RB_Tree_Node<T>* Node_del);
    bool Check_rule(RB_Tree_Node<T>* root, int blackNum,int CBNum);
    bool Check();
	void Fix_Tree_Delete(RB_Tree_Node<T>* current_Node);
	//删除节点后修复红黑树的性质
	RB_Tree_Node<T>* Find_Successor_Node(RB_Tree_Node<T>* current_Node);
	//寻找后继节点
	RB_Tree_Node<T>* Root_Node;	
    RB_Tree_Node<T>* T_NIL = new RB_Tree_Node<T>(0, colour::BLACK);
	
    //信标节点
};

#endif