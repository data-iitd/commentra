#include <iostream>     // Include iostream for input/output
#include <vector>      // Include vector for using dynamic arrays
#include <string>      // Include string for string manipulation
#include <sstream>     // Include sstream for string stream
#include <algorithm>   // Include algorithm for using algorithms like min and max
#include <limits>      // Include limits for numeric limits
#include <cmath>       // Include cmath for mathematical functions

using namespace std;    // Use the standard namespace

class Solution {
public:
    // Method to solve the problem using the given input and output objects
    void solve(istream &in, ostream &out) {
        int n, k;
        in >> n >> k; // Read the number of logs and the number of days

        // Initialize the minimum and maximum possible days
        int min = 1, max = (int)1e9 + 1000;

        // Vector to store the lengths of the logs
        vector<int> logsLength(n);
        for (int i = 0; i < n; ++i) {
            in >> logsLength[i]; // Read the length of each log
        }

        // Binary search to find the minimum day such that the number of days needed to cut the logs is greater than or equal to k
        while (min < max) {
            int mid = (min + max) / 2; // Calculate the middle day
            if (nei(mid, logsLength, k)) // If the number of days needed to cut the logs is greater than or equal to k
                max = mid; // Narrow down the search space to the left
            else
                min = mid + 1; // Narrow down the search space to the right
        }

        // Print the minimum day as the output
        out << min << endl;
    }

private:
    // Method to check if the number of days needed to cut the logs of given length is greater than or equal to k
    bool nei(int mid, const vector<int> &logsLength, int k) {
        int daysNeeded = 0; // Initialize the days needed to zero

        // Iterate through all the logs and calculate the days needed to cut them
        for (int log : logsLength) {
            daysNeeded += (log + mid - 1) / mid; // Calculate the days needed to cut the current log
            k -= daysNeeded; // Subtract the days needed from the remaining days
            if (k < 0) // If the remaining days are not sufficient to cut all the logs
                return false; // Return false to indicate that the middle day is not the answer
        }

        // If all the logs have been cut, return true to indicate that the middle day is the answer
        return true;
    }
};

int main() {
    Solution sol; // Create a Solution object
    sol.solve(cin, cout); // Call the solve method of Solution object
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
