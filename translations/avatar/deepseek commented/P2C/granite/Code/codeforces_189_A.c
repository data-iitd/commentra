
#include <stdio.h>
#include <stdlib.h>

void cutRibbon() {
    // Declare and initialize an array 'arr' of size 3 to store the input integers
    int arr[3];
    for (int i = 0; i < 3; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Sort the array 'arr' in ascending order
    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    // Assign the first integer in the sorted array 'arr' to the variable 'length'
    int length = arr[0];
    
    // Check if 'length' is perfectly divisible by the largest integer in 'arr'
    if (length % arr[2] == 0) {
        // Print the quotient and return if true
        printf("%d\n", length / arr[2]);
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
                ans = (ans > k + i)? ans : k + i;
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
                    ans = (ans > k + i + j)? ans : k + i + j;
                }
            }
        }
    }
    
    // Print the maximum number of ribbons that can be cut and return
    printf("%d\n", ans);
    return;
}

int main() {
    // Call the function 'cutRibbon' to execute the program
    cutRibbon();
    return 0;
}

