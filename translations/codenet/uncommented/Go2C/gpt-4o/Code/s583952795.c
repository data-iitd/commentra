#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_BUF_SIZE 10000
#define MAX_BUF_SIZE 100000000

char buffer[INITIAL_BUF_SIZE];

void flush() {
    fflush(stdout);
}

int readInt() {
    int value;
    scanf("%d", &value);
    return value;
}

char* intToString(int number) {
    char* str = (char*)malloc(12 * sizeof(char)); // Enough for int32
    sprintf(str, "%d", number);
    return str;
}

char* tenToN(int number, int n) {
    char* s = (char*)malloc(32 * sizeof(char)); // Buffer for the result
    s[0] = '\0'; // Initialize as empty string
    int tmp = number;

    do {
        char* digit = intToString(tmp % n);
        strcat(s, digit);
        free(digit);
        tmp /= n;
    } while (tmp > 0);

    // Reverse the string
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }

    return s;
}

int main() {
    int N = readInt();
    int K = readInt();
    char* s = tenToN(N, K);
    printf("%lu\n", strlen(s));
    free(s);
    return 0;
}

/* <END-OF-CODE> */
