
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N, P;
    char S[200001];
    scanf("%d %d", &N, &P);
    scanf("%s", S);
    int answer = checkSubNumbers(N, P, S);
    printf("%d\n", answer);
    return 0;
}

int checkSubNumbers(int N, int P, char S[]) {
    if (P == 2 || P == 5) {
        return checkTwoOrFive(N, P, S);
    } else {
        return checkNotTwoNorFive(N, P, S);
    }
}

int checkTwoOrFive(int N, int P, char S[]) {
    int answer = 0;
    int n;
    for (int i = N - 1; i >= 0; i--) {
        n = atoi(S + i);
        if (n % P == 0) {
            answer += i + 1;
        }
    }
    return answer;
}

int checkNotTwoNorFive(int N, int P, char S[]) {
    int multiplier = 1;
    int answer = 0;
    int remainderLookup[100001];
    int prevRemaider = -1;
    for (int i = N - 1; i >= 0; i--) {
        int digit = S[i] - '0';
        if (prevRemaider == -1) {
            int remainder = digit % P;
        } else {
            int remainder = (((multiplier * digit) % P) + prevRemaider) % P;
        }
        if (remainder == 0) {
            answer++;
        }
        int count = remainderLookup[remainder];
        answer += count;
        count++;
        remainderLookup[remainder] = count;
        prevRemaider = remainder;
        multiplier = (multiplier * 10) % P;
    }
    return answer;
}

// 