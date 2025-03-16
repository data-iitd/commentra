#include <stdio.h>

int main() {
    // Initialize sum variable to 0
    long long int sum = 0;

    // Read input string from standard input
    char str[100]; // Assuming the maximum length of the input string is 99 characters
    scanf("%s", str);

    // Iterate through each character in the string and add its ASCII value (after converting to digit) to sum
    for (int i = 0; str[i] != '\0'; i++) {
        sum += (str[i] - '0'); // Subtract '0' to convert ASCII value of digit character to its integer value
    }

    // Check if sum is divisible by 9
    if (sum % 9 == 0) {
        printf("Yes\n"); // Output "Yes" if sum is divisible by 9
    } else {
        printf("No\n"); // Output "No" otherwise
    }

    return 0;
}

// <END-OF-CODE>
