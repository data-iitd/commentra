#include <stdio.h>
#include <string.h>

int gcd(int a, int b) {
    a = a > b ? a : b;
    b = a > b ? b : a;
    while (a % b > 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return b;
}

int main() {
    char s[100000];  // Assuming the input string will not exceed 100000 characters
    scanf("%s", s);  // Read input string
    char t[100000];  // Processed string
    int i = 0, j = 0;  // Initialize indices

    // Process the input string character by character
    while (s[i] != '\0') {
        if (s[i] == 'A') {
            t[j++] = 'A';
            i++;
        } else if (s[i] == 'B') {
            if (s[i + 1] == 'C') {
                t[j++] = 'D';
                i += 2;
            } else {
                t[j++] = 'X';
                i++;
            }
        } else {
            t[j++] = 'X';
            i++;
        }
    }
    t[j] = '\0';  // Null-terminate the processed string

    int total = 0;  // Initialize total count
    int numA = 0;   // Initialize count of 'A' characters

    // Count the number of 'A' characters before each 'X' in the processed string
    for (i = 0; t[i] != '\0'; i++) {
        if (t[i] == 'X') {
            numA = 0;
        } else {
            if (t[i] == 'A') {
                numA++;
            } else {
                total += numA;
            }
        }
    }

    printf("%d\n", total);  // Print the total count

    // Define constants for infinity and modulo
    const long long INF = 10000000000000000000000LL;  // 10^25
    const long long mod = 7 + 1000000000;  // 7 + 10^9

    return 0;
}

// <END-OF-CODE>
