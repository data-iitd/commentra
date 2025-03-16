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
        }

        if (ok) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    }

public:
    int main() {
        solve();
        return 0;
    }
};

int main() {
    Main().main();
    return 0;
}
