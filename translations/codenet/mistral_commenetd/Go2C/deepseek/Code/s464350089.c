#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
#define IO_BUFFER_SIZE 1 * 1024 * 1024

// Helper function to read input
char* sc() {
    static char buf[IO_BUFFER_SIZE];
    static int len = 0;
    static int pos = 0;
    if (pos >= len) {
        len = fread(buf, 1, IO_BUFFER_SIZE, stdin);
        pos = 0;
    }
    return buf + pos++;
}

// Helper functions to read input as a word and an integer
char* next() {
    while (*sc() <= ' ');
    char* start = sc();
    while (*sc() > ' ');
    return start;
}

int nextInt() {
    char* str = next();
    return atoi(str);
}

int main() {
    // Reading the first two integers h and n
    int h = nextInt();
    int n = nextInt();

    // Initializing variable a to 0
    int a = 0;

    // Iterating through the array of size n and adding each integer to variable a
    for (int i = 0; i < n; i++) {
        a += nextInt();
    }

    // Checking if h is less than or equal to the sum of all integers and printing the result accordingly.
    if (h > a) {
        printf("No\n");
    } else {
        printf("Yes\n");
    }

    return 0;
}
