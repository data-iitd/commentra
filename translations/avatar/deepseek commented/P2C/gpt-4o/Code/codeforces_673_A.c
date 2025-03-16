#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);  // Take input for the number of elements in the array
    int arr[n];  // Declare an array of size n

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);  // Take input for the array elements
    }

    // Check if the first element of the array is greater than 15
    if (arr[0] > 15) {
        printf("15\n");  // If true, print 15
    } else {
        // Iterate through the array starting from the second element
        for (int i = 1; i < n; i++) {
            // Check if the difference between the current and previous element is greater than 15
            if (arr[i] - arr[i - 1] > 15) {
                printf("%d\n", arr[i - 1] + 15);  // If true, print the previous element plus 15 and break the loop
                break;
            }
            // If the loop completes without breaking
            if (i == n - 1) {
                if (arr[n - 1] == 90 || arr[n - 1] + 15 >= 90) {
                    printf("90\n");  // If the last element is 90 or adding 15 to the last element is >= 90, print 90
                } else {
                    printf("%d\n", arr[n - 1] + 15);  // Otherwise, print the last element plus 15
                }
            }
        }
    }

    return 0;
}
// <END-OF-CODE>
