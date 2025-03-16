#include <stdio.h>
#include <string.h>

#define MAX_N 100 // Assuming a maximum size for the input list

int main() {
    int n;
    scanf("%d", &n); // Read the number of elements in the list

    char l[MAX_N][100]; // Array to hold the strings (assuming max length of each string is 99)
    int s[MAX_N] = {0}; // Array to count occurrences of each string
    char f[4] = "Yes"; // Initialize flag with "Yes"
    int i = -1; // Initialize index

    // Read elements into the list
    for (int j = 0; j < n; j++) {
        scanf("%s", l[j]);
    }

    // Iterate through each element in the list
    for (int j = 0; j < n; j++) {
        // Increment the count of l[j] in the dictionary (using a simple array for counting)
        for (int k = 0; k <= i; k++) {
            if (strcmp(l[j], l[k]) == 0) {
                s[k]++;
                break;
            }
        }
        if (s[j] == 0) {
            s[j] = 1; // First occurrence
            i++; // Increment index
        }

        // Check if the count of l[j] is greater than or equal to 2
        if (s[j] >= 2) {
            strcpy(f, "No"); // Set flag to "No"
        }

        // Check if the index i is not -1 and the last character of previous element is not equal to the current element
        if (i != -1 && l[i - 1][strlen(l[i - 1]) - 1] != l[j][0]) {
            strcpy(f, "No"); // Set flag to "No"
        }
    }

    // Print the final value of flag f
    printf("%s\n", f);

    return 0;
}
