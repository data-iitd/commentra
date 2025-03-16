#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    // Taking the number of elements N and the number of queries K as input
    int N, K;
    scanf("%d %d", &N, &K);

    // Creating arrays to store positive and negative numbers
    int *lst = (int *)malloc(N * sizeof(int));
    int *lst_p = (int *)malloc(N * sizeof(int));
    int *lst_m = (int *)malloc(N * sizeof(int));
    int len_p = 0, len_m = 0;

    // Taking the list of numbers as input
    for (int i = 0; i < N; i++) {
        scanf("%d", &lst[i]);
        // If the number is zero, decrement the number of queries K
        if (lst[i] == 0) {
            K--;
        }
        // If the number is positive, add it to the list of positive numbers
        else if (lst[i] > 0) {
            lst_p[len_p++] = lst[i];
        }
        // If the number is negative, add it to the list of negative numbers
        else if (lst[i] < 0) {
            lst_m[len_m++] = lst[i];
        }
    }

    // Initializing variables
    int p, m;
    int ans = INT_MAX;

    // Function to check the minimum number of moves required
    for (int j = 0; j <= K; j++) {
        // If j is greater than the length of the list of positive numbers or if the number of elements to be taken from negative list is greater than the number of negative elements, then skip this iteration
        if (j > len_p || K - j > len_m) {
            continue;
        }

        // If j is 0, then p is initialized to 0
        if (j == 0) {
            p = 0;
        }
        // If j is not 0, then p is the last element of the list of positive numbers
        else {
            p = lst_p[j - 1];
        }

        // If K - j is 0, then m is initialized to 0
        if (K - j == 0) {
            m = 0;
        }
        // If K - j is not 0, then m is the last element of the list of negative numbers
        else {
            m = lst_m[len_m - (K - j)];
        }

        // Updating the answer with the minimum of the current answer and the sum of the absolute difference of p and m and the sum of p and m
        ans = (ans < (2 * p + abs(m))) ? ans : (2 * p + abs(m));
        ans = (ans < (p + 2 * abs(m))) ? ans : (p + 2 * abs(m));
    }

    // Printing the minimum number of moves required
    printf("%d\n", ans);

    // Freeing allocated memory
    free(lst);
    free(lst_p);
    free(lst_m);

    return 0;
}

// <END-OF-CODE>
