#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
    int x, l, r;
};

bool compare(const Point& a, const Point& b) {
    return a.r < b.r;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<Point> points(N);

    for (int i = 0; i < N; ++i) {
        std::cin >> points[i].x;
        int L;
        std::cin >> L;
        points[i].l = points[i].x - L;
        points[i].r = points[i].x + L;
    }

    std::sort(points.begin(), points.end(), compare);

    int start = points[0].r;
    int ans = 1;

    for (int i = 0; i < N; ++i) {
        if (points[i].l < start) {
            continue;
        }
        start = points[i].r;
        ++ans;
    }

    std::cout << ans << std::endl;
    return 0;
}
