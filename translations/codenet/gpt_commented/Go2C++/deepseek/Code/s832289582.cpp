#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// Function to read integers from input
int readInt() {
    int value;
    cin >> value;
    return value;
}

// Function to read a string from input
string readStr() {
    string value;
    cin >> value;
    return value;
}

// Function to check sub-numbers based on the value of P
int checkSubNumbers(int N, int P, const string& S) {
    switch (P) {
        case 2:
        case 5:
            // If P is 2 or 5, use the specific check for these primes
            return checkTwoOrFive(N, P, S);
        default:
            // For other primes, use the general check
            return checkNotTwoNorFive(N, P, S);
    }
}

// Function to count the sub-numbers divisible by 2 or 5
int checkTwoOrFive(int N, int P, const string& S) {
    int answer = 0;
    int n;

    // Iterate through the string S from the end to the beginning
    for (int i = N - 1; i >= 0; i--) {
        // Convert the character to an integer
        n = S[i] - '0';

        // Check if the digit is divisible by P and update the answer
        if (n % P == 0) {
            answer += i + 1; // Count the number of valid sub-numbers
        }
    }
    return answer;
}

// Function to count the sub-numbers for primes other than 2 and 5
int checkNotTwoNorFive(int N, int P, const string& S) {
    int multiplier = 1; // Initialize the multiplier for 10^i % P
    int answer = 0; // Initialize the answer counter
    vector<int> remainderLookup(P, 0); // Array to keep track of remainders
    int prevRemaider = -1; // Variable to store the previous remainder
    int digit, remainder, count;

    // Iterate through the string S from the end to the beginning
    for (int i = N - 1; i >= 0; i--) {
        digit = S[i] - '0'; // Convert the character to an integer

        // Calculate the current remainder based on the previous remainder
        if (prevRemaider == -1) { // First digit case
            remainder = digit % P;
        } else {
            remainder = ((multiplier * digit) % P + prevRemaider) % P;
        }

        // If the remainder is zero, increment the answer
        if (remainder == 0) {
            answer++;
        }

        // Update the count of sub-numbers with the current remainder
        count = remainderLookup[remainder];
        answer += count; // Add the count of previous occurrences of this remainder
        count++; // Increment the count for this remainder
        remainderLookup[remainder] = count; // Store the updated count
        prevRemaider = remainder; // Update the previous remainder
        multiplier = (multiplier * 10) % P; // Update the multiplier for the next digit
    }
    return answer;
}

int main() {
    // Read the integer values N and P, and the string S from input
    int N = readInt();
    int P = readInt();
    string S = readStr();

    // Check the sub-numbers based on the conditions and print the result
    int answer = checkSubNumbers(N, P, S);
    cout << answer << endl;

    return 0;
}
