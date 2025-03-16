
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

class Point {
public:
    int name;
    map<Point*, int> friends;
    Point(int name) {
        this->name = name;
    }
    void becomeFriend(Point* p, int length) {
        friends[p] = length;
    }
};

void dfs(Point* p, int length) {
    bool alreadyKnown = colors[p->name] != -1;
    if (alreadyKnown) return;
    if (length % 2 == 0) {
        colors[p->name] = 0;
    } else {
        colors[p->name] = 1;
    }
    for (auto entry : p->friends) {
        Point* friend = entry.first;
        int length2 = entry.second;
        dfs(friend, length + length2);
    }
}

int main() {
    int n;
    cin >> n;
    int m = n - 1;
    colors = new int[n];
    Arrays.fill(colors, -1);
    Point* points = new Point[n];
    for (int i = 0; i < n; i++) {
        points[i] = new Point(i);
    }
    while (m-- > 0) {
        int me, you;
        int length;
        cin >> me >> you >> length;
        points[me - 1].becomeFriend(points[you - 1], length);
        points[you - 1].becomeFriend(points[me - 1], length);
    }
    dfs(points[0], 0);
    for (int c : colors) {
        cout << c << endl;
    }
    return 0;
}

