#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    char s[100000]; // Assuming the input string will not exceed 100,000 characters
    int l = 2019;
    long long m[2019] = {0}; // Array to count occurrences of remainders
    long long a = 0; // Accumulated value
    long long r = 0; // Result

    // Read the input string
    scanf("%s", s);
    int len = strlen(s);

    // Initialize the count of the zero remainder
    m[0] = 1;

    // Iterate over the input string in reverse order
    for (int i = 0; i < len; i++) {
        // Update the accumulated value 'a' by converting the character to an integer
        // and adjusting its place value
        a += (s[len - 1 - i] - '0') * (long long)pow(10, i);
        
        // Update the result 'r' by adding the count of occurrences of the current remainder
        r += m[a % l];
        
        // Increment the count of the current remainder in the list 'm'
        m[a % l]++;
    }

    // Print the final result
    printf("%lld\n", r);

    return 0;
}
