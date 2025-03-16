#include <iostream>
#include <cmath>

int main() {
    int n, d;
    std::cin >> n >> d;
    int point[n+1][d+1];
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= d; j++) {
            std::cin >> point[i][j];
        }
    }
    
    int count = 0;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            int sum = 0;
            for (int k = 1; k <= d; k++) {
                sum += (point[i][k] - point[j][k]) * (point[i][k] - point[j][k]);
            }
            double kyori = std::sqrt(sum);
            if (std::ceil(kyori) == std::floor(kyori)) {
                count++;
            }
        }
    }
    
    std::cout << count << std::endl;
    return 0;
}
