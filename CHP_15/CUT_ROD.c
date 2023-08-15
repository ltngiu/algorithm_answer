#include"CUT_ROD.h"

int Memorized_Cut_Rod(int n, std::vector<int> &P){
    std::vector<int> r(n+1);
    for(auto key = r.begin(); key != r.end(); ++key){
        *key = INT_MIN;
    }
    r[0] = 0;
    return Memorized_cut_rod_aux(P, n, r);
}
int Memorized_cut_rod_aux(std::vector<int> &p, int n, std::vector<int> &r){
    if(r[n] >= 0)
        return r[n];
    int q;
    if(n == 0)
        q = 0;
    else q = INT_MIN;
    for(int i = 1; i <= n; ++i){
        q = std::max(q, p[i - 1] + Memorized_cut_rod_aux(p, n - i, r));
    }
    r[n] = q;
    return r[n];
}
int bottom_up_cut_rod(std::vector<int> &p, int n){
    std::vector<int> r(n+1);
    r[0] = 0;
    for(auto key = r.begin() + 1; key != r.end(); ++key){
        int q = INT_MIN;
        for(int i = 1; i <= key - r.begin(); ++i){
            q = std::max(q, p[i-1]+r[(key - r.begin())-i]);
        }
        r[key - r.begin()] = q;
    }
    return r[n];
}

std::vector<std::vector<int>> Extended_Bottom_Up_Cut_Rod(std::vector<int> &p, int n){
    std::vector<int> r(n+1);
    std::vector<int> s(n+1);
    r[0] = 0;
    s[0] = 0;
    int q;
    for(int j = 1; j <= n; ++j){
        q = INT_MIN;
        for(int i = 1; i <= j; ++i){
            if(q < r[j - i] + p[i - 1]){
                q = p[i - 1] + r[j - i];
                s[j] = i;
            }
        r[j] = q;
        }
    }
    std::vector<std::vector<int>> res;
    res.push_back(r);
    res.push_back(s);
    return res;
}