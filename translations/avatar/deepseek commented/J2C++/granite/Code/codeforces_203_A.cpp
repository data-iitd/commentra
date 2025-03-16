
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <stack>

using namespace std;

int main() {
    int x, t, a, b, da, db;
    cin >> x >> t >> a >> b >> da >> db;
    bool ok = false;
    for (int i = 0; i < t; i++) {
        int first = a - (da * i);
        for (int j = 0; j < t; j++) {
            int second = b - (db * j);
            if (second + first == x || second == x || first == x || x == 0) {
                ok = true;
                break;
            }
        }
        if (ok) break;
    }
    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}

// END-OF-CODE