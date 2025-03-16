#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read an integer from input
int readInt() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to read a string from input
char* readStr() {
    char *str = (char*)malloc(256 * sizeof(char));
    scanf("%s", str);
    return str;
}

// Function to check sub-numbers based on the prime P
int checkSubNumbers(int N, int P, char* S) {
    if (P == 2 || P == 5) {
        return checkTwoOrFive(N, P, S);
    } else {
        return checkNotTwoNorFive(N, P, S);
    }
}

// Function to check sub-numbers when P is 2 or 5
int checkTwoOrFive(int N, int P, char* S) {
    int answer = 0;
    int n;
    for (int i = N - 1; i >= 0; i--) {
        n = S[i] - '0';
        if (n % P == 0) {
            answer += i + 1;
        }
    }
    return answer;
}

// Function to check sub-numbers when P is not 2 or 5
int checkNotTwoNorFive(int N, int P, char* S) {
    int multiplier = 1; // 10^i % P
    int answer = 0;
    int remainderLookup[P];
    memset(remainderLookup, 0, sizeof(remainderLookup));
    int prevRemaider = -1;
    int digit, remainder, count;
    for (int i = N - 1; i >= 0; i--) {
        digit = S[i] - '0';
        if (prevRemaider == -1) { // first digit
            remainder = digit % P;
        } else {
            remainder = (((multiplier * digit) % P) + prevRemaider) % P;
        }
        if (remainder == 0) {
            answer++;
        }
        count = remainderLookup[remainder];
        answer += count;
        count++;
        remainderLookup[remainder] = count;
        prevRemaider = remainder;
        multiplier = (multiplier * 10) % P;
    }
    free(S); // Free the allocated memory for the string
    return answer;
}

int main() {
    int N = readInt();
    int P = readInt();
    char* S = readStr();
    int answer = checkSubNumbers(N, P, S);
    printf("%d\n", answer);
    return 0;
}

