#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char s[100]; // Assuming the maximum length of the string is 99 characters

    // Read an integer value from the user
    scanf("%d", &n);
    
    // Read a string value from the user
    scanf("%s", s);

    // Check if n is odd
    if (n % 2 != 0) {
        printf("No\n");
    }
    // Check if the first half of the string is equal to the second half
    else if (strncmp(s, s + n / 2, n / 2) == 0) {
        printf("Yes\n");
    }
    // If the first half is not equal to the second half, print 'No'
    else {
        printf("No\n");
    }

    return 0;
}

// <END-OF-CODE>
