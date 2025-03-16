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

        // Initialize counters for the number of changes needed
        int a1 = 0, a2 = 0;

        // First loop to change characters to make the string colorful
        for (size_t i = 1; i < x.length(); i++) {
            if (x[i] == x[i - 1]) {
                // Change the character to the opposite
                x[i] = (x[i] == '1') ? '0' : '1';
                // Increment the counter
                a1++;
            }
        }

        // Second loop to change characters to make the string colorful
        for (size_t i = x.length() - 1; i > 0; i--) {
            if (x[i] == x[i - 1]) {
                // Change the character to the opposite
                x[i - 1] = (x[i - 1] == '1') ? '0' : '1';
                // Increment the counter
                a2++;
            }
        }

        // Output the minimum number of changes needed
        cout << min(a1, a2) << endl;
    }
};

int main() {
    int testCases = 1; // Assuming we have one test case as per the original Java code
    CColoringColorfully solver;
    solver.solve(testCases);
    return 0;
}

// <END-OF-CODE>
