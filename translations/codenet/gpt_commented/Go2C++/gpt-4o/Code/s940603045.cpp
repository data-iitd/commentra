#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to calculate the sum of digits of a number
int sumOfDigits(const string& num) {
    int sum = 0;
    for (char c : num) {
        sum += c - '0'; // Convert char to int and accumulate
    }
    return sum;
}

// Main function
int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Read input as a string
    string N;
    cin >> N;

    // Calculate the sum of digits in the input number
    int digitSum = sumOfDigits(N);

    // Convert the string input to an integer
    long long m = stoll(N); // Use stoll for large integers

    // Check if the number is divisible by the sum of its digits
    if (m % digitSum == 0) {
        cout << "Yes" << endl; // Print "Yes" if divisible
    } else {
        cout << "No" << endl; // Print "No" if not divisible
    }

    return 0;
}

// Utility functions (if needed) can be added here

// <END-OF-CODE>
