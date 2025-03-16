
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
    int x, l, r;
};

bool compare(point a, point b) {
    return a.r < b.r;
}

int main() {
    int N;
    cin >> N;

    vector<point> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].l;
        points[i].r = points[i].x + points[i].l;
    }

    sort(points.begin(), points.end(), compare);

    int start = points[0].r;
    int ans = 1;
    for (int i = 1; i < N; i++) {
        if (points[i].l < start) {
            continue;
        }
        start = points[i].r;
        ans++;
    }

    cout << ans << endl;

    return 0;
}

