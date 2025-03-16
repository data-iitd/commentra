#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the count of each element in the list
struct element {
    int count;
    char value;
};

// Function to check if the list is a valid palindrome
int is_palindrome(struct element *s, int n) {
    // Initialize a flag 'f' with value 'Yes'
    int f = 1;

    // Initialize an index 'i' with value 0
    int i = 0;

    // Iterate through each element 'v' in the list
    for (int j = 0; j < n; j++) {
        // Increment the count of 'v' in dictionary 's'
        s[j].count++;

        // Check if the count of 'v' in dictionary 's' is greater than or equal to 2
        if (s[j].count >= 2) {
            // If yes, set the flag 'f' to 'No'
            f = 0;
        }

        // Check if the index 'i' is not -1 and the last character of previous element is not equal to the current element
        if (i != -1 && s[i].value != s[j].value) {
            // If yes, set the flag 'f' to 'No'
            f = 0;
        }

        // Increment the index 'i'
        i++;
    }

    // Return the final value of flag 'f'
    return f;
}

// Main function
int main() {
    // Read the number of elements in the list from user input
    int n;
    scanf("%d", &n);

    // Initialize an empty dictionary 's' with default value 0 using defaultdict
    struct element *s = (struct element *)malloc(n * sizeof(struct element));

    // Create an empty list 'l' with length 'n' by reading elements from user input
    char *l = (char *)malloc(n * sizeof(char));
    for (int i = 0; i < n; i++) {
        scanf("%s", &l[i]);
    }

    // Check if the list is a valid palindrome
    int f = is_palindrome(s, n);

    // Print the final value of flag 'f'
    printf("%d\n", f);

    // Free the memory allocated to 's' and 'l'
    free(s);
    free(l);

    // Return 0
    return 0;
}

