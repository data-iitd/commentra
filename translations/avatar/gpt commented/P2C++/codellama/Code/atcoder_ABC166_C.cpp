#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
    }

    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    map<int, int> hp;
    for (int i = 0; i < n; i++) {
        hp[p[i]] = h[i];
    }

    map<int, vector<int>> path;
    for (int i = 0; i < n; i++) {
        path[p[i]] = vector<int>();
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }

    int c = 0;
    for (int i = 0; i < n; i++) {
        int f = 0;
        for (int j = 0; j < path[i].size(); j++) {
            if (hp[i] <= hp[path[i][j]]) {
                f = 1;
                break;
            }
        }
        if (f == 0) {
            c++;
        }
    }

    cout << c << endl;

    return 0;
}

