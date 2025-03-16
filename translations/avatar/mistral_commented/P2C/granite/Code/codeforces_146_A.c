
#include <stdio.h>

int main() {
    int n, i, h1 = 0, h2 = 0, x = 0;

    // Ask user for the number of elements in the list
    scanf("%d", &n);

    // Get the list of numbers from user input
    int number[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &number[i]);
    }

    // Iterate through the list of numbers
    for (i = 0; i < n; i++) {
        // Check if the current number is not 4 and not 7
        if (number[i]!= 4 && number[i]!= 7) {
            // Print "NO" and break the loop if the condition is met
            printf("NO");
            x = 1;
            break;
        }

        // If the index is less than half the length of the list, add the number to h1
        if (i < n / 2) {
            h1 += number[i];
        }

        // If the index is greater than or equal to half the length of the list, add the number to h2
        else {
            h2 += number[i];
        }
    }

    // Check if the loop was broken due to a non-4 and non-7 number
    if (!x) {
        // If h1 and h2 are equal, print "YES"
        if (h1 == h2) {
            printf("YES");
        }
        // If h1 and h2 are not equal, print "NO"
        else {
            printf("NO");
        }
    }

    return 0;
}
