
#include <stdio.h> // Include the necessary header file

int main() {
    // Read an integer n from user input, which represents the number of elements
    int n;
    scanf("%d", &n);
    
    // Initialize a list to store the indices of elements that are equal to 1
    int arr[n];
    int count = 0;

    // Loop through the input values to find indices of elements equal to 1
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] == 1) {
            count++;
        }
    }

    // Check if the count of elements equal to 1 is 0
    if (count == 0) {
        // If the count is 0, print 0
        printf("0\n");
    } else {
        // If the count is not 0, initialize a result variable to 1
        long long result = 1;

        // Calculate the product of the differences between consecutive indices
        for (int i = 1; i < count; i++) {
            result *= (i - (i - 1));
        }

        // Print the final result
        printf("%lld\n", result);
    }

    return 0;
}
