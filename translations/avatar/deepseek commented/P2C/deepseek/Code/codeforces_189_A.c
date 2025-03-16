#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[3];
    int length;
    int ans = 0;

    // Take input from the user, which is expected to be a list of three integers
    scanf("%d %d %d %d", &arr[0], &arr[1], &arr[2], &length);

    // Sort the remaining three integers in ascending order
    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Check if 'length' is perfectly divisible by the largest integer in 'arr'
    if (length % arr[2] == 0) {
        // Print the quotient and return if true
        printf("%d\n", length / arr[2]);
        return 0;
    }

    // Initialize 'ans' to 0 for storing the maximum number of ribbons
    int k = 0;

    // If the two smaller integers are equal, proceed with this block
    if (arr[0] == arr[1]) {
        for (int i = 0; i <= length / arr[2]; i++) {
            int check = length - i * arr[2];
            if (check >= 0 && check % arr[0] == 0) {
                k = check / arr[0];
                if (ans < k + i) {
                    ans = k + i;
                }
            }
        }
    } else {
        // If the two smaller integers are not equal, iterate through all three integers
        for (int i = 0; i <= length / arr[2]; i++) {
            for (int j = 0; j <= length / arr[1]; j++) {
                int check = length - i * arr[2] - j * arr[1];
                if (check >= 0 && check % arr[0] == 0) {
                    k = check / arr[0];
                    if (ans < k + i + j) {
                        ans = k + i + j;
                    }
                }
            }
        }
    }

    // Print the maximum number of ribbons that can be cut and return
    printf("%d\n", ans);
    return 0;
}
