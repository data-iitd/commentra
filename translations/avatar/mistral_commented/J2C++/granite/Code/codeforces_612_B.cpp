
// Importing the iostream library for input/output operations
#include <iostream>

// Defining the main function as the entry point of the program
int main() {
    // Creating a new stream object to read input from the console
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    // Declaring an integer variable n to store the number of test cases
    int n;

    // Reading the number of test cases from the console
    std::cin >> n;

    // Declaring an integer array dp of size 200001 to store the position of each number in the sequence
    int dp[200001];

    // Initializing a long variable ans to store the answer
    long long ans = 0;

    // Iterating through each test case
    for (int i = 0; i < n; i++) {
        // Reading the next number to be added to the sequence
        int num;
        std::cin >> num;

        // Storing the position of the number in the dp array
        dp[num] = i;
    }

    // Calculating the answer by iterating through the dp array and finding the absolute difference between the positions of consecutive numbers
    for (int i = 2; i <= n; i++) {
        // Adding the absolute difference to the answer
        ans += std::abs(dp[i] - dp[i - 1]);
    }

    // Printing the answer to the console
    std::cout << ans << std::endl;

    return 0;
}

