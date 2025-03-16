
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int capacity;
    int size;
    char *buffer;
} Scanner;

Scanner *newScanner(int capacity) {
    Scanner *scanner = (Scanner *)malloc(sizeof(Scanner));
    scanner->capacity = capacity;
    scanner->size = 0;
    scanner->buffer = (char *)malloc(sizeof(char) * capacity);
    return scanner;
}

void freeScanner(Scanner *scanner) {
    free(scanner->buffer);
    free(scanner);
}

void scan(Scanner *scanner) {
    if (scanner->size == scanner->capacity) {
        scanner->capacity *= 2;
        scanner->buffer = (char *)realloc(scanner->buffer, sizeof(char) * scanner->capacity);
    }
    int c = getchar();
    while (c =='' || c == '\n') {
        c = getchar();
    }
    scanner->buffer[scanner->size] = c;
    scanner->size++;
}

void scanStr(Scanner *scanner, char *str) {
    int c = getchar();
    int i = 0;
    while (c!= '\n') {
        str[i] = c;
        i++;
        c = getchar();
    }
    str[i] = '\0';
}

int nextInt(Scanner *scanner) {
    int i = 0;
    int c = scanner->buffer[i];
    int sign = 1;
    if (c == '-') {
        sign = -1;
        i++;
        c = scanner->buffer[i];
    }
    int result = 0;
    while (c >= '0' && c <= '9') {
        result = result * 10 + (c - '0');
        i++;
        c = scanner->buffer[i];
    }
    scanner->size -= i;
    memmove(scanner->buffer, scanner->buffer + i, sizeof(char) * scanner->size);
    return result * sign;
}

char *nextStr(Scanner *scanner) {
    int i = 0;
    int c = scanner->buffer[i];
    while (c =='' || c == '\n') {
        i++;
        c = scanner->buffer[i];
    }
    int start = i;
    while (c!='' && c!= '\n') {
        i++;
        c = scanner->buffer[i];
    }
    int length = i - start;
    char *result = (char *)malloc(sizeof(char) * (length + 1));
    memcpy(result, scanner->buffer + start, sizeof(char) * length);
    result[length] = '\0';
    scanner->size -= i + 1;
    memmove(scanner->buffer, scanner->buffer + i + 1, sizeof(char) * scanner->size);
    return result;
}

int main() {
    Scanner *scanner = newScanner(256);
    int N = nextInt(scanner);
    int P = nextInt(scanner);
    char *S = nextStr(scanner);
    freeScanner(scanner);

    int answer = 0;
    if (P == 2 || P == 5) {
        answer = checkSubNumbers(N, P, S);
    } else {
        answer = checkNotTwoNorFive(N, P, S);
    }
    printf("%d\n", answer);
    return 0;
}

int checkSubNumbers(int N, int P, char *S) {
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
    int multiplier = 1; // 10^i % P
    int answer = 0;
    int remainderLookup[P];
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
    return answer;
}

