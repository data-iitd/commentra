

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);  // Take an integer input `n`
    int *arr = (int *)malloc(n * sizeof(int));  // Allocate memory for an array of size `n`
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;  // Initialize the array with numbers from 1 to `n`
    }
    int p[n], q[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);  // Take the first permutation `p` as an array of integers
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);  // Take the second permutation `q` as an array of integers
    }
    int *temp = (int *)malloc(n * sizeof(int));  // Allocate memory for a temporary array of size `n`
    for (int i = 0; i < n; i++) {
        temp[i] = arr[p[i] - 1];  // Map the elements of permutation `p` to the corresponding elements in the array
    }
    int *temp2 = (int *)malloc(n * sizeof(int));  // Allocate memory for another temporary array of size `n`
    for (int i = 0; i < n; i++) {
        temp2[i] = arr[q[i] - 1];  // Map the elements of permutation `q` to the corresponding elements in the array
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (temp[i]!= temp2[i]) {  // Compare the elements of the two permutations
            count++;  // Increment the count if the elements are not equal
        }
    }
    printf("%d", count);  // Print the count
    free(arr);  // Free the memory allocated for the array
    free(temp);  // Free the memory allocated for the first temporary array
    free(temp2);  // Free the memory allocated for the second temporary array
    return 0;
}
