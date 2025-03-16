#include <bits/stdc++.h> // Importing standard library
using namespace std; // Using the standard library

int main() { // Main function is the entry point of the program
    ios_base::sync_with_stdio(false); // Disabling synchronization with C++ IO streams
    cin.tie(NULL); // Disabling synchronization with C++ IO streams
    cout.tie(NULL); // Disabling synchronization with C++ IO streams
    int n, k; // Declaring variables
    cin >> n >> k; // Reading input
    int logsLength[n]; // Declaring an array of logs
    for (int i = 0; i < n; i++) { // Iterating through the array
        cin >> logsLength[i]; // Reading input
    }
    int min = 1, max = 1e9 + 1000; // Initializing the binary search range
    while (min < max) { // Performing binary search
        int mid = (min + max) / 2; // Calculating the middle value
        if (nei(mid, logsLength, k)) { // Checking if the current mid can be used to cut all logs
            max = mid; // Adjusting the max value to search in the lower half
        } else {
            min = mid + 1; // Adjusting the min value to search in the upper half
        }
    }
    cout << min << "\n"; // Printing the result
    return 0;
}

bool nei(int mid, int logsLength[], int k) { // nei method checks if the current mid can be used to cut all logs
    for (int log : logsLength) { // Iterating through each log
        k -= (log + mid - 1) / mid - 1; // Calculating the number of cuts needed for the current log
        if (k < 0) { // If k is negative, it means we cannot make the required cuts
            return false; // Return false as the current mid cannot be used
        }
    }
    return true; // Return true if all logs can be cut with the given number of k
}

