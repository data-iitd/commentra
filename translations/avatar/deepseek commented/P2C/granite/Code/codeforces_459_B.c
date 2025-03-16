
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Step 1: Take an integer input `n` which represents the number of elements in the list `l1`.
    int n;
    scanf("%d", &n);

    // Step 2: Take a space-separated string of integers, convert them into a list of integers, and store it in `l1`.
    int *l1 = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &l1[i]);
    }

    // Step 3: Sort the list `l1` in ascending order.
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (l1[j] > l1[j + 1]) {
                int temp = l1[j];
                l1[j] = l1[j + 1];
                l1[j + 1] = temp;
            }
        }
    }

    // Step 4: Assign the last element of the sorted list `l1` to `a`, which is the maximum value in the list.
    int a = l1[n - 1];

    // Step 5: Assign the first element of the sorted list `l1` to `b`, which is the minimum value in the list.
    int b = l1[0];

    // Step 6: Check if `a` is equal to `b`.
    if (a == b) {
        // Step 7: If `a` is equal to `b`, print the difference `a - b` and the number of ways to choose 2 elements from `n` elements.
        printf("%d %d\n", a - b, n * (n - 1) / 2);
    } else {
        // Step 8: If `a` is not equal to `b`, calculate the count of occurrences of `a` and `b` in the list `l1`.
        int ac = 0, bc = 0;
        for (int i = 0; i < n; i++) {
            if (l1[i] == a) {
                ac++;
            }
            if (l1[i] == b) {
                bc++;
            }
        }
        // Step 9: Print the difference `a - b` and the product of the counts of `a` and `b`.
        printf("%d %d\n", a - b, ac * bc);
    }

    // Step 10: Free the memory allocated for the list `l1`.
    free(l1);

    return 0;
}
