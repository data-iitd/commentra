
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    FILE *stream;
    char *buffer;
    int buffer_size;
    int position;
} Scanner;

Scanner *newScanner(FILE *stream, int buffer_size) {
    Scanner *scanner = (Scanner *)malloc(sizeof(Scanner));
    scanner->stream = stream;
    scanner->buffer_size = buffer_size;
    scanner->buffer = (char *)malloc(sizeof(char) * buffer_size);
    scanner->position = 0;
    return scanner;
}

void deleteScanner(Scanner *scanner) {
    free(scanner->buffer);
    free(scanner);
}

int nextInt(Scanner *scanner) {
    char *end;
    int number = strtol(scanner->buffer + scanner->position, &end, 10);
    scanner->position += end - (scanner->buffer + scanner->position);
    return number;
}

char *nextStr(Scanner *scanner) {
    char *start = scanner->buffer + scanner->position;
    while (scanner->buffer[scanner->position]!= '\0' && scanner->buffer[scanner->position]!='') {
        scanner->position++;
    }
    scanner->position++;
    char *end = scanner->buffer + scanner->position;
    char *result = (char *)malloc(sizeof(char) * (end - start + 1));
    strncpy(result, start, end - start);
    result[end - start] = '\0';
    return result;
}

int main() {
    Scanner *scanner = newScanner(stdin, 256 * 1024);
    int N = nextInt(scanner);
    int P = nextInt(scanner);
    char *S = nextStr(scanner);
    deleteScanner(scanner);

    int answer = 0;
    if (P == 2 || P == 5) {
        answer = checkTwoOrFive(N, P, S);
    } else {
        answer = checkNotTwoNorFive(N, P, S);
    }
    printf("%d\n", answer);
    return 0;
}

int checkTwoOrFive(int N, int P, char *S) {
    int answer = 0;
    for (int i = N - 1; i >= 0; i--) {
        if ((S[i] - '0') % P == 0) {
            answer += i + 1;
        }
    }
    return answer;
}

int checkNotTwoNorFive(int N, int P, char *S) {
    int multiplier = 1;
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

