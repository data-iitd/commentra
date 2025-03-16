#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

int main() {
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> pos(N, std::vector<int>(2));
    for (int i = 0; i < N; i++) {
        std::cin >> pos[i][0] >> pos[i][1];
    }
    double sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            sum += dist(pos[i][0], pos[i][1], pos[j][0], pos[j][1]);
        }
    }
    std::cout << std::fixed << std::setprecision(10) << sum / N << std::endl;
    return 0;
}

double dist(int x1, int y1, int x2, int y2) {
    return std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
