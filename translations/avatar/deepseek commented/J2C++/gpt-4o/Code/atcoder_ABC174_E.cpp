#include <iostream> // For standard input and output
#include <vector> // For using vectors
#include <string> // For string operations
#include <sstream> // For string stream operations
#include <algorithm> // For using algorithms like min and max

using namespace std; // Use the standard namespace

class Solution { // Solution class contains the logic for solving the problem
public:
    void solve(istream &in, ostream &out) { // solve method reads input, processes it, and writes the output
        int n, k; // Declare variables for number of logs and cuts allowed
        in >> n >> k; // Read the number of logs and cuts allowed
        vector<int> logsLength(n); // Create a vector to store the lengths of the logs
        for (int i = 0; i < n; ++i) { // Read the lengths of the logs
            in >> logsLength[i];
        }
        
        int min = 1, max = 1e9 + 1000; // Initialize the binary search range
        while (min < max) { // Perform binary search
            int mid = (min + max) / 2; // Calculate the middle value
            if (canCut(mid, logsLength, k)) { // Check if the current mid can be used to cut all logs
                max = mid; // Adjust the max value to search in the lower half
            } else {
                min = mid + 1; // Adjust the min value to search in the upper half
            }
        }
        out << min << endl; // Print the result
    }

private:
    bool canCut(int mid, const vector<int> &logsLength, int k) { // canCut method checks if the current mid can be used to cut all logs
        for (int log : logsLength) { // Iterate through each log
            k -= (log + mid - 1) / mid - 1; // Calculate the number of cuts needed for the current log
            if (k < 0) { // If k is negative, it means we cannot make the required cuts
                return false; // Return false as the current mid cannot be used
            }
        }
        return true; // Return true if all logs can be cut with the given number of k
    }
};

int main() { // Main function is the entry point of the program
    Solution sol; // Create a Solution object to solve the problem
    sol.solve(cin, cout); // Call the solve method to process the input and produce output
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
