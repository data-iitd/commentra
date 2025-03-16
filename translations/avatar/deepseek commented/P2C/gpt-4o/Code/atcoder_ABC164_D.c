#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    char s[2020]; // Assuming the input string can be up to 2019 characters long
    int l = 2019;
    long long m[2020] = {0}; // Initialize an array of size 2020 with zeros
    m[0] = 1; // Set the first element to 1
    long long a = 0, r = 0;

    // Take input string `s`
    scanf("%s", s);
    int len = strlen(s);

    // Iterate over the reversed string `s`
    for (int i = 0; i < len; i++) {
        // Calculate the value of the character's position times 10 raised to the power of its position in the reversed string, modulo `l`
        a += (s[len - 1 - i] - '0') * (long long)pow(10, i) % l;
        a %= l; // Ensure `a` is within bounds of `l`
        
        // Increment the running total `r` by the current value in `m` at the position `a % l`
        r += m[a];
        
        // Increment the value in `m` at the position `a % l` by 1
        m[a]++;
    }

    // Finally, print the value of `r`
    printf("%lld\n", r);

    return 0;
}
// <END-OF-CODE>
