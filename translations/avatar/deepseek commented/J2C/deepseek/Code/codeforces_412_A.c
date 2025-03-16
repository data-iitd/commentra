#include <stdio.h>

int main() {
    int n, k;
    char a[100];

    // Read the integers n and k from the user
    scanf("%d %d", &n, &k);
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
        for (int i = 0; i < n; i++) {
            printf("PRINT %c\n", a[i]); // Print the character and then move right
            if ((i + 1) < n) {
                printf("RIGHT\n"); // Print "RIGHT" if it's not the last character
            }
        }
    } else {
        // If k does not equal 1, print each character of the string a starting from the last character and moving leftwards
        for (int i = n - 1; i >= 0; i--) {
            printf("PRINT %c\n", a[i]); // Print the character and then move left
            if ((i - 1) >= 0) {
                printf("LEFT\n"); // Print "LEFT" if it's not the first character
            }
        }
    }

