
#include <stdio.h>

int main() {
    // Read the number of test cases
    int N;
    scanf("%d", &N);

    // Read the array V of size N
    int V[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &V[i]);
    }

    // Read the array C of size N
    int C[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &C[i]);
    }

    // Initialize an empty list to store the differences between V and C
    int list[N];
    int list_size = 0;

    // Initialize variables to store the current difference and the sum of differences
    int ans = 0;
    int X = 0;
    int Y = 0;

    // Iterate through each index i from 0 to N-1
    for (int i = 0; i < N; i++) {
        // If the difference between V[i] and C[i] is positive
        if (V[i] - C[i] > 0) {
            // Update X and Y with the respective values from V and C at index i
            X = V[i];
            Y = C[i];
            // Append the difference X-Y to the list
            list[list_size] = X - Y;
            list_size++;
            // Update the sum of differences
            ans += X - Y;
        }
    }

    // Print the sum of all the elements in the list
    printf("%d\n", sum(list, list_size));
    // Print the sum of all the differences between V and C
    printf("%d\n", ans);

    return 0;
}

int sum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

