#include <stdio.h>

int main() {
    // Read the number of test cases
    int N;
    scanf("%d", &N);

    // Declare arrays V and C
    int V[N], C[N];

    // Read the array V of size N
    for (int i = 0; i < N; i++) {
        scanf("%d", &V[i]);
    }

    // Read the array C of size N
    for (int i = 0; i < N; i++) {
        scanf("%d", &C[i]);
    }

    // Initialize an empty list to store the differences between V and C
    int list[N]; // Assuming the maximum size of the list is N
    int list_size = 0; // To keep track of the number of valid differences

    // Initialize variables to store the current difference and the sum of differences
    int ans = 0;

    // Iterate through each index i from 0 to N-1
    for (int i = 0; i < N; i++) {
        // If the difference between V[i] and C[i] is positive
        if (V[i] - C[i] > 0) {
            // Append the difference V[i] - C[i] to the list
            list[list_size++] = V[i] - C[i];
            // Update the sum of differences
            ans += V[i] - C[i];
        }
    }

    // Print the sum of all the elements in the list
    int sum_list = 0;
    for (int i = 0; i < list_size; i++) {
        sum_list += list[i];
    }
    printf("%d\n", sum_list);

    // Print the sum of all the differences between V and C
    printf("%d\n", ans);

    return 0;
}
// <END-OF-CODE>
