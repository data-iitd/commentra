#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 10000000000000000000ULL
#define EPS 1.0 / 10000000000.0
#define MOD 1000000007

// Function to read a single integer from standard input
int read_int() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a single string from standard input
void read_string(char *s, int size) {
    scanf("%s", s);
}

// Main function
int main() {
    // Reading input string and number of occurrences of '1' required
    char s[1000001]; // Assuming the maximum length of the string is 1,000,000
    read_string(s, sizeof(s));
    int k = read_int();

    // Finding the length of the substring consisting only of '1's
    int l = 0;
    while (s[l] == '1') {
        l++;
    }

    // If the length of the substring is greater than or equal to the required number of occurrences, return '1'
    if (l >= k) {
        printf("1\n");
        return 0;
    }

    // If the length of the substring is less than the required number of occurrences, return the character after the substring
    printf("%c\n", s[l]);
    return 0;
}

// <END-OF-CODE>
