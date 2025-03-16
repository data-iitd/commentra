#include <stdio.h>

int main() {
    // Declare variables to hold the number of elements, the target sum, and the list of integers
    int n, x;
    int l[100]; // Assuming a maximum size of 100 for the array
    int tmpSum = 0;
    int rs = 0;

    // Read the number of elements and the target sum from the standard input
    scanf("%d", &n);
    scanf("%d", &x);

    // Read n integers from the standard input and store them in the array l
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }

    // Iterate over the array l, updating the sum and checking the condition
    for (int i = 0; i < n; i++) {
        tmpSum += l[i];
        // If the sum is less than or equal to x, update the result
        if (tmpSum <= x) {
<<<<<<< HEAD
            rs = i + 1; // +1 because we want 1-based index
=======
            rs = i + 1; // +1 to convert to 1-based index
>>>>>>> 98c87cb78a (data updated)
        } else {
            break;
        }
    }

    // Print the result
    printf("%d\n", rs);

    return 0;
}

// <END-OF-CODE>
