
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
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
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    int c = 0;
    for (auto& entry : path) {
        bool f = false;
        for (int j : entry.second) {
            if (hp[entry.first] <= hp[j]) {
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
// END-OF-CODE