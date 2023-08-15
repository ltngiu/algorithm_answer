#include "red_black_tree.h"
template <class T>
//构造函数
RB_Tree<T>::RB_Tree(T Root_Data):Root_Node(NULL)
{	
	if (Root_Node == NULL)
	{
		Root_Node = new RB_Tree_Node<T>(Root_Data);
		Root_Node->color_tag = colour::BLACK;
        Root_Node->Father_Node = T_NIL;
        Root_Node->Left_child = T_NIL;
        Root_Node->Right_child = T_NIL;
        T_NIL->color_tag = colour::BLACK;
	}
}
//析构函数
template <class T>
RB_Tree<T>::~RB_Tree()
{
}
/************************************************************************/
/* 函数功能：向红黑树中插入一个节点                                        */
// 入口参数：插入的数据                                                   */
// 返回值：无                                                            */
/************************************************************************/
template <class T>
void RB_Tree<T>::Insert_Node(T insert_data){
    RB_Tree_Node<T> * y = T_NIL;
    RB_Tree_Node<T> * x = Root_Node;
    RB_Tree_Node<T> * Inserted_Node = new RB_Tree_Node<T>(insert_data);
    while(x != T_NIL){
        y = x;
        if(x->data > insert_data)
            x = x->Left_child;
        else x = x->Right_child;
    }
    Inserted_Node->Father_Node = y;
    if(y == NULL){
        Root_Node = Inserted_Node;
        Inserted_Node->Left_child = Inserted_Node->Right_child = Inserted_Node->Father_Node = T_NIL;
    }
    else if(y->data > Inserted_Node->data) y->Left_child = Inserted_Node;
    else y->Right_child = Inserted_Node;
    Inserted_Node->Left_child = T_NIL;
    Inserted_Node->Right_child = T_NIL;
    Inserted_Node->color_tag = colour::RED;
    // std::cout << Inserted_Node->color_tag << " " << y->color_tag << std::endl;
    if(Inserted_Node->color_tag == Inserted_Node->Father_Node->color_tag) {Fix_Tree(Inserted_Node);}
    // std::cout << Inserted_Node->color_tag << " " << y->color_tag << std::endl;
}

