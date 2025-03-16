
#include <stdio.h>  // Include the standard input/output library
#include <string.h>  // Include the string library for string manipulation

int main() {
    int n;  // Declare and initialize the variable n to store the number of elements
    scanf("%d", &n);  // Read the number of elements from the input

    char s[n][100];  // Declare a 2D array of characters to store the input elements
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);  // Read each element from the input and store it in the corresponding array index
    }

    int count[n];  // Declare an array to store the count of each element
    memset(count, 0, sizeof(count));  // Initialize the count array to all zeros

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (strcmp(s[i], s[j]) == 0) {  // Compare each element with all other elements
                count[i]++;  // Increment the count of the current element if it matches another element
            }
        }
    }

    int max_count = 0;  // Initialize the variable max_count to store the maximum count of any element
    int last_index = -1;  // Initialize the variable last_index to store the index of the last occurrence of the most frequent element
    for (int i = 0; i < n; i++) {
        if (count[i] > max_count) {  // Check if the current element's count is greater than the maximum count
            max_count = count[i];  // Update the maximum count if the current element's count is greater
            last_index = i;  // Update the index of the last occurrence of the most frequent element
        }
    }

    printf("%s", s[last_index]);  // Print the most frequent element that appears last in the original order

    return 0;  // Return 0 to indicate successful execution of the program
}
