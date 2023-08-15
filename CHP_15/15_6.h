#ifndef D15_6
#define D15_6
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<random>
class tree_node{
    private:
        std::string member_name;            //员工名字
        double score;                       //员工分数
        tree_node* left_child;              //左孩子
        tree_node* right_brother;           //右兄弟
        tree_node* grand;                   //父节点
        int numbers;                        //该员工的编号
        int p_child_num;                    //该节点的下属个数
        bool root = false;        
    public:        
        tree_node():member_name("nothing"), score(0), left_child(NULL), right_brother(NULL), grand(NULL), numbers(0), p_child_num(0), root(false){};
        tree_node(std::string &name, double sc, tree_node* l, tree_node *r, tree_node *f, int num, int childs, bool rot):
            member_name(name), score(sc), left_child(l), right_brother(r), grand(f), numbers(num), p_child_num(childs), root(rot){};
        bool is_root(){return root;};
        tree_node* let(){return left_child;};
        tree_node* rit(){return right_brother;};
        tree_node* fat(){return grand;};
        int nums(){return numbers;};
        int ch_num(){return p_child_num;};
        double scores(){return score;};
        std::string nam(){return member_name;};
};

void company_party_aux(int r, std::vector<int> &s1, std::vector<int> &s2, std::vector<int> &attend, std::vector<tree_node*> &p){
    if(p[r]){
        s1[r] = 0;
        s2[r] = p[r]->scores();
        for(tree_node* key = p[r]->let(); key != NULL; key = key->rit()){
            company_party_aux(key->nums()-1, s1, s2, attend, p);
            if(s1[key->nums() - 1] > s2[key->nums()-1]){
                s1[r] += s1[key->nums() - 1];
            }
            else s1[r] += s2[key->nums() - 1];
        s2[r] += s1[key->nums()-1];
        }
    }
    if(s1[r] > s2[r]) attend[r] = 0;
    else attend[r] = 1;
}
std::vector<std::vector<int>> company_party(int r, std::vector<tree_node*> &p){
    std::vector<int> s1(p.size()), s2(p.size()), attend(p.size());
    std::vector<int> s(1);
    company_party_aux(r, s1, s2, attend, p);
    if(s1[r] > s2[r]){
        s[0] = s1[r];
    }
    else s[0] = s2[r];
    std::vector<std::vector<int>> res;
    res.push_back(attend);
    res.push_back(s);
    return res;
}

void print_party_list(int r, std::vector<int> &attend, int parent_attend, std::vector<tree_node*> &p){
    int cur_attend;
    if(p[r]!= NULL){
        if(parent_attend == 0){
            cur_attend = attend[r];
            if(attend[r] == 1){
                std::cout << r << " ";
            }
            
        }
        else cur_attend = 0;
    }
    for(tree_node* key = p[r]->let(); key != NULL; key = key->rit()){
        print_party_list(key->nums()-1, attend, cur_attend, p);
    }
}
#endif