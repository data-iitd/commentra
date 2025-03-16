

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;  // Declare an integer variable `n` to store the number of elements in the list `m`
    scanf("%d", &n);  // Read an integer input representing the number of elements in the list `m`

    int **m = (int **)malloc(n * sizeof(int *));  // Allocate memory for the list `m`
    for (int i = 0; i < n; i++) {
        m[i] = (int *)malloc(2 * sizeof(int));  // Allocate memory for each sublist in `m`
        for (int j = 0; j < 2; j++) {
            scanf("%d", &m[i][j]);  // Read two integers from the user and store them in the sublist `m[i]`
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (m[i][1] < m[j][1]) {  // Compare the second elements of the sublists `m[i]` and `m[j]`
                int *temp = m[i];  // Swap the sublists `m[i]` and `m[j]`
                m[i] = m[j];
                m[j] = temp;
            }
        }
    }

    int *a = m[0];  // Assign the first element of the sorted list `m` to the variable `a`

    for (int i = 1; i < n; i++) {
        if (m[i][1] > a[1]) {  // Check if the second element of the current element `m[i]` is greater than the second element of the variable `a`
            printf("Happy Alex\n");  // If true, print "Happy Alex" and break out of the loop
            break;
        }
        a = m[i];  // If false, assign the current element `m[i]` to the variable `a`
    }

    if (i == n) {  // If the loop completes without breaking
        printf("Poor Alex\n");  // Print "Poor Alex"
    }

    for (int i = 0; i < n; i++) {
        free(m[i]);  // Free the memory allocated for each sublist in `m`
    }
    free(m);  // Free the memory allocated for the list `m`

    return 0;
}
// END-OF-CODE