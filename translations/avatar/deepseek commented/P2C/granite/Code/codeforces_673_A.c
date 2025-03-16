
#include <stdio.h>

int main() {
    int n, arr[100000];
    scanf("%d", &n);  // Take input for the number of elements in the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);  // Take input for the array elements
    }

    // Check if the first element of the array is greater than 15
    if (arr[0] > 15) {
        printf("15\n");  // If true, print 15
    } else {
        int i;
        for (i = 1; i < n; i++) {
            // Check if the difference between the current and previous element is greater than 15
            if (arr[i] - arr[i - 1] > 15) {
                printf("%d\n", arr[i - 1] + 15);  // If true, print the previous element plus 15 and break the loop
                break;
            }
        }
        if (i == n) {
            // If the loop completes without breaking
            if (arr[n - 1] == 90 || arr[n - 1] + 15 >= 90) {
                printf("90\n");  // If the last element is 90 or adding 15 to the last element is >= 90, print 90
            } else {
                printf("%d\n", arr[n - 1] + 15);  // Otherwise, print the last element plus 15
            }
        }
    }

    return 0;
}
