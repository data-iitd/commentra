#include <iostream>
#include <string>
using namespace std;

class BABC {
public:
    void solve(int testNumber) {
        string s;
        cin >> s; // Read the input string.
        
        // Replace all occurrences of "BC" with "D".
        size_t pos;
        while ((pos = s.find("BC")) != string::npos) {
            s.replace(pos, 2, "D");
        }

        long long cnt = 0; // Initialize a counter to keep track of the result.
        long long tmp = 0; // Temporary variable to count consecutive 'A's.
        
        for (char c : s) {
            if (c == 'A') {
                tmp++; // Increment tmp if the current character is 'A'.
            } else if (c == 'D') {
                cnt += tmp; // Add tmp to cnt if the current character is 'D'.
            } else {
                tmp = 0; // Reset tmp if the current character is not 'A' or 'D'.
            }
        }
        
        cout << cnt << endl; // Print the final count.
    }
};

int main() {
    BABC solver; // Create an instance of the BABC class.
    solver.solve(1); // Call the solve method of the BABC class.
    return 0; // Return 0 to indicate successful execution.
}

// <END-OF-CODE>
