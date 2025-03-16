#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
int checkSubNumbers(int N, int P, const char *S);
int checkTwoOrFive(int N, int P, const char *S);
int checkNotTwoNorFive(int N, int P, const char *S);

int main() {
    int N, P;
    char S[200001]; // Maximum length of S is 200000 + 1 for null terminator

    // Read N and P from standard input
    scanf("%d %d", &N, &P);
    // Read string S from standard input
    scanf("%s", S);

    int answer = checkSubNumbers(N, P, S); // Call checkSubNumbers function
    printf("%d\n", answer); // Print the answer

    return 0;
}

// checkSubNumbers function checks if any subnumber of given string S is divisible by prime number P
int checkSubNumbers(int N, int P, const char *S) {
    if (P == 2 || P == 5) {
        return checkTwoOrFive(N, P, S); // Call checkTwoOrFive function
    } else {
        return checkNotTwoNorFive(N, P, S); // Call checkNotTwoNorFive function
    }
}

// checkTwoOrFive function checks if any subnumber of given string S is divisible by prime number P equal to 2 or 5
int checkTwoOrFive(int N, int P, const char *S) {
    int answer = 0; // Initialize answer variable as 0
    for (int i = N - 1; i >= 0; i--) {
        int n = S[i] - '0'; // Convert character to integer
        if (n % P == 0) {
            answer += (i + 1); // Add index to answer
        }
    }
    return answer;
}

// checkNotTwoNorFive function checks if any subnumber of given string S is divisible by prime number P which is not equal to 2 or 5
int checkNotTwoNorFive(int N, int P, const char *S) {
    int multiplier = 1; // Initialize multiplier variable as 1
    int answer = 0; // Initialize answer variable as 0
    int remainderLookup[10000] = {0}; // Create an array for storing the count of remainders
    int prevRemainder = -1; // Initialize prevRemainder variable as -1

    for (int i = N - 1; i >= 0; i--) {
        int digit = S[i] - '0'; // Get the digit from the string S
        int remainder;

        if (prevRemainder == -1) {
            remainder = digit % P; // First digit remainder
        } else {
            remainder = ((multiplier * digit) % P + prevRemainder) % P; // Calculate new remainder
        }

        if (remainder == 0) {
            answer++; // Increment answer if remainder is 0
        }

        answer += remainderLookup[remainder]; // Add count of current remainder to answer
        remainderLookup[remainder]++; // Update count of current remainder
        prevRemainder = remainder; // Update previous remainder
        multiplier = (multiplier * 10) % P; // Update multiplier
    }
    return answer;
}
