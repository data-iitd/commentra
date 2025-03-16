#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Function prototypes
int checkSubNumbers(int N, int P, const string& S);
int checkTwoOrFive(int N, int P, const string& S);
int checkNotTwoNorFive(int N, int P, const string& S);

int main() {
    // Read the integer values N and P, and the string S from input
    int N, P;
    string S;
    cin >> N >> P >> S;

    // Check the sub-numbers based on the conditions and print the result
    int answer = checkSubNumbers(N, P, S);
    cout << answer << endl;

    return 0;
}

// checkSubNumbers determines the method to check sub-numbers based on the value of P
int checkSubNumbers(int N, int P, const string& S) {
    if (P == 2 || P == 5) {
        // If P is 2 or 5, use the specific check for these primes
        return checkTwoOrFive(N, P, S);
    } else {
        // For other primes, use the general check
        return checkNotTwoNorFive(N, P, S);
    }
}

// checkTwoOrFive counts the sub-numbers divisible by 2 or 5
int checkTwoOrFive(int N, int P, const string& S) {
    int answer = 0;

    // Iterate through the string S from the end to the beginning
    for (int i = N - 1; i >= 0; i--) {
        int n = S[i] - '0'; // Convert the character to an integer

        // Check if the digit is divisible by P and update the answer
        if (n % P == 0) {
            answer += i + 1; // Count the number of valid sub-numbers
        }
    }
    return answer;
}

// checkNotTwoNorFive counts the sub-numbers for primes other than 2 and 5
int checkNotTwoNorFive(int N, int P, const string& S) {
    int multiplier = 1; // Initialize the multiplier for 10^i % P
    int answer = 0;     // Initialize the answer counter
    vector<int> remainderLookup(P, 0); // Array to keep track of remainders
    int prevRemainder = -1; // Variable to store the previous remainder

    // Iterate through the string S from the end to the beginning
    for (int i = N - 1; i >= 0; i--) {
        int digit = S[i] - '0'; // Convert the character to an integer
        int remainder;

        // Calculate the current remainder based on the previous remainder
        if (prevRemainder == -1) { // First digit case
            remainder = digit % P;
        } else {
            remainder = (multiplier * digit % P + prevRemainder) % P;
        }

        // If the remainder is zero, increment the answer
        if (remainder == 0) {
            answer++;
        }

        // Update the count of sub-numbers with the current remainder
        int count = remainderLookup[remainder];
        answer += count; // Add the count of previous occurrences of this remainder
        count++; // Increment the count for this remainder
        remainderLookup[remainder] = count; // Store the updated count
        prevRemainder = remainder; // Update the previous remainder
        multiplier = (multiplier * 10) % P; // Update the multiplier for the next digit
    }
    return answer;
}

// <END-OF-CODE>
