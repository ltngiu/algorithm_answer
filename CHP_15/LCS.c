#include"LCS.h"

std::vector<std::vector<std::vector<int>>> LCS_LENGTH(std::vector<int> &X, std::vector<int> &Y){
    int m = X.size(), n = Y.size();
    std::vector<std::vector<int>> c(m + 1, std::vector<int>(n + 1));
    std::vector<std::vector<int>> b(m + 1, std::vector<int>(n + 1));
    for(int i = 0; i <= m; ++i) c[i][0] = 0;
    for(int i = 0; i <= n; ++i) c[0][i] = 0;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(X[i] == Y[j]){
                c[i + 1][j + 1] = c[i][j] + 1;
                b[i + 1][j + 1] = 0; //0表示左上
            }
            else if(c[i][j + 1] > c[i + 1][j]){
                c[i + 1][j + 1] = c[i][j + 1];
                b[i + 1][j + 1] = 1; //1表示上平移
            }
            else{
                c[i + 1][j + 1] = c[i + 1][j];
                b[i + 1][j + 1] = 2; //2表示左平移
            }
        }
    }
    std::vector<std::vector<std::vector<int>>> res;
    res.push_back(c);
    res.push_back(b);
    return res;
}

void print_LCS(std::vector<std::vector<int>> &b, std::vector<int> &X, int i, int j){
    if (i == 0 || j == 0){
    }
    else{
        if(b[i][j] == 0){
        print_LCS(b, X, i - 1, j - 1);
        std::cout << X[i - 1] << " ";
    }
    else if(b[i][j] == 1){
        print_LCS(b, X, i - 1, j);
    }
    else 
    print_LCS(b, X, i, j - 1);
    }
    
}