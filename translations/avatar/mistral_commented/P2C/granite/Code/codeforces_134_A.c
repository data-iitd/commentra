
#include <stdio.h>

int main() {
    // Reading the first line of input which contains the number of elements 'n' in the list 'w'
    int n;
    scanf("%d", &n);

    // Initializing an empty list 'd' to store the indices of the elements that satisfy the condition
    int d[n];
    int d_size = 0;

    // Declaring a variable 'x' to store the sum of all elements in the list 'w'
    int x = 0;

    // Iterating through each element 'i' in the list 'w'
    for (int i = 0; i < n; i++) {
        int w;
        scanf("%d", &w);
        x += w;

        // Calculating the average of the remaining sum of elements after removing the current element 'w[i]'
        // and checking if it's equal to the current element 'w[i]'
        if ((x - w) / (n - 1) == w) {
            // If the condition is true, append the index 'i+1' to the list 'd'
            d[d_size++] = i + 1;
        }
    }

    // Printing the length of the list 'd'
    printf("%d\n", d_size);

    // Printing the elements of the list 'd' separated by a space
    for (int i = 0; i < d_size; i++) {
        printf("%d ", d[i]);
    }

    return 0;
}
