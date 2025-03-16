#include <stdio.h>
#include <string.h>

int main() {
    // Define input variables 's' and 'l'
    char s[100]; // Assuming the input string will not exceed 99 characters
    int l = 2019;

    // Initialize list 'm' with initial value 1 for index 0 and zeros for other indices
    long long m[2019] = {0};
    m[0] = 1; // Set the first element to 1

    // Initialize variables 'a' and 'r' with zero values
    long long a = 0, r = 0;

    // Read the input string
    scanf("%s", s);
    int len = strlen(s);

    // Iterate through the string 's' in reverse order
    for (int i = 0; i < len; i++) {
        // Calculate the current digit's power and add it to 'a'
        a += (s[len - 1 - i] - '0') * pow(10, i);
        
        // Increment the index 'a % l' in list 'm'
        m[a % l]++;

        // Update 'r' with the current sum
        r += m[a % l];
    }

    // Print the final result 'r'
    printf("%lld\n", r);

    return 0;
}

// <END-OF-CODE>
