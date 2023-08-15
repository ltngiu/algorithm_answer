#include"matrix_mult.h"
std::vector<std::vector<std::vector<int>>> matrix_chain(std::vector<int> p){
    int n = p.size();

    
    std::vector<std::vector<int>> m(n, std::vector<int>(n));
    std::vector<std::vector<int>> s(n, std::vector<int>(n));
    for(int i = 1; i < n; ++i)
        m[i][i] = 0;
    int q;
    for(int l = 2; l < n; ++l){
        for(int i = 1; i <= n - l ; ++i){
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for(int k = i; k <= j - 1; ++k){
                q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    std::vector<std::vector<std::vector<int>>> res; 
    res.push_back(m);
    res.push_back(s);
    return res;
}