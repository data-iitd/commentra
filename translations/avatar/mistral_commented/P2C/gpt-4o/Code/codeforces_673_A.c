#include <stdio.h>

int main() {
    // Take the number of elements in the list as input
    int n;
    scanf("%d", &n);

    // Initialize an array 'arr' to store the input elements
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Check if the first element of the list is greater than 15
    if (arr[0] > 15) {
        // If it is, print 15
        printf("15\n");
    } else {
        // Else, iterate through the list starting from the second element
        for (int i = 1; i < n; i++) {
            // Check if the difference between the current and previous elements is greater than 15
            if (arr[i] - arr[i-1] > 15) {
                // If it is, print the previous element plus 15
                printf("%d\n", arr[i-1] + 15);
                // Break the loop as we have found the answer
                break;
            }
            // Else, if we reach here, it means that no difference was greater than 15
            else if (i == n - 1) {
                // Check if the last element of the list is 90 or if adding 15 to it results in 90 or more
                if (arr[n-1] == 90 || arr[n-1] + 15 >= 90) {
                    // If it is, print 90
                    printf("90\n");
                } else {
                    // Else, print the last element plus 15
                    printf("%d\n", arr[n-1] + 15);
                }
            }
        }
    }

    return 0;
}
// <END-OF-CODE>
