// Importing required packages
#include <iostream>
#include <string>

// Function to find the solution
int solve(int a, int b, int c) {
    // Declaring a temporary variable
    int temp;

    // Checking if c is equal to the sum of a and b
    if (c == a + b) {
        // If true, then calculate the value of temp
        temp = b + c;
        // Add a comment explaining the logic
        // temp = b + c; // c is equal to the sum of a and b
    } else if (c - 1 > a + b) {
        // Else if c is greater than the sum of a and b by 1
        // Calculate the difference between c and the sum of a and b
        int temp_diff = c - (a + b);
        // Calculate the value of temp
        temp = b + c - temp_diff;
        // Add a comment explaining the logic
        // temp = b + c - (c - (a + b)); // c is greater than the sum of a and b by 1
    } else {
        // Else, c is less than or equal to the sum of a and b
        // Calculate the value of temp
        temp = b + c;
        // Add a comment explaining the logic
        // temp = b + c; // c is less than or equal to the sum of a and b
    }

    // Return the value of temp as the answer
    return temp;
}

// Main function to read input and call the solve function
int main() {
    // Declaring variables a, b, and c to read input
    int a, b, c;
    // Reading input from stdin using std::cin
    std::cin >> a >> b >> c;
    // Calling the solve function and storing the result in ans
    int ans = solve(a, b, c);
    // Printing the answer using std::cout
    std::cout << ans << std::endl;
    // Add a comment explaining the logic
    // ans = solve(a, b, c); // Solving the problem using the solve function

    return 0;
}