/************************************************************************/
/* 函数功能：从红黑树中搜寻要删除的数据节点                             */
// 入口参数：删除的数据
// 返回值：1表示删除成功 -1表示删除失败
/************************************************************************/
template<class T>
int RB_Tree<T>::Delete_Node(T delete_data){
    RB_Tree_Node<T>* Deleted_Node = Root_Node;
    RB_Tree_Node<T> * Temp_Node = NULL;  
    RB_Tree_Node<T>* Temp = NULL;
    RB_Tree_Node<T> *Successor_Node;
    while(Deleted_Node->data != delete_data && Deleted_Node != T_NIL){
        if(delete_data > Deleted_Node->data && Deleted_Node->Right_child!=T_NIL) 
            Deleted_Node = Deleted_Node->Right_child;
        else Deleted_Node = Deleted_Node->Left_child;
    }
    if(Deleted_Node != T_NIL){//找到了需要删除的数据
        Temp_Node = Deleted_Node;
        colour color_tag = Temp_Node->color_tag;
        if(Deleted_Node->Left_child == T_NIL){
            Temp = Deleted_Node->Right_child;
            RB_Transplant(Deleted_Node, Deleted_Node->Right_child);
        }
        else if(Deleted_Node->Right_child == T_NIL){
            Temp = Deleted_Node->Left_child;
            RB_Transplant(Deleted_Node, Deleted_Node->Left_child);
        }
        else{
            Temp_Node = Find_Successor_Node(Deleted_Node);
            color_tag = Temp_Node->color_tag;
            Temp = Temp_Node->Right_child;
            if(Temp_Node->Father_Node == Deleted_Node) Temp->Father_Node = Temp_Node;
            else{
                RB_Transplant(Temp_Node, Temp_Node->Right_child);
                Temp_Node->Right_child = Deleted_Node->Right_child;
                Temp_Node->Right_child->Father_Node = Temp_Node;
            }
            RB_Transplant(Deleted_Node, Temp_Node);
            Temp_Node->Left_child = Deleted_Node->Left_child;
            Temp_Node->Left_child->Father_Node = Temp_Node;
            Temp_Node->color_tag = Deleted_Node->color_tag;
        }
        if(color_tag == colour::BLACK){
            Fix_Tree_Delete(Temp);
        }
    }//找到了需要删除的数据
    else return -1;
    return 1;
}
/************************************************************************/
/* 函数功能：删除节点的辅助函数，将一棵子树替换为另一棵子树                      */
// 入口参数：插入的当前节点
// 返回值：无
/************************************************************************/
template<class T>
void RB_Tree<T>::RB_Transplant(RB_Tree_Node<T>* current_Node, RB_Tree_Node<T>* next_Node){
    if(current_Node->Father_Node == T_NIL){
        Root_Node = next_Node;
        }
    else if(current_Node->Father_Node->Left_child == current_Node){
        current_Node->Father_Node->Left_child = next_Node;
        }
    else current_Node->Father_Node->Right_child = next_Node;
    next_Node->Father_Node = current_Node->Father_Node;
    
}
/************************************************************************/
/* 函数功能：插入节点后修整红黑树，保证满足性质                         */
// 入口参数：插入的当前节点
// 返回值：无
/************************************************************************/
template <class T>
void RB_Tree<T>::Fix_Tree(RB_Tree_Node<T>* current_Node){
    RB_Tree_Node<T>* temp_current = current_Node;
    RB_Tree_Node<T>* Uncle_Node;
    while (temp_current->Father_Node->color_tag == colour::RED){

        RB_Tree_Node<T>* father_Node = temp_current->Father_Node;
        RB_Tree_Node<T>* Grand_Node = father_Node->Father_Node;
        if(Grand_Node != T_NIL){//如果祖父节点非空
            if(Grand_Node->Left_child == father_Node){//如果当前节点的父节点是祖父节点的左孩子
                Uncle_Node = Grand_Node->Right_child;
                if(Uncle_Node != T_NIL){//如果叔叔节点非空
                    if(Uncle_Node->color_tag == colour::RED){//如果叔叔节点非空且是红色
                        Uncle_Node->color_tag = colour::BLACK;
                        father_Node->color_tag = colour::BLACK;
                        Grand_Node->color_tag = colour::RED;
                        temp_current = Grand_Node;
                    }//如果叔叔节点非空且是红色
                    else if(temp_current == father_Node->Right_child){//如果叔叔节点是非空黑色且当前节点是父节点的右孩子
                        temp_current = temp_current->Father_Node;
                        Left_Rotate(temp_current);
                    }//如果叔叔节点非空是黑色且当前节点是父节点的右孩子
                    else{//如果叔叔节点非空是黑色且当前节点是父节点的左孩子
                        father_Node->color_tag = colour::BLACK;
                        Grand_Node->color_tag = colour::RED;
                        Right_Rotate(Grand_Node);
                    }//如果叔叔节点非空是黑色且当前节点是父节点的左孩子
                }//如果叔叔节点非空
                else{//如果叔叔节点为空
                    if(temp_current == father_Node->Right_child){//如果叔叔节点为空且当前节点为父节点的右孩子
                        temp_current = temp_current->Father_Node;
                        Left_Rotate(temp_current);
                    }//如果叔叔节点为空且当前节点为父节点的右孩子
                    else{//如果叔叔节点为空且当前节点为父节点的左孩子
                        father_Node->color_tag = colour::BLACK;
                        Grand_Node->color_tag = colour::RED;
                        Right_Rotate(Grand_Node);
                    }//如果叔叔节点为空且当前节点为父节点的左孩子
                }//如果叔叔节点为空
            }//如果当前节点的父节点是祖父节点的左孩子
            else{//如果当前节点的父节点是祖父节点的右孩子
                Uncle_Node = Grand_Node->Left_child;
                if(Uncle_Node != T_NIL){//如果叔叔节点非空
                    if(Uncle_Node->color_tag == colour::RED){//如果叔叔节点非空且是红色的
                        Uncle_Node->color_tag = colour::BLACK;
                        father_Node->color_tag = colour::BLACK;
                        Grand_Node->color_tag = colour::RED;
                        temp_current = Grand_Node; 
                    }//如果叔叔节点非空且是红色的
                    else if(temp_current == father_Node->Left_child){//如果叔叔节点非空且是黑色的且当前节点是父节点的左孩子
                        temp_current = temp_current->Father_Node;
                        Right_Rotate(temp_current);
                    }//如果叔叔节点非空且是黑色的且当前节点是父节点的左孩子
                    else{//如果叔叔节点非空且是黑色的且当前节点是父节点的右孩子
                        father_Node->color_tag = colour::BLACK;
                        Grand_Node->color_tag = colour::RED;
                        Left_Rotate(Grand_Node);
                    }//如果叔叔节点非空且是黑色的且当前节点是父节点的右孩子
                }//如果叔叔节点非空
                else {//如果叔叔节点是空的
                    if(temp_current == father_Node->Left_child){//如果当前节点是左孩子
                        temp_current = temp_current->Father_Node;
                        Right_Rotate(temp_current);
                    }//如果当前节点是左孩子
                    else{//如果当前节点是右孩子
                        father_Node->color_tag = colour::BLACK;
                        Grand_Node->color_tag = colour::RED;
                        Left_Rotate(Grand_Node);
                    }//如果当前节点是右孩子
                }//如果叔叔节点是空的
            }//如果当前节点的父节点是祖父节点的右孩子
        }//如果祖父节点非空
    }//while(True)
    Root_Node->color_tag = colour::BLACK;
}
/************************************************************************/
/* 函数功能：删除节点后修正红黑树，保证性质满足                                */
// 入口参数：被删除的当前节点
// 返回值：无
/************************************************************************/
template<class T>
void RB_Tree<T>::Fix_Tree_Delete(RB_Tree_Node<T>* current_Node){
    RB_Tree_Node<T>* Temp_Node;
    while(current_Node != Root_Node && current_Node->color_tag == BLACK){
        if(current_Node == current_Node->Father_Node->Left_child){
            Temp_Node = current_Node->Father_Node->Right_child;
            if(Temp_Node->color_tag == colour::RED){
                Temp_Node->color_tag = colour::BLACK;
                current_Node->Father_Node->color_tag = colour::RED;
                Left_Rotate(current_Node->Father_Node);
                Temp_Node = current_Node->Father_Node->Right_child;
            }
            if(Temp_Node->Left_child->color_tag == colour::BLACK && Temp_Node->Right_child->color_tag == colour::BLACK){
                Temp_Node->color_tag = colour::RED;
                current_Node = current_Node->Father_Node;
            }
            else if(Temp_Node->Right_child->color_tag == colour::BLACK){
                Temp_Node->Left_child->color_tag = colour::BLACK;
                Temp_Node->color_tag = colour::RED;
                Right_Rotate(Temp_Node);
                Temp_Node = current_Node->Father_Node->Right_child;
            }
            else{
                Temp_Node->color_tag = Temp_Node->Father_Node->color_tag;
                Temp_Node->Father_Node->color_tag = colour::BLACK;
                Temp_Node->Right_child->color_tag = colour::BLACK;
                Left_Rotate(current_Node->Father_Node);
                current_Node = Root_Node;
            }
        }
        else{
            Temp_Node = current_Node->Father_Node->Left_child;
            if(Temp_Node->color_tag == colour::RED){
                Temp_Node->color_tag = colour::BLACK;
                current_Node->Father_Node->color_tag = colour::RED;
                Right_Rotate(current_Node->Father_Node);
                Temp_Node = current_Node->Father_Node->Left_child;
            }
            if(Temp_Node->Right_child->color_tag == colour::BLACK && Temp_Node->Left_child->color_tag == colour::BLACK){
                Temp_Node->color_tag = colour::RED;
                current_Node = current_Node->Father_Node;
            }
            else if(Temp_Node->Left_child->color_tag == colour::BLACK){
                Temp_Node->Right_child->color_tag = colour::BLACK;
                Temp_Node->color_tag = colour::RED;
                Left_Rotate(Temp_Node);
                Temp_Node = current_Node->Father_Node->Left_child;
            }
            else{
                Temp_Node->color_tag = Temp_Node->Father_Node->color_tag;
                Temp_Node->Father_Node->color_tag = colour::BLACK;
                Temp_Node->Left_child->color_tag = colour::BLACK;
                Right_Rotate(current_Node->Father_Node);
                current_Node = Root_Node;
            }
        }
    }//while
    current_Node->color_tag = colour::BLACK;
}
/************************************************************************/
/* 函数功能：对当前节点进行左旋操作                                     */
// 入口参数：左旋的当前节点
// 返回值：无
/************************************************************************/
template <class T>
void RB_Tree<T>::Left_Rotate(RB_Tree_Node<T>* current_Node)
{
    if(current_Node->Right_child == T_NIL) {std::cout<<"要左旋的节点为空！"<<std::endl; return;}
    else{
        RB_Tree_Node<T>* Right_node = current_Node->Right_child; 
        current_Node->Right_child = Right_node->Left_child;
        if(Right_node->Left_child != T_NIL){
            Right_node->Left_child->Father_Node = current_Node;
        }
        Right_node->Father_Node = current_Node->Father_Node;
        if(current_Node->Father_Node == T_NIL){
            Root_Node = Right_node;
        }
        else if(current_Node == current_Node->Father_Node->Left_child){
            current_Node->Father_Node->Left_child = Right_node;
        }
        else current_Node->Father_Node->Right_child = Right_node;
        Right_node->Left_child = current_Node;
        current_Node->Father_Node = Right_node;
        }
}
/************************************************************************/
/* 函数功能：对当前节点进行右旋操作                                     */
// 入口参数：右旋的当前节点
// 返回值：无
/************************************************************************/
template <class T>
void RB_Tree<T>::Right_Rotate(RB_Tree_Node<T>* current_Node){
    if(current_Node->Left_child == T_NIL) {std::cout<<"要右旋的节点为空！" << std::endl;return;}
    else{
        RB_Tree_Node<T>* Left_Node = current_Node->Left_child;
        current_Node->Left_child = Left_Node->Right_child;
        if(Left_Node->Right_child != T_NIL){
            Left_Node->Right_child->Father_Node = current_Node;
        }
        Left_Node->Father_Node = current_Node->Father_Node;
        if(current_Node->Father_Node == T_NIL){
            Root_Node = Left_Node;
        }
        else if(current_Node == current_Node->Father_Node->Left_child){
            current_Node->Father_Node->Left_child = Left_Node;
        }
        else current_Node->Father_Node->Right_child = Left_Node;
        Left_Node->Right_child = current_Node;
        current_Node->Father_Node = Left_Node;
    }
}
/************************************************************************/
/* 函数功能：验证红黑树的合法性                                       */
// 入口参数：无
// 返回值：true表示合法，false表示不合法
/************************************************************************/
template<class T>
bool RB_Tree<T>::Check(){
    int blackNum = 0;
    RB_Tree_Node<T> * cur = Root_Node;
    if(Root_Node->color_tag != colour::BLACK) return false;
    while(cur != T_NIL){
        if(cur->color_tag == colour::BLACK)
            ++blackNum;
        cur = cur->Left_child;
    }
    int CBNum = 0;
    return Check_rule(Root_Node, blackNum, CBNum);
}
/************************************************************************/
/* 函数功能：验证红黑树的合法性的辅助函数                                  */
// 入口参数：根节点，黑高，初始黑色节点数量
// 返回值：true表示合法，false表示不合法
/************************************************************************/

