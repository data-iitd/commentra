#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 200000

int nextInt(char **input) {
    int result;
    sscanf(*input, "%d", &result);
    *input += strlen(strchr(*input, ' ') + 1);
    return result;
}

unsigned long long nextUInt64(char **input) {
    unsigned long long result;
    sscanf(*input, "%llu", &result);
    *input += strlen(strchr(*input, ' ') + 1);
    return result;
}

char *nextStr(char **input) {
    char *space = strchr(*input, ' ');
    if (space == NULL) {
        space = *input + strlen(*input);
    }
    char *result = (char *)malloc(space - *input + 1);
    strncpy(result, *input, space - *input);
    result[space - *input] = '\0';
    *input = space + 1;
    return result;
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
    int n;
    for (int i = N - 1; i >= 0; i--) {
        n = S[i] - '0';
        if (n % P == 0) {
            answer += i + 1;
        }
    }
    return answer;
}

int checkNotTwoNorFive(int N, int P, char *S) {
    unsigned long long multiplier = 1;
    int answer = 0;
    int remainderLookup[P];
    memset(remainderLookup, 0, sizeof(remainderLookup));
    int prevRemaider = -1;
    int digit, remainder, count;
    for (int i = N - 1; i >= 0; i--) {
        digit = S[i] - '0';
        if (prevRemaider == -1) {
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
    return answer;
}

int main() {
    char buffer[MAX_N * 5 + 100]; // Adjust buffer size as needed
    fgets(buffer, sizeof(buffer), stdin);
    char *input = buffer;

    int N = nextInt(&input);
    int P = nextInt(&input);
    char *S = nextStr(&input);

    int answer = checkSubNumbers(N, P, S);
    printf("%d\n", answer);

    free(S);
    return 0;
}
