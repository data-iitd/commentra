#include <stdio.h>  // Including standard input-output library
#include <string.h> // Including string library for string operations

int main() {  // Main function to start the program
    int n, k;  // Declare integer variables n and k
    char a[100]; // Declare a character array to hold the string input

    scanf("%d", &n);  // Reading the first integer input from the user
    scanf("%d", &k);  // Reading the second integer input from the user
    scanf("%s", a);    // Reading the string input from the user

    if (k > n / 2) {  // Check if k is greater than n/2
        while (k < n) {  // If true, print "RIGHT" until k equals n
            printf("RIGHT\n");
            k++;
        }
    } else {  // Else if k is less than or equal to n/2
        while (k > 1) {  // Print "LEFT" until k equals 1
            printf("LEFT\n");
            k--;
        }
    }

    if (k == 1) {  // If k equals 1
        for (int i = 0; i < strlen(a); i++) {  // Iterate through each character in the string
            printf("PRINT %c\n", a[i]);  // Print the character
            if ((i + 1) < strlen(a)) {  // If the index is not the last one
                printf("RIGHT\n");  // Print "RIGHT"
            }
        }
    } else {  // Else if k is not equal to 1
        for (int i = strlen(a) - 1; i >= 0; i--) {  // Iterate through each character in reverse order
            printf("PRINT %c\n", a[i]);  // Print the character
            if ((i - 1) >= 0) {  // If the index is not the first one
                printf("LEFT\n");  // Print "LEFT"
            }
        }
    }

    return 0;  // Return 0 to indicate successful completion
}

// <END-OF-CODE>
