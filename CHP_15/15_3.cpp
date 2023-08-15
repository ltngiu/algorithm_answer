#include<iostream>
#include<cmath>
#include<iomanip>
#include<limits.h>
#include<cstdio>
#include<vector>
#include<random>
#include<algorithm>
const int n = 7;
const int MaxVal = 99999;
const int MaxLen = 201;
struct tagPoint{
    double x, y; 
};

double distance(tagPoint *points, int i, int j){
    return sqrt((points[i].x - points[j].x) * (points[i].x - points[j].x) + 
    (points[i].y - points[j].y) * (points[i].y - points[j].y));
}

std::vector<std::vector<std::vector<double>>> DP(tagPoint * points, int n){
    std::vector<std::vector<double>> b(n+1, std::vector<double>(n+1));
    std::vector<std::vector<double>> lt(n+1, std::vector<double>(n+1));
    b[1][2] = distance(points, 1, 2);
    for(int j = 3; j <= n; ++j){
        for(int i = 1; i <= j - 2; ++i){
            b[i][j] = b[i][j - 1] + distance(points, j - 1, j);
            lt[i][j] = j-1;
        }
        b[j - 1][j] = INT_MAX;
        for(int k = 1; k <= j - 2; ++k){
            double temp = b[k][j - 1] + distance(points, k, j);
            if(temp < b[j - 1][j]){
                b[j - 1][j] = temp;
                lt[j-1][j] = k;
            }
                
        }
    }
    b[n][n] = b[n-1][n] + distance(points, n - 1, n);
    lt[n][n] = n-1;
    std::vector<std::vector<std::vector<double>>> res;
    res.push_back(b);
    res.push_back(lt);
    return res;
}
bool cmp(double a, double b){
    return a<b;
}
void print_path(std::vector<std::vector<double>> &lt, int i, int j, tagPoint  *points){
    if(i >= j){
        if(i != 2 || j != 1){
            std::cout << int(lt[j][i]) <<"(" << points[int(lt[j][i])].x << ", " << points[int(lt[j][i])].y << ")" << " ";
            print_path(lt, int(lt[j][i]), j, points);
        }
    }
    else{
        if(i != 1||j !=2){
            print_path(lt, i, int(lt[i][j]), points);
            std::cout << int(lt[i][j]) << "(" << points[int(lt[i][j])].x << ", " << points[int(lt[i][j])].y << ")" << " ";
        }
    }
}
int main(){
    int NUM = 15;
    tagPoint points[NUM + 1];
    std::vector<double> x(NUM+1), y(NUM+1);
    std::default_random_engine e;
    std::uniform_real_distribution<double> u(-20, 20);
    for(int i = 0; i < NUM + 1; ++i){
        x[i] = u(e);
        y[i] = u(e);
    }
    sort(x.begin(), x.end(), cmp);

    for(int i = 0; i < NUM+1; ++i){
        points[i+1].x = x[i+1];
        points[i+1].y = y[i+1];
        // std::cout << "(" << points[i+1].x << " " << points[i+1].y << ") ";
        // std::cout << x[i+1] << " ";
    }
    auto mindis = DP(points, NUM);
    std::cout.setf(std::ios::fixed);
    std::cout << std::setprecision(2) << mindis[0][NUM][NUM] << std::endl;
    print_path(mindis[1], NUM, NUM, points);
    return 0;
}


