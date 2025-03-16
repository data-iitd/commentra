#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int x[3];
    int max = 0;

    // Step 1: Read input values for the array x and find the maximum value in x.
    for (int i = 0; i < 3; ++i) {
        scanf("%d", &x[i]);
        if (x[i] > max) {
            max = x[i];
        }
    }

    int k;
    scanf("%d", &k);

    long long a[3][max];

    // Step 2: Initialize a list of lists to store the input values for each sub-array.
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < x[i]; ++j) {
            scanf("%lld", &a[i][j]);
        }
        // Step 3: Sort each sub-array.
        for (int j = 0; j < x[i]; ++j) {
            for (int l = j + 1; l < x[i]; ++l) {
                if (a[i][j] > a[i][l]) {
                    long long temp = a[i][j];
                    a[i][j] = a[i][l];
                    a[i][l] = temp;
                }
            }
        }
    }

    long long ans[k];
    int ans_index = 0;

    // Step 6: Use nested loops to iterate through all possible combinations of elements from the three sub-arrays,
    // and add the sum of the selected elements to the result list if the product of their indices is less than or equal to k.
    for (int i = 0; i < x[0]; ++i) {
        for (int j = 0; j < x[1]; ++j) {
            for (int m = 0; m < x[2]; ++m) {
                if ((i + 1) * (j + 1) * (m + 1) <= k) {
                    long long tmp = a[0][x[0] - i - 1] + a[1][x[1] - j - 1] + a[2][x[2] - m - 1];
                    ans[ans_index++] = tmp;
                }
            }
        }
    }

    // Step 7: Sort the result list in ascending order.
    for (int i = 0; i < ans_index; ++i) {
        for (int j = i + 1; j < ans_index; ++j) {
            if (ans[i] > ans[j]) {
                long long temp = ans[i];
                ans[i] = ans[j];
                ans[j] = temp;
            }
        }
    }

    // Step 8: Print the top k values from the result list in descending order.
    for (int i = 0; i < k; ++i) {
        printf("%lld\n", ans[ans_index - i - 1]);
    }

    return 0;
}
