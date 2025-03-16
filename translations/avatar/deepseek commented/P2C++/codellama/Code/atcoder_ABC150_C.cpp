
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> orig;
    for (int i = 1; i <= n; i++) {
        vector<int> v;
        for (int j = 1; j <= n; j++) {
            v.push_back(j);
        }
        orig.push_back(v);
    }
    vector<int> p;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        p.push_back(x);
    }
    vector<int> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push_back(x);
    }
    int pn = 0;
    for (int i = 0; i < orig.size(); i++) {
        if (orig[i] == p) {
            pn = i;
            break;
        }
    }
    int qn = 0;
    for (int i = 0; i < orig.size(); i++) {
        if (orig[i] == q) {
            qn = i;
            break;
        }
    }
    cout << abs(pn - qn) << endl;
    return 0;
}

