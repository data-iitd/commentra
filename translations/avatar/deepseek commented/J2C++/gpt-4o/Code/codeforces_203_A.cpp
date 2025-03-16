#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Main {
public:
    void solve() {
        // Reading the number of test cases (t) and other required values
        int x; // Target value x
        int t; // Number of test cases (unused in this code)
        int a; // Value a
        int b; // Value b
        int da; // Difference a (da)
        int db; // Difference b (db)

        cin >> x >> t >> a >> b >> da >> db;

        // Variables to store calculated values
        int first;
        int second;

        // Flag to determine if a solution is found
        bool ok = false;

        // Nested loop to calculate possible values of first and second
        for (int i = 0; i < t; i++) {
            first = a - (da * i); // Calculate first value
            for (int j = 0; j < t; j++) {
                second = b - (db * j); // Calculate second value
                if (second + first == x || second == x || first == x || x == 0) {
                    // Check if the sum of first and second equals x, or if either value equals x, or if x is zero
                    ok = true;
                    break;
                }
            }
            if (ok) break; // Exit the outer loop if a solution is found
        }

        // Print the result based on the flag
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    int main() {
        solve();
        return 0;
    }
};

// Entry point
int main() {
    Main m;
    return m.main();
}

// <END-OF-CODE>
