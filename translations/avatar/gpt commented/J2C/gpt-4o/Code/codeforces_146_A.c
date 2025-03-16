#include <stdio.h> // Including standard input-output library
#include <string.h> // Including string library for string manipulation

int main() {
    // Initializing variables to hold the sum of the first half and the second half of the digits
    int x = 0, y = 0;
    int t = 0; // Variable to check if there are any digits other than '4' or '7'
    
    // Reading the length of the number and the number itself as a string
    int n;
    scanf("%d", &n);
    char str[n + 1]; // +1 for the null terminator
    scanf("%s", str);
    
    // Checking if all characters in the string are either '4' or '7'
    for (int i = 0; i < n; i++) {
        if (str[i] != '4' && str[i] != '7') {
            t = 1; // Set t to 1 if a character is found that is not '4' or '7'
        }
    }
    
    // If t is set, print "NO" indicating the number is not lucky
    if (t == 1) {
        printf("NO\n");
    } else {
        // Calculate the sum of the first half of the digits
        for (int i = 0; i < n / 2; i++) {
            x += str[i] - '0'; // Convert char to int
        }
        // Calculate the sum of the second half of the digits
        for (int i = n - 1; i >= n / 2; i--) {
            y += str[i] - '0'; // Convert char to int
        }
        // Compare the two sums and print "YES" if they are equal, otherwise print "NO"
        if (x == y) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
