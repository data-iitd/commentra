#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n); // Read the number of elements
    int *a = (int *)malloc((n + 1) * sizeof(int)); // Allocate memory for the array
    int sum = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); // Read the list elements
        sum += a[i]; // Calculate the sum of the elements
    }

    if (sum % (n * (n + 1) / 2) != 0) {
        // Check if the sum of the list is divisible by the triangular number
        printf("NO\n");
    } else {
        double k = (double)sum / (n * (n + 1) / 2);
        a[n] = a[0]; // Append the first element to the end of the array to create a circular list

        int condition1 = 0;
        int condition2 = 0;

        for (int i = 1; i <= n; i++) {
            double temp1 = fmod(k - a[i] + a[i - 1], n);
            double temp2 = (k - a[i] + a[i - 1]) / n;

            if (temp1 != 0) {
                condition1 = 1; // If any condition fails, set condition1 to true
            }
            if (temp2 < 0) {
                condition2++; // Count how many times the condition fails
            }
        }

        if (condition1 || condition2 != n) {
            // Check if the condition is met for all elements in the circular list
            printf("NO\n");
        } else {
            printf("YES\n");
            // If the condition is met, print "YES"
        }
    }

    free(a); // Free the allocated memory
    return 0;
}

// <END-OF-CODE>
