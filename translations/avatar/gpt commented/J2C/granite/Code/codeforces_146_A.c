
#include <stdio.h>
#include <string.h>

int main() {
    // Creating variables to hold the sum of the first half and the second half of the digits
    int x = 0, y = 0;
    int t = 0; // Variable to check if there are any digits other than '4' or '7'
    
    // Reading the length of the number and the number itself as a string
    int n;
    char str[1000];
    scanf("%d", &n);
    scanf("%s", str);
    
    // Checking if all characters in the string are either '4' or '7'
    for (int i = 0; i < n; i++) {
        if (str[i]!= '4' && str[i]!= '7') {
            t = 1; // Set t to 1 if a character is found that is not '4' or '7'
        }
    }
    
    // If t is set, print "NO" indicating the number is not lucky
    if (t == 1) {
        printf("NO");
    } else {
        // Calculate the sum of the first half of the digits
        for (int i = 0; i < n / 2; i++) {
            x = x + str[i] - '0';
        }
        // Calculate the sum of the second half of the digits
        for (int i = n - 1; i > (n / 2) - 1; i--) {
            y = y + str[i] - '0';
        }
        // Compare the two sums and print "YES" if they are equal, otherwise print "NO"
        if (x == y) {
            printf("YES");
        } else {
            printf("NO");
        }
    }
    
    return 0;
}
