#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class CColoringColorfully {
public:
    void solve(int testNumber) {
        // Read the input string
        string x;
        cin >> x;

        // Initialize counters for the number of changes made
        int a1 = 0, a2 = 0;

        // First pass: modify from left to right
        for (size_t i = 1; i < x.length(); i++) {
            // Check if the current character is the same as the previous one
            if (x[i] == x[i - 1]) {
                // Change the character to the opposite value
                x[i] = (x[i] == '1') ? '0' : '1';
                // Increment the change counter
                a1++;
            }
        }

        // Second pass: modify from right to left
        for (size_t i = x.length() - 1; i > 0; i--) {
            // Check if the current character is the same as the previous one
            if (x[i] == x[i - 1]) {
                // Change the previous character to the opposite value
                x[i - 1] = (x[i - 1] == '1') ? '0' : '1';
                // Increment the change counter
                a2++;
            }
        }

        // Output the minimum number of changes made in either pass
        cout << min(a1, a2) << endl;
    }
};

int main() {
    // Instantiate the solver class for the problem
    CColoringColorfully solver;

    // Solve the problem for the first test case
    solver.solve(1);

    return 0;
}

// <END-OF-CODE>
