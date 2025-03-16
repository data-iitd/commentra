

#include <stdio.h>

// Function to read a single line from standard input and strip any trailing whitespace characters.
char* rs() {
    int c;
    char* s = (char*)malloc(100);
    int i = 0;
    while ((c = getchar())!= '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return s;
}

// Function to read an integer from standard input.
int ri() {
    char* s = rs();
    int n = 0;
    for (int i = 0; s[i] >= '0' && s[i] <= '9'; i++) {
        n = n * 10 + (s[i] - '0');
    }
    free(s);
    return n;
}

// Function to read a list of strings from standard input.
char** rs_(int* n) {
    int c;
    char** s = (char**)malloc(sizeof(char*) * 100);
    int i = 0;
    *n = 0;
    while ((c = getchar())!= '\n') {
        if (c =='') {
            *n = *n + 1;
            s = (char**)realloc(s, sizeof(char*) * (*n + 1));
        } else {
            s[*n] = (char*)malloc(100);
            int j = 0;
            s[*n][j++] = c;
            while ((c = getchar())!='') {
                s[*n][j++] = c;
            }
            s[*n][j] = '\0';
        }
    }
    return s;
}

// Function to read a list of integers from standard input.
int* ri_(int* n) {
    char** s;
    int* a = (int*)malloc(sizeof(int) * 100);
    *n = 0;
    s = rs_(n);
    for (int i = 0; i < *n; i++) {
        a[i] = 0;
        for (int j = 0; s[i][j] >= '0' && s[i][j] <= '9'; j++) {
            a[i] = a[i] * 10 + (s[i][j] - '0');
        }
    }
    for (int i = 0; i < *n; i++) {
        free(s[i]);
    }
    free(s);
    return a;
}

int main() {
    int N = ri();
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += i * (N / i) * (N / i + 1) / 2;
    }
    printf("%d\n", ans);
    return 0;
}
