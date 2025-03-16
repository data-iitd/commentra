#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INITIAL_BUF_SIZE 10000
#define MAX_BUF_SIZE 100000000

char buffer[INITIAL_BUF_SIZE];
int bufferIndex = 0;

void readBuffer(char *buf, int size) {
    fgets(buf, size, stdin);
}

int readInt() {
    int num = 0;
    char ch;
    while ((ch = getchar()) != ' ' && ch != '\n') {
        num = num * 10 + (ch - '0');
    }
    return num;
}

char* TenToN(int number, int n) {
    static char s[100];
    int tmp = number;
    int index = 0;
    while (tmp > 0) {
        int remainder = tmp % n;
        s[index++] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'A');
        tmp /= n;
    }
    s[index] = '\0';
    // Reverse the string
    for (int i = 0; i < index / 2; i++) {
        char temp = s[i];
        s[i] = s[index - i - 1];
        s[index - i - 1] = temp;
    }
    return s;
}

int main() {
    int N = readInt();
    int K = readInt();
    char* s = TenToN(N, K);
    printf("%lu\n", strlen(s));
    return 0;
}

