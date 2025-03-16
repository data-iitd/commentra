#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MOD 1000000007

// Function for the base case
void main_b() {
    char s[1000];
    scanf("%s", s);
    long long pp = 0;
    int na = 0;

    // Iterate over the string in reverse order
    for (int i = strlen(s) - 1; i >= 0; i--) {
        int c = s[i] - '0'; // Convert char to int
        long long cc = na + c;
        na = 0;

        // If the sum is less than or equal to 4, add to pp
        if (cc <= 4) {
            pp += cc;
        } else {
            na = 1;
            // If it's the last digit, add 1 to pp
            if (i == strlen(s) - 1) {
                pp += 1;
            }
            pp += 10 - cc;
        }
    }
    printf("%lld\n", pp);
}

// Main function for the general case
long long main_func() {
    char s[1000];
    scanf("%s", s);
    long long pmin = 1000;
    long long mmin = 0;
    char new_s[1001];
    sprintf(new_s, "0%s", s); // Prepend '0' to the string

    // Iterate over the string in reverse order
    for (int i = strlen(new_s) - 1; i >= 0; i--) {
        int v = new_s[i] - '0'; // Convert char to int
        long long npmin = (pmin + 10 - (v + 1) < mmin + 10 - v) ? (pmin + 10 - (v + 1)) : (mmin + 10 - v);
        long long nmmin = (pmin + v + 1 < mmin + v) ? (pmin + v + 1) : (mmin + v);
        pmin = npmin;
        mmin = nmmin;
    }
    return (pmin < mmin) ? pmin : mmin;
}

int main() {
    // Check if the script is running in test mode
    int isTest = 0; // Change to 1 if in test mode

    // Call the main function
    long long ret = main_func();
    if (ret != -1) {
        printf("%lld\n", ret);
    }

    return 0;
}

// <END-OF-CODE>
