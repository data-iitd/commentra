#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
    int x, l, r;
};

struct Points {
    std::vector<Point> points;
    int size() const {
        return points.size();
    }
    Point& operator[](int index) {
        return points[index];
    }
    const Point& operator[](int index) const {
        return points[index];
    }
};

int nextInt(std::istream& is) {
    int t;
    is >> t;
    return t;
}

bool compare(const Point& a, const Point& b) {
    return a.r < b.r;
}

int main() {
    int N;
    std::cin >> N;
    Points points;
    points.points.resize(N);
    for (int i = 0; i < N; ++i) {
        points[i].x = nextInt(std::cin);
        int L = nextInt(std::cin);
        points[i].l = points[i].x - L;
        points[i].r = points[i].x + L;
    }
    std::sort(points.points.begin(), points.points.end(), compare);
    // 区間スケジューリング問題に帰着する
    int start = points[0].r;
    int ans = 1;
    for (int i = 0; i < points.size(); ++i) {
        if (points[i].l < start) {
            continue;
        }
        start = points[i].r;
        ++ans;
    }
    std::cout << ans << std::endl;
    return 0;
}
