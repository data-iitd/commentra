#include <stdio.h>
#include <limits.h>

void rememberTheNumber(int nums[], int i, char operations[], long long *ans) {
    if (i >= 3) {
        return; // If the index 'i' is greater than or equal to 3, return.
    }

    for (int j = 0; j < 4; j++) {
        for (int k = j + 1; k < 4; k++) {
            if (nums[j] != -1 && nums[k] != -1) {
                long long s = nums[j]; // Store the value of nums[j].
                nums[j] = -1; // Mark nums[j] as processed.
                long long t = nums[k]; // Store the value of nums[k].

                if (operations[i] == '+') {
                    nums[k] = s + t; // Perform addition.
                } else if (operations[i] == '*') {
                    nums[k] = s * t; // Perform multiplication.
                }

                if (i == 2 && nums[k] < *ans) {
                    *ans = nums[k]; // Update the answer if condition is met.
                }

                rememberTheNumber(nums, i + 1, operations, ans); // Recursive call.

                nums[j] = s; // Restore the original value of nums[j].
                nums[k] = t; // Restore the original value of nums[k].
            }
        }
    }
}

int main() {
    int nums[4];
    char operations[3];
    long long ans = LLONG_MAX; // Initialize the answer with a large number.

    // Read the list of numbers as input.
    for (int i = 0; i < 4; i++) {
        scanf("%d", &nums[i]);
    }

    // Read the list of operations as input.
    for (int i = 0; i < 3; i++) {
        scanf(" %c", &operations[i]);
    }

    rememberTheNumber(nums, 0, operations, &ans); // Call the function with initial index '0'.
    printf("%lld\n", ans); // Print the final answer.

    return 0;
}

// <END-OF-CODE>
