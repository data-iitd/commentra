
#include <stdio.h>

int main() {
    // Get the number of elements in the array from user input
    int N;
    scanf("%d", &N);

    // Initialize an array 'n' of size N
    int n[N];

    // Get the elements of the array from user input and store them in 'n'
    for (int i = 0; i < N; i++) {
        scanf("%d", &n[i]);
    }

    // Initialize variables 'a' and 'pos'
    int a = 1;
    int pos = 0;

    // Iterate through the array 'n' starting from the second element
    for (int i = 1; i < N; i++) {
        // Check if the current element is greater than the previous one
        if (n[pos] > n[i]) {
            // Increment the variable 'a' if the condition is true
            a += 1;
            // Update the position of the previous greater element
            pos = i;
        }
    }

    // Print the value of 'a' as the output
    printf("%d\n", a);

    return 0;
}
