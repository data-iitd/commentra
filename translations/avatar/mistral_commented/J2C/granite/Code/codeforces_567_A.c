
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, max, min;
    scanf("%d", &a); // Reading the size of the array from user input
    int ar[a]; // Initializing the array with the given size

    // Reading array elements from user input
    for (int i = 0; i < a; i++) {
        scanf("%d", &ar[i]); // Reading an integer value from user input and storing it in the array
    }

    // Finding maximum and minimum differences between consecutive elements in the array
    for (int i = 0; i < a; i++) {
        // Finding maximum difference between current element and first element
        max = (ar[i] - ar[0]) > (ar[a - 1] - ar[i])? (ar[i] - ar[0]) : (ar[a - 1] - ar[i]);

        // Finding minimum difference between current element and previous element
        if (i == 0) {
            min = ar[i + 1] - ar[i]; // For the first element, minimum difference is between current and next element
        } else if (i == a - 1) {
            min = ar[i] - ar[i - 1]; // For the last element, minimum difference is between current and previous element
        } else {
            min = (ar[i] - ar[i - 1]) < (ar[i + 1] - ar[i])? (ar[i] - ar[i - 1]) : (ar[i + 1] - ar[i]); // For other elements, minimum difference is between current and previous or next element, whichever is smaller
        }

        // Printing minimum and maximum differences for each pair of consecutive elements
        printf("%d %d\n", min, max); // Printing minimum and maximum differences for each pair of consecutive elements
    }

    return 0;
}
