#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    char s[100]; // Assuming the input string will not exceed 99 characters
    int l = 2019;
    int m[2019] = {0}; // Initialize all elements to 0
    long long a = 0;
    long long r = 0;

    // Read input
    scanf("%s", s);
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        // Process the string in reverse
        a += (s[len - 1 - i] - '0') * (long long)pow(10, i);
        r += m[a % l];
        m[a % l]++;
    }

    printf("%lld\n", r);
    return 0;
}

// <END-OF-CODE>
