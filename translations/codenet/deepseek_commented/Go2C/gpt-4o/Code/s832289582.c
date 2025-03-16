#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 200000
#define MAX_P 10000

// Function prototypes
int checkSubNumbers(int N, int P, char *S);
int checkTwoOrFive(int N, int P, char *S);
int checkNotTwoNorFive(int N, int P, char *S);

int main() {
    int N, P;
    char S[MAX_N + 1]; // +1 for null terminator

<<<<<<< HEAD
    // Read N, P, and S from input
    scanf("%d %d %s", &N, &P, S);
    
    int answer = checkSubNumbers(N, P, S);
    printf("%d\n", answer);
    
=======
    // Read N and P
    scanf("%d %d", &N, &P);
    // Read string S
    scanf("%s", S);

    int answer = checkSubNumbers(N, P, S);
    printf("%d\n", answer);

>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// checkSubNumbers determines whether P is 2 or 5 and calls the appropriate helper function.
int checkSubNumbers(int N, int P, char *S) {
    if (P == 2 || P == 5) {
        return checkTwoOrFive(N, P, S);
    } else {
        return checkNotTwoNorFive(N, P, S);
    }
}

// checkTwoOrFive iterates over the string S from the end to the beginning, checking if the last digit of each substring is divisible by P.
int checkTwoOrFive(int N, int P, char *S) {
    int answer = 0;
    for (int i = N - 1; i >= 0; i--) {
        int n = S[i] - '0'; // Convert the current character to an integer.
        if (n % P == 0) { // Check if the integer is divisible by P.
            answer += (i + 1); // If it is, add the position to the answer.
        }
    }
    return answer;
}

// checkNotTwoNorFive uses a rolling hash approach to efficiently determine the number of substrings of S that are divisible by P.
int checkNotTwoNorFive(int N, int P, char *S) {
    int multiplier = 1; // 10^i % P
    int answer = 0;
    int remainderLookup[MAX_P] = {0}; // Create an array to store the counts of remainders.
    int prevRemainder = -1;
<<<<<<< HEAD
    
    for (int i = N - 1; i >= 0; i--) {
        int digit = S[i] - '0'; // Convert the current character to an integer.
        int remainder;
        
=======
    int digit, remainder, count;

    for (int i = N - 1; i >= 0; i--) {
        digit = S[i] - '0'; // Convert the current character to an integer.
>>>>>>> 98c87cb78a (data updated)
        if (prevRemainder == -1) { // If it's the first digit, calculate the remainder directly.
            remainder = digit % P;
        } else { // Otherwise, use the rolling hash approach.
            remainder = ((multiplier * digit) % P + prevRemainder) % P;
        }
<<<<<<< HEAD
        
        if (remainder == 0) { // If the remainder is 0, increment the answer.
            answer++;
        }
        
        int count = remainderLookup[remainder]; // Get the current count of this remainder.
        answer += count; // Add the count to the answer.
        count++; // Increment the count.
        remainderLookup[remainder] = count; // Update the count in the array.
        
        prevRemainder = remainder; // Update the previous remainder.
        multiplier = (multiplier * 10) % P; // Update the multiplier for the next iteration.
    }
    
=======
        if (remainder == 0) { // If the remainder is 0, increment the answer.
            answer++;
        }
        count = remainderLookup[remainder]; // Get the current count of this remainder.
        answer += count; // Add the count to the answer.
        count++; // Increment the count.
        remainderLookup[remainder] = count; // Update the count in the array.
        prevRemainder = remainder; // Update the previous remainder.
        multiplier = (multiplier * 10) % P; // Update the multiplier for the next iteration.
    }
>>>>>>> 98c87cb78a (data updated)
    return answer;
}
