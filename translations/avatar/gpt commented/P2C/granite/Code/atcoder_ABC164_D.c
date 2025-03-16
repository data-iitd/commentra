
#include <stdio.h>
#include <string.h>

int main() {
    // Read input string and set the length variable
    char s[2020];
    int l = 2019;
    scanf("%s", s);

    // Initialize a list to count occurrences of remainders, and variables for accumulated value and result
    int m[l] = {1}, a = 0, r = 0;

    // Iterate over the input string in reverse order
    for (int i = strlen(s) - 1; i >= 0; i--) {
        // Update the accumulated value 'a' by converting the character to an integer and adjusting its place value
        a = (a + s[i] - '0') % l;

        // Update the result 'r' by adding the count of occurrences of the current remainder
        r += m[a];

        // Increment the count of the current remainder in the list'm'
        m[a]++;
    }

    // Print the final result
    printf("%d\n", r);

    return 0;
}