template<class T>
bool RB_Tree<T>:: Check_rule(RB_Tree_Node<T>* root, int blackNum,int CBNum){
    if(root == NULL) return true;
    if(root->color_tag == colour::BLACK){
        ++CBNum;
        if(root->Left_child == T_NIL && root->Right_child == T_NIL){
            if(blackNum == CBNum) return true;
            else{
                std::cout << "叶子节点为" << root->data << "路径的黑色节点数目与最左侧支路的黑色节点数目不等！" << std::endl;
                return false;
            }
        }
    }
    else if(root->Father_Node != T_NIL && root->Father_Node->color_tag == colour::RED){
        std::cout << root->Father_Node->data << "和" << root->data << "为两个连续的红色节点" << std::endl;
        return false;
    }
    return Check_rule(root->Left_child, blackNum, CBNum) && Check_rule(root->Right_child, blackNum, CBNum);
}


/************************************************************************/
/* 函数功能：找寻当前节点的中序后继节点                                 */
// 入口参数：当前节点
// 返回值：当前节点的中序后继节点
/************************************************************************/
template<class T>
RB_Tree_Node<T>* RB_Tree<T>::Find_Successor_Node(RB_Tree_Node<T>* current_Node)
{
    RB_Tree_Node<T>* temp_Node = current_Node->Right_child;
	while(temp_Node->Left_child != T_NIL)
	{
		temp_Node = temp_Node->Left_child;
	}
	return temp_Node;	   
}

/************************************************************************/
/* 函数功能：清除该节点相关的所有信息                                   */
// 入口参数：当前节点
// 返回值：无
/************************************************************************/
template<class T>
void RB_Tree<T>::erase_Node(RB_Tree_Node<T>* Node_del)
{
    if(Node_del->Father_Node){
        Node_del->Father_Node = NULL;
    }
    Node_del->color_tag = NULL;
	Node_del->Father_Node = NULL;
	Node_del->Left_child = NULL;
	Node_del->Right_child = NULL;
	Node_del->data = NULL;	
	delete Node_del;
}