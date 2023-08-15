//图像压缩
#include"15_8.h"
int main(){
    int m, n;
    std::cout << "请输入图像的尺寸" << std::endl;
    std::cin >> m >> n;
    ++m, ++n;
    std::default_random_engine e(15);
    std::uniform_real_distribution<double> u(0.5, 10);
    std::vector<std::vector<double>> image(m, std::vector<double>(n));
    //假设这是一幅m*n的图形，为每个元素分配随机的破坏度
    for(int i = 1; i < m; ++i){
        for(int j = 1; j < n; ++j){
            image[i][j] = u(e);
            // std::cout << image[i][j] << " ";
            // if(j % 10 == 0) std::cout <<std::endl;
        }
        // std::cout << std::endl;
    }
    auto res = seam_carve(image);
    std::cout << res.cast[m-1][res.n] << std::endl;
    double init = 0;
    //init表示总的破坏度的累计
    // print_res(res.choic, image, m, res.n, init);
    std::cout <<std::endl;
    std::cout << init;
    return 0;
}