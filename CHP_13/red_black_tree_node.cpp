
#include "red_black_tree_node.h"

template <class T>
RB_Tree_Node<T>::RB_Tree_Node(T data_in):data(data_in),color_tag(colour::RED),Left_child(NULL),Right_child(NULL),Father_Node(NULL)
{
}
template <class T>
RB_Tree_Node<T>::RB_Tree_Node(T data_in, colour color_in):data(data_in),color_tag(color_in),Left_child(NULL),Right_child(NULL),Father_Node(NULL)
{
}
template <class T>
RB_Tree_Node<T>::~RB_Tree_Node(void)
{
}