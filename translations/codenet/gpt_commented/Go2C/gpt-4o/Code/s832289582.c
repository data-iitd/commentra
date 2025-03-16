#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 200000
#define MAX_P 10000

// Function prototypes
int checkSubNumbers(int N, int P, const char *S);
int checkTwoOrFive(int N, int P, const char *S);
int checkNotTwoNorFive(int N, int P, const char *S);

int main() {
    // Initialize variables
    int N, P;
    char S[MAX_N + 1]; // +1 for null terminator

    // Read the integer values N and P, and the string S from input
    scanf("%d %d %s", &N, &P, S);

    // Check the sub-numbers based on the conditions and print the result
    int answer = checkSubNumbers(N, P, S);
    printf("%d\n", answer);

    return 0;
}

// checkSubNumbers determines the method to check sub-numbers based on the value of P
int checkSubNumbers(int N, int P, const char *S) {
    if (P == 2 || P == 5) {
        // If P is 2 or 5, use the specific check for these primes
        return checkTwoOrFive(N, P, S);
    } else {
        // For other primes, use the general check
        return checkNotTwoNorFive(N, P, S);
    }
}

// checkTwoOrFive counts the sub-numbers divisible by 2 or 5
int checkTwoOrFive(int N, int P, const char *S) {
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

// checkNotTwoNorFive counts the sub-numbers for primes other than 2 and 5
int checkNotTwoNorFive(int N, int P, const char *S) {
    int multiplier = 1; // Initialize the multiplier for 10^i % P
    int answer = 0;     // Initialize the answer counter
    int remainderLookup[MAX_P] = {0}; // Array to keep track of remainders
    int prevRemainder = -1; // Variable to store the previous remainder
    int digit, remainder, count;

    // Iterate through the string S from the end to the beginning
    for (int i = N - 1; i >= 0; i--) {
        digit = S[i] - '0'; // Convert the character to an integer

        // Calculate the current remainder based on the previous remainder
        if (prevRemainder == -1) { // First digit case
            remainder = digit % P;
        } else {
            remainder = (((multiplier * digit) % P) + prevRemainder) % P;
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
        prevRemainder = remainder; // Update the previous remainder
        multiplier = (multiplier * 10) % P; // Update the multiplier for the next digit
    }
    return answer;
}
