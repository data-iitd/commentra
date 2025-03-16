#include <bits/stdc++.h>
using namespace std;

// Function to check if the number of days needed to cut the logs of given length is greater than or equal to k
bool nei ( int mid, int [ ] logsLength, int k ) {
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

// Function to find the minimum day such that the number of days needed to cut the logs is greater than or equal to k
int findMinDay ( int n, int k, int [ ] logsLength ) {
    int min = 1, max = (int) 1e9 + 1000; // Initialize the minimum and maximum possible days

    // Binary search to find the minimum day such that the number of days needed to cut the logs is greater than or equal to k
    while (min < max) {
        int mid = (min + max) / 2; // Calculate the middle day
        if (nei(mid, logsLength, k)) // If the number of days needed to cut the logs is greater than or equal to k
            max = mid; // Narrow down the search space to the left
        else
            min = mid + 1; // Narrow down the search space to the right
    }

    // Return the minimum day
    return min;
}

// Driver code
int main ( ) {
    int t; // Read the number of test cases
    cin >> t; // Read a test case
    while (t--) {
        int n, k; // Read the number of logs and the number of days
        cin >> n >> k; // Read a test case
        int logsLength [ n ]; // Initialize an array of size n to store the length of each log
        for (int i = 0; i < n; ++i) // Iterate through all the elements of the array
            cin >> logsLength [ i ]; // Read an integer as the next element
        cout << findMinDay(n, k, logsLength) << endl; // Print the minimum day as the output
    }
    return 0;
}

