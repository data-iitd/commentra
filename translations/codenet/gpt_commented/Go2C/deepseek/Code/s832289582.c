#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
int checkTwoOrFive(int N, int P, char* S);
int checkNotTwoNorFive(int N, int P, char* S);

int main() {
    // Initialize the input scanner with a buffer size of 256 KB
    char buffer[256 * 1024];
    setvbuf(stdin, buffer, _IOFBF, sizeof(buffer));

    // Read the integer values N and P, and the string S from input
    int N, P;
    char S[200001];
    scanf("%d %d %s", &N, &P, S);

    // Check the sub-numbers based on the conditions and print the result
    int answer;
    if (P == 2 || P == 5) {
        answer = checkTwoOrFive(N, P, S);
    } else {
        answer = checkNotTwoNorFive(N, P, S);
    }
    printf("%d\n", answer);

    return 0;
}

// checkTwoOrFive counts the sub-numbers divisible by 2 or 5
int checkTwoOrFive(int N, int P, char* S) {
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
int checkNotTwoNorFive(int N, int P, char* S) {
    int multiplier = 1; // Initialize the multiplier for 10^i % P
    int answer = 0; // Initialize the answer counter
    int remainderLookup[P]; // Array to keep track of remainders
    int prevRemaider = -1; // Variable to store the previous remainder
    int digit, remainder, count;

    // Initialize the remainder lookup array
    memset(remainderLookup, 0, sizeof(remainderLookup));

    // Iterate through the string S from the end to the beginning
    for (int i = N - 1; i >= 0; i--) {
        digit = S[i] - '0'; // Convert the character to an integer

        // Calculate the current remainder based on the previous remainder
        if (prevRemaider == -1) { // First digit case
            remainder = digit % P;
        } else {
            remainder = (((multiplier * digit) % P) + prevRemaider) % P;
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
