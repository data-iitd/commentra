#include <stdio.h>
#include <stdlib.h>

int main() {
    // Take the number of test cases as input
    int n;
    scanf("%d", &n);

    // Initialize arrays 't' and 'a' with size n+1
    int *t = (int *)malloc((n + 1) * sizeof(int));
    int *a = (int *)malloc((n + 1) * sizeof(int));
    int *cnt = (int *)calloc(n + 1, sizeof(int)); // Initialize count array with 0

    // Read the input for array 't'
    t[0] = 0; // First element is 0
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
    }

    // Read the input for array 'a'
    a[0] = 0; // First element is 0
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    // Initialize an empty list 'ans' and a variable to track its size
    int *ans = (int *)malloc((n + 1) * sizeof(int));
    int ans_size = 0;

    // Iterate through each element in list 'a' and increment the count of its corresponding index in list 'cnt'
    for (int i = 1; i <= n; i++) {
        cnt[a[i]]++;
    }

    // Iterate through each index from 1 to n
    for (int i = 1; i <= n; i++) {
        // If the current index in list 't' is 1
        if (t[i] == 1) {
            // Initialize an empty list 'crt' to store the current sequence
            int *crt = (int *)malloc((n + 1) * sizeof(int));
            int crt_size = 0;
            // Get the current element in list 'a'
            int x = a[i];
            // Continue adding elements to 'crt' as long as the corresponding index in 'cnt' has a count of 1
            while (cnt[x] == 1) {
                crt[crt_size++] = x;
                x = a[x];
            }
            // If the length of the current sequence is greater than the length of the current answer sequence
            if (crt_size > ans_size) {
                ans_size = crt_size;
                for (int j = 0; j < crt_size; j++) {
                    ans[j] = crt[j];
                }
            }
            free(crt); // Free the temporary array
        }
    }

    // Reverse the order of elements in the answer sequence
    for (int i = 0; i < ans_size / 2; i++) {
        int temp = ans[i];
        ans[i] = ans[ans_size - 1 - i];
        ans[ans_size - 1 - i] = temp;
    }

    // Print the length of the answer sequence
    printf("%d\n", ans_size);
    // Print the answer sequence with each element separated by a space
    for (int i = 0; i < ans_size; i++) {
        printf("%d", ans[i]);
        if (i < ans_size - 1) {
            printf(" ");
        }
    }
    printf("\n");

    // Free allocated memory
    free(t);
    free(a);
    free(cnt);
    free(ans);

    return 0;
}

// <END-OF-CODE>
