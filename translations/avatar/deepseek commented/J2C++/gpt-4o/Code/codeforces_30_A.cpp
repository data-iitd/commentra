#include <iostream>
#include <cmath>

using namespace std;

class Main {
public:
    void solve() {
        // Step 1: Reading Input Values
        int A, B, n;
        cin >> A >> B >> n;

        // Step 2: Handling Special Case A == 0
        if (A == 0) {
            if (B == 0)
                cout << 1 << endl;
            else
                cout << "No solution" << endl;
            return;
        }

        // Step 3: Checking Divisibility
        if (B % A != 0) {
            cout << "No solution" << endl;
            return;
        }

        // Step 4: Normalizing B
        B /= A;
        bool neg = B < 0;
        if (neg && n % 2 == 0) {
            cout << "No solution" << endl;
            return;
        }
        if (neg)
            B = -B;

        // Step 5: Iterating to Find Solution
        for (int x = 0; x <= B; x++) {
            if (pow(x, n) == B) {
                cout << (neg ? -x : x) << endl;
                return;
            }
        }

        // Step 6: No Solution Found
        cout << "No solution" << endl;
    }
};

int main() {
    Main m;
    m.solve();
    return 0;
}

// <END-OF-CODE>
