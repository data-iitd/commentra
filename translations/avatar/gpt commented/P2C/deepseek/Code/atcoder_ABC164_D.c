#include <stdio.h>
#include <string.h>

int main() {
    char s[202];
    int l = 2019;
    int m[l];
    long long a = 0, r = 0;
    int i, e;

    // Read input string
    scanf("%s", s);

    // Initialize the list to count occurrences of remainders
    memset(m, 0, sizeof(m));
    m[0] = 1;

    // Iterate over the input string in reverse order
    int len = strlen(s);
    for (i = 0; i < len; i++) {
        e = s[len - 1 - i] - '0';
        // Update the accumulated value 'a'
        a += e * pow(10, i, l);
        a %= l;
        // Update the result 'r'
        r += m[a];
        // Increment the count of the current remainder
        m[a]++;
    }

    // Print the final result
    printf("%lld\n", r);

    return 0;
}
