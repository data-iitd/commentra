#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    // Creating a Scanner object to read input from the user
    int n, i, x = 0, y = 0, t = 0;
    char str[100];
    
    // Reading the length of the number and the number itself as a string
    scanf("%d", &n);
    scanf("%s", str);
    
    // Checking if all characters in the string are either '4' or '7'
    for (i = 0; i < n; i++) {
        if (str[i] != '4' && str[i] != '7') {
            t = 1; // Set t to 1 if a character is found that is not '4' or '7'
        }
    }
    
    // If t is set, print "NO" indicating the number is not lucky
    if (t == 1) {
        printf("NO\n");
    } else {
        // Calculate the sum of the first half of the digits
        for (i = 0; i < n / 2; i++) {
            x = x + str[i] - '0';
        }
        // Calculate the sum of the second half of the digits
        for (i = n - 1; i > (n / 2) - 1; i--) {
            y = y + str[i] - '0';
        }
        // Compare the two sums and print "YES" if they are equal, otherwise print "NO"
        if (x == y) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}

