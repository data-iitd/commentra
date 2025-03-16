
#include <stdio.h>

// Function to read a line from standard input and remove trailing whitespace
char* rs() {
    static char buf[1024];
    fgets(buf, sizeof(buf), stdin);
    int c = 0;
    while (buf[c]!= '\n') c++;
    buf[c] = '\0';
    return buf;
}

// Function to read an integer from standard input
int ri() {
    int n;
    scanf("%d", &n);
    return n;
}

// Function to read a line from standard input and return a list of strings
char** rs_() {
    int n = 0;
    char* buf = rs();
    char** res = (char**)malloc(sizeof(char*) * 1024);
    char* p = buf;
    while (*p) {
        if (*p =='') {
            *p = '\0';
            res[n++] = p + 1;
        }
        p++;
    }
    return res;
}

// Function to read a line from standard input and return a list of integers
int* ri_() {
    int n = 0;
    char* buf = rs();
    int* res = (int*)malloc(sizeof(int) * 1024);
    char* p = buf;
    while (*p) {
        if (*p =='') {
            *p = '\0';
            res[n++] = atoi(p + 1);
        }
        p++;
    }
    return res;
}

int main() {
    // Read the integer N from input
    int N = ri();

    // Initialize the answer variable to accumulate the result
    long long ans = 0;

    // Loop through each integer from 1 to N (inclusive)
    for (int i = 1; i <= N; i++) {
        // Calculate the contribution of the current integer i to the answer
        ans += i * (N / i) * (N / i + 1) / 2;
    }

    // Print the final result
    printf("%lld\n", ans);

    return 0;
}
