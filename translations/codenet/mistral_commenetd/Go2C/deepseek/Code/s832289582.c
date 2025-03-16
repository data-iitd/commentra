#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 200000
#define MAX_P 10000

int checkSubNumbers(int N, int P, char* S);
int checkTwoOrFive(int N, int P, char* S);
int checkNotTwoNorFive(int N, int P, char* S);

int main() {
    char S[MAX_N + 1];
    int N, P;
    scanf("%d %d %s", &N, &P, S);
    int answer = checkSubNumbers(N, P, S);
    printf("%d\n", answer);
    return 0;
}

int checkSubNumbers(int N, int P, char* S) {
    if (P == 2 || P == 5) {
        return checkTwoOrFive(N, P, S);
    } else {
        return checkNotTwoNorFive(N, P, S);
    }
}

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

int checkNotTwoNorFive(int N, int P, char* S) {
    int multiplier = 1;
    int answer = 0;
    int remainderLookup[P];
    memset(remainderLookup, 0, sizeof(remainderLookup));
    int prevRemaider = -1;
    for (int i = N - 1; i >= 0; i--) {
        int digit = S[i] - '0';
        if (prevRemaider == -1) {
            prevRemaider = digit % P;
        } else {
            prevRemaider = ((multiplier * digit) % P + prevRemaider) % P;
        }
        if (prevRemaider == 0) {
            answer++;
        }
        answer += remainderLookup[prevRemaider];
        remainderLookup[prevRemaider]++;
        multiplier = (multiplier * 10) % P;
    }
    return answer;
}
