#include <stdio.h>

int main() {
    // Read an integer input which represents the number of elements in the array
    int n;
    scanf("%d", &n);

    // Declare an array to store the elements
    int arr[n];

    // Read the next line of input and store it in the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Check if the first element of the array is greater than 15
    if (arr[0] > 15) {
        // If true, print 15 as the output
        printf("15\n");
    } else {
        // Iterate through the array starting from the second element
        for (int i = 1; i < n; i++) {
            // Check if the difference between the current and previous element is greater than 15
            if (arr[i] - arr[i - 1] > 15) {
                // If true, print the previous element plus 15 and exit the loop
                printf("%d\n", arr[i - 1] + 15);
                break;
            }
            // If no break occurred, check the last element of the array
            if (i == n - 1) {
                if (arr[n - 1] == 90 || arr[n - 1] + 15 >= 90) {
                    // If the last element is 90 or adding 15 to it results in 90 or more, print 90
                    printf("90\n");
                } else {
                    // Otherwise, print the last element plus 15
                    printf("%d\n", arr[n - 1] + 15);
                }
            }
        }
    }

    return 0;
}
// <END-OF-CODE>
