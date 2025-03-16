
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the number of elements 'n' and a list 'l' of 'n' integers from standard input
    int n;
    scanf("%d", &n);
    int l[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }

    // Sort the list 'l' in ascending order
    qsort(l, n, sizeof(int), cmpfunc);

    // Initialize an answer variable 'ans' to zero
    int ans = 0;

    // Iterate through each pair of indices 'i' and 'j' in the list 'l'
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Assign the elements at indices 'i' and 'j' to variables 'a' and 'b' respectively
            int a = l[i];
            int b = l[j];

            // Use bisect_left to find the index 'right' where an element greater than 'a+b' is present
            int right = lower_bound(l, l + n, a + b) - l;

            // Use bisect_right to find the index 'left' where the smallest element greater than'max(a-b, b-a)' is present
            int left = upper_bound(l, l + n, max(a - b, b - a)) - l;

            // Calculate the temporary answer 'tmp' based on the indices 'left' and 'right'
            int tmp = max(0, right - left);

            // Subtract one from the temporary answer 'tmp' if both 'i' and 'j' lie between 'left' and 'right'
            if (left <= i && i < right) {
                tmp--;
            }
            if (left <= j && j < right) {
                tmp--;
            }

            // Add the temporary answer 'tmp' to the final answer 'ans'
            ans += tmp;
        }
    }

    // Print the final answer 'ans' divided by three
    printf("%d\n", ans / 3);

    return 0;
}

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

