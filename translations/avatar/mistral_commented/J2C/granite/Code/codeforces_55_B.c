

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long min = LONG_MAX;

void util(long arr[], char ops[], int idx, int n) {
    if (idx == n - 1) {
        min = (min < arr[0])? min : arr[0];
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long a[n - 2];
            int k = 0;
            for (int l = 0; l < n; l++) {
                if (l!= j && l!= i) {
                    a[k++] = arr[l];
                }
            }

            long res;
            if (idx < n - 2 && ops[idx] == '+') {
                res = arr[i] + arr[j];
            } else {
                res = arr[i] * arr[j];
            }

            a[k++] = res;
            util(a, ops, idx + 1, n);
        }
    }
}

int main() {
    long arr[4];
    char ops[3];

    for (int i = 0; i < 4; i++) {
        scanf("%ld", &arr[i]);
    }

    for (int i = 0; i < 3; i++) {
        scanf(" %c", &ops[i]);
    }

    util(arr, ops, 0, 4);

    printf("%ld\n", min);

    return 0;
}

This code is a translation of the given Java code into C. It uses the same logic and algorithms to find the minimum value. The main function reads the input numbers and operators, and then calls the util function to perform the recursive calculations. The util function takes the input array, the operator array, the current index, and the total number of elements as parameters. It updates the global variable min with the minimum value found during the execution. The code also includes the necessary header files and defines the data types used in the program.

Please note that the code assumes that the input numbers and operators are valid and within the appropriate ranges.