#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> XY(2 * N);
    for (int i = 0; i < 2 * N; ++i) {
        std::cin >> XY[i];
    }

    std::vector<std::pair<int, int>> points;
    for (int i = 0; i < N; ++i) {
        points.emplace_back(XY[2 * i], XY[2 * i + 1]);
    }

    for (int i = 0; i < N; ++i) {
        double x = points[i].first;
        double y = points[i].second;
        std::vector<double> angles;
        for (int j = 0; j < N; ++j) {
            if (i != j) {
                double angle = std::atan2(points[j].first - x, points[j].second - y);
                angles.push_back(angle);
            }
        }
        std::sort(angles.begin(), angles.end());
        angles.push_back(angles[0] + 2 * M_PI);
        double ans = 0;
        for (size_t k = 0; k < angles.size(); ++k) {
            double a = angles[k];
            double b = angles[k + 1];
            if (b - a >= M_PI) {
                ans = (b - a) - M_PI;
                break;
            }
        }
        std::cout << std::fixed << std::setprecision(10) << ans / (2 * M_PI) << std::endl;
    }

    return 0;
}

