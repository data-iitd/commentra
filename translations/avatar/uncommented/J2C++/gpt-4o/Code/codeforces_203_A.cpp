#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Main {
public:
    void solve() {
        int x, t, a, b, da, db;
        cin >> x >> t >> a >> b >> da >> db;
        int first, second;
        bool ok = false;

        for (int i = 0; i < t; i++) {
            first = a - (da * i);
            for (int j = 0; j < t; j++) {
                second = b - (db * j);
                if (second + first == x || second == x || first == x || x == 0) {
                    ok = true;
                    break;
                }
            }
            if (ok) break; // Break outer loop if found
        }

        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    void run() {
        solve();
    }
};

int main() {
    Main().run();
    return 0;
}

// <END-OF-CODE>
