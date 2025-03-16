
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

// Private nested class for the solution logic
class Solution {
    // Method to solve the problem using the given input and output objects
    private:
        void solve ( int n , int k ) {
            int min = 1, max = 1e9 + 1000; // Initialize the minimum and maximum possible days

            // Binary search to find the minimum day such that the number of days needed to cut the logs is greater than or equal to k
            while (min < max) {
                int mid = (min + max) / 2; // Calculate the middle day
                if (nei(mid, logsLength, k)) // If the number of days needed to cut the logs is greater than or equal to k
                    max = mid; // Narrow down the search space to the left
                else
                    min = mid + 1; // Narrow down the search space to the right
            }

            // Print the minimum day as the output
            cout << min << endl;
        }

        // Method to check if the number of days needed to cut the logs of given length is greater than or equal to k
        private:
            bool nei ( int mid , int [ ] logsLength , int k ) {
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

// Private nested static class for reading input
class InputReader {
    private:
        int n; // Initialize the number of logs as zero
        int k; // Initialize the number of days as zero
        int logsLength [ ] = new int [ n ]; // Initialize an array of size n to store the lengths of the logs

        // Constructor to initialize the InputReader object with the given input stream
        InputReader ( ) {
            cin >> n >> k; // Read the number of logs and the number of days
            for (int i = 0; i < n; ++i) // Iterate through all the logs
                cin >> logsLength [ i ]; // Read the length of the current log
        }

        // Method to read an integer
        int nextInt ( ) {
            return cin.nextInt(); // Return the next integer
        }

        // Method to read an array of integers
        int [ ] readArray ( int n ) {
            int [ ] a = new int [ n ]; // Initialize an array of size n
            for (int i = 0; i < n; ++i) // Iterate through all the elements of the array
                a [ i ] = nextInt(); // Read an integer as the next element
            return a; // Return the array
        }
};

int main ( ) {
    InputReader in = new InputReader(); // Create an InputReader object
    Solution sol = new Solution(); // Create a Solution object
    sol.solve(in.n, in.k); // Call the solve method of Solution object
    return 0; // Return 0 to indicate that the program has ended successfully
}

