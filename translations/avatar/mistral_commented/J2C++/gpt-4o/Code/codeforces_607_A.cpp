#include <iostream>  // Including required header for input and output
#include <vector>   // Including required header for using vector
#include <algorithm> // Including required header for using std::max

using namespace std;

int main() {  // Main function starts the execution of the C++ program
    int max = 0;  // Initializing max variable to store the maximum length of a subsequence
    int n; 
    cin >> n;  // Reading the number of elements in the array from the console
    vector<int> beacon(1000001, 0);  // Creating a vector of size 1000001 to store the indices of beacons
    vector<int> dp(1000001, 0);       // Creating a vector of size 1000001 to store the length of the longest subsequence ending at each index

    for (int i = 0; i < n; i++) {  // Loop to read the elements and their indices from the console
        int a; 
        cin >> a;  // Reading the element
        cin >> beacon[a];  // Storing the index of the beacon for the given element
    }

    if (beacon[0] != 0) dp[0] = 1;  // If the first beacon exists, the length of the subsequence ending at index 0 is 1

    for (int i = 1; i < 1000001; i++) {  // Loop to calculate the length of the longest subsequence ending at each index
        if (beacon[i] != 0 && beacon[i] < i) {
            dp[i] = dp[i - beacon[i] - 1] + 1;  // If the beacon exists and its index is less than the current index, update the length of the subsequence
        } else if (beacon[i] != 0) {
            dp[i] = 1;  // If the beacon exists but its index is greater than or equal to the current index, the length of the subsequence is 1
        } else {
            dp[i] = dp[i - 1];  // If there is no beacon, the length of the subsequence remains the same as the previous index
        }
        max = std::max(max, dp[i]);  // Updating the maximum length of the subsequence
    }

    cout << n - max;  // Printing the difference between the total number of elements and the maximum length of the subsequence
    return 0;  // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
