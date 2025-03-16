#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int lst[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &lst[i]);
    }

    // Sort the list in ascending order
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (lst[i] > lst[j]) {
                int temp = lst[i];
                lst[i] = lst[j];
                lst[j] = temp;
            }
        }
    }

    // Reverse the list to get it in descending order
    for (int i = 0; i < n / 2; i++) {
        int temp = lst[i];
        lst[i] = lst[n - i - 1];
        lst[n - i - 1] = temp;
    }

    // Initialize a counter for odd numbers
    int od = 0;

    // Count the number of odd integers in the list
    for (int i = 0; i < n; i++) {
        if (lst[i] & 1) {  // Check if the number is odd using bitwise AND
            od++;  // Increment the odd counter
        }
    }

    // Initialize variables for sum and a flag to track even number inclusion
    int sum = 0;
    int ok = 0;

    // Iterate through the sorted list to calculate the desired sum
    for (int i = 0; i < n; i++) {
        if (lst[i] % 2 == 0) {  // Check if the current number is even
            sum += lst[i];  // Add even numbers directly to the sum
        } else {
            // If we have already included an odd number or there is more than one odd number left
            if (ok || od > 1) {
                sum += lst[i];  // Add the odd number to the sum
                od--;  // Decrement the odd counter
                ok = !ok;  // Toggle the flag to indicate an odd number has been included
            }
        }
    }

    // Print the final calculated sum
    printf("%d\n", sum);

    return 0;
}
