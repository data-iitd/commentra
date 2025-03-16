#include <iostream>
#include <string>

using namespace std;

class BABC {
public:
    void solve(int testNumber, istream &in, ostream &out) {
        // Read the input string and replace occurrences of "BC" with "D"
        string s;
        in >> s;
        size_t pos;
        while ((pos = s.find("BC")) != string::npos) {
            s.replace(pos, 2, "D");
        }

        // Initialize counters for 'A' and the result
        long long cnt = 0;
        long long tmp = 0;

        // Iterate through the modified string to count occurrences
        for (char c : s) {
            // Increment temporary counter for 'A'
            if (c == 'A') {
                tmp++;
            }
            // Add the count of 'A's to the result when 'D' is encountered
            else if (c == 'D') {
                cnt += tmp;
            }
            // Reset the temporary counter for any other character
            else {
                tmp = 0;
            }
        }

        // Output the final count of valid pairs
        out << cnt << endl;
    }
};

int main() {
    // Create an instance of the BABC class to solve the problem
    BABC solver;

    // Call the solve method with test number, input stream, and output stream
    solver.solve(1, cin, cout);

    return 0;
}

// <END-OF-CODE>
