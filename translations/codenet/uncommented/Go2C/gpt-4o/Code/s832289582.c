#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 200000

int checkSubNumbers(int N, int P, char *S);
int checkTwoOrFive(int N, int P, char *S);
int checkNotTwoNorFive(int N, int P, char *S);

int main() {
    int N, P;
    char S[MAX_N + 1];

    scanf("%d %d %s", &N, &P, S);
    int answer = checkSubNumbers(N, P, S);
    printf("%d\n", answer);

    return 0;
}

int checkSubNumbers(int N, int P, char *S) {
    if (P == 2 || P == 5) {
        return checkTwoOrFive(N, P, S);
    } else {
        return checkNotTwoNorFive(N, P, S);
    }
}

int checkTwoOrFive(int N, int P, char *S) {
    int answer = 0;
    for (int i = N - 1; i >= 0; i--) {
        int n = S[i] - '0';
        if (n % P == 0) {
            answer += i + 1;
        }
    }
    return answer;
}

int checkNotTwoNorFive(int N, int P, char *S) {
    int multiplier = 1; // 10^i % P
    int answer = 0;
    int remainderLookup[P];
    memset(remainderLookup, 0, sizeof(remainderLookup));
    int prevRemainder = -1;
    int digit, remainder, count;

    for (int i = N - 1; i >= 0; i--) {
        digit = S[i] - '0';
        if (prevRemainder == -1) { // first digit
            remainder = digit % P;
        } else {
            remainder = ((multiplier * digit) % P + prevRemainder) % P;
        }
        if (remainder == 0) {
            answer++;
        }
        count = remainderLookup[remainder];
        answer += count;
        count++;
        remainderLookup[remainder] = count;
        prevRemainder = remainder;
        multiplier = (multiplier * 10) % P;
    }
    return answer;
}
