#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int x, t, a, b, da, db;
    cin >> x >> t >> a >> b >> da >> db;

    if (x == 0) {
        cout << "YES" << endl;
        return 0;
    }

    for (int i = 0; i <= min(a / da, t - 1); ++i) {
        for (int j = 0; j <= min(b / db, t - 1); ++j) {
            if (a - da * i == x || b - db * j == x) {
                cout << "YES" << endl;
                return 0;
            }
            if ((a - da * i) + (b - db * j) == x) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}

