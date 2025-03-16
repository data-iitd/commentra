
#include <stdio.h>

int main() {
    int n, i, high, tower, maximum;

    // Take the number of elements in the list as input
    scanf("%d", &n);

    // Initialize an empty list 'l' to store the input elements
    int l[n];

    // Read the list elements from the standard input, convert them to integers and store in the list
    for (i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }

    // Initialize variables 'high' and 'tower' with initial values
    high = 1;
    tower = n;

    // Iterate through the list starting from the second element
    for (i = 1; i < n; i++) {
        // If the current element is same as the previous one, decrement 'tower' and increment 'high'
        if (l[i] == l[i-1]) {
            tower--;
            high++;
        }
        // If the current element is different, check if 'high' is greater than the current maximum and update it if true
        else {
            if (high > maximum) {
                maximum = high;
            }
            high = 1;
        }
    }

    // Check if the last 'high' value is greater than the current maximum and update it if true
    if (high > maximum) {
        maximum = high;
    }

    // Print the final result
    printf("%d %d\n", maximum, tower);

    return 0;
}
