#include <stdio.h>

void cutRibbon() {
    int arr[4];
    
    // Read input and convert it into an array of integers
    for (int i = 0; i < 4; i++) {
        scanf("%d", &arr[i]);
    }
    
    // The first element is the total length of the ribbon
    int length = arr[0];
    
    // Sort the next three elements (the lengths of the pieces) in ascending order
    for (int i = 1; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    // If the total length is divisible by the smallest piece length, print the maximum number of pieces
    if (length % arr[1] == 0) {
        printf("%d\n", length / arr[1]);
        return;
    }
    
    // Initialize the answer variable to keep track of the maximum pieces
    int ans = 0;
    
    // Case when the two smallest piece lengths are equal
    if (arr[1] == arr[2]) {
        int k = 0;
        // Iterate through the number of the largest pieces that can fit into the ribbon
        for (int i = 0; i <= length / arr[3]; i++) {
            // Calculate the remaining length after using i pieces of the largest size
            int check = length - i * arr[3];
            // Check if the remaining length can be completely divided by the smallest piece length
            if (check >= 0 && check % arr[1] == 0) {
                k = check / arr[1];
                // Update the maximum pieces found
                ans = (ans > k + i) ? ans : (k + i);
            }
        }
    } else {
        // Case when the two smallest piece lengths are different
        int k = 0;
        // Iterate through the number of the largest pieces that can fit into the ribbon
        for (int i = 0; i <= length / arr[3]; i++) {
            // Iterate through the number of the second largest pieces that can fit into the ribbon
            for (int j = 0; j <= length / arr[2]; j++) {
                // Calculate the remaining length after using i pieces of the largest size and j pieces of the second largest size
                int check = length - i * arr[3] - j * arr[2];
                // Check if the remaining length can be completely divided by the smallest piece length
                if (check >= 0 && check % arr[1] == 0) {
                    k = check / arr[1];
                    // Update the maximum pieces found
                    ans = (ans > k + i + j) ? ans : (k + i + j);
                }
            }
        }
    }
    
    // Print the maximum number of pieces that can be obtained
    printf("%d\n", ans);
}

// Call the function to execute the ribbon cutting logic
int main() {
    cutRibbon();
    return 0;
}

// <END-OF-CODE>
