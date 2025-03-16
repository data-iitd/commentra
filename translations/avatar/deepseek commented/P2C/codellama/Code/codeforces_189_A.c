#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cutRibbon() {
    // Take input from the user, which is expected to be a list of three integers
    char input[100];
    scanf("%s", input);
    
    // Assign the first integer in the input list to the variable 'length'
    int length = atoi(strtok(input, " "));
    
    // Sort the remaining three integers in ascending order and assign to 'arr'
    int arr[3];
    arr[0] = atoi(strtok(NULL, " "));
    arr[1] = atoi(strtok(NULL, " "));
    arr[2] = atoi(strtok(NULL, " "));
    qsort(arr, 3, sizeof(int), compare);
    
    // Check if 'length' is perfectly divisible by the largest integer in 'arr'
    if (length % arr[0] == 0) {
        // Print the quotient and return if true
        printf("%d\n", length / arr[0]);
        return;
    }
    
    // Initialize 'ans' to 0 for storing the maximum number of ribbons
    int ans = 0;
    
    // If the two smaller integers are equal, proceed with this block
    if (arr[0] == arr[1]) {
        int k = 0;
        // Iterate through possible combinations of the two smaller integers
        for (int i = 0; i <= length / arr[2]; i++) {
            int check = length - i * arr[2];
            if (check >= 0 && check % arr[0] == 0) {
                k = check / arr[0];
                ans = max(ans, k + i);
            }
        }
    } else {
        // If the two smaller integers are not equal, iterate through all three integers
        int k = 0;
        for (int i = 0; i <= length / arr[2]; i++) {
            for (int j = 0; j <= length / arr[1]; j++) {
                int check = length - i * arr[2] - j * arr[1];
                if (check >= 0 && check % arr[0] == 0) {
                    k = check / arr[0];
                    ans = max(ans, k + i + j);
                }
            }
        }
    }
    
    // Print the maximum number of ribbons that can be cut and return
    printf("%d\n", ans);
    return;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    cutRibbon();
    return 0;
}

