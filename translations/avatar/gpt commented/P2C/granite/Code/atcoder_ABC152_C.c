
#include <stdio.h>  // Including the standard input/output library

int main() {
    int N, i, a, pos;  // Declaring variables for the number of elements, loop index, counter, and position

    // Taking input for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    // Declaring an array of integers to store the elements
    int n[N];

    // Taking input for the elements and storing them in the array
    printf("Enter the elements separated by spaces: ");
    for (i = 0; i < N; i++) {
        scanf("%d", &n[i]);
    }

    // Initializing the counter and position
    a = 1;
    pos = 0;

    // Looping through the array starting from the second element
    for (i = 1; i < N; i++) {
        // Checking if the current element is smaller than the element at 'pos'
        if (n[pos] > n[i]) {
            a++;  // Incrementing the counter if the condition is met
            pos = i;  // Updating 'pos' to the current index
        }
    }

    // Printing the final count of elements that were smaller than the previous ones
    printf("%d\n", a);

    return 0;  // Returning 0 to indicate successful execution
}
