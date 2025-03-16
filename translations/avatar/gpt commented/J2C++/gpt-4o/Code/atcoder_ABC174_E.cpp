#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

class Solution {
public:
    void solve(istream &in, ostream &out) {
        // Read the number of logs and the value of k
        int n, k;
        in >> n >> k;

        // Read the lengths of the logs into a vector
        vector<int> logsLength(n);
        for (int i = 0; i < n; ++i) {
            in >> logsLength[i];
        }

        // Initialize binary search bounds
        int min = 1, max = static_cast<int>(1e9) + 1000;

        // Perform binary search to find the minimum possible length
        while (min < max) {
            int mid = (min + max) / 2;

            // Check if it's possible to cut the logs with the current mid length
            if (canCut(mid, logsLength, k))
                max = mid; // If possible, search in the lower half
            else
                min = mid + 1; // Otherwise, search in the upper half
        }

        // Output the minimum length found
        out << min << endl;
    }

private:
    // Helper method to determine if logs can be cut with the given mid length
    bool canCut(int mid, const vector<int> &logsLength, int k) {
        for (int log : logsLength) {
            k -= (log + mid - 1) / mid - 1; // Calculate the number of cuts needed
        }
        // Return true if we can make the cuts within the limit of k
        return k >= 0;
    }
};

int main() {
    // Create an instance of Solution to solve the problem
    Solution sol;
    sol.solve(cin, cout); // Pass standard input and output streams

    return 0;
}

// <END-OF-CODE>
