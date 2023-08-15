#ifndef seam_carving
#define seam_carving
#include<cstdio>
#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<random>
//解题思路：为了求取第i行第j列元素结尾的最小值和路径选择，
//只需要知道前(i-1)行，以(i-1, j-1), (i-1, j), (i-1, j+1)
//结尾的最小值和路径并进行选择即可
struct reslt{
    std::vector<std::vector<double>> cast;
    std::vector<std::vector<int>> choic;
    int n;
};
reslt seam_carve(std::vector<std::vector<double>> & img){
    int m = img.size(), n = img[0].size();
    std::vector<std::vector<double>> t(m, std::vector<double>(n, INT_MAX)); //t[i][j]表示前i行，第i行以第j列结尾的路径的最小值
    std::vector<std::vector<int>> c(m, std::vector<int>(n)); 
    //c[i][j]表示以第i行第j列结尾的路径的上一步应该选什么也就是(j-1,j,j+1)三选一
    for(int i = 1; i < n; ++i) { t[1][i] = img[1][i];}
    for(int i = 2; i < m; ++i){
        for(int j = 1; j < n; ++j){
            std::vector<double> path(i+1);
            if(j == 1){
                for(int k = 0; k <= 1; ++k){
                    double temp = img[i][j] + t[i-1][j+k];
                    if(temp < t[i][j]){
                        t[i][j] = temp;
                        c[i][j] = k;
                    }
                }
            }
            else if(j == n-1){
                for(int k = -1; k <= 0; ++k){
                    double temp = img[i][j] + t[i-1][j+k];
                    if(temp < t[i][j]){
                        t[i][j] = temp;
                        c[i][j] = k;
                    }
                }
            }
            else{
                for(int k = -1; k <= 1; ++k){
                    double temp = img[i][j] + t[i-1][j+k];
                    if(temp < t[i][j]){
                        t[i][j] = temp;
                        c[i][j] = k;
                    }
                }
            }
        }
    }
    reslt res;
    res.cast = t;
    res.choic = c;
    res.n = std::min_element(t[m-1].begin()+1, t[m-1].end()) - t[m-1].begin();
    return res;
}

void print_res(std::vector<std::vector<int>> & choi, std::vector<std::vector<double>> &img, int m, int j, double &mins){

    if(m > 1){        
        mins += img[m-1][j];
        print_res(choi, img,  m - 1, choi[m-1][j] + j, mins);
        std::cout << "("<< m-1 <<", " << j <<"): " << img[m-1][j] << "; ";
        if((m-1)%10 == 0) std::cout << std::endl;
    }
}
#endif