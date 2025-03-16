
#include <stdio.h> // Include the standard input/output library

int main() {
    int n, k; // Declare and initialize the variables n and k
    char a[100]; // Declare an array a of size 100 to store the string a

    // Read the integer n from the user
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Read the integer k from the user
    printf("Enter the value of k: ");
    scanf("%d", &k);

    // Read the string a from the user
    printf("Enter the string a: ");
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
        for (int i = 0; i < strlen(a); i++) {
            printf("PRINT %c\n", a[i]); // Print the character and then move right
            if ((i + 1) < strlen(a)) {
                printf("RIGHT\n"); // Print "RIGHT" if it's not the last character
            }
        }
    } else {
        // If k does not equal 1, print each character of the string a starting from the last character and moving leftwards
        for (int i = strlen(a) - 1; i >= 0; i--) {
            printf("PRINT %c\n", a[i]); // Print the character and then move left
            if ((i - 1) >= 0) {
                printf("LEFT\n"); // Print "LEFT" if it's not the first character
            }
        }
    }

    return 0; // Return 0 to indicate successful execution
}
