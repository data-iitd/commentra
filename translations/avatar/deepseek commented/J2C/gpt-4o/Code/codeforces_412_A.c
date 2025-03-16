#include <stdio.h> // Including standard input-output library

int main() {
    int n, k; // Declare variables for n and k
    char a[100]; // Declare a character array to hold the string a

    // Read the integer n and k from the user
    scanf("%d", &n);
    scanf("%d", &k);
    // Read the string a from the user
    scanf("%s", a);

    // Check if k is greater than n/2
    if (k > n / 2) {
        // Move right until k equals n
        while (k < n) {
            printf("RIGHT\n"); // Print "RIGHT"
            k++; // Increment k
        }
    } else {
        // Move left until k equals 1
        while (k > 1) {
            printf("LEFT\n"); // Print "LEFT"
            k--; // Decrement k
        }
    }

    // If k equals 1, print each character of the string a starting from the first character and moving rightwards
    if (k == 1) {
        for (int i = 0; a[i] != '\0'; i++) {
            printf("PRINT %c\n", a[i]); // Print the character and then move right
            if (a[i + 1] != '\0') {
                printf("RIGHT\n"); // Print "RIGHT" if it's not the last character
            }
        }
    } else {
        // If k does not equal 1, print each character of the string a starting from the last character and moving leftwards
        for (int i = 0; a[i] != '\0'; i++); // Find the length of the string
        for (int i = i - 1; i >= 0; i--) {
            printf("PRINT %c\n", a[i]); // Print the character and then move left
            if (i - 1 >= 0) {
                printf("LEFT\n"); // Print "LEFT" if it's not the first character
            }
        }
    }

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
