
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    unordered_map<int, int> hp;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        hp[p[i]] = h;
    }

    unordered_map<int, vector<int>> path;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }

    int c = 0;
    for (auto const& [i, v] : path) {
        bool f = false;
        for (int j : v) {
            if (hp[i] <= hp[j]) {
                f = true;
                break;
            }
        }
        if (!f) {
            c++;
        }
    }

    cout << c << endl;

    return 0;
}
