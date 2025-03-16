// Importing the necessary header for input and output
#include <iostream>
#include <vector>
#include <cmath> // For abs function

using namespace std;

// Defining the main function as the entry point of the program
int main() {
    // Creating a variable to read the number of test cases
    int n;
    cin >> n;

    // Declaring a vector dp of size 200001 to store the position of each number in the sequence
    vector<int> dp(200001, 0);

    // Initializing a long long variable ans to store the answer
    long long ans = 0;

    // Iterating through each test case
    for (int i = 0; i < n; i++) {
        // Reading the next number to be added to the sequence
        int num;
        cin >> num;

        // Storing the position of the number in the dp vector
        dp[num] = i;
    }

    // Calculating the answer by iterating through the dp vector and finding the absolute difference between the positions of consecutive numbers
    for (int i = 2; i <= n; i++) {
        // Adding the absolute difference to the answer
        ans += abs(dp[i] - dp[i - 1]);
    }

    // Printing the answer to the console
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
