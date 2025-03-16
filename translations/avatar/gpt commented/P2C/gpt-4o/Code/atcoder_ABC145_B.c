#include <stdio.h>
#include <string.h>

int main() {
    // Read an integer input from the user
    int n;
    scanf("%d", &n);
    
    // Read a string input from the user
    char s[100]; // Assuming the maximum length of the string is 99 characters
    scanf("%s", s);
    
    // Check if the length of the string is odd
    if (n % 2 != 0) {
        // If the length is odd, print 'No' since it cannot be split into two equal halves
        printf("No\n");
    } 
    // Check if the first half of the string is equal to the second half
    else {
        int half = n / 2;
        if (strncmp(s, s + half, half) == 0) {
            // If both halves are equal, print 'Yes'
            printf("Yes\n");
        } else {
            // If the halves are not equal, print 'No'
            printf("No\n");
        }
    }
    
    return 0;
}

// <END-OF-CODE>
