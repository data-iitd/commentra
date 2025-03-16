

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, levels, sum = 0, sum2 = 0, sum3 = 0, arr[100], count = 0, level2, level3, arr2[200], arr3[100], i, j, x;

    // Read the total number of levels and the number of levels completed by the user
    scanf("%d %d", &n, &levels);

    // Read the levels completed by the user
    for (i = 0; i < levels; i++) {
        scanf("%d", &arr[i]);
    }

    // Read the number of levels completed by the second user
    scanf("%d", &level2);

    // Calculate the total number of levels
    level3 = levels + level2;

    // Copy levels from arr to arr2
    for (i = 0; i < levels; i++) {
        arr2[i] = arr[i];
    }

    // Read additional levels for arr2
    for (i = levels; i < level3; i++) {
        scanf("%d", &arr2[i]);
    }

    // Generate a sequence of numbers from 1 to n
    for (i = 0; i < n; i++) {
        arr3[i] = i + 1;
    }

    // Check if all numbers from 1 to n are present in arr2
    for (i = 0; i < n; i++) {
        for (x = 0; x < level3; x++) {
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
