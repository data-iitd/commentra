#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int m = n - 1;
    int colors[n];
    fill(colors, colors + n, -1);

    Point points[n];
    for (int i = 0; i < n; i++) {
        points[i] = Point(i);
    }

    while (m-- > 0) {
        int me, you;
        cin >> me >> you;
        int length;
        cin >> length;
        points[me - 1].becomeFriend(points[you - 1], length);
        points[you - 1].becomeFriend(points[me - 1], length);
    }

    dfs(points[0], 0);

    for (int c : colors) {
        cout << c << endl;
    }
}

class Point {
public:
    int name;
    map<Point, int> friends;

    Point(int name) {
        this->name = name;
        this->friends = map<Point, int>();
    }

    void becomeFriend(Point p, int length) {
        this->friends[p] = length;
    }
};

void dfs(Point p, int length) {
    bool alreadyKnown = colors[p.name]!= -1;
    if (alreadyKnown) return;

    if (length % 2 == 0) {
        colors[p.name] = 0;
    } else {
        colors[p.name] = 1;
    }

    for (pair<Point, int> entry : p.friends) {
        Point friend = entry.first;
        int length2 = entry.second;
        dfs(friend, length + length2);
    }
}

