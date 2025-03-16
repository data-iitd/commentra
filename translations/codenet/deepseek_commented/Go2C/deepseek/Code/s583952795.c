#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* TenToN(int number, int n) {
    char* s = (char*)malloc(100000 * sizeof(char)); // Allocate memory for the result string
    int i = 0;
    int tmp = number;

    while (tmp > 0) {
        int remainder = tmp % n;
        if (remainder < 10) {
            s[i++] = '0' + remainder;
        } else {
            s[i++] = 'A' + (remainder - 10);
        }
        tmp /= n;
    }
    s[i] = '\0';

    // Reverse the string
    for (int j = 0; j < i / 2; j++) {
        char temp = s[j];
        s[j] = s[i - j - 1];
        s[i - j - 1] = temp;
    }

    return s;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    char* s = TenToN(N, K);
    printf("%lu\n", strlen(s));
    free(s); // Free the allocated memory

    return 0;
}

