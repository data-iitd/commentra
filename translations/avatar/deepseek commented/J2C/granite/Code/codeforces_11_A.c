

#include <stdio.h>

int main() {
    int n, d;
    scanf("%d %d", &n, &d); // Read the number of elements and the difference threshold
    int nums[n]; // Initialize an array to store the numbers
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]); // Read the numbers and store them in the array
    }
    int result = 0; // Initialize the result variable to 0
    int a = 0; // Initialize another variable to store the difference
    for (int i = 1; i < n; i++) {
        a = (nums[i - 1] - nums[i]); // Calculate the difference between consecutive elements
        if (a >= 0) {
            result += a / d + 1; // Update the result based on the difference
            nums[i] += (a / d + 1) * d; // Adjust the current element to meet the condition
        }
    }
    printf("%d\n", result); // Print the final result
    return 0;
}
