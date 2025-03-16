#include <iostream> // For input and output
#include <vector> // For using vector
#include <string> // For using string
#include <algorithm> // For using std::fill

using namespace std;

class TaskC {
public:
    void solve(int testNumber, istream &in, ostream &out) {
        int n;
        in >> n; // Read the number of test cases

        vector<long long> cnt(5, 0); // Initialize a vector of size 5 to store counts

        for (int i = 0; i < n; ++i) {
            string str;
            in >> str; // Read a string from input

            if (str[0] == 'M') {
                cnt[0]++; // Increment the count of 'M'
            } else if (str[0] == 'A') {
                cnt[1]++; // Increment the count of 'A'
            } else if (str[0] == 'R') {
                cnt[2]++; // Increment the count of 'R'
            } else if (str[0] == 'C') {
                cnt[3]++; // Increment the count of 'C'
            } else if (str[0] == 'H') {
                cnt[4]++; // Increment the count of 'H'
            }
        }

        long long res = cnt[0] * cnt[1] * cnt[2] + // Calculate the first product
                        cnt[0] * cnt[1] * cnt[3] + // Calculate the second product
                        cnt[0] * cnt[1] * cnt[4] + // Calculate the third product
                        cnt[0] * cnt[2] * cnt[3] + // Calculate the fourth product
                        cnt[0] * cnt[2] * cnt[4] + // Calculate the fifth product
                        cnt[0] * cnt[3] * cnt[4] + // Calculate the sixth product
                        cnt[1] * cnt[2] * cnt[3] + // Calculate the seventh product
                        cnt[1] * cnt[2] * cnt[4] + // Calculate the eighth product
                        cnt[1] * cnt[3] * cnt[4] + // Calculate the ninth product
                        cnt[2] * cnt[3] * cnt[4];   // Calculate the tenth product

        out << res << endl; // Write the result to the output
    }
};

int main() {
    ios::sync_with_stdio(false); // For faster input/output
    cin.tie(nullptr); // Untie cin from cout

    TaskC solver; // Create an instance of the TaskC class
    solver.solve(1, cin, cout); // Call the solve method with test number, input stream, and output stream

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
