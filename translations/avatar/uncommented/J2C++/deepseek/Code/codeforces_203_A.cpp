#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Main {
private:
    void solve() {
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
    }

public:
    void run() {
        solve();
    }
};

int main() {
    Main().run();
    return 0;
}

