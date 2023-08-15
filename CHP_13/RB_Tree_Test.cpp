#include "red_black_tree.c"
#include<vector>
#include<iostream>
int main()
{

    std::vector<double> arra = { 16, 3, 7, 11, 9, 26, 18, 14, 15, 20, 100,0,1,2,5};
	RB_Tree<double>* m_RB_Tree = new RB_Tree<double>(arra[0]);
    for(auto key = arra.begin() + 1; key != arra.end(); ++key)
        {m_RB_Tree->Insert_Node(*key);}
    if(m_RB_Tree->Check())
        std::cout<< "生成的红黑树是合法的" << std::endl;
    for(auto key = arra.begin(); key != arra.end(); ++key)
    {
        m_RB_Tree->Delete_Node(*key);
        if(m_RB_Tree->Check())
            std::cout<< "删除节点" << *key <<"后，生成的红黑树是合法的" << std::endl;
        m_RB_Tree->Insert_Node(*key);
        if(m_RB_Tree->Check())
            std::cout<< "重新插入节点" << *key << "后，生成的红黑树也是合法的" << std::endl;
    }

	return 0;
}