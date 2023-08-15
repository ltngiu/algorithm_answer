#include"LCS_1.h"
std::vector<int> LCS_LENGTH(std::vector<int> &X, std::vector<int> &Y){
    int m = X.size(), n = Y.size();
    std::vector<int> res;
    int row, colum, rest;
    rest = 0;
    std::vector<std::vector<int>> b(m + 1, std::vector<int>(n + 1));
    for(int i = 0; i < m + 1; ++i) b[i][0] = 0;
    for(int j = 0; j < n + 1; ++j) b[0][j] = 0;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(X[i] == Y[j]){
                b[i+1][j+1] = b[i][j] + 1;
                if(b[i + 1][j + 1] > rest){
                    rest = b[i + 1][j + 1];
                    colum = j;
                    row = i;
                }

            }
            else{
                b[i + 1][j + 1] = 0;
            }
        }
    }
    res.push_back(rest);
    res.push_back(row);
    res.push_back(colum);
    return res;

}