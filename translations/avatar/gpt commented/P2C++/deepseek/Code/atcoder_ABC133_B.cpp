#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

int main() {
    int n, d;
    std::cin >> n >> d;

    std::vector<std::vector<int>> points(n, std::vector<int>(d));
    for (auto& point : points) {
        for (int& coord : point) {
            std::cin >> coord;
        }
    }

    auto dist = [](const std::vector<int>& x, const std::vector<int>& y) {
        double tmp = 0.0;
        for (int i = 0; i < x.size(); ++i) {
            tmp += std::pow(x[i] - y[i], 2);
        }
        return std::sqrt(tmp);
    };

    int count = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (std::floor(dist(points[i], points[j])) == dist(points[i], points[j])) {
                ++count;
            }
        }
    }

    std::cout << count << std::endl;

    return 0;
}
