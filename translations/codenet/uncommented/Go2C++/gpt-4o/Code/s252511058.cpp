#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, l, r;
};

bool compare(const Point &a, const Point &b) {
    return a.r < b.r;
}

int main() {
    int N;
    cin >> N;
    vector<Point> points(N);
    
    for (int i = 0; i < N; i++) {
        cin >> points[i].x;
        int L;
        cin >> L;
        points[i].l = points[i].x - L;
        points[i].r = points[i].x + L;
    }
    
    sort(points.begin(), points.end(), compare);
    
    // 区間スケジューリング問題に帰着する
    int start = points[0].r;
    int ans = 1;
    
    for (int i = 1; i < points.size(); i++) {
        if (points[i].l < start) {
            continue;
        }
        start = points[i].r;
        ans++;
    }
    
    cout << ans << endl;
    return 0;
}

// <END-OF-CODE>
