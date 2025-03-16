#include <iostream>
#include <vector>
#include <algorithm>

// Macro definitions for maximum and minimum
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

// Comparison function for sort to sort integers in descending order
bool compare_int(long int a, long int b) {
    return a > b; // Sort in descending order
}

// Function to calculate the greatest common divisor (GCD) using recursion
long int gcd(long int a, long int b) {
    if (b == 0) {
        return a; // Base case: if b is 0, return a
    } else {
        return gcd(b, a % b); // Recursive case
    }
}

// Function to calculate the least common multiple (LCM) using GCD
long int lcm(long int a, long int b) {
    return a * b / gcd(a, b); // LCM formula
}

// Main function
int main() {
    long int n; // Number of participants
    long long int k; // Points required to win
    long int q; // Number of questions
    std::vector<long int> a(100001); // Vector to store the questions
    std::vector<long long int> point(100001, 0); // Vector to track points of each participant

    // Read input values for n, k, and q
    std::cin >> n >> k >> q;

    // Process each question and update points for the corresponding participant
    for (long int i = 0; i < q; i++) {
        std::cin >> a[i]; // Read the participant number for the question
        point[a[i] - 1]++; // Increment the point for the participant who answered
    }

    // Determine if each participant has enough points to win
    for (long int i = 0; i < n; i++) {
        if (k - (q - point[i]) > 0) { // Check if the participant has enough points
            std::cout << "Yes\n"; // Participant can win
        } else {
            std::cout << "No\n"; // Participant cannot win
        }
    }

    return 0; // End of the program
}

// <END-OF-CODE>
