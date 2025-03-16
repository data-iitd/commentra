#include <iostream>
#include <cmath>

using namespace std;

class Main {
public:
    void solve() {
        int A, B, n;
        cin >> A >> B >> n;

        if (A == 0) {
            if (B == 0) {
                cout << 1 << endl;
            } else {
                cout << "No solution" << endl;
            }
            return;
        }

        if (B % A != 0) {
            cout << "No solution" << endl;
            return;
        }

        B /= A;
        bool neg = B < 0;

        if (neg && n % 2 == 0) {
            cout << "No solution" << endl;
            return;
        }

        if (neg) B = -B;

        for (int x = 0; x <= B; x++) {
            if (pow(x, n) == B) {
                cout << (neg ? -x : x) << endl;
                return;
            }
        }

        cout << "No solution" << endl;
    }
};

int main() {
    Main m;
    m.solve();
    return 0;
}

// <END-OF-CODE>
