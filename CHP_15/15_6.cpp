#include"15_6.h"
#include<random>
int main(){
    std::vector<double> f(76);
    std::default_random_engine e;
    std::uniform_real_distribution<double> u(0, 100);
    for(int i = 0; i < 76; ++i){
        f[i] = u(e);
    }
    //随机分配员工的社交能力分值
    std::vector<std::string> names;
    for(int i = 0; i < 76; ++i){
        std::string temp = "a" + std::to_string(i+1);
        names.push_back(temp);
    }
    //员工的名字列表
    std::vector<tree_node*> node_list(76);
    for(int i = 0; i < 76; ++i) node_list[i] = new tree_node;
    for(int i = 0; i < 4; ++i){
        if(i == 0){
            *(node_list[i])={names[i], f[i], node_list[1], NULL, NULL, i+1, i+3, true};
        }
        else if(i == 1){
            for(int j = 1; j <= i+2; ++j){
                if(j != 3 * i){
                    *(node_list[j])={names[j], f[j], node_list[4*(j)], node_list[j+1], node_list[i-1], j+1, i+3, false};
                }
                else{
                    *(node_list[j]) = {names[j], f[j], node_list[4*j], NULL, node_list[i-1], j+1, i+3, false};
                }
            }
        }
        else if(i == 2){
            for(int j = 1; j <= i+1; ++j){
                for(int k = 0; k < 3; ++k){
                    *(node_list[4*j+k])={names[4*j+k], f[4*j+k], node_list[5*(4*j+k-1)+1], node_list[4*j+k+1], node_list[j], 4*j+k +1, i+3, false};
                }
                *(node_list[4*j+3])={names[4*j+3], f[4*j+3], node_list[5*(4*j+2)+1], NULL, node_list[j], 4*j+4, i+3, false};
            }
        }
        else{
            for(int j = 3; j < 15; ++j){
                for(int i = 1; i < 5; ++i){
                    *(node_list[5*j+i]) = {names[5*j+i], f[5*j+i], NULL, node_list[5*j+i+1], node_list[j+1], 5*j+i+1, 0, false};
                }
                *(node_list[5*(j+1)]) = {names[5*j+5], f[5*j+5], NULL, NULL, node_list[j+1], 5*j+5+1, 0, false};
            }
        }
    }

    auto res = company_party(0, node_list);
    print_party_list(0, res[0], 0, node_list);
    
    
    
    return 0;
}