
#include <stdio.h> // Include the standard input/output library

int main() {
    int a; // Declare the size of the array
    scanf("%d", &a); // Read the size of the array from the user

    int ar[a]; // Declare the array with the size read from the user
    int max = 0, min = 0; // Declare max and min to 0

    // Read the elements of the array from the user
    for (int i = 0; i < a; i++) {
        scanf("%d", &ar[i]);
    }

    // Calculate the minimum and maximum differences between consecutive elements of the array
    for (int i = 0; i < a; i++) {
        max = (ar[i] - ar[0]) > (ar[a - 1] - ar[i])? (ar[i] - ar[0]) : (ar[a - 1] - ar[i]); // Calculate the maximum difference
        if (i == 0) {
            min = ar[i + 1] - ar[i]; // Calculate the minimum difference for the first element
        } else if (i == a - 1) {
            min = ar[i] - ar[i - 1]; // Calculate the minimum difference for the last element
        } else {
            min = (ar[i] - ar[i - 1]) < (ar[i + 1] - ar[i])? (ar[i] - ar[i - 1]) : (ar[i + 1] - ar[i]); // Calculate the minimum difference for other elements
        }
        printf("%d %d\n", min, max); // Display the minimum and maximum differences
    }

    return 0; // Return 0 to indicate successful execution
}
