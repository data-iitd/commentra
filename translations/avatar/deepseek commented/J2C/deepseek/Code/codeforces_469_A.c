#include <stdio.h>

int main() {
    int n, levels, level2, level3, count = 0;

    // Read the total number of levels
    scanf("%d", &n);

    // Read the number of levels the user has completed
    scanf("%d", &levels);

    int arr[levels];

    // Read the levels completed by the user
    for (int i = 0; i < levels; i++) {
        scanf("%d", &arr[i]);
    }

    // Read the number of levels the second user has completed
    scanf("%d", &level2);
    level3 = levels + level2;
    int arr2[level3];

    // Copy levels from arr to arr2
    for (int i = 0; i < levels; i++) {
        arr2[i] = arr[i];
    }

    // Read additional levels for arr2
    for (int i = levels; i < level3; i++) {
        scanf("%d", &arr2[i]);
    }

    // Generate a sequence of numbers from 1 to n
    int arr3[n];
    for (int i = 0; i < n; i++) {
        arr3[i] = i + 1;
    }

    // Check if all numbers from 1 to n are present in arr2
    for (int i = 0; i < n; i++) {
        for (int x = 0; x < level3; x++) {
            if (arr3[i] == arr2[x]) {
                count++;
                break;
            }
        }
    }

    // Print the result based on whether all levels were completed
    if (count == n) {
        printf("I become the guy.\n");
    } else {
        printf("Oh, my keyboard!\n");
    }

    return 0;
}
