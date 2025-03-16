
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // Declare two strings to hold the input
    char str1[100], str2[100];
    
    // Read two strings from the standard input
    scanf("%s %s", str1, str2);

    // Sort the first string in ascending order
    qsort(str1, strlen(str1), sizeof(char), compare);
    
    // Sort the second string in descending order
    qsort(str2, strlen(str2), sizeof(char), compare_desc);

    // Determine the length of the shorter string for the loop
    int loop = strlen(str1) > strlen(str2)? strlen(str2) : strlen(str1);
    
    // Initialize a flag to track if the condition is met
    int flag = 0;

    // Loop through the characters of both strings up to the length of the shorter one
    for (int i = 0; loop > i; i++) {
        char ch1 = str1[i]; // Get the character from the first string
        char ch2 = str2[i]; // Get the character from the second string

        // Check if the characters are equal
        if (ch1 == ch2) {
            // If we are at the last character of the shorter string and str1 is shorter
            if (loop == i + 1 && strlen(str1) < strlen(str2)) {
                flag = 1; // Set the flag to true
                break; // Exit the loop
            } else {
                continue; // Continue to the next iteration
            }
        } else {
            // If the character from str2 is greater than that from str1
            if (ch2 > ch1) {
                flag = 1; // Set the flag to true
                break; // Exit the loop
            } else {
                break; // Exit the loop if ch1 is greater
            }
        }
    }

    // Output the result based on the flag's value
    if (flag) {
        printf("Yes\n"); // Condition met
    } else {
        printf("No\n"); // Condition not met
    }

    return 0;
}

// Compare function for qsort to sort strings in ascending order
int compare(const void *a, const void *b) {
    return *(char*)a - *(char*)b;
}

// Compare function for qsort to sort strings in descending order
int compare_desc(const void *a, const void *b) {
    return *(char*)b - *(char*)a;
}
