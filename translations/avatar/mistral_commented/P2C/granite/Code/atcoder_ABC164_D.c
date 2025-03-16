
#include <stdio.h>
#include <math.h>

int main() {
    // Define input variables's' and 'l'
    char s[2020];
    int l = 2019;

    // Initialize list'm' with initial value 1 for index 0 and zeros for other indices
    int m[2020] = {1};
    for (int i = 1; i < l; i++) {
        m[i] = 0;
    }

    // Initialize variables 'a' and 'r' with zero values
    int a = 0, r = 0;

    // Read the string's' from user input
    scanf("%s", s);

    // Iterate through the string's' in reverse order
    for (int i = strlen(s) - 1; i >= 0; i--) {
        // Calculate the current digit's power and add it to 'a'
        a = (a + (s[i] - '0') * pow(10, strlen(s) - 1 - i, l)) % l;

        // Increment the index 'a % l' in list'm'
        m[a % l]++;

        // Update 'r' with the current sum
        r += m[a % l];
    }

    // Print the final result 'r'
    printf("%d\n", r);

    return 0;
}
