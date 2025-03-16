#include <stdio.h> // Including standard input-output library

int main() {
    int a; // Variable to store the size of the array
    scanf("%d", &a); // Reading the size of the array from the user
    int ar[a]; // Initializing the array with the size read from the user
    int max = 0, min = 0; // Initializing max and min to 0

    // Filling the array with integers read from the user
    for (int i = 0; i < a; i++) {
        scanf("%d", &ar[i]);
    }

    // Calculating the minimum and maximum differences between consecutive elements of the array
    for (int i = 0; i < a; i++) {
        max = (ar[i] - ar[0] > ar[a - 1] - ar[i]) ? (ar[i] - ar[0]) : (ar[a - 1] - ar[i]); // Calculating the maximum difference
        if (i == 0) {
            min = ar[i + 1] - ar[i]; // Calculating the minimum difference for the first element
        } else if (i == a - 1) {
            min = ar[i] - ar[i - 1]; // Calculating the minimum difference for the last element
        } else {
            min = (ar[i] - ar[i - 1] < ar[i + 1] - ar[i]) ? (ar[i] - ar[i - 1]) : (ar[i + 1] - ar[i]); // Calculating the minimum difference for other elements
        }
        printf("%d %d\n", min, max); // Displaying the minimum and maximum differences
    }

    return 0; // Indicating that the program ended successfully
}

// <END-OF-CODE>
