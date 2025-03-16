#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Reads an integer from the standard input using a StringTokenizer.
int readInt() {
    char *str;
    int num;
    scanf("%s", str);
    num = atoi(str);
    return num;
}

// The main method is the entry point of the program.
int main(int argc, char *argv[]) {
    int K = readInt();

    // Check if K is divisible by 2 or 5, return -1 if true.
    if (K % 2 == 0 || K % 5 == 0) {
        printf("-1\n");
        return 0;
    }

    // If K is divisible by 7, divide K by 7.
    if (K % 7 == 0) {
        K /= 7;
    }

    // Multiply K by 9.
    K *= 9;

    // Initialize the answer and the remainder.
    int ans = 1;
    int remainder = 10 % K;

    // Loop to find the number of digits required to form a number that is a multiple of K.
    while (remainder != 1) {
        ans++;
        remainder = remainder * 10 % K;
    }

    printf("%d\n", ans);
    return 0;
}

