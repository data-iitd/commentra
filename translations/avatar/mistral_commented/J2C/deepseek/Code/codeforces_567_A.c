#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, i;
    int max, min;

    // Asking user for the size of the array and initializing it
    scanf("%d", &a);
    int ar[a];

    // Reading array elements from user input
    for (i = 0; i < a; i++) {
        scanf("%d", &ar[i]);
    }

    // Finding maximum and minimum differences between consecutive elements in the array
    for (i = 0; i < a; i++) {
        // Finding maximum difference between current element and first element
        max = (ar[i] - ar[0] > ar[a - 1] - ar[i]) ? ar[i] - ar[0] : ar[a - 1] - ar[i];

        // Finding minimum difference between current element and previous element
        if (i == 0) {
            min = ar[i + 1] - ar[i]; // For the first element, minimum difference is between current and next element
        } else if (i == a - 1) {
            min = ar[i] - ar[i - 1]; // For the last element, minimum difference is between current and previous element
        } else {
            min = (ar[i] - ar[i - 1] < ar[i + 1] - ar[i]) ? ar[i] - ar[i - 1] : ar[i + 1] - ar[i];
        }

        // Printing minimum and maximum differences for each pair of consecutive elements
        printf("%d %d\n", min, max);
    }

    return 0;
}
