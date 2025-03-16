
#####
# Code
#####

#include <iostream>
#include <vector>
#include <algorithm>

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

    vector<vector<int>> path(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        path[a-1].push_back(b-1);
        path[b-1].push_back(a-1);
    }

    int c = 0;
    for (int i = 0; i < n; i++) {
        bool f = false;
        for (int j : path[i]) {
            if (h[i] <= h[j]) {
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
