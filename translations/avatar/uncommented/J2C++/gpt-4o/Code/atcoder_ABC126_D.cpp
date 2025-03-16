#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Point {
public:
    int name;
    map<Point*, int> friends;

    Point(int name) : name(name) {}

    void becomeFriend(Point* p, int length) {
        friends[p] = length;
    }
};

vector<int> colors;

void dfs(Point* p, int length) {
    if (colors[p->name] != -1) return;

    colors[p->name] = (length % 2 == 0) ? 0 : 1;

    for (auto& entry : p->friends) {
        Point* friendPoint = entry.first;
        int length2 = entry.second;
        dfs(friendPoint, length + length2);
    }
}

int main() {
    int n;
    cin >> n;
    int m = n - 1;
    colors.resize(n, -1);
    vector<Point*> points(n);

    for (int i = 0; i < n; i++) {
        points[i] = new Point(i);
    }

    while (m-- > 0) {
        int me, you, length;
        cin >> me >> you >> length;
        me--; you--; // Convert to 0-based index
        points[me]->becomeFriend(points[you], length);
        points[you]->becomeFriend(points[me], length);
    }

    dfs(points[0], 0);

    for (int c : colors) {
        cout << c << endl;
    }

    // Clean up dynamically allocated memory
    for (Point* point : points) {
        delete point;
    }

    return 0;
}

// <END-OF-CODE>
