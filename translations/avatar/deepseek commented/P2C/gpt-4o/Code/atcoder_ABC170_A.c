#include <stdio.h>

int main() {
    int a[100]; // Assuming a maximum size of 100 for the input array
    int n = 0; // Variable to keep track of the number of elements

    // Take input from user
    while (scanf("%d", &a[n]) == 1) {
        n++;
    }

    // Iterate over the list, checking each element
    for (int e = 0; e < n; e++) {
        if (a[e] == 0) { // If an element is 0
            printf("%d\n", e + 1); // Print the position (1-indexed) of that element and break the loop
            break;
        }
    }

    return 0;
}

// <END-OF-CODE>
