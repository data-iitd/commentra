#include <iostream>
using namespace std;

// Function to find the product of two numbers after subtracting 2 from each
int solution(int n, int m) {
    // Set n and m to be the input numbers after subtracting 2 from each
    n = n - 2;
    m = m - 2;

    // Check if n is less than 0, if so set it to 1
    if (n < 0) {
        n = 1;
    }

    // Check if m is less than 0, if so set it to 1
    if (m < 0) {
        m = 1;
    }

    // Multiply n and m and return the result
    return n * m;
}

// Main function to read input and call solution function
int main() {
    // Initialize two variables n and m to read input
    int n, m;

    // Use cin to read input from the standard input
    cin >> n >> m;

    // Call solution function with n and m as arguments and print the result
    cout << solution(n, m) << endl;

    return 0;
}

